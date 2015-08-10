/**
 * \file angle.hh
 * \author Andrew Kubera <andrew.kubera@cern.ch>
 * \date May 18, 2015
 *
 */

#pragma once

#include <cmath>

static const double DEGREES_TO_RADIANS = M_PI / 180.0;

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

inline Radians operator"" _rad(long double r) { return Radians(r); }
inline Radians operator"" _rad(unsigned long long r) { return Radians(r); }
inline Degrees operator"" _deg(long double d) { return Degrees(d); }
inline Degrees operator"" _deg(unsigned long long d) { return Degrees(d); }
