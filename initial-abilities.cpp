/// @file       initial-abilities.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::initial_abilities.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "initial-abilities.hpp"
#include "roll-dice.hpp"

namespace dungeon {
namespace abilities {

initial::initial(unsigned &s) {
  int b15;
  do {
    b15 = 0;
    for (unsigned i = 0; i < id::_size(); ++i) {
      unsigned const r = roll_dice(3, 6, s);
      set(id::_from_integral(i), r);
      if (r >= 15) {
        ++b15;
      }
    }
  } while (b15 < 2);
}

} // namespace abilities
} // namespace dungeon
