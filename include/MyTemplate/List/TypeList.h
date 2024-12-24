//
// Created by Admin on 24/12/2024.
//

#pragma once

#include "List.h"
#include "../Name.h"

namespace My {
template <typename... Ts>
struct TypeList {};

// [ Name ]
template <typename... Ts>
struct Name<TypeList<Ts...>> {
  friend std::ostream& operator<<(std::ostream& os, Name<TypeList<Ts...>>) {
    os << "[" << Name<Ts...>() << "]";
    return os;
  }
};

// [ List ]
// Basic
template <>
struct IsEmpty<TypeList<>> {
  static constexpr bool value = true;
};

template <typename Head, typename... Tail>
struct FrontT<TypeList<Head, Tail...>> {
  using type = Head;
};

template <typename T, typename... Ts>
struct PushFrontT<TypeList<Ts...>, T> {
  using type = TypeList<T, Ts...>;
};

template <typename Head, typename... Tail>
struct PopFrontT<TypeList<Head, Tail...>> {
  using type = TypeList<Tail...>;
};

// Optimized
template <typename... Ts>
struct ClearT<TypeList<Ts...>, false> {
  using type = TypeList<>;
};

template <template <typename T> class Op, typename... Ts>
struct TransformT<TypeList<Ts...>, Op> {
  using type = TypeList<typename Op<Ts>::type...>;
};
}  // namespace My