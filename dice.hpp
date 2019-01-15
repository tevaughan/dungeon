
/// @file       dice.hpp
/// @author     Thomas E. Vaughan
/// @brief      Declaration of dungeon::dice::roll.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_DICE_HPP
#define DUNGEON_DICE_HPP

namespace dungeon {
namespace dice {

/// Initialize seed for random-number generator.  By default, use the value
/// returned by time() at execution-time.
/// @param s  Seed for random-number generator.
void init(unsigned s = 0);

/// Roll a certain number of dice, each with the same number of factes.
/// @param num_dice    Number of dice to roll.
/// @param num_facets  Number of facets on each die.
/// @return            Sum of values, each contributed from corresponding die.
unsigned roll(unsigned num_dice, unsigned num_facets);

} // namespace dice
} // namespace dungeon

#endif // ndef DUNGEON_DICE_HPP

