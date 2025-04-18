#pragma once

#include <memory>

#include "../Name.hpp"

template <typename T>
struct Smkz::details::custom_type_name<std::unique_ptr<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unique_ptr<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};
