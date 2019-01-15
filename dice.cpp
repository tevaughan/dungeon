/// @file       dice.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::dice::init and dungeon::dice::roll.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "dice.hpp"
#include <cstdlib> // for rand
#include <ctime>   // for time

namespace dungeon {
namespace dice {

void init(unsigned s) {
  if (s == 0) {
    srand(time(nullptr));
  }
  srand(s);
}

unsigned roll(unsigned num_dice, unsigned num_facets) {
  unsigned sum = 0;
  for (unsigned i = 0; i < num_dice; ++i) {
    sum += rand() % num_facets;
  }
  return sum;
}

} // namespace dice
} // namespace dungeon
