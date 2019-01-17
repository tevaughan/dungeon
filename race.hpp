/// @file       race.hpp
/// @author     Thomas E. Vaughan
/// @brief      Declaration of dungeon::race.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_RACE_HPP
#define DUNGEON_RACE_HPP

#include "initial-abilities.hpp" // for initial_abilities
#include <string>                // for string

namespace dungeon {
namespace race {

enum sex_id { MALE, FEMALE }; ///< Identifier for sex.

/// Features of a race and sex of characters.
class race {
public:
  /// Allow easy setting of abilities.
  struct ab: public abilities::basic {
    ab(array a) { a_ = a; } ///< Copy abilities from array.
  };

  std::string const name;      ///< Name of race.
  sex_id            sex;       ///< Identifier for sex.
  ab const          modifiers; ///< Modifiers to initial abilities.
  ab const          minima;    ///< Minimum abilities.
  ab const          maxima;    ///< Maximum abilities.

protected:
  /// Initialize features of race.
  /// @param n    Name of race.
  /// @param s    Identifier for sex.
  /// @param mod  Modifiers to initial abilities.
  /// @param min  Minimum abilities.
  /// @param max  Maximum abilities.
  race(std::string n, sex_id s, ab mod, ab min, ab max);

  /// Return abilities, modified according to race, but only if initial
  /// abilities be consistent with the race; otherwise, return a set of
  /// abilities, every one of which is set to zero.
  /// @param i  Initial abilities.
  /// @return   Modified abilities, or zeros if inconsistent with race.
  abilities::basic modify(abilities::initial i);
};

/// Features of dwarf race.
struct dwarf: public race {
  static ab const mod;
  static std::array<ab, 2> const min;
  static std::array<ab, 2> const max;
  dwarf(sex_id s): race("dwarf", s, mod, min[s], max[s]) {}
};

/// Features of elf race.
struct elf: public race {
  static ab const mod;
  static std::array<ab, 2> const min;
  static std::array<ab, 2> const max;
  elf(sex_id s): race("elf", s, mod, min[s], max[s]) {}
};

/// Features of gnome race.
struct gnome: public race {
  static ab const mod;
  static std::array<ab, 2> const min;
  static std::array<ab, 2> const max;
  gnome(sex_id s): race("gnome", s, mod, min[s], max[s]) {}
};

/// Features of half_elf race.
struct half_elf: public race {
  static ab const mod;
  static std::array<ab, 2> const min;
  static std::array<ab, 2> const max;
  half_elf(sex_id s): race("half_elf", s, mod, min[s], max[s]) {}
};

/// Features of halfling race.
struct halfling: public race {
  static ab const mod;
  static std::array<ab, 2> const min;
  static std::array<ab, 2> const max;
  halfling(sex_id s): race("halfling", s, mod, min[s], max[s]) {}
};

/// Features of half_orc race.
struct half_orc: public race {
  static ab const mod;
  static std::array<ab, 2> const min;
  static std::array<ab, 2> const max;
  half_orc(sex_id s): race("half_orc", s, mod, min[s], max[s]) {}
};

/// Features of human race.
struct human: public race {
  static ab const mod;
  static std::array<ab, 2> const min;
  static std::array<ab, 2> const max;
  human(sex_id s): race("human", s, mod, min[s], max[s]) {}
};

} // namespace race
} // namespace dungeon

#endif // ndef DUNGEON_RACE_HPP
