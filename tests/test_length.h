
#include "bandit/bandit.h"

#include "phys_types/length.hh"

using namespace bandit;

auto test_length_units = []() {

  it("includes meters", [&] () {
    Length::Units meters = Length::Units::Meter();
    float val = static_cast<float>(meters);
    AssertThat(val, Equals(1.0f));
  });

  it("includes centimeters", [&] () {
    Length::Units length = Length::Units::cm();
    float val = static_cast<float>(length);
    AssertThat(val, EqualsWithDelta(1.0e-2f, 1e-24f));
  });

  it("includes kilometers", [&] () {
    Length::Units length = Length::Units::km();
    float val = static_cast<float>(length);
    AssertThat(val, EqualsWithDelta(1.0e3f, 1e-24f));
  });

  it("includes picometers", [&] () {
    Length::Units length = Length::Units::pm();
    AssertThat(static_cast<float>(length), EqualsWithDelta(1.0e-12f, 1e-24f));
  });

  it("includes femtometers", [&] () {
    Length::Units length = Length::Units::fm();
    AssertThat(static_cast<float>(length), EqualsWithDelta(1.0e-15f, 1e-24f));
  });
};

auto test_length = []() {
  it("has a default constructor", [&] () {
    Length length = Length();
    AssertThat(length.As(Length::Units::Meter()), Equals(0.0f));
  });

  it("can convert numeric literals", [&] () {
    Length length = 1.5_cm;
    AssertThat(length.As(Length::Units::Meter()), Equals(0.015f));
  });

  it("can convert units to themselves", [&] () {
    Length length(1.0, Length::Units::cm());
    AssertThat(length.As(Length::Units::cm()), Equals(1.0f));
  });

  it("can convert miles to meters", [&] () {
    Length length(1.0, Length::Units::mile());
    AssertThat(length.As(Length::Units::mile()), Equals(1.0f));
    AssertThat(length.As(Length::Units::Meter()), Equals(1609.344f));
    AssertThat(length.As(Length::Units::yard()), Equals(1760.f));
  });

  it("can convert yards to meters", [&] () {
    Length length(1.0, Length::Units::yard());
    AssertThat(length.As(Length::Units::Meter()), Equals(0.9144f));
  });
};
