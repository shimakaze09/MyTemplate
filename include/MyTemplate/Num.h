//
// Created by Admin on 24/12/2024.
//

#pragma once

#include "Basic.h"

namespace My {
// type, value
template <typename T, T N>
struct Num;

template <bool b>
using Bool = Num<bool, b>;
using True = Num<bool, true>;
using False = Num<bool, false>;

template <char c>
using Char = Num<char, c>;
template <short N>
using Short = Num<short, N>;
template <int N>
using Int = Num<int, N>;
template <long N>
using Long = Num<long, N>;
template <size_t N>
using Size = Num<size_t, N>;
}  // namespace My

// ============================================================

namespace My {
template <typename T, T N>
struct Num {
  using type = T;
  static constexpr unsigned value = N;
};
}  // namespace My
