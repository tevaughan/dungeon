/// @file       lib/ability/scores.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of dungeon::ability::word_size,
///             declaration of dungeon::ability::scores.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITY_SCORES_HPP
#define DUNGEON_ABILITY_SCORES_HPP

#include "charis-tab.hpp" // for charis_rec, charis_tab
#include "consti-tab.hpp" // for consti_rec, consti_tab
#include "dexter-tab.hpp" // for dexter_rec, dexter_tab
#include "id.hpp"         // for id
#include "intell-tab.hpp" // for intell_rec, intell_tab
#include "streng-tab.hpp" // for streng_rec, streng_tab
#include "wisdom-tab.hpp" // for wisdom_rec, wisdom_tab
#include <array>          // for array
#include <cstdint>        // for int8_t

namespace dungeon {
namespace ability {

/// Return size of smallest word that can store m bytes of data.
/// @param m  Number of bytes that need to be stored in word.
inline unsigned constexpr word_size(unsigned m) {
  unsigned n = (m ? 1u : 0u);
  while (n < m) {
    n <<= 1u;
  }
  return n;
}

/// The parameters that define the basic abilities of a character in the game.
class scores {
protected:
  /// Type of internal storage for basic abilities.
  using array = std::array<int8_t, word_size(id::_size())>;

  array a_; ///< Storage for abilities.

  /// Set attributes to zero; disallow public construction.
  scores() { a_.fill(0); }

  /// Set ability.
  /// @param i  Identifier of ability.
  /// @param v  New value for ability.
  void set(id i, int8_t v) { a_[i._to_integral()] = v; }

  /// Copy of ability.
  /// @param i  Identifier of ability to copy.
  int get(id i) const { return a_[i._to_integral()]; }

  /// Strength score, scaled by 1000 and added to exception-strength score.
  int mod_streng_score() const { return get(id::ST) * 1000 + get(id::ES); }

public:
  /// Copy of ability.
  /// @param i  Identifier of ability to copy.
  int operator[](id i) const { return get(i); }

  /// Features pertaining to strength-ability.
  streng_rec const &st() const { return streng_tab()[mod_streng_score()]; }

  /// Features pertaining to intelligence-ability.
  intell_rec const &in() const { return intell_tab()[get(id::IN)]; }

  /// Features pertaining to wisdom-ability.
  wisdom_rec const &ws() const { return wisdom_tab()[get(id::WS)]; }

  /// Features pertaining to dexterity-ability.
  dexter_rec const &dx() const { return dexter_tab()[get(id::DX)]; }

  /// Features pertaining to constitution-ability.
  consti_rec const &cn() const { return consti_tab()[get(id::CN)]; }

  /// Features pertaining to charisma-ability.
  charis_rec const &ch() const { return charis_tab()[get(id::CH)]; }
};
// class scores

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_SCORES_HPP
