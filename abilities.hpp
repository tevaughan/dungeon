/// @file       abilities.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of dungeon::basic_abilities;
///             declaration of dungeon::initial_abilities.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITIES_HPP
#define DUNGEON_ABILITIES_HPP

#include <cstdint> // for uint8_t

namespace dungeon {

/// The race and the parameters that define the basic abilities of a character
/// in the game.
class basic_abilities {
protected:
  uint8_t a_[7];       ///< Storage for abilities.
  basic_abilities() {} ///< Do nothing, but disallow public construction.

public:
  uint8_t strn() const { return a_[0]; } ///< Strength.
  uint8_t intl() const { return a_[1]; } ///< Intelligence.
  uint8_t wsdm() const { return a_[2]; } ///< Wisdom.
  uint8_t dxtr() const { return a_[3]; } ///< Dexterity.
  uint8_t cnst() const { return a_[4]; } ///< Constitution.
  uint8_t chrs() const { return a_[5]; } ///< Charisma.
  uint8_t estr() const { return a_[6]; } ///< Exceptional strn (when strn=18).
};

/// Initial abilities generated at random.
struct initial_abilities: public basic_abilities {
  /// Generate initial abilities at random.
  ///
  /// Each initial ability (apart from exceptional strength) is obtained by
  /// rolling 3d6, but a set of such roles is discarded in favor of a new set
  /// until at least each of two abilities in the set is at least 15 in value.
  /// If strength be 18, then the exceptional strength is determined by
  /// way of 1d100.
  ///
  /// @param s  Reference to seed (changing state) for generator.
  initial_abilities(unsigned &s);
};

} // namespace dungeon

#endif // ndef DUNGEON_ABILITIES_HPP
