//
// Created by Admin on 24/12/2024.
//

#include <array>
#include <iostream>
#include <type_traits>

#include <MyTemplate/SI.h>

using namespace std;
using namespace My;

template <typename Base, typename Impl, typename ArgList>
struct IA : Base {};

template <typename Base, typename Impl, typename ArgList>
struct IB : Base {
  using IList = TemplateList<IA>;
};

template <typename Base, typename Impl, typename ArgList>
struct IC : Base {
  using IList = TemplateList<IA>;
};

template <typename Base, typename Impl, typename ArgList>
struct ID : Base {
  using IList = TemplateList<IB>;
};

template <typename Base, typename Impl, typename ArgList>
struct IE : Base {
  using IList = TemplateList<IA>;
};

template <typename Base, typename Impl, typename ArgList>
struct IF : Base {
  using IList = TemplateList<IC, ID>;
};

// MSVC: /d1reportSingleClassLayoutG
struct G : SI<TemplateList<IE, IF>, G> {};

int main() {
  static_assert(G::IsContain<IA>());
  static_assert(G::IsContain<IB>());
  static_assert(G::IsContain<IC>());
  static_assert(G::IsContain<ID>());
  static_assert(G::IsContain<IE>());
  static_assert(G::IsContain<IF>());
}
