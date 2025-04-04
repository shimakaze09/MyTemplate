//
// Created by Admin on 29/12/2024.
//

#include <MyTemplate/Func.h>

#include <iostream>

using namespace My;
using namespace std;

int main() {
  {  // basic
    auto expandedFunc = FuncExpand<void(int&, int&, float&)>::get(
        [](int& sum, int n) { sum += n; });
    int sum = 0;
    int v = 3;
    float tmp;
    expandedFunc(sum, v, tmp);
    cout << sum << endl;
  }
  {  // return
    auto expandedFunc =
        FuncExpand<float(int)>::get([](int n) -> int { return n + 1; });
    cout << expandedFunc(3) << endl;
  }
}