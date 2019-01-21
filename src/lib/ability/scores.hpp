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

#include "id.hpp"         // for id
#include "streng-tab.hpp" // for streng_rec, streng_tab
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

/// Features pertaining to intelligence-ability.
struct in_features {
  int add_lang;     ///< Possible number of additional languages.
  int spell_chance; ///< Percentage for magic-user to know each listed spell.
  int min_spells;   ///< Magic-user's minimum number of spells per level.
  int max_spells;   ///< Magic-user's maximum number of spells per level.
};

/// Features pertaining to wisdom-ability.
struct ws_features {
  int mag_attack_adj;  ///< Adjustment to saving throw against magical attack.
  int spell_bonus;     ///< Spell-level of cleric's one bonus spell.
  int max_spell_level; ///< Cleric's maximum spell-level.
  int failure_prob;    ///< Cleric's percentage of spell-failure.
};

/// Features pertaining to dexterity-ability.
struct dx_features {
  int react_attack_adj; ///< Adjustment for both surprise and missile combat.
  int defense_adj;      ///< Adjustment to defense against attack.
  int pick_pocket;      ///< Thief's adjustment percentage for picking pockets.
  int open_lock;        ///< Thief's adjustment percentage for opening lock.
  int loc_rem_trap;     ///< Thief's adjustment percentage for traps.
  int mov_silent;       ///< Thief's adjustment percentage for silence.
  int hiding;           ///< Thisf's adjustment percentage for hiding.
};

/// Features pertaining to constitution-ability.
struct cn_features {
  int hp_adj;         ///< Hit-points adjustment.
  int fighter_hp_adj; ///< Hit-points adjustment for a fighter.
  int shock_surv;     ///< Percentage chance of surviving system-shock.
  int res_surv;       ///< Percentage chance of surviving resurrection.
};

/// Features pertaining to charisma-ability.
struct ch_features {
  int max_henchmen; ///< Maximum number of henchmen.
  int loyalty_adj;  ///< Percentage adjustment for loyalty.
  int reaction_adj; ///< Percentage adjustment for reaction on meeting.
};

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

public:
  /// Copy of ability.
  /// @param i  Identifier of ability to copy.
  int operator[](id i) const { return get(i); }

  /// Features pertaining to strength-ability.
  streng_rec const &st() const {
    return streng_tab()[get(id::ST) * 1000 + get(id::ES)];
  }
  in_features const &in() const; ///< Features pertaining to intel.-ability.
  ws_features const &ws() const; ///< Features pertaining to wisdom-ability.
  dx_features const &dx() const; ///< Features pertaining to dexterity-ability.
  cn_features const &cn() const; ///< Features pertaining to const.-ability.
  ch_features const &ch() const; ///< Features pertaining to charisma-ability.
};
// class scores

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_SCORES_HPP
