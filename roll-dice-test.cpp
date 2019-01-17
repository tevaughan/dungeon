/// @file       roll-dice-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Tests of function dungeon::roll_dice.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "roll-dice.hpp"
#include "catch.hpp" // for TEST_CASE
#include <cmath>     // for sqrt
#include <cstdio>    // for printf
#include <ctime>     // for time
#include <vector>    // for vector

using namespace dungeon;
using namespace std;

/// A sequence of rolls, each involving a certain number of dice, every one of
/// which has the same number of facets.
struct roll_sequence: public vector<unsigned> {
  /// Initialize the value of each roll in the sequence.
  /// @param n  Number of rolls.
  /// @param d  Number of dice on each roll.
  /// @param f  Number of facets on each die.
  /// @param s  Reference to state of random-number generator.
  roll_sequence(unsigned n, unsigned d, unsigned f, unsigned &s):
      vector<unsigned>(n) {
    for (auto &e : *this) {
      e = roll_dice(d, f, s);
    }
  }
};

TEST_CASE("Seed must be repeated to repeat sequence.", "[dice]") {
  enum { N = 20, D = 3, F = 6 };
  unsigned            s = 10;
  roll_sequence const r1(N, D, F, s);
  s = 10;
  roll_sequence const r2(N, D, F, s);
  REQUIRE(r1 == r2);
  roll_sequence const r3(N, D, F, s);
  REQUIRE(r1 != r3);
  s = time(nullptr);
  roll_sequence const r4(N, D, F, s);
  REQUIRE(r1 != r4);
  REQUIRE(r3 != r4);
}

/// Estimated variance of number of counts in cell in histogram.
/// @param nk  Number of counts in cell k in histogram.
/// @param n   Total number of counts in histogram.
/// @return    Estimated variance for case of equal weights.
double var(double nk, double n) { return nk * (1.0 - nk / n); }

/// Estimated standard deviation of number of counts in cell in histogram.
/// @param nk  Number of counts in cell k in histogram.
/// @param n   Total number of counts in histogram.
/// @return    Estimate standard deviation for case of equal weights.
double stdev(double nk, double n) { return sqrt(var(nk, n)); }

/// Number of standard deviations of tolerance for bell-curve test.
double constexpr NSD = 4.0;

/// Total number of counts for histogram in bell-curve test.
unsigned constexpr N = 1000;

/// Number of dice used in each roll in bell-curve test.
unsigned constexpr D = 3;

/// Minimum and maximum values for coordinates in counts-space in
/// histogram-plot of bell-curve.
struct hlim {
  double min; ///< Minimum coordinate (counts).
  double max; ///< Maximum coordinate (counts).

  /// Initialize values so that first call to update() is guaranteed to change
  /// both limits.
  hlim(): min(N), max(0) {}

  /// Update min and max.
  ///
  /// Passed in is a pair of counts, each corresponding to one of the two cells
  /// at the same distance from what should be the center of symmetry for the
  /// distribution in the histogram.
  ///
  /// @param nl   Number of counts at cell left of center.
  /// @param nr   Number of counts at cell left of center.
  void update(double nl, double nr) {
    double const sl = NSD * stdev(nl, N);
    double const sr = NSD * stdev(nr, N);
    if (nl + sl > max) {
      max = nl + sl;
    }
    if (nr + sr > max) {
      max = nr + sr;
    }
    if (nl - sl < min) {
      min = nl - sl;
    }
    if (nr - sr < min) {
      min = nr - sr;
    }
  }
};

/// Draw histogram that is used in bell-curve test.
/// @param sz   Number of cells in histogram.
/// @param lim  Limits of drawing in counts-space.
/// @param h    Data for histogram.
void draw_histogram(unsigned sz, hlim const &lim, vector<unsigned> const &h) {
  printf("\n");
  for (unsigned i = 0; i < sz; ++i) {
    unsigned const k = i + D;
    printf("%02d ", k);
    double constexpr MAX_W = 69.99; // Histogram width in characters.
    double const   c       = MAX_W / (lim.max - lim.min);
    double const   s       = c * NSD * stdev(h[i], N);
    double const   m       = c * (h[i] - lim.min);
    unsigned const im      = unsigned(m);
    unsigned const il      = unsigned(m - s);
    unsigned const ih      = unsigned(m + s);
    unsigned const iz      = unsigned(c * (0 - lim.min));
    for (unsigned j = 0; j <= ih; ++j) {
      if (j == im) {
        printf("#");
      } else if (j == iz) {
        printf("z");
      } else if (j == il || j == ih) {
        printf("|");
      } else if (j > il && j < ih) {
        printf("-");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

TEST_CASE("Bell curve is produced for 3d6.", "[dice]") {
  enum { /* facets */ F = 6, MAX = D * F, MIN = D, SZ = MAX - MIN + 1 };
  vector<unsigned>    h(SZ, 0);
  unsigned            s = time(nullptr);
  roll_sequence const r(N, D, F, s);
  for (auto &e : r) {
    ++h[e - D]; // Add element to histogram.
  }
  hlim limits;
  // Adding one to SZ before dividing by two allows test to work for either
  // even or odd SZ.
  for (unsigned i = 0; i < (SZ + 1) / 2; ++i) {
    // Test symmetry of distribution.
    unsigned const j  = SZ - i - 1;
    double const   nl = h[i];
    double const   nr = h[j];
    double const   vl = var(nl, N);
    double const   vr = var(nr, N);
    REQUIRE(fabs(nl - nr) <= NSD * sqrt(vl + vr));
    if (i > 0) {
      // Test monotonicity of each wing.
      double const nll = h[i - 1];
      double const nrr = h[j + 1];
      REQUIRE(nl >= nll - NSD * sqrt(vl + var(nll, N)));
      REQUIRE(nr >= nrr - NSD * sqrt(vr + var(nrr, N)));
    }
    limits.update(nl, nr);
  }
  draw_histogram(SZ, limits, h);
}
