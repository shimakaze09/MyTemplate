//
// Created by Admin on 23/02/2025.
//

#include <MyTemplate/Concept.h>

#include <iostream>

using namespace My;

template <class T>
Concept(can_speak, &T::Speak);

class C {
 public:
  void Speak() {}
};

class D {};

int main() {
  static_assert(Require<can_speak, C> == true);
  static_assert(Require<can_speak, D> == false);
}
