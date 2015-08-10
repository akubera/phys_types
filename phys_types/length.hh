/**
 * \file length.hh
 * \author Andrew Kubera
 * \date Aug 09, 2015
 */

#pragma once

#include "quantity.hxx"

#include <cmath>
#include "constants.hxx"

/**
 * \class Length
 * \brief Quantity of energy
 */
class Length : public Quantity<float> {
public:
  struct Units {
    friend class Length;

    template <int POWER=0>
    static constexpr const Units Meter(){ return Units(::pow(10.f, POWER)); };

    static constexpr const Units Gm(){ return Units::Meter<SI_Prefix::giga>(); };
    static constexpr const Units Mm(){ return Units::Meter<SI_Prefix::mega>(); };
    static constexpr const Units km(){ return Units::Meter<SI_Prefix::kilo>(); };
    static constexpr const Units  m(){ return Units::Meter(); };
    static constexpr const Units cm(){ return Units::Meter<SI_Prefix::centi>(); };
    static constexpr const Units mm(){ return Units::Meter<SI_Prefix::milli>(); };
    static constexpr const Units um(){ return Units::Meter<SI_Prefix::micro>(); };
    static constexpr const Units nm(){ return Units::Meter<SI_Prefix::nano>(); };
    static constexpr const Units pm(){ return Units::Meter<SI_Prefix::pico>(); };
    static constexpr const Units fm(){ return Units::Meter<SI_Prefix::femto>(); };

    constexpr operator float() const { return factor; };
    constexpr Units operator*(float scale) const { return Units(factor * scale);};

    static constexpr Units inch(){ return Units::cm() * 2.54f; }
    static constexpr Units foot(){ return Units::inch() * 12.0f; }
    static constexpr Units yard(){ return Units::foot() * 3.0f; }
    static constexpr Units chain(){ return Units::yard() * 22.0f; }
    static constexpr Units furlong(){ return Units::chain() * 10.0f; }
    static constexpr Units mile(){ return Units::foot() * 5280.0f; }
    static constexpr Units league(){ return Units::mile() * 3.0f; }

    private:
      constexpr Units(float x):factor(x){};
      float factor;
   };

  /**
   * Default Constructor
   */
  Length(){ /* no-op */ };

  constexpr Length(float value, Units conversion):
    Quantity<float>(value * conversion)
  {
  };

  float As(Length::Units units) const {
    return _value / units.factor;
  }

};


constexpr Length operator "" _cm(long double x) {
  return Length(x, Length::Units::cm());
}

constexpr Length operator "" _mm(long double x) {
  return Length(x, Length::Units::mm());
}

constexpr Length operator "" _inch(long double x) {
  return Length(x, Length::Units::inch());
}

constexpr Length operator "" _foot(long double x) {
  return Length(x, Length::Units::yard());
}

constexpr Length operator "" _yard(long double x) {
  return Length(x, Length::Units::yard());
}

constexpr Length operator "" _mile(long double x) {
  return Length(x, Length::Units::mile());
}
