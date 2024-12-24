//
// Created by Admin on 24/12/2024.
//

#pragma once

#include "../Name.h"
#include "List.h"

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
struct Front<TypeList<Head, Tail...>> {
  using type = Head;
};

template <typename T, typename... Ts>
struct PushFront<TypeList<Ts...>, T> {
  using type = TypeList<T, Ts...>;
};

template <typename Head, typename... Tail>
struct PopFront<TypeList<Head, Tail...>> {
  using type = TypeList<Tail...>;
};

// Optimized
template <typename... Ts>
struct Clear<TypeList<Ts...>, false> {
  using type = TypeList<>;
};

template <template <typename T> class Op, typename... Ts>
struct Transform<TypeList<Ts...>, Op> {
  using type = TypeList<typename Op<Ts>::type...>;
};

template <typename List, typename... Ts>
struct ContainList<List, TypeList<Ts...>>
    : Conjunction<Bool<Contain_v<List, Ts>>...> {};

template <typename List, typename... Ts>
constexpr bool ContainList_v = ContainList<List, Ts...>::type::value;
}  // namespace My
