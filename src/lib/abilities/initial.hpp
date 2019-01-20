/// @file       initial-abilities.hpp
/// @author     Thomas E. Vaughan
/// @brief      Declaration of dungeon::abilities::initial.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_INITIAL_ABILITIES_HPP
#define DUNGEON_INITIAL_ABILITIES_HPP

#include "basic.hpp" // for basic_abilities

namespace dungeon {
namespace abilities {

/// Initial abilities generated at random.
struct initial: public basic {
  /// Generate initial abilities at random.
  ///
  /// Each initial ability (apart from exceptional strength) is obtained by
  /// rolling 3d6, but a set of such roles is discarded in favor of a new set
  /// until at least each of two abilities in the set is at least 15 in value.
  ///
  /// @param s  Reference to state of random-number generator.
  initial(unsigned &s);
};

} // namespace abilities
} // namespace dungeon

#endif // ndef DUNGEON_INITIAL_ABILITIES_HPP
