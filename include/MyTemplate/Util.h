//
// Created by Admin on 2/04/2025.
//

#pragma once

#include <string_view>
#include <type_traits>

namespace My {
template <typename T>
struct IType {
  using type = T;
};

template <typename T, T V>
struct IValue {
  static constexpr T value = V;
};

template <typename T>
struct IsIValue;
template <typename T>
constexpr bool IsIValue_v = IsIValue<T>::value;
template <auto V>
using IValue_of = IValue<decltype(V), V>;

template <template <typename, typename...> class Op,
          template <typename...> class Test>
struct AddIf;  // Ttype

template <template <typename...> class Test>
struct Negate;  // Ttype

template <typename...>
struct typename_template_type;

template <typename T>
struct is_typename_template_type;
template <typename T>
static constexpr bool is_typename_template_type_v =
    is_typename_template_type<T>::value;

// use IValue to replace integral value in template arguments
// we provide some partial template specializations (see details/ToTTType.inl for more details)
// [example]
// template<typename T, size_t N>
// struct Array;
// to_typename_template_type_t<Array<T, N>> == typename_template_type<T, IValue<size_t, N>>
template <typename T>
struct to_typename_template_type : IType<T> {};

template <typename T>
using to_typename_template_type_t = typename to_typename_template_type<T>::type;

// type object
// type value
template <typename T>
struct member_pointer_traits;
template <typename T>
using member_pointer_traits_object = typename member_pointer_traits<T>::object;
template <typename T>
using member_pointer_traits_value = typename member_pointer_traits<T>::value;

template <template <typename...> typename T, typename... Ts>
struct is_instantiable;
template <template <typename...> typename T, typename... Ts>
constexpr bool is_instantiable_v = is_instantiable<T, Ts...>::value;

template <template <typename...> class TA, template <typename...> class TB>
struct is_same_typename_template;
template <template <typename...> class TA, template <typename...> class TB>
constexpr bool is_same_typename_template_v =
    is_same_typename_template<TA, TB>::value;

template <typename Instance, template <typename...> class T>
struct is_instance_of;
template <typename Instance, template <typename...> class T>
constexpr bool is_instance_of_v = is_instance_of<Instance, T>::value;

template <typename T, typename... Args>
struct is_list_initializable;
template <typename T, typename... Args>
static constexpr bool is_list_initializable_v =
    is_list_initializable<T, Args...>::value;

template <typename T>
struct is_defined;
template <typename T>
static constexpr bool is_defined_v = is_defined<T>::value;

constexpr size_t string_hash(const char* str, size_t N) noexcept;

constexpr size_t string_hash(std::string_view str) noexcept {
  return string_hash(str.data(), str.size());
}

template <size_t N>
constexpr size_t string_hash(const char (&str)[N]) noexcept {
  return string_hash(str, N - 1);
}

constexpr size_t string_hash(const char* str) noexcept;

template <typename T>
struct is_function_pointer;
template <typename T>
constexpr bool is_function_pointer_v = is_function_pointer<T>::value;
}  // namespace My

#include "details/ToTTType.inl"
#include "details/Util.inl"
