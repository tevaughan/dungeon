add_executable (tests
   ability-initial-test.cpp
   race-test.cpp
   roll-dice-test.cpp
   tests.cpp)

target_link_libraries (tests dungeon)
target_include_directories (tests PRIVATE ../lib)
