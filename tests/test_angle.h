/**
 * \file test_angle.h
 *
 */


#include "bandit/bandit.h"
using namespace bandit;

#include "phys_types/angle.hh"

auto test_angle_units = []() {

  it("includes radians", [&] () {
    Angle::Units rads = Angle::Units::Radians();
    float val = static_cast<float>(rads);
    AssertThat(val, Equals(1.0f));
  });

  it("includes degrees", [&] () {
    Angle::Units degs = Angle::Units::Degrees();
    float val = static_cast<float>(degs);
    AssertThat(val, EqualsWithDelta(0.0174532925f, 1e-12));
  });

};


auto test_angle = []() {

  it("has a default constructor", [&] () {
    Angle angle = Angle();
    AssertThat(angle.As(Angle::Units::Radians()), Equals(0.0f));
  });

  it("calculates sine", [&] () {
    Angle angle(1.0, Angle::Units::Radians());
    float sine = angle.sin();
    AssertThat(sine, EqualsWithDelta(0.8414709848, 1e-7));
  });

  it("calculates cosine", [&] () {
    Angle angle(1.0, Angle::Units::Radians());
    float cosine = angle.cos();
    AssertThat(cosine, EqualsWithDelta(0.5403023059, 1e-7));
  });

  it("calculates tangent", [&] () {
    Angle angle(1.0, Angle::Units::Radians());
    float tangent = angle.tan();
    AssertThat(tangent, EqualsWithDelta(1.557407725, 1e-7));
  });

  it("calculates sine from degrees", [&] () {
    Angle angle(100.0, Angle::Units::Degrees());
    float sine = angle.sin();
    AssertThat(sine, EqualsWithDelta(0.984807753, 1e-7));
  });

  it("calculates cotangent from degrees", [&] () {
    Angle angle(80.0, Angle::Units::Degrees());
    float val = angle.cot();
    AssertThat(val, EqualsWithDelta(0.1763269807, 1e-7));
  });

};
