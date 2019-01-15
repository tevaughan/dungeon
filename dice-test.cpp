/// @file       dice-test.cpp
/// @author     Thomas E. Vaughan
/// @brief      Test of functions in dungeon::dice.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#include "dice.hpp"
#include "catch.hpp" // for TEST_CASE
#include <cmath>     // for sqrt
#include <cstdio>    // for printf
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
  /// @param s  Seed for random-number generation; by default use time().
  roll_sequence(unsigned n, unsigned d, unsigned f, unsigned s = 0):
      vector<unsigned>(n) {
    dice::init(s);
    for (auto &e : *this) {
      e = dice::roll(d, f);
    }
  }
};

TEST_CASE("Seed must be repeated to repeat sequence.", "[dice]") {
  enum { N = 20, D = 3, F = 6 };
  roll_sequence const r1(N, D, F, 10);
  roll_sequence const r2(N, D, F, 10);
  REQUIRE(r1 == r2);
  roll_sequence const r3(N, D, F, 11);
  REQUIRE(r1 != r3);
  roll_sequence const r4(N, D, F);
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

TEST_CASE("Bell curve is produced for 3d6.", "[dice]") {
  enum { N = 100000, D = 3, F = 6, MAX = D * F, MIN = D, SZ = MAX - MIN + 1 };
  double constexpr NSD = 4.0;
  vector<unsigned>    h(SZ, 0);
  roll_sequence const r(N, D, F);
  for (auto e : r) {
    ++h[e - D]; // Add element to histogram.
  }
  double min = N, max = 0;
  for (unsigned i = 0; i < SZ / 2; ++i) {
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
  printf("\n");
  for (unsigned i = 0; i < SZ; ++i) {
    unsigned const k = i + 3;
    printf("%02d ", k);
    double constexpr MAX_W = 69.99; // Histogram width in characters.
    double const   c       = MAX_W / (max - min);
    double const   s       = c * NSD * stdev(h[i], N);
    double const   m       = c * (h[i] - min);
    double const   z       = c * (0 - min);
    unsigned const im      = unsigned(m);
    unsigned const il      = unsigned(m - s);
    unsigned const ih      = unsigned(m + s);
    unsigned const iz      = unsigned(z);
    for (unsigned j = 0; j <= ih; ++j) {
      if (j == im) {
        printf("#");
        continue;
      }
      if (j == il || j == ih) {
        printf("|");
        continue;
      }
      if (j > il && j < ih) {
        printf("-");
        continue;
      }
      if (j == iz) {
        printf("z");
        continue;
      }
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}
