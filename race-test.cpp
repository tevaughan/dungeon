/// @file       race-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Tests of dungeon::race.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "race.hpp"
#include "catch.hpp" // for TEST_CASE

using namespace dungeon::race;

TEST_CASE("Each race can be instantiated.", "[race]") {
  dwarf    dm(MALE);
  dwarf    df(FEMALE);
  elf      em(MALE);
  elf      ef(FEMALE);
  gnome    gm(MALE);
  gnome    gf(FEMALE);
  half_elf hem(MALE);
  half_elf hef(FEMALE);
  halfling ham(MALE);
  halfling haf(FEMALE);
  half_orc hom(MALE);
  half_orc hof(FEMALE);
  human    hum(MALE);
  human    huf(FEMALE);
}
