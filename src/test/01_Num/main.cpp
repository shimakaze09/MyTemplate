//
// Created by Admin on 24/12/2024.
//

#include <iostream>
#include <type_traits>

#include <MyTemplate/Name.h>
#include <MyTemplate/Num.h>

using namespace std;
using namespace My;

int main() {
  cout << Name<Bool<true>>() << endl;
  cout << Name<Int<1>>() << endl;
  cout << Name<Size<10>>() << endl;

  return 0;
}
