#pragma once

#include <list>

#include "../Name.hpp"

template <typename T>
struct Smkz::details::custom_type_name<std::list<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::list<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
