//
// Created by Admin on 29/12/2024.
//

#include <MyTemplate/Func.h>

#include <iostream>

using namespace My;
using namespace std;

int main() {
  auto expandedFunc =
      FuncExpand<int&, int&, float&>::run([](int& sum, int n) { sum += n; });
  int sum = 0;
  int v = 3;
  float tmp;
  expandedFunc(sum, v, tmp);
  cout << sum << endl;
}
