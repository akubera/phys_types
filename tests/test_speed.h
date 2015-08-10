/**
 * \file test_time.h
 *
 */

#include "bandit/bandit.h"
using namespace bandit;

#include "phys_types/speed.hh"


auto test_speed_units = []() {

  it("includes meters per second", [&] () {
    Speed::Units s = Speed::Units::meters_per_second();
    float val = static_cast<float>(s);
    AssertThat(val, Equals(1.0f));
  });

};


auto test_speed = []() {

  it("has a default constructor", [&] () {
    Speed t = Speed();
    AssertThat(t.As(Speed::Units::Default()), Equals(1.0f));
  });

  it("converts days to seconds", [&] () {
    Speed s(Length(1.0, Length::Units::Meter()),
            Time(1.0, Time::Units::Second()));
    float val = static_cast<float>(s.As(Speed::Units::meters_per_second()));
    AssertThat(val, Equals(1.0));
  });

};
