/// @file       lib/race.cpp
/// @author     Thomas E. Vaughan
///
/// @brief      Definition of
///             dungeon::race::ab,
///             dungeon::race::mods,
///             dungeon::race::mins,
///             dungeon::race::maxs,
///             dungeon::race::modify.
///
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "race.hpp"

namespace dungeon {
namespace race {

/// Allow easy setting of abilities.
class ab : public ability::scores {
public:
  ab(array a) { a_ = a; } ///< Copy abilities from array.
  ab() = default;         ///< Allow default construction.
  using scores::set;      ///< Allow setting elements.
  /// Return reference to this as parent-type.
  scores const &basic() const { return *this; }
};

/// Extract modifiers by species.
static ab const &mods(species s) {
  using mod_array = std::array<ab, species::_size()>;
  static mod_array const m{
      ab{{+0, +0, +0, +0, +1, -1, +0}}, // dwarf
      ab{{+0, +0, +0, +1, -1, +0, +0}}, // elf
      ab{{+0, +0, +0, +0, +0, +0, +0}}, // gnome
      ab{{+0, +0, +0, +0, +0, +0, +0}}, // half-elf
      ab{{-1, +0, +0, +1, +0, +0, +0}}, // halfling
      ab{{+1, +0, +0, +0, +1, -2, +0}}, // half-orc
      ab{{+0, +0, +0, +0, +0, +0, +0}}  // human
  };
  return m[s._to_integral()];
}

enum { NSP = species::_size(), NSX = sex::_size() }; ///< Short-hand.

/// Extract minima by species and sex.
static ab const &mins(species sp, sex sx) {
  using mins_array = std::array<ab, NSP * NSX>;
  static mins_array const m{
      ab({8, 3, 3, 3, /**/ 12, 3, 0}), // dwarf male
      ab({8, 3, 3, 3, /**/ 12, 3, 0}), // dwarf female
      ab({3, 8, 3, 7, /***/ 6, 8, 0}), // elf male
      ab({3, 8, 3, 7, /***/ 6, 8, 0}), // elf female
      ab({6, 7, 3, 3, /***/ 8, 3, 0}), // gnome male
      ab({6, 7, 3, 3, /***/ 8, 3, 0}), // gnome female
      ab({3, 4, 3, 6, /***/ 6, 3, 0}), // half-elf male
      ab({3, 4, 3, 6, /***/ 6, 3, 0}), // half-elf female
      ab({6, 6, 3, 8, /**/ 10, 3, 0}), // halfling male
      ab({6, 6, 3, 8, /**/ 10, 3, 0}), // halfling female
      ab({6, 3, 3, 3, /**/ 13, 3, 0}), // half-orc male
      ab({6, 3, 3, 3, /**/ 13, 3, 0}), // half-orc female
      ab({3, 3, 3, 3, /***/ 3, 3, 0}), // human male
      ab({3, 3, 3, 3, /***/ 3, 3, 0})  // human female
  };
  return m[sp._to_integral() * NSX + sx._to_integral()];
}

/// Extract maxima by species and sex.
static ab const &maxs(species sp, sex sx) {
  using maxs_array = std::array<ab, NSP * NSX>;
  static maxs_array const m{
      ab({18, 18, 18, 17, 19, 16, 0}), // dwarf male
      ab({17, 18, 18, 17, 19, 16, 0}), // dwarf female
      ab({18, 18, 18, 19, 18, 18, 0}), // elf male
      ab({16, 18, 18, 19, 18, 18, 0}), // elf female
      ab({18, 18, 18, 18, 18, 18, 0}), // gnome male
      ab({15, 18, 18, 18, 18, 18, 0}), // gnome female
      ab({18, 18, 18, 18, 18, 18, 0}), // half-elf male
      ab({17, 18, 18, 18, 18, 18, 0}), // half-elf female
      ab({17, 18, 18, 18, 19, 18, 0}), // halfling male
      ab({14, 18, 17, 18, 19, 18, 0}), // halfling female
      ab({18, 17, 14, 17, 19, 12, 0}), // half-orc male
      ab({18, 17, 14, 17, 19, 12, 0}), // half-orc female
      ab({18, 18, 18, 18, 18, 18, 0}), // human male
      ab({18, 18, 18, 18, 18, 18, 0})  // human female
  };
  return m[sp._to_integral() * NSX + sx._to_integral()];
}

ability::scores modify(ability::initial i, species sp, sex sx) {
  ab const &tmods = mods(sp);
  ab const &tmins = mins(sp, sx);
  ab const &tmaxs = maxs(sp, sx);
  ab r; // Return value.
  for (auto aid : ability::id::_values()) {
    r.set(aid, i[aid] + tmods[aid]);
    if (r[aid] < tmins[aid]) {
      // Indicate inconsistency.
      ab const a({0, 0, 0, 0, 0, 0, 0});
      return a.basic();
    }
    if (r[aid] > tmaxs[aid]) {
      r.set(aid, tmaxs[aid]);
    }
  }
  return r.basic();
}

} // namespace race
} // namespace dungeon
