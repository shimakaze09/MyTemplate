//
// Created by Admin on 24/12/2024.
//

#pragma once

namespace My{
template<unsigned N>
    struct Num {
  static constexpr unsigned value = N;
  using type = unsigned;
};
}