//
// Created by Admin on 2/04/2025.
//

#include <iostream>

#include <MyTemplate/TStr.h>

using namespace std;
using namespace My;

static constexpr const std::string_view gs_sv = "sv";
static constexpr const char gs_ca[] = "gs_ca";
static constexpr const char* gs_cptr = "gs_cptr";

int main() {
  constexpr auto str0 = TSTR("hello world");
  static_assert(
      std::is_same_v<decltype(str0), const TStr<char, 'h', 'e', 'l', 'l', 'o',
                                                ' ', 'w', 'o', 'r', 'l', 'd'>>);
  cout << str0.value << endl;
  cout << TSTR(gs_sv).value << endl;
  cout << TSTR(gs_ca).value << endl;
  cout << TSTR(gs_cptr).value << endl;
  return 0;
}
