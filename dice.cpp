/// @file       dice.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::dice::roll.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "dice.hpp"
#include <cstdio>  // for printf
#include <cstdlib> // for rand_r

namespace dungeon {
namespace dice {

unsigned roll(unsigned num_dice, unsigned num_facets, unsigned &s) {
  unsigned sum = 0;
  for (unsigned i = 0; i < num_dice; ++i) {
    sum += rand_r(&s) % num_facets + 1;
  }
  return sum;
}

} // namespace dice
} // namespace dungeon
