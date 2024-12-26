//
// Created by Admin on 26/12/2024.
//

#include <iostream>

#include <MyTemplate/List/Typelist.h>
#include <MyTemplate/Name.h>
#include <MyTemplate/TypeID/TypeID.h>

using namespace std;
using namespace My;

int main() {
  using list = TypeList<int, float, double, TypeList<>>;
  cout << "TypeID<int>        : " << TypeID<int> << endl;
  cout << "TypeID<float>      : " << TypeID<float> << endl;
  cout << "TypeID<double>     : " << TypeID<double> << endl;
  cout << "TypeID<TypeList<>> : " << TypeID<TypeList<>> << endl;

  cout << Name<QuickSort_t<list, TypeID_Less>>() << endl;
}
