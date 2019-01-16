/// @file       abilities-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Tests of dungeon::basic_abilities, dungeon::initial_abilities.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "abilities.hpp"
#include "catch.hpp" // for TEST_CASE

using namespace dungeon;

TEST_CASE("Each of two or more abilities has value >= 15.", "[abilities]") {
  unsigned s = time(nullptr);
  for (unsigned i = 0; i < 1000; ++i) {
    initial_abilities a(s);
    int               b15 = 0;
    if (a.strn() >= 15) {
      ++b15;
    }
    if (a.strn() == 18) {
      REQUIRE(a.estr() > 0);
    } else {
      REQUIRE(a.estr() == 0);
    }
    if (a.intl() >= 15) {
      ++b15;
    }
    if (a.wsdm() >= 15) {
      ++b15;
    }
    if (a.dxtr() >= 15) {
      ++b15;
    }
    if (a.cnst() >= 15) {
      ++b15;
    }
    if (a.chrs() >= 15) {
      ++b15;
    }
    REQUIRE(b15 >= 2);
  }
}
