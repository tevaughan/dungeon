/// @file       dice-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Test of functions in dungeon::dice.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "dice.hpp"
#include "catch.hpp" // for TEST_CASE
#include <vector>    // for vector

using namespace dungeon;
using namespace std;

/// A sequence of rolls, each involving a certain number of dice, every one of
/// which has the same number of facets.
struct roll_sequence: public vector<unsigned> {
  /// Initialize the value of each roll in the sequence.
  /// @param n  Number of rolls.
  /// @param d  Number of dice on each roll.
  /// @param f  Number of facets on each die.
  /// @param s  Seed for random-number generation; by default use time().
  roll_sequence(unsigned n, unsigned d, unsigned f, unsigned s = 0):
      vector<unsigned>(n) {
    dice::init(s);
    for (auto &e : *this) {
      e = dice::roll(d, f);
    }
  }
};

TEST_CASE("Seed can be repeated to repeat sequence.", "[dice]") {
  enum { N = 20, D = 3, F = 6 };
  roll_sequence const r1(N, D, F, 10);
  roll_sequence const r2(N, D, F, 10);
  REQUIRE(r1 == r2);
  roll_sequence const r3(N, D, F, 11);
  REQUIRE(r1 != r3);
  roll_sequence const r4(N, D, F);
  REQUIRE(r1 != r4);
  REQUIRE(r3 != r4);
}
