#pragma once

#include "../Name.h"

#include <span>

template <typename T>
struct My::details::custom_type_name<std::span<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::span<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
