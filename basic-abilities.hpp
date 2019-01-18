/// @file       basic-abilities.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::abilities::word_size,
///             dungeon::abilities::id,
///             dungeon::abilities::st_features,
///             dungeon::abilities::in_features,
///             dungeon::abilities::ws_features,
///             dungeon::abilities::dx_features,
///             dungeon::abilities::cn_features,
///             dungeon::abilities::ch_features;
///             declaration of
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
///
/// ES is for exceptional strength, and the corresponding ability is zero
/// whenever strength be below 18 or, even if 18, whenever the character is not
/// a fighter.
BETTER_ENUM(id, unsigned, ST = 0, IN, WS, DX, CN, CH, ES);

/// Features pertaining to strength-ability.
struct st_features {
  int hit_adj;    ///< Adjustment to hit-throw.
  int damage_adj; ///< Adjustment to damage.
  int weight_adj; ///< Adjustment to weight allowance.
  int open_doors; ///< Chances out of six for opening locked door.
  int od_throws;  ///< Number for throws for opening locked door.
  int bblg;       ///< Percentage for bending bars and lifting gates.
};

/// Features pertaining to intelligence-ability.
struct in_features {
  int add_lang;     ///< Possible number of additional languages.
  int spell_chance; ///< Percentage for magic-user to know each listed spell.
  int min_spells;   ///< Magic-user's minimum number of spells per level.
  int max_spells;   ///< Magic-user's maximum number of spells per level.
};

/// Features pertaining to wisdom-ability.
struct ws_features {
  int mag_attack_adj; ///< Adjustment to saving throw against magical attack.
  int spell_bonus;    ///< Cleric's spell bonus.
  int failure_prob;   ///< Cleric's percentage of spell-failure.
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
  int hit_point_adj; ///< Hit-points adjustment.
  int shock_surv;    ///< Percentage chance of surviving system-shock.
  int res_surv;      ///< Percentage chance of surviving resurrection.
};

/// Features pertaining to charisma-ability.
struct ch_features {
  int max_henchmen; ///< Maximum number of henchmen.
  int loyalty_adj;  ///< Percentage adjustment for loyalty.
  int reaction_adj; ///< Percentage adjustment for reaction on meeting.
};

/// The parameters that define the basic abilities of a character in the game.
class basic {
protected:
  /// Type of internal storage for basic abilities.
  using ar = std::array<int8_t, word_size(id::_size())>;

  ar a_; ///< Storage for abilities.

  /// Set attributes to zero; disallow public construction.
  basic() { a_.fill(0); }

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

  st_features const &st() const; ///< Features pertaining to strength-ability.
  in_features const &in() const; ///< Features pertaining to intel.-ability.
  ws_features const &ws() const; ///< Features pertaining to wisdom-ability.
  dx_features const &dx() const; ///< Features pertaining to dexterity-ability.
  cn_features const &cn() const; ///< Features pertaining to const.-ability.
  ch_features const &ch() const; ///< Features pertaining to charisma-ability.
};

} // namespace abilities
} // namespace dungeon

#endif // ndef DUNGEON_BASIC_ABILITIES_HPP
