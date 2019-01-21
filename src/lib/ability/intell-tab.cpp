/// @file       lib/ability/intell-tab.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::abilities::intell_tab.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "intell-tab.hpp"

namespace dungeon {
namespace ability {

table<intell_rec> const &intell_tab() {
  static table<intell_rec> const t{
      {/***/ 7, intell_rec{0, /***/ 0, /***/ 0, /***/ 0}},
      {/***/ 8, intell_rec{1, /***/ 0, /***/ 0, /***/ 0}},
      {/***/ 9, intell_rec{1, /**/ 35, /***/ 4, /***/ 6}},
      {/**/ 11, intell_rec{2, /**/ 45, /***/ 5, /***/ 7}},
      {/**/ 12, intell_rec{3, /**/ 45, /***/ 5, /***/ 7}},
      {/**/ 13, intell_rec{3, /**/ 55, /***/ 6, /***/ 9}},
      {/**/ 14, intell_rec{4, /**/ 55, /***/ 6, /***/ 9}},
      {/**/ 15, intell_rec{4, /**/ 65, /***/ 7, /**/ 11}},
      {/**/ 16, intell_rec{5, /**/ 65, /***/ 7, /**/ 11}},
      {/**/ 17, intell_rec{6, /**/ 75, /***/ 8, /**/ 14}},
      {/**/ 18, intell_rec{7, /**/ 85, /***/ 9, /**/ 18}},
      {/**/ 19, intell_rec{7, /**/ 95, /**/ 10, /**/ 99}}}; // 99 means all.
  return t;
}

} // namespace ability
} // namespace dungeon
