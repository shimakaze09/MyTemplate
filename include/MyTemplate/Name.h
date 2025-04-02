//
// Created by Admin on 2/04/2025.
//

#pragma once

namespace My {
template <auto V>
constexpr auto constexpr_name() noexcept;
template <typename T>
constexpr auto type_name() noexcept;
}  // namespace My

#include "details/Name.inl"
