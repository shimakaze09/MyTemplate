#pragma once

#include <queue>

#include "../Name.hpp"

template <typename T>
struct Smkz::details::custom_type_name<std::queue<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::queue<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
