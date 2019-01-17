/// @file       initial-abilities-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Test of dungeon::initial_abilities.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "initial-abilities.hpp"
#include "catch.hpp" // for TEST_CASE

using namespace dungeon::abilities;

/// Increment counter if ability be at least 15.
/// @param a    Ability.
/// @param b15  Counter to increment.
void check(unsigned a, unsigned &b15) {
  if (a >= 15) {
    ++b15;
  }
}

TEST_CASE("Each of two or more abilities has value >= 15.", "[abilities]") {
  unsigned s = time(nullptr);
  for (unsigned i = 0; i < 1000; ++i) {
    initial const a(s);
    unsigned      b15 = 0;
    check(a[id::ST], b15);
    check(a[id::IN], b15);
    check(a[id::WS], b15);
    check(a[id::DX], b15);
    check(a[id::CN], b15);
    check(a[id::CH], b15);
    REQUIRE(b15 >= 2);
  }
}
