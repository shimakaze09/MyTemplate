#pragma once

#include <unordered_set>

#include "../Name.hpp"

template <typename Key>
struct Smkz::details::custom_type_name<std::unordered_set<Key>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_set<{"), type_name<Key>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash>
struct Smkz::details::custom_type_name<std::unordered_set<Key, Hash>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_set<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash, typename KeyEqual>
struct Smkz::details::custom_type_name<
    std::unordered_set<Key, Hash, KeyEqual>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_set<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(), TStr_of_a<','>{},
                      type_name<KeyEqual>(), TStrC_of<'}', '>'>{});
  }
};

template <typename Key>
struct Smkz::details::custom_type_name<std::unordered_multiset<Key>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_multiset<{"), type_name<Key>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash>
struct Smkz::details::custom_type_name<std::unordered_multiset<Key, Hash>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_multiset<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(),
                      TStrC_of<'}', '>'>{});
  }
};

template <typename Key, typename Hash, typename KeyEqual>
struct Smkz::details::custom_type_name<
    std::unordered_multiset<Key, Hash, KeyEqual>> {
  static constexpr auto get() noexcept {
    return concat_seq(TSTR("std::unordered_multiset<{"), type_name<Key>(),
                      TStr_of_a<','>{}, type_name<Hash>(), TStr_of_a<','>{},
                      type_name<KeyEqual>(), TStrC_of<'}', '>'>{});
  }
};
