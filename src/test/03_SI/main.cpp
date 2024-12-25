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
struct ISing : SIV<Base, IPeople> {
  using SIV<Base, IPeople>::SIV;

  void Sing() { cout << "Sing"; }
};

template <typename Base>
struct IJump : SIV<Base, ISing> {
  using SIV<Base, ISing>::SIV;

  void Jump() { cout << "Jump"; }
};

template <typename Base>
struct IRap : SIV<Base, IJump> {
  using SIV<Base, IJump>::SIV;

  void Rap() { cout << "Rap"; }
};

template <typename Base>
struct IBasketball : SIV<Base, IPeople> {
  using SIV<Base, IPeople>::SIV;

  void Basketball() { cout << "Basketball"; }
};

struct CXK : SII<IBasketball, IRap> {
  CXK() : SI("CXK") {}
};

int main() {
  CXK cxk;
  cout << "Hello everyone, I'm " << cxk.name
       << ", a trainee with 2.5 years of experience\n"
       << "I like ";
  cxk.Sing();
  cout << ", ";
  cxk.Jump();
  cout << ", ";
  cxk.Rap();
  cout << ", ";
  cxk.Basketball();
  cout << "!";

  return 0;
}