/// @file       lib/ability/streng-tab.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::abilities::streng_tab.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "streng-tab.hpp"

namespace dungeon {
namespace ability {

table<streng_rec> const &streng_tab() {
  static table<streng_rec> const t{
      {/***/ 3000, streng_rec{-3, -1, /**/ -350, 1, 1, /***/ 0}},
      {/***/ 5000, streng_rec{-2, -1, /**/ -250, 1, 1, /***/ 0}},
      {/***/ 7000, streng_rec{-1, +0, /**/ -150, 1, 1, /***/ 0}},
      {/***/ 9000, streng_rec{+0, +0, /*****/ 0, 2, 1, /***/ 1}},
      {/**/ 11000, streng_rec{+0, +0, /*****/ 0, 2, 1, /***/ 2}},
      {/**/ 13000, streng_rec{+0, +0, /***/ 100, 2, 1, /***/ 4}},
      {/**/ 15000, streng_rec{+0, +0, /***/ 200, 2, 1, /***/ 7}},
      {/**/ 16000, streng_rec{+0, +1, /***/ 350, 3, 1, /**/ 10}},
      {/**/ 17000, streng_rec{+1, +1, /***/ 500, 3, 1, /**/ 13}},
      {/**/ 18000, streng_rec{+1, +2, /***/ 750, 3, 1, /**/ 16}},
      {/**/ 18050, streng_rec{+1, +3, /**/ 1000, 3, 1, /**/ 20}},
      {/**/ 18075, streng_rec{+2, +3, /**/ 1250, 4, 1, /**/ 25}},
      {/**/ 18090, streng_rec{+2, +4, /**/ 1500, 4, 1, /**/ 30}},
      {/**/ 18099, streng_rec{+2, +5, /**/ 2000, 4, 1, /**/ 35}},
      {/**/ 18100, streng_rec{+3, +6, /**/ 3000, 5, 2, /**/ 40}}};
  return t;
}

} // namespace ability
} // namespace dungeon
