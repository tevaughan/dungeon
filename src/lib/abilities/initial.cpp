/// @file       initial-abilities.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::initial_abilities.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "initial.hpp"
#include "roll-dice.hpp"

namespace dungeon {
namespace abilities {

initial::initial(unsigned &s) {
  int b15;
  do {
    b15 = 0;
    for (auto i : id::_values()) {
      switch (i) {
      case id::ST:
      case id::IN:
      case id::WS:
      case id::DX:
      case id::CN:
      case id::CH: {
        unsigned const r = roll_dice(3, 6, s);
        set(i, r);
        if (r >= 15) {
          ++b15;
        }
      } break;
      case id::ES:
        break;
      }
    }
  } while (b15 < 2);
}

} // namespace abilities
} // namespace dungeon
