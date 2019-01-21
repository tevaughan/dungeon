/// @file       lib/ability/wisdom-tab.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::abilities::wisdom_tab.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "wisdom-tab.hpp"

namespace dungeon {
namespace ability {

table<wisdom_rec> const &wisdom_tab() {
  static table<wisdom_rec> const t{{/***/ 3, wisdom_rec{-3, 0, 0, /**/ 100}},
                                   {/***/ 4, wisdom_rec{-2, 0, 0, /**/ 100}},
                                   {/***/ 7, wisdom_rec{-1, 0, 0, /**/ 100}},
                                   {/***/ 8, wisdom_rec{+0, 0, 0, /**/ 100}},
                                   {/***/ 9, wisdom_rec{+0, 0, 5, /***/ 20}},
                                   {/**/ 10, wisdom_rec{+0, 0, 5, /***/ 15}},
                                   {/**/ 11, wisdom_rec{+0, 0, 5, /***/ 10}},
                                   {/**/ 12, wisdom_rec{+0, 0, 5, /****/ 5}},
                                   {/**/ 14, wisdom_rec{+0, 1, 5, /****/ 0}},
                                   {/**/ 15, wisdom_rec{+1, 2, 5, /****/ 0}},
                                   {/**/ 16, wisdom_rec{+2, 2, 5, /****/ 0}},
                                   {/**/ 17, wisdom_rec{+3, 3, 6, /****/ 0}},
                                   {/**/ 18, wisdom_rec{+4, 4, 7, /****/ 0}}};
  return t;
}

} // namespace ability
} // namespace dungeon
