add_executable (tests
   initial-abilities-test.cpp
   race-test.cpp
   roll-dice-test.cpp
   tests.cpp)

target_link_libraries (tests dungeon)
target_include_directories (tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_directories (tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
