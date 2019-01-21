/// @file       lib/ability/dexter-tab.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::abilities::dexter_tab.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "dexter-tab.hpp"

namespace dungeon {
namespace ability {

table<dexter_rec> const &dexter_tab() {
  static table<dexter_rec> const t{
      {/***/ 3, dexter_rec{-3, +4, +00, +00, +00, +00, +00}},
      {/***/ 4, dexter_rec{-2, +3, +00, +00, +00, +00, +00}},
      {/***/ 5, dexter_rec{-1, +2, +00, +00, +00, +00, +00}},
      {/***/ 6, dexter_rec{+0, +1, +00, +00, +00, +00, +00}},
      {/***/ 8, dexter_rec{+0, +0, +00, +00, +00, +00, +00}},
      {/***/ 9, dexter_rec{+0, +0, -15, -10, -10, -20, -10}},
      {/**/ 10, dexter_rec{+0, +0, -10, -05, -10, -15, -05}},
      {/**/ 11, dexter_rec{+0, +0, -05, +00, -05, -10, +00}},
      {/**/ 12, dexter_rec{+0, +0, +00, +00, +00, -05, +00}},
      {/**/ 14, dexter_rec{+0, +0, +00, +00, +00, +00, +00}},
      {/**/ 15, dexter_rec{+0, -1, +00, +00, +00, +00, +00}},
      {/**/ 16, dexter_rec{+1, -2, +00, +05, +00, +00, +00}},
      {/**/ 17, dexter_rec{+2, -3, +05, +10, +00, +05, +05}},
      {/**/ 18, dexter_rec{+3, -4, +10, +15, +05, +10, +10}}};
  return t;
}

} // namespace ability
} // namespace dungeon
