//
// Created by Admin on 24/12/2024.
//

#pragma once

#include "Num.h"

namespace My{
// Conjunction
template<bool v, typename LastN, typename... Ns>
struct ConjunctionRecT;
template<typename LastN>
struct ConjunctionRecT<true, LastN> {
  using type = LastN;
};
template<typename LastN, typename... Ns>
struct ConjunctionRecT<false, LastN, Ns...> {
  using type = LastN;
};
template<typename LastN, typename NHead, typename... NTail>
struct ConjunctionRecT<true, LastN, NHead, NTail...> :
    ConjunctionRecT<static_cast<bool>(NHead::value), NHead, NTail...> {};

template<typename... Ns>
using ConjunctionT = ConjunctionRecT<true, True, Ns...>;
template<typename... Ns>
using Conjunction = typename ConjunctionT<Ns...>::type;

// Disjunction
template<bool v, typename LastN, typename... Ns>
struct DisjunctionRecT;
template<typename LastN>
struct DisjunctionRecT<false, LastN> {
  using type = LastN;
};
template<typename LastN, typename... Ns>
struct DisjunctionRecT<true, LastN, Ns...> {
  using type = LastN;
};
template<typename LastN, typename NHead, typename... NTail>
struct DisjunctionRecT<false, LastN, NHead, NTail...> :
    DisjunctionRecT<static_cast<bool>(NHead::value), NHead, NTail...> {};

template<typename... Ns>
using DisjunctionT = DisjunctionRecT<false, False, Ns...>;
template<typename... Ns>
using Disjunction = typename DisjunctionT<Ns...>::type;
}