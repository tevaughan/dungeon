add_subdirectory (ability)
add_subdirectory (race)

add_library (dungeon SHARED
   roll-dice.cpp)

target_include_directories (dungeon PRIVATE .)
target_link_libraries (dungeon ability race)
