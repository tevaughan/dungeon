/// @file       lib/ability/wisdom-tab.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::ability::wisdom_rec;
///             declaration of
///             dungion::ability::wisdom_tab.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITY_WISDOM_TAB_HPP
#define DUNGEON_ABILITY_WISDOM_TAB_HPP

#include "table.hpp"

namespace dungeon {
namespace ability {

/// Record in wisdom-ability table.
struct wisdom_rec {
  int mag_attack_adj;  ///< Adjustment to saving throw against magical attack.
  int spell_bonus;     ///< Spell-level of cleric's one bonus spell.
  int max_spell_level; ///< Cleric's maximum spell-level.
  int failure_prob;    ///< Cleric's percentage of spell-failure.
};

table<wisdom_rec> const &wisdom_tab();

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_WISDOM_TAB_HPP
