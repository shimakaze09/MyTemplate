#pragma once

#include <set>

#include "../Name.hpp"

template <typename T>
struct Smkz::details::custom_type_name<std::set<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::set<{"), type_name<T>(), TStrC_of<'}', '>'>{});
  }
};

template <typename T, typename Less>
struct Smkz::details::custom_type_name<std::set<T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::set<{"), type_name<T>(), TStr_of_a<','>{},
                      type_name<Less>(), TStrC_of<'}', '>'>{});
  }
};

template <typename T>
struct Smkz::details::custom_type_name<std::multiset<T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::multiset<{"), type_name<T>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename T, typename Less>
struct Smkz::details::custom_type_name<std::multiset<T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::multiset<{"), type_name<T>(), TStr_of_a<','>{},
                      type_name<Less>(), TStrC_of<'}', '>'>{});
  }
};
