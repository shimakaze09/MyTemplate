#pragma once

#include <stack>

#include "Name_deque.hpp"

template <typename T>
struct Smkz::details::custom_type_name<std::stack<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::stack<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
