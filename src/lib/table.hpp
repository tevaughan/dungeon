/// @file       table.hpp
/// @author     Thomas E. Vaughan
/// @brief      Definition of dungeon::table
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_TABLE_HPP
#define DUNGEON_TABLE_HPP

#include <map> // for map

namespace dungeon {

/// Table whose key is an integer and whose value is some record of type R.
/// The key stored in the table for each record is the maximum value of the
/// search key corresponding to the record.
///
/// @tparam R  Type of each record (row) in table.
template <typename R> struct table: protected std::map<int, R> {
  using std::map<int, R>::map; ///< Expose ancestor's constructor.

  /// Look up record.
  /// @param  s  Search-key.
  /// @return    Record corresponding to key.
  R const &operator[](int s) const {
    // map::lower_bound finds the first element whose stored key is not less
    // than the search-key.
    auto i = this->lower_bound(s);
    if (i == this->end()) {
      // If there be no such element, then the search-key is larger than the
      // largest stored key; so the last record in the table is returned.
      return this->rbegin()->second;
    }
    return i->second;
  }
};

} // namespace dungeon

#endif // ndef DUNGEON_TABLE_HPP
