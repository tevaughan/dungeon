/// @file       lib/ability/charis-tab.cpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::abilities::charis_tab.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "charis-tab.hpp"

namespace dungeon {
namespace ability {

table<charis_rec> const &charis_tab() {
  static table<charis_rec> const t{
      {/***/ 3, charis_rec{/***/ 1, /**/ -30, /**/ -25}},
      {/***/ 4, charis_rec{/***/ 1, /**/ -25, /**/ -20}},
      {/***/ 5, charis_rec{/***/ 2, /**/ -20, /**/ -15}},
      {/***/ 6, charis_rec{/***/ 2, /**/ -15, /**/ -10}},
      {/***/ 7, charis_rec{/***/ 3, /**/ -10, /***/ -5}},
      {/***/ 8, charis_rec{/***/ 3, /***/ -5, /***/ +0}},
      {/**/ 11, charis_rec{/***/ 4, /***/ +0, /***/ +0}},
      {/**/ 12, charis_rec{/***/ 5, /***/ +0, /***/ +0}},
      {/**/ 13, charis_rec{/***/ 5, /***/ +0, /***/ +5}},
      {/**/ 14, charis_rec{/***/ 6, /***/ +5, /**/ +10}},
      {/**/ 15, charis_rec{/***/ 7, /**/ +15, /**/ +15}},
      {/**/ 16, charis_rec{/***/ 8, /**/ +20, /**/ +25}},
      {/**/ 17, charis_rec{/**/ 10, /**/ +30, /**/ +30}},
      {/**/ 18, charis_rec{/**/ 15, /**/ +40, /**/ +35}}};
  return t;
}

} // namespace ability
} // namespace dungeon
