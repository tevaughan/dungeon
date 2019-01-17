/// @file       basic-abilities.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::abilities::word_size,
///             dungeon::abilities::id,
///             dungeon::abilities::basic.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_BASIC_ABILITIES_HPP
#define DUNGEON_BASIC_ABILITIES_HPP

#include "enum.h"  // for BETTER_ENUM
#include <array>   // for array
#include <cstdint> // for int8_t

namespace dungeon {
namespace abilities {

/// Return size of smallest word that can store m bytes of data.
/// @param m  Number of bytes that need to be stored in word.
inline unsigned constexpr word_size(unsigned m) {
  unsigned n = (m ? 1u : 0u);
  while (n < m) {
    n <<= 1u;
  }
  return n;
}

/// Identifier for each ability.
BETTER_ENUM(id, unsigned, ST = 0, IN, WS, DX, CN, CH);

/// The parameters that define the basic abilities of a character in the game.
class basic {
protected:
  using array = std::array<int8_t, word_size(id::_size())>;

  array a_;  ///< Storage for abilities.
  basic() {} ///< Do nothing, but disallow public construction.

  /// Set ability.
  /// @param i  Identifier of ability.
  /// @param v  New value for ability.
  void set(id i, int8_t v) { a_[i._to_integral()] = v; }

public:
  /// Copy of ability.
  /// @param i  Identifier of ability to copy.
  int8_t operator[](id i) const { return a_[i._to_integral()]; }
};

} // namespace abilities
} // namespace dungeon

#endif // ndef DUNGEON_BASIC_ABILITIES_HPP
