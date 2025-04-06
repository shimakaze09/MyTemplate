//
// Created by Admin on 2/04/2025.
//

#pragma once

#include <string_view>

// u?int{8|16|32|64}
#define MY_NAME_X_INT

// float{32|64} (maybe float80 for long double)
#define MY_NAME_X_FLOAT

namespace My {
template <auto V>
constexpr auto constexpr_name() noexcept;

// [rule]
// - reference : &/&&{...}
// - cv : const? volatile?{...}
// - member pointer : {object_type_name}::*{value_type_name}
// - function : ({arg_1_type_name}, ..., {arg_n_type_name})-{const? volatile? &/&&? noexcept?}->{result_type_name}
// - int : u?int{8|16|32|64}
// - float : float{32|64}
// - template : name<{arg_1_type_name}, ..., {arg_n_type_name}>
// - basic : namespace_name::kernel_name
// [custom]
// - member_pointer_name
// - type_namespace_name
template <typename T>
constexpr auto type_name() noexcept;

//
// constexpr name traits
//////////////////////////

constexpr bool constexpr_name_is_null_pointer(std::string_view name) noexcept;
constexpr bool constexpr_name_is_integral(std::string_view name) noexcept;

//
// type name traits
/////////////////////

// primary

constexpr bool type_name_is_void(std::string_view name) noexcept;
constexpr bool type_name_is_null_pointer(std::string_view name) noexcept;
constexpr bool type_name_is_integral(std::string_view name) noexcept;
constexpr bool type_name_is_floating_point(std::string_view name) noexcept;
constexpr bool type_name_is_array(std::string_view name) noexcept;
constexpr bool type_name_is_function(std::string_view name) noexcept;
constexpr bool type_name_is_pointer(std::string_view name) noexcept;
constexpr bool type_name_is_lvalue_reference(std::string_view name) noexcept;
constexpr bool type_name_is_rvalue_reference(std::string_view name) noexcept;
constexpr bool type_name_is_member_pointer(std::string_view name) noexcept;

// properties

constexpr bool type_name_is_const(std::string_view name) noexcept;
constexpr bool type_name_is_volatile(std::string_view name) noexcept;
constexpr bool type_name_is_cv(std::string_view name) noexcept;
constexpr bool type_name_is_reference(std::string_view name) noexcept;
constexpr bool type_name_is_signed(std::string_view name) noexcept;
constexpr bool type_name_is_unsigned(std::string_view name) noexcept;
constexpr bool type_name_is_bounded_array(std::string_view name) noexcept;
constexpr bool type_name_is_unbounded_array(std::string_view name) noexcept;

constexpr std::size_t type_name_rank(std::string_view name) noexcept;
constexpr std::size_t type_name_extent(std::string_view name,
                                       std::size_t N = 0) noexcept;

// modification (clip)

constexpr std::string_view type_name_remove_cv(std::string_view name) noexcept;
constexpr std::string_view type_name_remove_const(
    std::string_view name) noexcept;

constexpr std::string_view type_name_remove_topmost_volatile(
    std::string_view name) noexcept;

constexpr std::string_view type_name_remove_reference(
    std::string_view name) noexcept;
constexpr std::string_view type_name_remove_pointer(
    std::string_view name) noexcept;

constexpr std::string_view type_name_remove_cvref(
    std::string_view name) noexcept;

constexpr std::string_view type_name_remove_extent(
    std::string_view name) noexcept;

constexpr std::string_view type_name_remove_all_extents(
    std::string_view name) noexcept;

// modification (add, hash)

constexpr std::size_t type_name_add_const_hash(std::string_view name) noexcept;
constexpr std::size_t type_name_add_volatile_hash(
    std::string_view name) noexcept;
constexpr std::size_t type_name_add_cv_hash(std::string_view name) noexcept;
constexpr std::size_t type_name_add_lvalue_reference_hash(
    std::string_view name) noexcept;
constexpr std::size_t type_name_add_rvalue_reference_hash(
    std::string_view name) noexcept;
constexpr std::size_t type_name_add_pointer_hash(
    std::string_view name) noexcept;
constexpr std::size_t type_name_add_const_lvalue_reference_hash(
    std::string_view name) noexcept;

// modification (add, alloc)

// if no change, result's data is same with input (no allocate)
// else allocate (no end character '\0')

template <typename Alloc>
constexpr std::string_view type_name_add_const(std::string_view name,
                                               Alloc alloc);
template <typename Alloc>
constexpr std::string_view type_name_add_volatile(std::string_view name,
                                                  Alloc alloc);
template <typename Alloc>
constexpr std::string_view type_name_add_cv(std::string_view name, Alloc alloc);
template <typename Alloc>
constexpr std::string_view type_name_add_lvalue_reference(std::string_view name,
                                                          Alloc alloc);
template <typename Alloc>
constexpr std::string_view type_name_add_rvalue_reference(std::string_view name,
                                                          Alloc alloc);
template <typename Alloc>
constexpr std::string_view type_name_add_pointer(std::string_view name,
                                                 Alloc alloc);
template <typename Alloc>
constexpr std::string_view type_name_add_const_lvalue_reference(
    std::string_view name, Alloc alloc);

// composite

constexpr bool type_name_is_arithmetic(std::string_view name) noexcept;
constexpr bool type_name_is_fundamental(std::string_view name) noexcept;
}  // namespace My

#include "details/Name.inl"
