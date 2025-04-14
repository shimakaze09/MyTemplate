#pragma once

#include "../Name.h"

#include <queue>

template <typename T>
struct My::details::custom_type_name<std::queue<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::queue<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
