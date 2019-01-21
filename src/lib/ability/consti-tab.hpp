/// @file       lib/ability/consti-tab.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::ability::consti_rec;
///             declaration of
///             dungion::ability::consti_tab.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITY_CONSTI_TAB_HPP
#define DUNGEON_ABILITY_CONSTI_TAB_HPP

#include "table.hpp"

namespace dungeon {
namespace ability {

/// Record in consti-ability table.
struct consti_rec {
  int hp_adj;         ///< Hit-points adjustment.
  int fighter_hp_adj; ///< Hit-points adjustment for a fighter.
  int shock_surv;     ///< Percentage chance of surviving system-shock.
  int res_surv;       ///< Percentage chance of surviving resurrection.
};

table<consti_rec> const &consti_tab();

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_CONSTI_TAB_HPP
