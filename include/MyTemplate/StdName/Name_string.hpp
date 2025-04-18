#pragma once

#include <string>

#include "Name_string_view.hpp"

template <typename Elem>
struct Smkz::details::custom_type_name<std::basic_string<Elem>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::basic_string<{"), type_name<Elem>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Elem, typename Traits>
struct Smkz::details::custom_type_name<std::basic_string<Elem, Traits>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::basic_string<{"), type_name<Elem>(),
                      TStr_of_a<','>{}, type_name<Traits>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <>
constexpr auto Smkz::type_name<std::string>() noexcept {
  return TSTR("std::string");
}

template <>
constexpr auto Smkz::type_name<std::wstring>() noexcept {
  return TSTR("std::wstring");
}

template <>
constexpr auto Smkz::type_name<std::u8string>() noexcept {
  return TSTR("std::u8string");
}

template <>
constexpr auto Smkz::type_name<std::u16string>() noexcept {
  return TSTR("std::u16string");
}

template <>
constexpr auto Smkz::type_name<std::u32string>() noexcept {
  return TSTR("std::u32string");
}
