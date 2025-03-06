//
// Created by Admin on 24/12/2024.
//

#pragma once

#include "TemplateList.h"

#define InterfaceTraits_Regist(Interface, ...) \
  template <>                                  \
  struct My::InterfaceTraits<Interface> {      \
    using IList = TemplateList<__VA_ARGS__>;   \
  }

#define InterfaceTraits_Regist_Pro(Interface, ...) \
  template <>                                      \
  struct My::InterfaceTraits<Interface>            \
      : My::detail::SI_::IListBase<__VA_ARGS__>

#define ImplTraits_Regist(Impl, ...)         \
  template <>                                \
  struct My::ImplTraits<Impl> {              \
    using IList = TemplateList<__VA_ARGS__>; \
  }

#define ImplTraits_Regist_Pro(Impl, ...) \
  template <>                            \
  struct My::ImplTraits<Impl> : My::detail::SI_::IListBase<__VA_ARGS__>

namespace My::detail::SI_ {
template <typename Impl>
struct SI;
template <typename Impl>
using SI_t = typename SI<Impl>::type;
}  // namespace My::detail::SI_

namespace My {
// IList : TemplateList<...>
template <typename Impl>
struct ImplTraits {};

// IList : TemplateList<...>
template <template <typename...> class Interface>
struct InterfaceTraits {};

// template<template<typename, typename>class Interface>
// static constexpr bool IsContain() noexcept;
template <typename Impl>
using SI = detail::SI_::SI_t<Impl>;

template <typename T, template <typename...> class Interface>
struct SI_IsContain;
template <typename T, template <typename...> class Interface>
static constexpr bool SI_IsContain_v = SI_IsContain<T, Interface>::value;
}  // namespace My

namespace My::detail::SI_ {
template <typename Enabler, typename T, template <typename...> class Interface>
struct SI_IsContain_Helper;
}

namespace My {
template <typename T, template <typename...> class Interface>
struct SI_IsContain : detail::SI_::SI_IsContain_Helper<void, T, Interface> {};
}  // namespace My

namespace My::detail::SI_ {
// [basic]
template <template <typename...> class... Ts>
struct IListBase {
  using IList = TemplateList<Ts...>;
};

template <typename Impl, typename Enabler>
struct ImplTrait_IList_Helper : IType<TemplateList<>> {};

template <typename Impl>
struct ImplTrait_IList_Helper<Impl,
                              std::void_t<typename ImplTraits<Impl>::IList>>
    : IType<typename ImplTraits<Impl>::IList> {};

template <typename Impl>
struct ImplTrait_IList : ImplTrait_IList_Helper<Impl, void> {};

template <typename Impl>
using ImplTrait_IList_t = typename ImplTrait_IList<Impl>::type;

template <template <typename, typename> class Interface, typename Enabler>
struct InterfaceTrait_IList_Helper : IType<TemplateList<>> {};

template <template <typename, typename> class Interface>
struct InterfaceTrait_IList_Helper<
    Interface, std::void_t<typename InterfaceTraits<Interface>::IList>>
    : IType<typename InterfaceTraits<Interface>::IList> {};

template <template <typename, typename> class Interface>
struct InterfaceTrait_IList : InterfaceTrait_IList_Helper<Interface, void> {};
template <template <typename, typename> class Interface>
using InterfaceTrait_IList_t = typename InterfaceTrait_IList<Interface>::type;

// [TopoSort]
template <typename IList, typename SortedIList>
struct TopoSort_Helper;
template <typename IList, typename SortedIList>
using TopoSort_Helper_t = typename TopoSort_Helper<IList, SortedIList>::type;

template <typename SortedIList>
struct TopoSort_Helper<TemplateList<>, SortedIList> : IType<SortedIList> {};

template <template <typename, typename> class IHead,
          template <typename, typename> class... ITail, typename SortedIList>
struct TopoSort_Helper<TemplateList<IHead, ITail...>, SortedIList> {
  template <bool>
  struct Recursion;

  template <>
  struct Recursion<true> : IType<SortedIList> {};

  template <>
  struct Recursion<false>
      : IType<TPushFront_t<
            TopoSort_Helper_t<InterfaceTrait_IList_t<IHead>, SortedIList>,
            IHead>> {};

  using type = TopoSort_Helper_t<
      TemplateList<ITail...>,
      typename Recursion<TContain_v<SortedIList, IHead>>::type>;
};

// [SI]
template <typename IList>
struct TopoSort : TopoSort_Helper<IList, TemplateList<>> {};

template <typename IList>
using TopoSort_t = typename TopoSort<IList>::type;

template <typename Impl>
struct Nil {
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator+(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator-(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator*(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator/(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator^(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator&(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator|(SI_ERROR) = delete;
  // template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  // void operator~() = delete;
  // template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  // void operator!() = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator<(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator>(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator+=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator-=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator*=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator/=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator%=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator^=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator&=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator|=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator<<(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator>>(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator>>=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator<<=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator==(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator!=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator<=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator>=(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator&&(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator||(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator++(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator--(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator,(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator->*(SI_ERROR) = delete;
  // template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  // void operator->() = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator()(SI_ERROR) = delete;
  template <typename SI_ERROR, typename = typename SI_ERROR::SI_ERROR>
  void operator[](SI_ERROR) = delete;

  template <template <typename, typename> class Interface>
  static constexpr bool IsContain() noexcept {
    using IList = detail::SI_::TopoSort_t<detail::SI_::ImplTrait_IList_t<Impl>>;
    return TContain_v<IList, Interface>;
  }
};

template <typename IList, typename Impl>
struct SI_Helper;
template <typename IList, typename Impl>
using SI_Helper_t = typename SI_Helper<IList, Impl>::type;

template <typename Impl>
struct SI : SI_Helper<TopoSort_t<ImplTrait_IList_t<Impl>>, Impl> {};

template <typename Impl>
struct SI_Helper<TemplateList<>, Impl> : IType<Nil<Impl>> {};

template <template <typename, typename> class IHead,
          template <typename, typename> class... ITail, typename Impl>
struct SI_Helper<TemplateList<IHead, ITail...>, Impl>
    : IType<IHead<SI_Helper_t<TemplateList<ITail...>, Impl>, Impl>> {};

// [is contain]
template <typename Enabler, typename T, template <typename...> class Interface>
struct SI_IsContain_Helper : std::false_type {};

template <typename T, template <typename...> class Interface>
struct SI_IsContain_Helper<std::enable_if_t<std::is_base_of_v<Nil<T>, T>>, T,
                           Interface>
    : IValue<bool, T::template IsContain<Interface>()> {};

template <typename T, template <typename...> class Interface>
struct SI_IsContain : SI_IsContain_Helper<void, T, Interface> {};
}  // namespace My::detail::SI_
