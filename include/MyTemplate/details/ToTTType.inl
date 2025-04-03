//
// Created by Admin on 2/04/2025.
//

#pragma once

// To Typename Template Type

// 1
template <template <auto> class T, auto Int>
struct My::to_typename_template_type<T<Int>>
    : IType<typename_template_type<IValue_of<Int>>> {};

// 1...
//template<template<auto...>class T, auto... Ints>
//struct My::to_typename_template_type<T<Ints...>>
//	: IType<typename_template_type<IValue_of<Ints>...>> {};

// 1 0
template <template <auto, typename> class T, auto Int, typename U>
struct My::to_typename_template_type<T<Int, U>>
    : IType<typename_template_type<IValue_of<Int>, U>> {};

// 1 0...
//template<template<auto, typename...>class T, auto Int, typename... Us>
//struct My::to_typename_template_type<T<Int, Us...>>
//	: IType<typename_template_type<IValue_of<Int>, Us...>> {};

// 0 1
template <template <typename, auto> class T, typename U, auto Int>
struct My::to_typename_template_type<T<U, Int>>
    : IType<typename_template_type<U, IValue_of<Int>>> {};

// 0 1...
//template<template<typename, auto...>class T, typename U, auto... Ints>
//struct My::to_typename_template_type<T<U, Ints...>>
//	: IType<typename_template_type<U, IValue_of<Ints>...>> {};

// 1 1
template <template <auto, auto> class T, auto Int0, auto Int1>
struct My::to_typename_template_type<T<Int0, Int1>>
    : IType<typename_template_type<IValue_of<Int0>, IValue_of<Int1>>> {};

// 1 1...
//template<template<auto, auto, typename...>class T, auto Int, auto... Ints>
//struct My::to_typename_template_type<T<Int, Ints...>>
//	: IType<typename_template_type<IValue_of<Int>, IValue_of<Ints>...>> {};

// 1 0 0
template <template <auto, typename, typename> class T, auto Int, typename U0,
          typename U1>
struct My::to_typename_template_type<T<Int, U0, U1>>
    : IType<typename_template_type<IValue_of<Int>, U0, U1>> {};

// 1 0 0 0...
template <template <auto, typename, typename, typename...> class T, auto Int,
          typename U0, typename U1, typename... Us>
struct My::to_typename_template_type<T<Int, U0, U1, Us...>>
    : IType<typename_template_type<IValue_of<Int>, U0, U1, Us...>> {};

// 0 1 0
template <template <typename, auto, typename> class T, typename U0, auto Int,
          typename U1>
struct My::to_typename_template_type<T<U0, Int, U1>>
    : IType<typename_template_type<U0, IValue_of<Int>, U1>> {};

// 0 1 0 0...
template <template <typename, auto, typename, typename...> class T, typename U0,
          auto Int, typename U1, typename... Us>
struct My::to_typename_template_type<T<U0, Int, U1, Us...>>
    : IType<typename_template_type<U0, IValue_of<Int>, U1, Us...>> {};

// 0 0 1
template <template <typename, typename, auto> class T, typename U0, typename U1,
          auto Int>
struct My::to_typename_template_type<T<U0, U1, Int>>
    : IType<typename_template_type<U0, U1, IValue_of<Int>>> {};

// 0 0 1 1...
template <template <typename, typename, auto, auto...> class T, typename U0,
          typename U1, auto Int, auto... Ints>
struct My::to_typename_template_type<T<U0, U1, Int, Ints...>>
    : IType<
          typename_template_type<U0, U1, IValue_of<Int>, IValue_of<Ints>...>> {
};

// 1 1 0
template <template <auto, auto, typename> class T, auto Int0, auto Int1,
          typename U>
struct My::to_typename_template_type<T<Int0, Int1, U>>
    : IType<typename_template_type<IValue_of<Int0>, IValue_of<Int1>, U>> {};

// 1 1 0 0...
template <template <auto, auto, typename, typename...> class T, auto Int0,
          auto Int1, typename U, typename... Us>
struct My::to_typename_template_type<T<Int0, Int1, U, Us...>>
    : IType<
          typename_template_type<IValue_of<Int0>, IValue_of<Int1>, U, Us...>> {
};

// 1 0 1
template <template <auto, typename, auto> class T, auto Int0, typename U,
          auto Int1>
struct My::to_typename_template_type<T<Int0, U, Int1>>
    : IType<typename_template_type<IValue_of<Int0>, U, IValue_of<Int1>>> {};

// 1 0 1 1...
template <template <auto, typename, auto, auto...> class T, auto Int0,
          typename U, auto Int1, auto... Ints>
struct My::to_typename_template_type<T<Int0, U, Int1, Ints...>>
    : IType<typename_template_type<IValue_of<Int0>, U, IValue_of<Int1>,
                                   IValue_of<Ints>...>> {};

// 0 1 1
template <template <typename, auto, auto> class T, typename U, auto Int0,
          auto Int1>
struct My::to_typename_template_type<T<U, Int0, Int1>>
    : IType<typename_template_type<U, IValue_of<Int0>, IValue_of<Int1>>> {};

// 0 1 1 1...
template <template <typename, auto, auto, auto...> class T, typename U,
          auto Int0, auto Int1, auto... Ints>
struct My::to_typename_template_type<T<U, Int0, Int1, Ints...>>
    : IType<typename_template_type<U, IValue_of<Int0>, IValue_of<Int1>,
                                   IValue_of<Ints>...>> {};

// 1 1 1
template <template <auto, auto, auto> class T, auto Int0, auto Int1, auto Int2>
struct My::to_typename_template_type<T<Int0, Int1, Int2>>
    : IType<typename_template_type<IValue_of<Int0>, IValue_of<Int1>,
                                   IValue_of<Int2>>> {};

// 1 1 1 1...
template <template <auto, auto, auto, auto...> class T, auto Int0, auto Int1,
          auto Int2, auto... Ints>
struct My::to_typename_template_type<T<Int0, Int1, Int2, Ints...>>
    : IType<typename_template_type<IValue_of<Int0>, IValue_of<Int1>,
                                   IValue_of<Int2>, IValue_of<Ints>...>> {};
