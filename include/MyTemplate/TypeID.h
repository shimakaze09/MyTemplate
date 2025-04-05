//
// Created by Admin on 26/12/2024.
//

#pragma once

#include "Name.h"

namespace My {
class StrID {
 public:
  static constexpr std::size_t InvalidValue() noexcept {
    return static_cast<std::size_t>(-1);
  }

  constexpr StrID() noexcept : value{InvalidValue()} {}

  explicit constexpr StrID(std::size_t value) noexcept : value{value} {}

  constexpr StrID(std::string_view str) noexcept : value{string_hash(str)} {}

  template <std::size_t N>
  constexpr StrID(const char (&str)[N]) noexcept : value{string_hash(str)} {}

  constexpr std::size_t GetValue() const noexcept { return value; }

  constexpr bool Valid() const noexcept { return value != InvalidValue(); }

  constexpr bool Is(std::string_view str) const noexcept {
    return operator==(StrID{str});
  }

  constexpr void Reset() noexcept { value = InvalidValue(); }

  explicit constexpr operator std::size_t() const noexcept { return value; }

  explicit constexpr operator bool() const noexcept { return Valid(); }

  constexpr bool operator<(const StrID& rhs) const noexcept {
    return value < rhs.value;
  }

  constexpr bool operator<=(const StrID& rhs) const noexcept {
    return value <= rhs.value;
  }

  constexpr bool operator>(const StrID& rhs) const noexcept {
    return value > rhs.value;
  }

  constexpr bool operator>=(const StrID& rhs) const noexcept {
    return value >= rhs.value;
  }

  constexpr bool operator==(const StrID& rhs) const noexcept {
    return value == rhs.value;
  }

  constexpr bool operator!=(const StrID& rhs) const noexcept {
    return value != rhs.value;
  }

 private:
  std::size_t value;
};

class TypeID : private StrID {
 public:
  using StrID::GetValue;
  using StrID::InvalidValue;
  using StrID::Reset;
  using StrID::StrID;
  using StrID::Valid;
  using StrID::operator std::size_t;
  using StrID::operator bool;

  using StrID::Is;

  template <typename T>
  constexpr bool Is() const noexcept {
    return operator==(TypeID::of<T>);
  }

  template <typename T>
  static constexpr TypeID of = TypeID{type_name<T>().value};

  constexpr bool operator<(const TypeID& rhs) const noexcept {
    return StrID::operator<(rhs);
  }

  constexpr bool operator<=(const TypeID& rhs) const noexcept {
    return StrID::operator<=(rhs);
  }

  constexpr bool operator>(const TypeID& rhs) const noexcept {
    return StrID::operator>(rhs);
  }

  constexpr bool operator>=(const TypeID& rhs) const noexcept {
    return StrID::operator>=(rhs);
  }

  constexpr bool operator==(const TypeID& rhs) const noexcept {
    return StrID::operator==(rhs);
  }

  constexpr bool operator!=(const TypeID& rhs) const noexcept {
    return StrID::operator!=(rhs);
  }
};

template <typename X, typename Y>
    struct TypeID_Less : IValue < bool,
    TypeID::of<X><TypeID::of<Y>> {
  static_assert(std::is_same_v<X, Y> || TypeID::of<X> != TypeID::of<Y>);
};

template <typename X, typename Y>
constexpr bool TypeID_Less_v = TypeID_Less<X, Y>::value;
}  // namespace My

template <>
struct std::hash<My::StrID> {
  std::size_t operator()(const My::StrID& ID) const noexcept {
    return ID.GetValue();
  }
};

template <>
struct std::hash<My::TypeID> {
  std::size_t operator()(const My::TypeID& ID) const noexcept {
    return ID.GetValue();
  }
};
