/// @file       lib/race/species.hpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::race::species.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_RACE_SPECIES_HPP
#define DUNGEON_RACE_SPECIES_HPP

#include "enum.h" // for BETTER_ENUM

namespace dungeon {
namespace race {

/// Identifier for species.
BETTER_ENUM(species, unsigned, //
            DWARF, ELF, GNOME, HALF_ELF, HALFLING, HALF_ORC, HUMAN);

} // namespace race
} // namespace dungeon

#endif // ndef DUNGEON_RACE_SPECIES_HPP
