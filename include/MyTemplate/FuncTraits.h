//
// Created by Admin on 26/12/2024.
//

#pragma once

#include "TypeList.h"

namespace My {
// ArgList : TypeList<Args...>
// Ret
template <typename T>
struct FuncTraits;
}  // namespace My

// ============================================================

namespace My::detail::FuncTraits {
template <typename T>
struct FuncTraits;
}

namespace My {
// ArgList, Ret
template <typename T>
struct FuncTraits : detail::FuncTraits::FuncTraits<T> {};
}  // namespace My

namespace My::detail::FuncTraits {
template <typename T>
struct FuncTraits;

template <typename _Ret, typename... Args>
struct FuncTraits<_Ret(Args...)> {
  using ArgList = TypeList<Args...>;
  using Ret = _Ret;
};

template <typename T, typename _Ret, typename... Args>
struct FuncTraits<_Ret (T::*)(Args...)> {
  using ArgList = TypeList<Args...>;
  using Ret = _Ret;
};

template <typename T, typename _Ret, typename... Args>
struct FuncTraits<_Ret (T::*)(Args...) const> {
  using ArgList = TypeList<Args...>;
  using Ret = _Ret;
};

template <typename T>
struct FuncTraits : FuncTraits<decltype(&std::decay_t<T>::operator())> {};
}  // namespace My::detail::FuncTraits
