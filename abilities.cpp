/// @file       abilities.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::initial_abilities.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "abilities.hpp"
#include "dice.hpp"
#include <ctime> // for time

namespace dungeon {

initial_abilities::initial_abilities(unsigned &s) {
  {
    int b15;
    do {
      b15 = 0;
      for (int i = 0; i < 6; ++i) {
        unsigned const r = dice::roll(3, 6, s);
        a_[i]            = r;
        if (r >= 15) {
          ++b15;
        }
      }
    } while (b15 < 2);
  }
  if (strn() == 18) {
    a_[6] = dice::roll(1, 100, s);
  } else {
    a_[6] = 0;
  }
}

} // namespace dungeon
