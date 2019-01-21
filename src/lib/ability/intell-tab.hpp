/// @file       lib/ability/intell-tab.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::ability::intell_rec;
///             declaration of
///             dungion::ability::intell_tab.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITY_INTELL_TAB_HPP
#define DUNGEON_ABILITY_INTELL_TAB_HPP

#include "table.hpp"

namespace dungeon {
namespace ability {

/// Record in intelligence-ability table.
struct intell_rec {
  int add_lang;     ///< Possible number of additional languages.
  int spell_chance; ///< Percentage for magic-user to know each listed spell.
  int min_spells;   ///< Magic-user's minimum number of spells per level.
  int max_spells;   ///< Magic-user's maximum number of spells per level.
};

table<intell_rec> const &intell_tab();

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_INTELL_TAB_HPP
