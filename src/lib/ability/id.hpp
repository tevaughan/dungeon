/// @file       lib/ability/id.hpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::ability::id.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_ABILITY_ID_HPP
#define DUNGEON_ABILITY_ID_HPP

#include "enum.h" // for BETTER_ENUM

namespace dungeon {
namespace ability {

/// Identifier for each ability.
///
/// ES is for exceptional strength, and the corresponding ability is zero
/// whenever strength be below 18 or, even if 18, whenever the character is not
/// a fighter.
BETTER_ENUM(id, unsigned, ST = 0, IN, WS, DX, CN, CH, ES);

} // namespace ability
} // namespace dungeon

#endif // ndef DUNGEON_ABILITY_ID_HPP
