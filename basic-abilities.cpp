/// @file       basic-abilities.cpp
/// @author     Thomas E. Vaughan
/// @brief      Implementation of dungeon::abilities::basic.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "basic-abilities.hpp"
#include <iostream> // for cerr, endl

namespace dungeon {
namespace abilities {

/// Find offset of record in table of features for ability.
/// @tparam T  Type of table associating maximum ability-score with offset.
/// @param  m  Table associating maximum ability-score with offset.
/// @param  s  Ability-score whose offset is sought.
/// @return    Offset corresponding to ability-score.
template <typename T>
unsigned find_offset(unsigned min, T const &m, unsigned s) {
  if (s < min) {
    std::cerr << "ERROR: score=" << s << " < " << min << std::endl;
    throw "score too small";
  }
  // At the moment, linear search is used.  This could be optimized a bit.
  for (unsigned i = 0; i < m.size(); ++i) {
    if (m[i] >= s) {
      return i;
    }
  }
  std::cerr << "ERROR: score=" << s << std::endl;
  throw "score too large";
  return m.size() - 1;
}

st_features const &basic::st() const {
  enum : unsigned { NR = 15 }; // Number of records in table.

  static std::array<unsigned, NR> const max_score({/***/ 3000,
                                                   /***/ 5000,
                                                   /***/ 7000,
                                                   /***/ 9000,
                                                   /**/ 11000,
                                                   /**/ 13000,
                                                   /**/ 15000,
                                                   /**/ 16000,
                                                   /**/ 17000,
                                                   /**/ 18000,
                                                   /**/ 18050,
                                                   /**/ 18075,
                                                   /**/ 18090,
                                                   /**/ 18099,
                                                   /**/ 18100});

  static std::array<st_features, NR> const table(
      {st_features{-3, -1, /**/ -350, 1, 1, /***/ 0},
       st_features{-2, -1, /**/ -250, 1, 1, /***/ 0},
       st_features{-1, +0, /**/ -150, 1, 1, /***/ 0},
       st_features{+0, +0, /*****/ 0, 2, 1, /***/ 1},
       st_features{+0, +0, /*****/ 0, 2, 1, /***/ 2},
       st_features{+0, +0, /***/ 100, 2, 1, /***/ 4},
       st_features{+0, +0, /***/ 200, 2, 1, /***/ 7},
       st_features{+0, +1, /***/ 350, 3, 1, /**/ 10},
       st_features{+1, +1, /***/ 500, 3, 1, /**/ 13},
       st_features{+1, +2, /***/ 750, 3, 1, /**/ 16},
       st_features{+1, +3, /**/ 1000, 3, 1, /**/ 20},
       st_features{+2, +3, /**/ 1250, 4, 1, /**/ 25},
       st_features{+2, +4, /**/ 1500, 4, 1, /**/ 30},
       st_features{+2, +5, /**/ 2000, 4, 1, /**/ 35},
       st_features{+3, +6, /**/ 3000, 5, 2, /**/ 40}});

  unsigned const score  = get(id::ST) * 1000 + get(id::ES);
  unsigned const offset = find_offset(3000, max_score, score);
  return table[offset];
}

} // namespace abilities
} // namespace dungeon
