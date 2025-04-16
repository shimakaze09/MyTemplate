#pragma once

#include <forward_list>

#include "../Name.hpp"

template <typename T>
struct My::details::custom_type_name<std::forward_list<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::forward_list<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
