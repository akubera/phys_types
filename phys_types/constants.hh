/**
 * \file constants.hh
 * \brief Defines constants to be used elsewhere
 */

#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

/**
 * \brief A map of SI prefix names to the integer exponent associated
 */
namespace SI_Prefix {
  const int yotta = 24;
  const int zetta = 21;
  const int   exa = 18;
  const int  peta = 15;
  const int  tera = 12;
  const int  giga = 9;
  const int  mega = 6;
  const int  kilo = 3;
  const int hecto = 2;
  const int  deca = 1;
  const int  deci = -1;
  const int centi = -2;
  const int milli = -3;
  const int micro = -6;
  const int  nano = -9;
  const int  pico = -12;
  const int femto = -15;
  const int  atto = -18;
  const int zepto = -21;
  const int yocto = -24;
}

constexpr long double
operator "" _times_pi(long double x) {
  return x * 3.1415926535897932384626433832795;
}

constexpr long double
operator "" _times_e(long double x) {
  return x * 2.718281828459045235;
}

constexpr long double
operator "" _times_c(long double x) {
  return x * 299792458;
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif
