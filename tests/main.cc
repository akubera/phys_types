
#include "bandit/bandit.h"
using namespace bandit;

#include "test_length.h"
#include "test_energy.h"
#include "test_angle.h"
#include "test_time.h"
#include "test_speed.h"

go_bandit([](){
  describe("Time.Units", test_time_units);
  describe("Time", test_time);

  describe("Length.Units", test_length_units);
  describe("Length", test_length);

  describe("Energy.Units", test_energy_units);
  describe("Energy", test_energy);

  describe("Angle.Units", test_angle_units);
  describe("Angle", test_angle);

  describe("Speed.Units", test_speed_units);
  describe("Speed", test_speed);
});


int
main(int argc, char *argv[]) {
  return bandit::run(argc, argv);
}
