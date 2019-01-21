/// @file       lib/ability/initial.hpp
/// @author     Thomas E. Vaughan
/// @brief      Declaration of dungeon::ability::initial.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABL_INITIAL_HPP
#define DUNGEON_ABL_INITIAL_HPP

#include "scores.hpp" // for scores

namespace dungeon {
namespace ability {

/// Initial abilities generated at random.
struct initial : public scores {
  /// Generate initial abilities at random.
  ///
  /// Each initial ability (apart from exceptional strength) is obtained by
  /// rolling 3d6, but a set of such roles is discarded in favor of a new set
  /// until at least each of two abilities in the set is at least 15 in value.
  ///
  /// @param s  Reference to state of random-number generator.
  initial(unsigned &s);
};

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABL_INITIAL_HPP
