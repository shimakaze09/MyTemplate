//
// Created by Admin on 24/12/2024.
//

#pragma once

namespace My {
struct EBCONil {};

template <template <typename> class... Classes>
struct EBCO;

template <template <typename> class Class>
struct EBCO<Class> {
  template <typename Base>
  using type = Class<Base>;
};

template <template <typename> class ClassHead,
          template <typename> class... ClassTail>
struct EBCO<ClassHead, ClassTail...> {
  template <typename Base>
  using type = ClassHead<typename EBCO<ClassTail...>::template type<Base>>;
};

template <template <typename, typename...> class... Interfaces>
struct EBCOI;

template <template <typename, typename...> class Interface>
struct EBCOI<Interface> {
  template <typename Base, typename... Ts>
  using type = Interface<Base, Ts...>;
};

template <template <typename, typename...> class IHead,
          template <typename, typename...> class... ITail>
struct EBCOI<IHead, ITail...> {
  template <typename Base, typename... Ts>
  using type =
      IHead<typename EBCOI<ITail...>::template type<Base, Ts...>, Ts...>;
};
}  // namespace My
