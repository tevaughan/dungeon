/// @file       lib/ability/charis-tab.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::ability::charis_rec;
///             declaration of
///             dungion::ability::charis_tab.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITY_CHARIS_TAB_HPP
#define DUNGEON_ABILITY_CHARIS_TAB_HPP

#include "table.hpp"

namespace dungeon {
namespace ability {

/// Record in charis-ability table.
struct charis_rec {
  int max_henchmen; ///< Maximum number of henchmen.
  int loyalty_adj;  ///< Percentage adjustment for loyalty.
  int reaction_adj; ///< Percentage adjustment for reaction on meeting.
};

table<charis_rec> const &charis_tab();

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_CHARIS_TAB_HPP
