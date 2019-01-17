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

using ab = race::ab;
using mf = std::array<ab, 2>;

ab const dwarf::mod({0, 0, 0, 0, +1, -1});
ab const elf::mod({0, 0, 0, +1, -1, 0});
ab const gnome::mod({0, 0, 0, 0, 0, 0});
ab const half_elf::mod({0, 0, 0, 0, 0, 0});
ab const halfling::mod({-1, 0, 0, +1, 0, 0});
ab const half_orc::mod({+1, 0, 0, 0, +1, -2});
ab const human::mod({0, 0, 0, 0, 0, 0});

mf const dwarf::min({ab({8, 3, 3, 3, 12, 3}), //
                     ab({8, 3, 3, 3, 12, 3})});

mf const dwarf::max({ab({18, 18, 18, 17, 19, 16}),
                     ab({17, 18, 18, 17, 19, 16})});

mf const elf::min({ab({3, 8, 3, 7, 6, 8}), //
                   ab({3, 8, 3, 7, 6, 8})});

mf const elf::max({ab({18, 18, 18, 19, 18, 18}), //
                   ab({16, 18, 18, 19, 18, 18})});

mf const gnome::min({ab({6, 7, 3, 3, 8, 3}), //
                     ab({6, 7, 3, 3, 8, 3})});

mf const gnome::max({ab({18, 18, 18, 18, 18, 18}), //
                     ab({15, 18, 18, 18, 18, 18})});

mf const half_elf::min({ab({3, 4, 3, 6, 6, 3}), //
                        ab({3, 4, 3, 6, 6, 3})});

mf const half_elf::max({ab({18, 18, 18, 18, 18, 18}), //
                        ab({17, 18, 18, 18, 18, 18})});

mf const halfling::min({ab({6, 6, 3, 8, 10, 3}), //
                        ab({6, 6, 3, 8, 10, 3})});

mf const halfling::max({ab({17, 18, 18, 18, 19, 18}), //
                        ab({14, 18, 17, 18, 19, 18})});

mf const half_orc::min({ab({6, 3, 3, 3, 13, 3}), //
                        ab({6, 3, 3, 3, 13, 3})});

mf const half_orc::max({ab({18, 17, 14, 17, 19, 12}), //
                        ab({18, 17, 14, 17, 19, 12})});

mf const human::min({ab({3, 3, 3, 3, 3, 3}), //
                     ab({3, 3, 3, 3, 3, 3})});

mf const human::max({ab({18, 18, 18, 18, 18, 18}), //
                     ab({18, 18, 18, 18, 18, 18})});

} // namespace race
} // namespace dungeon
