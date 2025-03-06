//
// Created by Admin on 24/12/2024.
//

#include <array>
#include <iostream>
#include <type_traits>

#include <MyTemplate/SI.h>

using namespace std;
using namespace My;

template <typename Base, typename Impl>
struct IA : Base {};

template <typename Base, typename Impl>
struct IB : Base {};

template <typename Base, typename Impl>
struct IC : Base {};

template <typename Base, typename Impl>
struct ID : Base {};

template <typename Base, typename Impl>
struct IE : Base {};

template <typename Base, typename Impl>
struct IF : Base {};

InterfaceTraits_Regist(IB, IA);
InterfaceTraits_Regist(IC, IA);
InterfaceTraits_Regist(ID, IB);
InterfaceTraits_Regist(IE, IA);
InterfaceTraits_Regist(IF, IC, ID);

// MSVC: /d1reportSingleClassLayoutG

struct G;
ImplTraits_Regist(G, IE, IF);

struct G : SI<G> {};

int main() {
  static_assert(G::IsContain<IA>());
  static_assert(G::IsContain<IB>());
  static_assert(G::IsContain<IC>());
  static_assert(G::IsContain<ID>());
  static_assert(G::IsContain<IE>());
  static_assert(G::IsContain<IF>());
}
