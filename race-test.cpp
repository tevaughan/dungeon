/// @file       race-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Tests of dungeon::race.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "race.hpp"
#include "catch.hpp" // for TEST_CASE

using namespace dungeon::race;
using namespace dungeon::abilities;

void print(basic const &b) {
  printf("st=%02d in=%02d ws=%02d dx=%02d cn=%02d ch=%02d", //
         b[id::ST], b[id::IN], b[id::WS], b[id::DX], b[id::CN], b[id::CH]);
}

TEST_CASE("Race-restrictions are respected.", "[race]") {
  unsigned rng_state = 1;
  initial  i1(rng_state);
  printf("initial: ");
  print(i1);
  printf("\n");
  for (auto sp : species::_values()) {
    for (auto sx : sex::_values()) {
      printf("%s %s: ", sp._to_string(), sx._to_string());
      print(modify(i1, sp, sx));
      printf("\n");
    }
  }
}
