//
// Created by Admin on 2/04/2025.
//

#pragma once

// u?int{8|16|32|64}
 #define MY_NAME_X_INT

namespace My {
template <auto V>
constexpr auto constexpr_name() noexcept;

// you can customize
// - member_pointer_name
// - type_namespace_name
template <typename T>
constexpr auto type_name() noexcept;
}  // namespace My

#include "details/Name.inl"
