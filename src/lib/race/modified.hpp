/// @file       lib/race/modified.hpp
/// @author     Thomas E. Vaughan
/// @brief      Declaration of dungeon::race::modified.
/// @copyright  2019 Thomas E. Vaughan
/// @license    GPL3; see 'LICENSE' file.

#ifndef DUNGEON_RACE_MODIFIED_HPP
#define DUNGEON_RACE_MODIFIED_HPP

#include "ability/initial.hpp" // for initial_abilities
#include "sex.hpp"
#include "species.hpp"

namespace dungeon {
namespace race {

struct modified : public ability::scores {
  enum { NSP = species::_size(), NSX = sex::_size() };
  using mods_array = std::array<array, NSP>;
  using lims_array = std::array<array, NSP * NSX>;
  static mods_array const mods;
  static lims_array const mins;
  static lims_array const maxs;

  /// According to biology, modify initial abilities, but only if initial
  /// abilities be consistent with the biology; otherwise, generate a set of
  /// abilities, every one of which is set to zero.
  ///
  /// @param i   Initial abilities.
  /// @param sp  Species of character.
  /// @param sx  Sex of character.
  modified(ability::initial i, species sp, sex sx);
};

} // namespace race
} // namespace dungeon

#endif // ndef DUNGEON_RACE_MODIFIED_HPP
