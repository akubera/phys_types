
#include "bandit/bandit.h"

#include "phys_types/energy.hh"

using namespace bandit;

// const lest::test specification[] = {
auto test_energy_units =  []() {

    it("includes Joules", [&] () {
      Energy::Units joules = Energy::Units::Joule();
      float val = static_cast<float>(joules);
      AssertThat(val, Equals(1.0f));
    });

    it("includes electron volts", [&] () {
      Energy::Units joules = Energy::Units::eV();
      float val = static_cast<float>(joules);
      AssertThat(val, EqualsWithDelta(1.60218e-19f, 1e-24f));
    });

    it("includes GeV", [&] () {
      Energy::Units joules = Energy::Units::GeV();
      float val = static_cast<float>(joules);
      AssertThat(val, EqualsWithDelta(1.60218e-10f, 1e-15f));
    });
};

auto test_energy = []() {
    it("has a default constructor", [&] () {
      Energy energy = Energy();
      AssertThat(energy.As(Energy::Units::Joule()), Equals(0.0f));
    });

    it("can convert numeric literals", [&] () {
      Energy energy = 1.5_Joule;
      AssertThat(energy.As(Energy::Units::Joule()), Equals(1.5f));
    });

  it("can convert units to themselves", [&] () {
    AssertThat(Energy(1.0, Energy::Units::eV()).As(Energy::Units::eV()), Equals(1.0f));
    AssertThat(Energy(1e4, Energy::Units::keV()).As(Energy::Units::keV()), Equals(1e4));
    AssertThat(Energy(15.0, Energy::Units::MJ()).As(Energy::Units::MJ()), Equals(15.f));
  });

    it("can convert eV numeric literals", [&] () {
      auto Joule = Energy::Units::Joule();
      const Energy proton_rest_energy = 938272046._eV;
      // AssertThat(energy.As(Energy::Units::Joule()), Equals(1.5f));
      AssertThat(proton_rest_energy.As(Joule), EqualsWithDelta(1.50328e-10f, 1e-15f));
    });
};
