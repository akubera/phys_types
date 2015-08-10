/**
 * \file time.hh
 */

#pragma once

#include "quantity.hh"


/**
 * \class Time
 * \brief Quantity of time.
 *
 * Base unit is the standard second.
 */
class Time : public Quantity<float> {
public:
  struct Units {
    friend class Time;

    template <int POWER=0>
    static constexpr const Units Second(){ return Units(::pow(10.f, POWER)); };

    static constexpr const Units Gs(){ return Units::Second<SI_Prefix::giga>(); };
    static constexpr const Units Ms(){ return Units::Second<SI_Prefix::mega>(); };
    static constexpr const Units ks(){ return Units::Second<SI_Prefix::kilo>(); };
    static constexpr const Units  s(){ return Units::Second(); };
    static constexpr const Units cs(){ return Units::Second<SI_Prefix::centi>(); };
    static constexpr const Units ms(){ return Units::Second<SI_Prefix::milli>(); };
    static constexpr const Units us(){ return Units::Second<SI_Prefix::micro>(); };
    static constexpr const Units ns(){ return Units::Second<SI_Prefix::nano>(); };
    static constexpr const Units ps(){ return Units::Second<SI_Prefix::pico>(); };
    static constexpr const Units fs(){ return Units::Second<SI_Prefix::femto>(); };

    static constexpr Units minute(){ return Units::Second() * 60.0f; }
    static constexpr Units hour(){ return Units::minute() * 60.0f; }
    static constexpr Units day(){ return Units::hour() * 24.0f; }

    // static const Units min;

    constexpr operator float() const { return factor; };
    constexpr Units operator*(float scale) const { return Units(factor * scale);};

    private:
      constexpr Units(float x):factor(x){};
      float factor;
   };

   /**
    * Default Constructor
    */
   Time(){ /* no-op */ };

   constexpr Time(float value, Units conversion):
     Quantity<float>(value * conversion)
   {  };

   float As(Time::Units units) const {
     return _value / units.factor;
   }

};
