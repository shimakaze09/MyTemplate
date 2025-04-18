#include <MyTemplate/Type.hpp>
#include <iostream>

using namespace Smkz;
using namespace std;

struct A {};
struct AA {};

int main() {
  cout << details::raw_type_name<float>().View() << endl;

  cout << TypeID_of<int>.GetValue() << endl;
#ifdef SMKZ_NAME_X_INT
  cout << TypeID("int32").GetValue() << endl;
#else
  cout << TypeID("int").GetValue() << endl;
#endif  // SMKZ_NAME_X_INT

  cout << TypeID_of<float>.GetValue() << endl;
#ifdef SMKZ_NAME_X_FLOAT
  cout << TypeID("float32").GetValue() << endl;
#else
  cout << TypeID("float").GetValue() << endl;
#endif
  cout << TypeID_of<const A>.GetValue() << endl;
  cout << TypeID("const{A}").GetValue() << endl;
  cout << TypeID_of<AA>.GetValue() << endl;
  cout << TypeID("AA").GetValue() << endl;

  if (TypeID_of<int> < TypeID_of<float>)
    cout << "TypeID_of<int> < TypeID_of<float>" << endl;
  if (TypeID_of<int> <= TypeID_of<float>)
    cout << "TypeID_of<int> <= TypeID_of<float>" << endl;
  if (TypeID_of<int> > TypeID_of<float>)
    cout << "TypeID_of<int> > TypeID_of<float>" << endl;
  if (TypeID_of<int> >= TypeID_of<float>)
    cout << "TypeID_of<int> >= TypeID_of<float>" << endl;
  if (TypeID_of<int> == TypeID_of<float>)
    cout << "TypeID_of<int> == TypeID_of<float>" << endl;
  if (TypeID_of<int> != TypeID_of<float>)
    cout << "TypeID_of<int> != TypeID_of<float>" << endl;
}
