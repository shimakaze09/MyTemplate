#pragma once

#include "../Name.h"

#include <unordered_set>

template <typename Key>
struct My::details::custom_type_name<std::unordered_set<Key>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_set<{"), type_name<Key>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash>
struct My::details::custom_type_name<std::unordered_set<Key, Hash>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_set<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash, typename KeyEqual>
struct My::details::custom_type_name<std::unordered_set<Key, Hash, KeyEqual>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_set<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(), TStr_of_a<','>{},
                      type_name<KeyEqual>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key>
struct My::details::custom_type_name<std::pmr::unordered_set<Key>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::unordered_set<{"), type_name<Key>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash>
struct My::details::custom_type_name<std::pmr::unordered_set<Key, Hash>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::unordered_set<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash, typename KeyEqual>
struct My::details::custom_type_name<
    std::pmr::unordered_set<Key, Hash, KeyEqual>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::unordered_set<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(), TStr_of_a<','>{},
                      type_name<KeyEqual>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key>
struct My::details::custom_type_name<std::unordered_multiset<Key>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_multiset<{"), type_name<Key>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash>
struct My::details::custom_type_name<std::unordered_multiset<Key, Hash>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_multiset<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash, typename KeyEqual>
struct My::details::custom_type_name<
    std::unordered_multiset<Key, Hash, KeyEqual>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_multiset<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(), TStr_of_a<','>{},
                      type_name<KeyEqual>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key>
struct My::details::custom_type_name<std::pmr::unordered_multiset<Key>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::unordered_multiset<{"), type_name<Key>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash>
struct My::details::custom_type_name<std::pmr::unordered_multiset<Key, Hash>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::unordered_multiset<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash, typename KeyEqual>
struct My::details::custom_type_name<
    std::pmr::unordered_multiset<Key, Hash, KeyEqual>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::pmr::unordered_multiset<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(), TStr_of_a<','>{},
                      type_name<KeyEqual>(), TStrC_of<'}', '>'>{});
  }
};
