/// @file       race.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::human.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "race.hpp"

namespace dungeon {
namespace race {

race::race(std::string n, sex_id s, ab mod, ab min, ab max):
    name(n),
    sex(s),
    modifiers(mod),
    minima(min),
    maxima(max) {}

using ab = race::ab;          ///< Short-hand.
using mf = std::array<ab, 2>; ///< Short-hand.

ab const dwarf::mod({0, 0, 0, 0, +1, -1, 0});
ab const elf::mod({0, 0, 0, +1, -1, 0, 0});
ab const gnome::mod({0, 0, 0, 0, 0, 0, 0});
ab const half_elf::mod({0, 0, 0, 0, 0, 0, 0});
ab const halfling::mod({-1, 0, 0, +1, 0, 0, 0});
ab const half_orc::mod({+1, 0, 0, 0, +1, -2, 0});
ab const human::mod({0, 0, 0, 0, 0, 0, 0});

mf const dwarf::min({ab({8, 3, 3, 3, 12, 3, 0}), //
                     ab({8, 3, 3, 3, 12, 3, 0})});

mf const dwarf::max({ab({18, 18, 18, 17, 19, 16, 0}),
                     ab({17, 18, 18, 17, 19, 16, 0})});

mf const elf::min({ab({3, 8, 3, 7, 6, 8, 0}), //
                   ab({3, 8, 3, 7, 6, 8, 0})});

mf const elf::max({ab({18, 18, 18, 19, 18, 18, 0}), //
                   ab({16, 18, 18, 19, 18, 18, 0})});

mf const gnome::min({ab({6, 7, 3, 3, 8, 3, 0}), //
                     ab({6, 7, 3, 3, 8, 3, 0})});

mf const gnome::max({ab({18, 18, 18, 18, 18, 18, 0}), //
                     ab({15, 18, 18, 18, 18, 18, 0})});

mf const half_elf::min({ab({3, 4, 3, 6, 6, 3, 0}), //
                        ab({3, 4, 3, 6, 6, 3, 0})});

mf const half_elf::max({ab({18, 18, 18, 18, 18, 18, 0}), //
                        ab({17, 18, 18, 18, 18, 18, 0})});

mf const halfling::min({ab({6, 6, 3, 8, 10, 3, 0}), //
                        ab({6, 6, 3, 8, 10, 3, 0})});

mf const halfling::max({ab({17, 18, 18, 18, 19, 18, 0}), //
                        ab({14, 18, 17, 18, 19, 18, 0})});

mf const half_orc::min({ab({6, 3, 3, 3, 13, 3, 0}), //
                        ab({6, 3, 3, 3, 13, 3, 0})});

mf const half_orc::max({ab({18, 17, 14, 17, 19, 12, 0}), //
                        ab({18, 17, 14, 17, 19, 12, 0})});

mf const human::min({ab({3, 3, 3, 3, 3, 3, 0}), //
                     ab({3, 3, 3, 3, 3, 3, 0})});

mf const human::max({ab({18, 18, 18, 18, 18, 18, 0}), //
                     ab({18, 18, 18, 18, 18, 18, 0})});

} // namespace race
} // namespace dungeon
