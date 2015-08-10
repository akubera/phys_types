/**
 * \file speed.hh
 */

#pragma once

#include "length.hh"
#include "time.hh"

/**
 * \class Speed
 * \brief Derived quantity class containing the ratio of length and time.
 */
class Speed : public RatioQuantity<Length, Time> {
public:
  struct Units {
    friend class Speed;

    static constexpr const Units Default(){ return Units(1.0); };
    static constexpr const Units meters_per_second(){ return Units::Default(); };


    constexpr operator float() const { return factor; };

    private:
      constexpr Units(float x): factor(x){};
      float factor;
  };

  Speed():
    RatioQuantity(Length(1.0, Length::Units::Meter()), Time(1.0, Time::Units::Second()))
  { }

  Speed(Length l, Time t):
    RatioQuantity(l, t)
  { }

  /**
   * Return the speed as provided unit
   */
  float As(Speed::Units speed_units) const {
    return _numerator.As(Length::Units::Meter()) / _denominator.As(Time::Units::Second()) * speed_units.factor;
  }

  float As(Length::Units len_units, Time::Units time_units) const {
    return _numerator.As(len_units) / _denominator.As(time_units);
  }

};
