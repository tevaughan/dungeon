/// @file       lib/race/modified.cpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::race::mods,
///             dungeon::race::mins,
///             dungeon::race::maxs,
///             dungeon::race::modified.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "modified.hpp"

namespace dungeon {
namespace race {

modified::mods_array const modified::mods{
    array{+0, +0, +0, +0, +1, -1, +0}, // dwarf
    array{+0, +0, +0, +1, -1, +0, +0}, // elf
    array{+0, +0, +0, +0, +0, +0, +0}, // gnome
    array{+0, +0, +0, +0, +0, +0, +0}, // half-elf
    array{-1, +0, +0, +1, +0, +0, +0}, // halfling
    array{+1, +0, +0, +0, +1, -2, +0}, // half-orc
    array{+0, +0, +0, +0, +0, +0, +0}  // human
};

modified::lims_array const modified::mins{
    array{8, 3, 3, 3, /**/ 12, 3, 0}, // dwarf male
    array{8, 3, 3, 3, /**/ 12, 3, 0}, // dwarf female
    array{3, 8, 3, 7, /***/ 6, 8, 0}, // elf male
    array{3, 8, 3, 7, /***/ 6, 8, 0}, // elf female
    array{6, 7, 3, 3, /***/ 8, 3, 0}, // gnome male
    array{6, 7, 3, 3, /***/ 8, 3, 0}, // gnome female
    array{3, 4, 3, 6, /***/ 6, 3, 0}, // half-elf male
    array{3, 4, 3, 6, /***/ 6, 3, 0}, // half-elf female
    array{6, 6, 3, 8, /**/ 10, 3, 0}, // halfling male
    array{6, 6, 3, 8, /**/ 10, 3, 0}, // halfling female
    array{6, 3, 3, 3, /**/ 13, 3, 0}, // half-orc male
    array{6, 3, 3, 3, /**/ 13, 3, 0}, // half-orc female
    array{3, 3, 3, 3, /***/ 3, 3, 0}, // human male
    array{3, 3, 3, 3, /***/ 3, 3, 0}  // human female
};

modified::lims_array const modified::maxs{
    array{18, 18, 18, 17, 19, 16, 0}, // dwarf male
    array{17, 18, 18, 17, 19, 16, 0}, // dwarf female
    array{18, 18, 18, 19, 18, 18, 0}, // elf male
    array{16, 18, 18, 19, 18, 18, 0}, // elf female
    array{18, 18, 18, 18, 18, 18, 0}, // gnome male
    array{15, 18, 18, 18, 18, 18, 0}, // gnome female
    array{18, 18, 18, 18, 18, 18, 0}, // half-elf male
    array{17, 18, 18, 18, 18, 18, 0}, // half-elf female
    array{17, 18, 18, 18, 19, 18, 0}, // halfling male
    array{14, 18, 17, 18, 19, 18, 0}, // halfling female
    array{18, 17, 14, 17, 19, 12, 0}, // half-orc male
    array{18, 17, 14, 17, 19, 12, 0}, // half-orc female
    array{18, 18, 18, 18, 18, 18, 0}, // human male
    array{18, 18, 18, 18, 18, 18, 0}  // human female
};

modified::modified(ability::initial i, species sp, sex sx) {
  array const &tmods = mods[sp];
  array const &tmins = mins[NSX * sp + sx];
  array const &tmaxs = maxs[NSX * sp + sx];
  for (auto aid : ability::id::_values()) {
    set(aid, i[aid] + tmods[aid]);
    if (get(aid) < tmins[aid]) {
      // Indicate inconsistency.
      a_ = {0, 0, 0, 0, 0, 0, 0};
      return;
    }
    if (get(aid) > tmaxs[aid]) {
      set(aid, tmaxs[aid]);
    }
  }
}

} // namespace race
} // namespace dungeon
