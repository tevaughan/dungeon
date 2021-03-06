/// @file       test/race-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Tests of dungeon::race.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "catch.hpp" // for TEST_CASE
#include "race/modified.hpp"

using namespace dungeon::ability;
using namespace dungeon::race;

void print(scores const &b) {
  printf("st=%02d in=%02d ws=%02d dx=%02d cn=%02d ch=%02d", //
         b[id::ST], b[id::IN], b[id::WS], b[id::DX], b[id::CN], b[id::CH]);
}

TEST_CASE("Race-restrictions are respected.", "[race]") {
  unsigned rng_state = 1;
  {
    initial i1(rng_state);
    REQUIRE(modified(i1, species::DWARF, sex::MALE)[id::ST] == 0);
    REQUIRE(modified(i1, species::DWARF, sex::FEMALE)[id::ST] == 0);
    REQUIRE(modified(i1, species::ELF, sex::MALE)[id::ST] == 0);
    REQUIRE(modified(i1, species::ELF, sex::FEMALE)[id::ST] == 0);
  }
  {
    initial i2(rng_state);
    REQUIRE(modified(i2, species::ELF, sex::MALE)[id::ST] == 0);
    REQUIRE(modified(i2, species::ELF, sex::FEMALE)[id::ST] == 0);
    REQUIRE(modified(i2, species::HALF_ELF, sex::MALE)[id::ST] == 0);
    REQUIRE(modified(i2, species::HALF_ELF, sex::FEMALE)[id::ST] == 0);
    REQUIRE(modified(i2, species::HALFLING, sex::MALE)[id::ST] == 0);
    REQUIRE(modified(i2, species::HALFLING, sex::FEMALE)[id::ST] == 0);
  }
  {
    initial itmp(rng_state);
    initial i3(rng_state);
    printf("initial: ");
    print(i3);
    printf("\n");
    for (auto sp : species::_values()) {
      for (auto sx : sex::_values()) {
        printf("%s %s: ", sp._to_string(), sx._to_string());
        print(modified(i3, sp, sx));
        printf("\n");
      }
    }
  }
}
