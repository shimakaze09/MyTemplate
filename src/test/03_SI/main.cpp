//
// Created by Admin on 24/12/2024.
//

#include <array>
#include <iostream>
#include <type_traits>

#include <MyTemplate/SI.h>

using namespace std;
using namespace My;

template <typename Base>
struct IPeople : Base {
  using Base::Base;

  IPeople(const string& name) : name(name) {}

  string name;
};

template <typename Base>
struct ISing : Base {
  using Base::Base;

  void Sing() { cout << "Sing"; }
};

template <typename Base>
struct IJump : Base {
  using Base::Base;

  void Jump() { cout << "Jump"; }
};

template <typename Base>
struct IRap : Base {
  using Base::Base;

  void Rap() { cout << "Rap"; }
};

template <typename Base>
struct IBasketball : Base {
  using Base::Base;

  void Basketball() { cout << "Basketball"; }
};

struct Performer : SII<IBasketball, ISing, IJump, IRap, IPeople>::Ttype<> {
  Performer() : Ttype("KK") {}
};

int main() {
  Performer performer;
  cout << "Hello everyone, I'm " << performer.name
       << ", a trainee with 2.5 years of experience\n"
       << "I like ";
  performer.Sing();
  cout << ", ";
  performer.Jump();
  cout << ", ";
  performer.Rap();
  cout << ", ";
  performer.Basketball();
  cout << "!";

  return 0;
}