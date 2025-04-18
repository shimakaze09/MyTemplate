#pragma once

#include "TemplateList.hpp"

#define SI_InterfaceTraits_Register(Interface, ...) \
  template <>                                       \
  struct Smkz::SI_InterfaceTraits<Interface> {      \
    using IList = TemplateList<__VA_ARGS__>;        \
  }

#define SI_InterfaceTraits_Register_Pro(Interface, ...) \
  template <>                                           \
  struct Smkz::SI_InterfaceTraits<Interface>            \
      : Smkz::details::IListBase<__VA_ARGS__>

#define SI_CombineInterface(Interface, ...) \
  template <typename Base, typename Impl>   \
  struct Interface : Base {                 \
    using Base::Base;                       \
  };                                        \
  SI_InterfaceTraits_Register(Interface, __VA_ARGS__)

#define SI_ImplTraits_Register(Impl, ...)    \
  template <>                                \
  struct Smkz::SI_ImplTraits<Impl> {         \
    using IList = TemplateList<__VA_ARGS__>; \
  }

#define SI_ImplTraits_Register_Pro(Impl, ...) \
  template <>                                 \
  struct Smkz::SI_ImplTraits<Impl> : Smkz::details::IListBase<__VA_ARGS__>

namespace Smkz::details {
template <typename Impl>
struct SI;
template <typename Impl>
using SI_t = typename SI<Impl>::type;
}  // namespace Smkz::details

namespace Smkz {
// IList : TemplateList<Interfaces...>
template <typename Impl>
struct SI_ImplTraits {};

// IList : TemplateList<Interfaces...>
template <template <typename Base, typename Impl> class Interface>
struct SI_InterfaceTraits {};

template <typename Impl>
using SI = details::SI_t<Impl>;

template <typename T, template <typename Base, typename Impl> class Interface>
struct SI_Contains;
template <typename T, template <typename Base, typename Impl> class Interface>
static constexpr bool SI_Contains_v = SI_Contains<T, Interface>::value;
}  // namespace Smkz

#include "details/SI.inl"
