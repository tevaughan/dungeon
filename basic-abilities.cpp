/// @file       basic-abilities.cpp
/// @author     Thomas E. Vaughan
/// @brief      Implementation of dungeon::abilities::basic.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "basic-abilities.hpp"
#include <iostream> // for cerr, endl
#include <map>      // for map

namespace dungeon {
namespace abilities {

// For looking up a record in each table below, map::lower_bound is used
// because the key for each record is the maximum ability-score corresponding
// to the record.  map::lower_bound finds the first element whose key is not
// less than the relevant ability-score in the instance of basic.  If there be
// no such element, then the ability-score in the instance is larger than the
// largest tabulated score; so the last record in the table is returned.

// Strength table.
st_features const &basic::st() const {
  static std::map<unsigned, st_features> const table{
      {/***/ 3000, st_features{-3, -1, /**/ -350, 1, 1, /***/ 0}},
      {/***/ 5000, st_features{-2, -1, /**/ -250, 1, 1, /***/ 0}},
      {/***/ 7000, st_features{-1, +0, /**/ -150, 1, 1, /***/ 0}},
      {/***/ 9000, st_features{+0, +0, /*****/ 0, 2, 1, /***/ 1}},
      {/**/ 11000, st_features{+0, +0, /*****/ 0, 2, 1, /***/ 2}},
      {/**/ 13000, st_features{+0, +0, /***/ 100, 2, 1, /***/ 4}},
      {/**/ 15000, st_features{+0, +0, /***/ 200, 2, 1, /***/ 7}},
      {/**/ 16000, st_features{+0, +1, /***/ 350, 3, 1, /**/ 10}},
      {/**/ 17000, st_features{+1, +1, /***/ 500, 3, 1, /**/ 13}},
      {/**/ 18000, st_features{+1, +2, /***/ 750, 3, 1, /**/ 16}},
      {/**/ 18050, st_features{+1, +3, /**/ 1000, 3, 1, /**/ 20}},
      {/**/ 18075, st_features{+2, +3, /**/ 1250, 4, 1, /**/ 25}},
      {/**/ 18090, st_features{+2, +4, /**/ 1500, 4, 1, /**/ 30}},
      {/**/ 18099, st_features{+2, +5, /**/ 2000, 4, 1, /**/ 35}},
      {/**/ 18100, st_features{+3, +6, /**/ 3000, 5, 2, /**/ 40}}};
  auto i = table.lower_bound(get(id::ST) * 1000 + get(id::ES));
  if (i == table.end()) {
    return table.rbegin()->second; // Use last record.
  }
  return i->second;
}

// Intelligence table.
#if 0
in_features const &basic::in() const {
  // TBS
}
#endif

} // namespace abilities
} // namespace dungeon
