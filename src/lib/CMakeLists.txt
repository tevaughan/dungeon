add_subdirectory (abilities)

add_library (dungeon SHARED
   race.cpp
   roll-dice.cpp)

target_include_directories (dungeon PRIVATE .)
target_link_libraries (dungeon abilities)
