/// @file       abilities/streng-tab.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::abilities::streng_rec;
///             declaration of
///             dungion::abilities::streng_tab.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITIES_STRENG_TAB_HPP
#define DUNGEON_ABILITIES_STRENG_TAB_HPP

#include "table.hpp"

namespace dungeon {
namespace abilities {

/// Record in strength-ability table.
struct streng_rec {
  int hit_adj;    ///< Adjustment to hit-throw.
  int damage_adj; ///< Adjustment to damage.
  int weight_adj; ///< Adjustment to weight allowance.
  int open_doors; ///< Chances out of six for opening locked door.
  int od_throws;  ///< Number for throws for opening locked door.
  int bblg;       ///< Percentage for bending bars and lifting gates.
};

table<streng_rec> const &streng_tab();
} // namespace abilities
} // namespace dungeon

#endif // ndef DUNGEON_ABILITIES_STRENG_TAB_HPP
