#pragma once

#include "../Name.h"

#include <map>

template <typename Key, typename T>
struct My::details::custom_type_name<std::map<Key, T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::map<{"), type_name<Key>(), TStr_of_a<','>{},
                      type_name<T>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T, typename Less>
struct My::details::custom_type_name<std::map<Key, T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::map<{"), type_name<Key>(), TStr_of_a<','>{},
                      type_name<T>(), TStr_of_a<','>{}, type_name<Less>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T>
struct My::details::custom_type_name<std::pmr::map<Key, T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::map<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T, typename Less>
struct My::details::custom_type_name<std::pmr::map<Key, T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::map<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStr_of_a<','>{},
                      type_name<Less>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T>
struct My::details::custom_type_name<std::multimap<Key, T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::multimap<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T, typename Less>
struct My::details::custom_type_name<std::multimap<Key, T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::multimap<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStr_of_a<','>{},
                      type_name<Less>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T>
struct My::details::custom_type_name<std::pmr::multimap<Key, T>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::multimap<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename T, typename Less>
struct My::details::custom_type_name<std::pmr::multimap<Key, T, Less>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::multimap<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<T>(), TStr_of_a<','>{},
                      type_name<Less>(), TStrC_of<'}', '>'>{});
  }
};
