//
// Created by Admin on 24/12/2024.
//

#include <iostream>
#include <type_traits>

#include <MyTemplate/Num.h>

using namespace std;
using namespace My;

int main() {
  Bool<true>{};
  Int<1>{};
  Size<10>{};

  return 0;
}
