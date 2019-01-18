/// @file       race.hpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::race::species,
///             dungeon::race::sex;
///             declaration of
///             dungeon::race::modify.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_RACE_HPP
#define DUNGEON_RACE_HPP

#include "enum.h"                // for BETTER_ENUM
#include "initial-abilities.hpp" // for initial_abilities

namespace dungeon {
namespace race {

/// Identifier for species.
BETTER_ENUM(species, unsigned, //
            DWARF, ELF, GNOME, HALF_ELF, HALFLING, HALF_ORC, HUMAN);

/// Identifier for sex.
BETTER_ENUM(sex, unsigned, MALE, FEMALE);

/// Return abilities, modified according to biology, but only if initial
/// abilities be consistent with the biology; otherwise, return a set of
/// abilities, every one of which is set to zero.
///
/// @param i   Initial abilities.
/// @param sp  Species of character.
/// @param sx  Sex of character.
/// @return    Modified abilities, or zeros if inconsistent with biology.
abilities::basic modify(abilities::initial i, species sp, sex sx);

} // namespace race
} // namespace dungeon

#endif // ndef DUNGEON_RACE_HPP
