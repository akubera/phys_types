/**
 * \file phys_types/energy.hh
 * \author Andrew Kubera
 * \date Aug 09, 2015
 */

#pragma once

#include "quantity.hxx"
#include "constants.hxx"

#include <cmath>

constexpr float ev_to_joule() { return 1.602176620898e-19; }
constexpr float joule_to_ev() { return 1.0/ev_to_joule(); }

/**
 * \class Energy
 * \brief Quantity of energy
 */
class Energy : Quantity<float> {
public:
  struct Units {
    friend class Energy;

    template <int POWER=0>
    static constexpr Units Joule(float factor=1.0f){ return Units(factor * ::pow(10.f, POWER)); };

    static constexpr const Units MJ(){ return Units::Joule<SI_Prefix::mega>(); };
    static constexpr const Units kJ(){ return Units::Joule<SI_Prefix::kilo>(); };
    static constexpr const Units mJ(){ return Units::Joule<SI_Prefix::milli>(); };


    template <int POWER=0>
    static constexpr const Units eV(){ return Units::Joule<POWER>(ev_to_joule()); };

    static constexpr const Units meV(){ return Units::eV<SI_Prefix::milli>(); };
    static constexpr const Units keV(){ return Units::eV<SI_Prefix::kilo>(); };
    static constexpr const Units MeV(){ return Units::eV<SI_Prefix::mega>(); };
    static constexpr const Units GeV(){ return Units::eV<SI_Prefix::giga>(); };
    static constexpr const Units TeV(){ return Units::eV<SI_Prefix::tera>();};

    static constexpr const Units erg(){ return Units(1.0e-7f); };


    constexpr operator float() const { return factor; };

    private:
      constexpr Units(float x):factor(x){};
      float factor;
   };

  /**
   * Default Constructor
   */
  Energy(){ /* no-op */ };

  /**
   * Construct with a value
   */
  constexpr Energy(float value, Units conversion):
    Quantity<float>(value * conversion)
  {
  };


  /**
   * Return the energy as provided unit
   */
  float As(Energy::Units units) const {
    return _value / units.factor;
  }

};

constexpr Energy operator "" _Joule(long double x) {
  return Energy(x, Energy::Units::Joule());
}

constexpr Energy operator "" _eV(long double x) {
  return Energy(x, Energy::Units::eV());
}

constexpr Energy operator "" _KeV(long double x) {
  return Energy(x, Energy::Units::keV());
}

constexpr Energy operator "" _MeV(unsigned long long int x) {
  return Energy(x, Energy::Units::MeV());
}

constexpr Energy operator "" _GeV(long double x) {
  return Energy(x, Energy::Units::GeV());
}

constexpr Energy operator "" _TeV(long double x) {
  return Energy(x, Energy::Units::TeV());
}

constexpr Energy operator "" _MJ(long double x) {
  return Energy(x, Energy::Units::MJ());
}

constexpr Energy operator "" _kJ(long double x) {
  return Energy(x, Energy::Units::kJ());
}

constexpr Energy operator "" _mJ(long double x) {
  return Energy(x, Energy::Units::mJ());
}
