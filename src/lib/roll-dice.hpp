/// @file       lib/roll-dice.hpp
/// @author     Thomas E. Vaughan
/// @brief      Declaration of dungeon::roll_dice.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ROLL_DICE_HPP
#define DUNGEON_ROLL_DICE_HPP

namespace dungeon {

/// Roll a certain number of dice, each with the same number of facets.
/// @param num_dice    Number of dice to roll.
/// @param num_facets  Number of facets on each die.
/// @param s           Reference to state of random-number generator.
/// @return            Sum of values, each contributed from corresponding die.
unsigned roll_dice(unsigned num_dice, unsigned num_facets, unsigned &s);

} // namespace dungeon

#endif // ndef DUNGEON_ROLL_DICE_HPP
