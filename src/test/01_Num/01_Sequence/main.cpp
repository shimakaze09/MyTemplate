//
// Created by Admin on 25/12/2024.
//

#include <array>
#include <iostream>
#include <type_traits>

#include <MyTemplate/Basic.h>
#include <MyTemplate/Num/Num.h>

using namespace std;
using namespace My;

template <typename T, T... Vals>
void PrintSequence(sequence<T, Vals...>) {
  cout << Name<T>() << ": ";
  array<T, sizeof...(Vals)> vArr = {Vals...};
  for (auto v : vArr)
    cout << v << ", ";
}

int main() {
  PrintSequence(MakeSequence<Size<5>>{});
  return 0;
}