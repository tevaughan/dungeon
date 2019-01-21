/// @file       lib/race/sex.hpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::race::sex.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_RACE_SEX_HPP
#define DUNGEON_RACE_SEX_HPP

#include "enum.h" // for BETTER_ENUM

namespace dungeon {
namespace race {

/// Identifier for sex.
BETTER_ENUM(sex, unsigned, MALE, FEMALE);

} // namespace race
} // namespace dungeon

#endif // ndef DUNGEON_RACE_HPP
