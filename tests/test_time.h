/**
 * \file test_time.h
 *
 */

#include "bandit/bandit.h"
using namespace bandit;

#include "phys_types/time.hh"


auto test_time_units = []() {

  it("includes seconds", [&] () {
    Time::Units s = Time::Units::Second();
    float val = static_cast<float>(s);
    AssertThat(val, Equals(1.0f));
  });

  it("includes minutes", [&] () {
    Time::Units s = Time::Units::minute();
    float val = static_cast<float>(s);
    AssertThat(val, Equals(60.0));
  });



};


auto test_time = []() {

  it("has a default constructor", [&] () {
    Time t = Time();
    AssertThat(t.As(Time::Units::Second()), Equals(0.0f));
  });

  it("converts days to seconds", [&] () {
    Time day(1.0, Time::Units::day());
    float val = static_cast<float>(day.As(Time::Units::Second()));
    AssertThat(val, Equals(86400));
  });

  it("converts minutes to hours", [&] () {
    Time min(1.0, Time::Units::minute());
    float val = static_cast<float>(min.As(Time::Units::hour()));
    AssertThat(val, EqualsWithDelta(0.0166667, 1e-7));
  });

};
