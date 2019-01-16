/// @file       dice.hpp
/// @author     Thomas E. Vaughan
/// @brief      Declaration of dungeon::dice::roll.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_DICE_HPP
#define DUNGEON_DICE_HPP

namespace dungeon {
namespace dice {

/// Roll a certain number of dice, each with the same number of facets.
/// A pointer to the seed, which is modified, must be passed in on every call.
/// @param num_dice    Number of dice to roll.
/// @param num_facets  Number of facets on each die.
/// @param s           Reference to seed for generator; modified on return.
/// @return            Sum of values, each contributed from corresponding die.
unsigned roll(unsigned num_dice, unsigned num_facets, unsigned &s);

} // namespace dice
} // namespace dungeon

#endif // ndef DUNGEON_DICE_HPP
