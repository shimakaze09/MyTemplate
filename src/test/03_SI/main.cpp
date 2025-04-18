#include <MyTemplate/SI.hpp>
#include <array>
#include <iostream>
#include <string>
#include <type_traits>

using namespace std;
using namespace Smkz;

template <typename Base, typename Impl>
struct IA : Base {
  IA(float) {}
};
template <typename Base, typename Impl>
struct IB : Base {
  using Base::Base;
};
template <typename Base, typename Impl>
struct IC : Base {
  using Base::Base;
};
template <typename Base, typename Impl>
struct ID : Base {
  using Base::Base;
};
template <typename Base, typename Impl>
struct IE : Base {
  using Base::Base;
};

SI_InterfaceTraits_Register(IB, IA);
SI_InterfaceTraits_Register(IC, IA);
SI_InterfaceTraits_Register(ID, IB);
SI_InterfaceTraits_Register(IE, IA);
SI_CombineInterface(IF, IC, ID);

// MSVC: /d1reportSingleClassLayoutG

struct G;
SI_ImplTraits_Register(G, IE, IF);
struct G : SI<G> {
  using SI<G>::SI;
};

struct A {};
int main() {
  static_assert(SI_Contains_v<G, IA>);
  static_assert(SI_Contains_v<G, IB>);
  static_assert(SI_Contains_v<G, IC>);
  static_assert(SI_Contains_v<G, ID>);
  static_assert(SI_Contains_v<G, IE>);
  static_assert(SI_Contains_v<G, IF>);

  G{1.f};
}
