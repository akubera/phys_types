/**
 * \file angle.hh
 * \author Andrew Kubera <andrew.kubera@cern.ch>
 * \date May 18, 2015
 *
 */

#pragma once

#include "quantity.hh"

#include <cmath>

static const double DEGREES_TO_RADIANS = M_PI / 180.0;

class Angle : public Quantity<float> {
public:
  struct Units {
    friend class Angle;
    static constexpr const Units Radians() { return Units(1.0); };
    static constexpr const Units Degrees() { return Units(DEGREES_TO_RADIANS); };

    constexpr operator float() const { return factor; };
  private:
    constexpr Units(float x): factor(x) {};
    float factor;
  };

  Angle() { };
  constexpr Angle(float value, Units conversion):
    Quantity<float>(value*conversion)
  {}

  float As(Angle::Units units) const {
    return _value / units.factor;
  }

  float sin() const {
    return ::sin(_value);
  }

  float cos() const {
    return ::cos(_value);
  }

  float tan() const {
    return ::tan(_value);
  }

  float asin() const {
    return ::asin(_value);
  }

  float acos() const {
    return ::acos(_value);
  }

  float atan() const {
    return ::atan(_value);
  }

  float sec() const {
    return 1/cos();
  }

  float csc() const {
    return 1/sin();
  }

  float cot() const {
    return cos()/sin();
  }
};

class Degrees;

class Radians {
  float _value;
public:
  constexpr explicit Radians(float angle_in_radians):
    _value(angle_in_radians) {};
	Radians(const Degrees& angle_in_degrees);
  constexpr float getValue() const { return _value; }

  double sin() const { return std::sin(_value); }
  double cos() const { return std::cos(_value); }

  operator float() const { return _value; }

};

class Degrees {
  float _value;
public:
  constexpr explicit Degrees(float angle_in_degrees): _value(angle_in_degrees) {};
  Degrees(const Radians& angle);
  constexpr float getValue() const { return _value; }

  double sin() const { return std::sin(_value * DEGREES_TO_RADIANS); }
  double cos() const { return std::cos(_value * DEGREES_TO_RADIANS); }
};

inline Radians::Radians(const Degrees& angle):
  _value(angle.getValue() * DEGREES_TO_RADIANS) {}

inline Degrees::Degrees(const Radians& angle):
  _value(angle.getValue() / DEGREES_TO_RADIANS) {}

inline Angle operator"" _rad(long double r) { return Angle(r, Angle::Units::Radians()); }
inline Angle operator"" _rad(unsigned long long r) { return Angle(r, Angle::Units::Radians()); }
inline Angle operator"" _deg(long double d) { return Angle(d, Angle::Units::Degrees()); }
inline Angle operator"" _deg(unsigned long long d) { return Angle(d, Angle::Units::Degrees()); }
