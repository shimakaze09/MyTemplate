//
// Created by Admin on 26/12/2024.
//

#include <MyTemplate/TypeID.h>

#include <iostream>

using namespace My;
using namespace std;

struct A {};

struct AA {};

int main() {
  cout << details::raw_type_name<float>().value << endl;

  cout << TypeID_of<int>.GetValue() << endl;
#ifdef MY_NAME_X_INT
  cout << TypeID("int32").GetValue() << endl;
#else
  cout << TypeID("int").GetValue() << endl;
#endif  // MY_NAME_X_INT

  cout << TypeID_of<float>.GetValue() << endl;
#ifdef MY_NAME_X_FLOAT
  cout << TypeID("float32").GetValue() << endl;
#else
  cout << TypeID("float").GetValue() << endl;
#endif
  cout << TypeID_of<const A>.GetValue() << endl;
  cout << TypeID("const{A}").GetValue() << endl;
  cout << TypeID_of<AA>.GetValue() << endl;
  cout << TypeID("AA").GetValue() << endl;
}
