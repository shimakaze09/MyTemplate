//
// Created by Admin on 29/12/2024.
//

#pragma once

#include "Concept.h"
#include "Typelist.h"

#include <tuple>
#include <utility>

namespace My {
// type ArgList : TypeList<Args...>
// type Ret
// type Obj
// type Signature
// bool is_member
// bool is_const
template <typename T>
struct FuncTraits;
template <typename T>
using FuncTraits_ArgList = typename FuncTraits<T>::ArgList;
template <typename T>
using FuncTraits_Ret = typename FuncTraits<T>::Ret;
template <typename T>
using FuncTraits_Obj = typename FuncTraits<T>::Obj;
template <typename T>
using FuncTraits_Signature = typename FuncTraits<T>::Signature;

// NewFunc == Ret(Args...)
// static Ret(Args...) run(Func);
// - { Func's arguments, ... } == { Args... }
// - Ret == void or Ret <- Func'return type
template <typename NewFunc>
struct FuncExpand;

// run()
template <typename Func>
struct MemFuncOf;

template <typename Func>
struct IsConstFunc;
template <typename Func>
constexpr bool IsConstFunc_v = IsConstFunc<Func>::value;

template <typename Func>
struct RemoveFuncConst;
template <typename Func>
using RemoveFuncConst_t = typename RemoveFuncConst<Func>::type;

template <typename Lambda>
constexpr auto DecayLambda(Lambda&& lambda);
}  // namespace My

//============================================================

namespace My::detail::Func_ {
// ref: qobjectdefs_impl.h

template <typename T>
struct RmvLValueRef : IType<T> {};

template <typename T>
struct RmvLValueRef<T&> : IType<T> {};

template <typename T>
struct RmvConstRef : IType<T> {};

template <typename T>
struct RmvConstRef<const T&> : IType<T> {};

template <typename A1, typename A2>
struct AreArgumentsCompatible
    : std::is_same<const typename RmvLValueRef<A1>::type&,
                   const typename RmvLValueRef<A2>::type&> {};

template <typename A1, typename A2>
struct AreArgumentsCompatible<A1, A2&> : std::false_type {};

template <typename A>
struct AreArgumentsCompatible<A&, A&> : std::true_type {};

// void as a return value
template <typename A>
struct AreArgumentsCompatible<void, A> : std::true_type {};

template <typename A>
struct AreArgumentsCompatible<A, void> : std::true_type {};

template <>
struct AreArgumentsCompatible<void, void> : std::true_type {};

// ========================

template <typename ToArgList, typename FromArgList>
struct CheckCompatibleArguments : std::false_type {};

template <>
struct CheckCompatibleArguments<TypeList<>, TypeList<>> : std::true_type {};

template <typename ToArgList>
struct CheckCompatibleArguments<ToArgList, TypeList<>> : std::true_type {};

template <typename FromArgHead, typename... FromArgTail>
struct CheckCompatibleArguments<TypeList<>,
                                TypeList<FromArgHead, FromArgTail...>>
    : std::false_type {};

template <typename ToArgHead, typename FromArgHead, typename... ToArgTail,
          typename... FromArgTail>
struct CheckCompatibleArguments<TypeList<ToArgHead, ToArgTail...>,
                                TypeList<FromArgHead, FromArgTail...>> {
  static constexpr bool value =
      AreArgumentsCompatible<typename RmvConstRef<ToArgHead>::type,
                             typename RmvConstRef<FromArgHead>::type>::value &&
      CheckCompatibleArguments<TypeList<ToArgTail...>,
                               TypeList<FromArgTail...>>::value;
};
}  // namespace My::detail::Func_

namespace My {
template <typename Func>
struct FuncTraitsBase;

template <typename _Ret, typename... Args>
struct FuncTraitsBase<_Ret(Args...)> {
  using ArgList = TypeList<Args...>;
  using Ret = _Ret;
  using Signature = Ret(Args...);
};

template <typename Ret, typename... Args>
struct FuncTraitsBase<Ret(Args...) const> : FuncTraitsBase<Ret(Args...)> {};

template <typename Ret, typename... Args>
struct FuncTraits<Ret(Args...)> : FuncTraitsBase<Ret(Args...)> {
  using Obj = void;
  static constexpr bool is_member = false;
  static constexpr bool is_const = false;
};

template <typename Func>
struct FuncTraits<Func*> : FuncTraits<Func> {};

template <typename T, typename Func>
struct FuncTraits<Func T::*> : FuncTraitsBase<Func> {
  using Obj = T;
  static constexpr bool is_member = false;
  static constexpr bool is_const = false;
};

template <typename T>
struct FuncTraits : FuncTraits<decltype(&std::decay_t<T>::operator())> {};

//============================================================

template <typename Ret, typename... Args>
struct FuncExpand<Ret(Args...)> {
  template <typename Func>
  static auto run(Func&& func) noexcept {
    static_assert(
        std::is_void_v<Ret> || std::is_convertible_v<FuncTraits_Ret<Func>, Ret>,
        "Func's return can't convert to Ret");
    constexpr size_t N = Length_v<typename FuncTraits<Func>::ArgList>;
    return run(std::forward<Func>(func), std::make_index_sequence<N>{});
  }

 private:
  template <typename Func, size_t... Ns>
  static auto run(Func&& func, std::index_sequence<Ns...>) {
    using FromArgList = typename FuncTraits<Func>::ArgList;
    using ToArgList = TypeList<Args...>;
    return [func = std::forward<Func>(func)](Args... args) {
      std::tuple<Args...> argTuple{std::forward<Args>(args)...};
      static_assert(detail::Func_::CheckCompatibleArguments<ToArgList,
                                                            FromArgList>::value,
                    "from and to arguments are not compatible.");
      if constexpr (std::is_void_v<Ret>)
        func(std::get<Ns>(argTuple)...);
      else
        return static_cast<Ret>(func(std::get<Ns>(argTuple)...));
    };
  }
};

// =========================

namespace detail::Func_ {
template <typename Func, typename>
struct IsConstFuncHelper : std::true_type {};

template <typename Func>
struct IsConstFuncHelper<Func, std::void_t<Func*>> : std::false_type {};
}  // namespace detail::Func_

template <typename Func>
struct IsConstFunc : detail::Func_::IsConstFuncHelper<Func, void> {};

template <typename Func>
struct RemoveFuncConst : IType<Func> {};

template <typename Ret, typename... Args>
struct RemoveFuncConst<Ret(Args...) const> : IType<Ret(Args...)> {};

template <typename Obj, typename Ret, typename... Args>
struct RemoveFuncConst<Ret (Obj::*)(Args...) const>
    : IType<Ret (Obj::*)(Args...)> {};

template <typename Func>
struct MemFuncOf {
  template <typename Obj>
  static constexpr auto run(Func Obj::* func) noexcept {
    return func;
  }

  static constexpr auto run(RemoveFuncConst_t<Func> func) noexcept {
    return func;
  }
};

// =================================================================

template <typename Lambda>
constexpr auto DecayLambda(Lambda&& lambda) {
  return static_cast<std::add_pointer_t<
      FuncTraits_Signature<std::remove_reference_t<Lambda>>>>(lambda);
}
}  // namespace My
