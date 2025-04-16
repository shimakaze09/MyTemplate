#pragma once

#include <vector>

#include "../Name.hpp"

template <typename T>
struct My::details::custom_type_name<std::vector<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::vector<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
