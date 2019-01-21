/// @file       lib/ability/dexter-tab.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::ability::dexter_rec;
///             declaration of
///             dungion::ability::dexter_tab.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITY_DEXTER_TAB_HPP
#define DUNGEON_ABILITY_DEXTER_TAB_HPP

#include "table.hpp"

namespace dungeon {
namespace ability {

/// Record in dexter-ability table.
struct dexter_rec {
  int react_attack_adj; ///< Adjustment for both surprise and missile combat.
  int defense_adj;      ///< Adjustment to defense against attack.
  int pick_pocket;      ///< Thief's adjustment percentage for picking pockets.
  int open_lock;        ///< Thief's adjustment percentage for opening lock.
  int loc_rem_trap;     ///< Thief's adjustment percentage for traps.
  int mov_silent;       ///< Thief's adjustment percentage for silence.
  int hiding;           ///< Thisf's adjustment percentage for hiding.
};

table<dexter_rec> const &dexter_tab();

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_DEXTER_TAB_HPP
