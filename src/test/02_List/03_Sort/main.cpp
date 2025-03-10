//
// Created by Admin on 26/12/2024.
//

#include <iostream>

#include <MyTemplate/TypeID.h>
#include <MyTemplate/Typelist.h>

using namespace std;
using namespace My;

int main() {
  using list = TypeList<int, float, double, TypeList<>>;
  cout << "TypeID<int>        : " << TypeID<int> << endl;
  cout << "TypeID<float>      : " << TypeID<float> << endl;
  cout << "TypeID<double>     : " << TypeID<double> << endl;
  cout << "TypeID<TypeList<>> : " << TypeID<TypeList<>> << endl;

  using sorted_list = QuickSort_t<list, TypeID_Less>;
  cout << "@0 : " << TypeID<At_t<sorted_list, 0>> << endl;
  cout << "@1 : " << TypeID<At_t<sorted_list, 1>> << endl;
  cout << "@2 : " << TypeID<At_t<sorted_list, 2>> << endl;
  cout << "@3 : " << TypeID<At_t<sorted_list, 3>> << endl;

  return 0;
}
