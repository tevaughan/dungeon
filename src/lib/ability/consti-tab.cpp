/// @file       lib/ability/consti-tab.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::abilities::consti_tab.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "consti-tab.hpp"

namespace dungeon {
namespace ability {

table<consti_rec> const &consti_tab() {
  static table<consti_rec> const t{
      {/***/ 3, consti_rec{-2, -2, 35, /***/ 40}},
      {/***/ 4, consti_rec{-1, -1, 40, /***/ 45}},
      {/***/ 5, consti_rec{-1, -1, 45, /***/ 50}},
      {/***/ 6, consti_rec{-1, -1, 50, /***/ 55}},
      {/***/ 7, consti_rec{+0, +0, 55, /***/ 60}},
      {/***/ 8, consti_rec{+0, +0, 60, /***/ 65}},
      {/***/ 9, consti_rec{+0, +0, 65, /***/ 70}},
      {/**/ 10, consti_rec{+0, +0, 70, /***/ 75}},
      {/**/ 11, consti_rec{+0, +0, 75, /***/ 80}},
      {/**/ 12, consti_rec{+0, +0, 80, /***/ 85}},
      {/**/ 13, consti_rec{+0, +0, 85, /***/ 90}},
      {/**/ 14, consti_rec{+0, +0, 88, /***/ 92}},
      {/**/ 15, consti_rec{+1, +1, 91, /***/ 94}},
      {/**/ 16, consti_rec{+2, +2, 95, /***/ 96}},
      {/**/ 17, consti_rec{+2, +3, 97, /***/ 98}},
      {/**/ 18, consti_rec{+2, +4, 99, /**/ 100}}, // 99 means all
  };
  return t;
}

} // namespace ability
} // namespace dungeon
