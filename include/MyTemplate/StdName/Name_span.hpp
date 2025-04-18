#pragma once

#include <span>

#include "../Name.hpp"

template <typename T>
struct Smkz::details::custom_type_name<std::span<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::span<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
