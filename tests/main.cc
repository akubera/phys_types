
#include "bandit/bandit.h"
using namespace bandit;

#include "test_length.h"
#include "test_energy.h"
#include "test_angle.h"

go_bandit([](){
  describe("Length.Units", test_length_units);
  describe("Length", test_length);

  describe("Energy.Units", test_energy_units);
  describe("Energy", test_energy);

  describe("Angle.Units", test_angle_units);
  describe("Angle", test_angle);
});


int
main(int argc, char *argv[]) {
  return bandit::run(argc, argv);
}
