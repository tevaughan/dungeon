/// @file       basic-abilities.cpp
/// @author     Thomas E. Vaughan
/// @brief      Implementation of dungeon::abilities::basic.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "basic-abilities.hpp"
#include "table.hpp"
#include <iostream> // for cerr, endl

namespace dungeon {
namespace abilities {

// Query strength-table.
st_features const &basic::st() const {
  static table<st_features> const t{
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
  return t[get(id::ST) * 1000 + get(id::ES)];
}

// Query intelligence-table.
in_features const &basic::in() const {
  static table<in_features> const t{
      {/***/ 7, in_features{0, /***/ 0, /***/ 0, /***/ 0}},
      {/***/ 8, in_features{1, /***/ 0, /***/ 0, /***/ 0}},
      {/***/ 9, in_features{1, /**/ 35, /***/ 4, /***/ 6}},
      {/**/ 11, in_features{2, /**/ 45, /***/ 5, /***/ 7}},
      {/**/ 12, in_features{3, /**/ 45, /***/ 5, /***/ 7}},
      {/**/ 13, in_features{3, /**/ 55, /***/ 6, /***/ 9}},
      {/**/ 14, in_features{4, /**/ 55, /***/ 6, /***/ 9}},
      {/**/ 15, in_features{4, /**/ 65, /***/ 7, /**/ 11}},
      {/**/ 16, in_features{5, /**/ 65, /***/ 7, /**/ 11}},
      {/**/ 17, in_features{6, /**/ 75, /***/ 8, /**/ 14}},
      {/**/ 18, in_features{7, /**/ 85, /***/ 9, /**/ 18}},
      {/**/ 19, in_features{7, /**/ 95, /**/ 10, /**/ 99}}}; // 99 means all.
  return t[get(id::IN)];
}

// Query wisdom-table.
ws_features const &basic::ws() const {
  static table<ws_features> const t{
      {/***/ 3, ws_features{-3, 0, 0, /**/ 100}},
      {/***/ 4, ws_features{-2, 0, 0, /**/ 100}},
      {/***/ 7, ws_features{-1, 0, 0, /**/ 100}},
      {/***/ 8, ws_features{+0, 0, 0, /**/ 100}},
      {/***/ 9, ws_features{+0, 0, 5, /***/ 20}},
      {/**/ 10, ws_features{+0, 0, 5, /***/ 15}},
      {/**/ 11, ws_features{+0, 0, 5, /***/ 10}},
      {/**/ 12, ws_features{+0, 0, 5, /****/ 5}},
      {/**/ 14, ws_features{+0, 1, 5, /****/ 0}},
      {/**/ 15, ws_features{+1, 2, 5, /****/ 0}},
      {/**/ 16, ws_features{+2, 2, 5, /****/ 0}},
      {/**/ 17, ws_features{+3, 3, 6, /****/ 0}},
      {/**/ 18, ws_features{+4, 4, 7, /****/ 0}}};
  return t[get(id::WS)];
}

// Query dexterity-table.
dx_features const &basic::dx() const {
  static table<dx_features> const t{
      {/***/ 3, dx_features{-3, +4, +00, +00, +00, +00, +00}},
      {/***/ 4, dx_features{-2, +3, +00, +00, +00, +00, +00}},
      {/***/ 5, dx_features{-1, +2, +00, +00, +00, +00, +00}},
      {/***/ 6, dx_features{+0, +1, +00, +00, +00, +00, +00}},
      {/***/ 8, dx_features{+0, +0, +00, +00, +00, +00, +00}},
      {/***/ 9, dx_features{+0, +0, -15, -10, -10, -20, -10}},
      {/**/ 10, dx_features{+0, +0, -10, -05, -10, -15, -05}},
      {/**/ 11, dx_features{+0, +0, -05, +00, -05, -10, +00}},
      {/**/ 12, dx_features{+0, +0, +00, +00, +00, -05, +00}},
      {/**/ 14, dx_features{+0, +0, +00, +00, +00, +00, +00}},
      {/**/ 15, dx_features{+0, -1, +00, +00, +00, +00, +00}},
      {/**/ 16, dx_features{+1, -2, +00, +05, +00, +00, +00}},
      {/**/ 17, dx_features{+2, -3, +05, +10, +00, +05, +05}},
      {/**/ 18, dx_features{+3, -4, +10, +15, +05, +10, +10}}};
  return t[get(id::DX)];
}

// Query constitution-table.
cn_features const &basic::cn() const {
  static table<cn_features> const t{
      {/***/ 3, cn_features{-2, -2, 35, /***/ 40}},
      {/***/ 4, cn_features{-1, -1, 40, /***/ 45}},
      {/***/ 5, cn_features{-1, -1, 45, /***/ 50}},
      {/***/ 6, cn_features{-1, -1, 50, /***/ 55}},
      {/***/ 7, cn_features{+0, +0, 55, /***/ 60}},
      {/***/ 8, cn_features{+0, +0, 60, /***/ 65}},
      {/***/ 9, cn_features{+0, +0, 65, /***/ 70}},
      {/**/ 10, cn_features{+0, +0, 70, /***/ 75}},
      {/**/ 11, cn_features{+0, +0, 75, /***/ 80}},
      {/**/ 12, cn_features{+0, +0, 80, /***/ 85}},
      {/**/ 13, cn_features{+0, +0, 85, /***/ 90}},
      {/**/ 14, cn_features{+0, +0, 88, /***/ 92}},
      {/**/ 15, cn_features{+1, +1, 91, /***/ 94}},
      {/**/ 16, cn_features{+2, +2, 95, /***/ 96}},
      {/**/ 17, cn_features{+2, +3, 97, /***/ 98}},
      {/**/ 18, cn_features{+2, +4, 99, /**/ 100}},
  };
  return t[get(id::CN)];
}

// Query charisma-table.
ch_features const &basic::ch() const {
  static table<ch_features> const t{
      {/***/ 3, ch_features{/***/ 1, /**/ -30, /**/ -25}},
      {/***/ 4, ch_features{/***/ 1, /**/ -25, /**/ -20}},
      {/***/ 5, ch_features{/***/ 2, /**/ -20, /**/ -15}},
      {/***/ 6, ch_features{/***/ 2, /**/ -15, /**/ -10}},
      {/***/ 7, ch_features{/***/ 3, /**/ -10, /***/ -5}},
      {/***/ 8, ch_features{/***/ 3, /***/ -5, /***/ +0}},
      {/**/ 11, ch_features{/***/ 4, /***/ +0, /***/ +0}},
      {/**/ 12, ch_features{/***/ 5, /***/ +0, /***/ +0}},
      {/**/ 13, ch_features{/***/ 5, /***/ +0, /***/ +5}},
      {/**/ 14, ch_features{/***/ 6, /***/ +5, /**/ +10}},
      {/**/ 15, ch_features{/***/ 7, /**/ +15, /**/ +15}},
      {/**/ 16, ch_features{/***/ 8, /**/ +20, /**/ +25}},
      {/**/ 17, ch_features{/**/ 10, /**/ +30, /**/ +30}},
      {/**/ 18, ch_features{/**/ 15, /**/ +40, /**/ +35}}};
  return t[get(id::CH)];
}

} // namespace abilities
} // namespace dungeon
