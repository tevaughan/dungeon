cmake_minimum_required (VERSION 3.7)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) # For youcompleteme.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O0 -std=c++14")
project (Dungeon)
aux_source_directory(. Dungeon_SRCS)
include_directories(.)
add_executable(tests ${Dungeon_SRCS})
add_custom_target(format for i in *.cpp *.hpp\; do clang-format -i $$i\; done)
