/// @file       basic-abilities.cpp
/// @author     Thomas E. Vaughan
/// @brief      Implementation of dungeon::abilities::basic.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "basic-abilities.hpp"

namespace dungeon {
namespace abilities {

st_features const &basic::st() const {
  enum { NR = 15 }; // Number of records in table.
  static std::array<st_features, NR> const table(
      {st_features{-3, -1, /***/ -350, 1, 1, /***/ 0},
       st_features{-2, -1, /***/ -250, 1, 1, /***/ 0},
       st_features{-1, +0, /***/ -150, 1, 1, /***/ 0},
       st_features{+0, +0, /*****/ +0, 2, 1, /***/ 1},
       st_features{+0, +0, /*****/ +0, 2, 1, /***/ 2},
       st_features{+0, +0, /***/ +100, 2, 1, /***/ 4},
       st_features{+0, +0, /***/ +200, 2, 1, /***/ 7},
       st_features{+0, +1, /***/ +350, 3, 1, /**/ 10},
       st_features{+1, +1, /***/ +500, 3, 1, /**/ 13},
       st_features{+1, +2, /***/ +750, 3, 1, /**/ 16},
       st_features{+1, +3, /**/ +1000, 3, 1, /**/ 20},
       st_features{+2, +3, /**/ +1250, 4, 1, /**/ 25},
       st_features{+2, +4, /**/ +1500, 4, 1, /**/ 30},
       st_features{+2, +5, /**/ +2000, 4, 1, /**/ 35},
       st_features{+3, +6, /**/ +3000, 5, 2, /**/ 40}});
  return table[0];
}

} // namespace abilities
} // namespace dungeon
