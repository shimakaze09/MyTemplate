#pragma once

#include <map>

#include "../Name.hpp"

template <typename Key, typename T>
struct Smkz::details::custom_type_name<std::map<Key, T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::map<{"), type_name<Key>(), TStr_of_a<','>{},
                      type_name<T>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T, typename Less>
struct Smkz::details::custom_type_name<std::map<Key, T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::map<{"), type_name<Key>(), TStr_of_a<','>{},
                      type_name<T>(), TStr_of_a<','>{}, type_name<Less>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T>
struct Smkz::details::custom_type_name<std::multimap<Key, T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::multimap<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T, typename Less>
struct Smkz::details::custom_type_name<std::multimap<Key, T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::multimap<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStr_of_a<','>{},
                      type_name<Less>(), TStrC_of<'}', '>'>{});
  }
};
