cmake_minimum_required (VERSION 3.7)
project (Dungeon)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) # For youcompleteme.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O0 -std=c++14")
aux_source_directory(. Dungeon_SRCS)
include_directories(.)
add_executable(tests ${Dungeon_SRCS})

# Make format target that runs clang-format on sources.
add_custom_target(format
   cd ${CMAKE_SOURCE_DIR}\;
   for i in *.cpp *.hpp\; do
      clang-format -i $$i\;
   done)

# Make dox target that runs doxygen.
add_custom_target(dox
   cd ${CMAKE_SOURCE_DIR}\;
   doxygen)

find_program(SYMLINKS symlinks)
if (NOT SYMLINKS)
   message("symlinks program not found; symlinks will not be relativized.")
   set (SYMLINKS "")
endif ()

# Generate link so that vim can find database in source directory.
add_custom_target(ycm_db ALL
   cd ${CMAKE_SOURCE_DIR}\;
   ln -fs ${CMAKE_BINARY_DIR}/compile_commands.json\;
   if test -x ${SYMLINKS}\; then ${SYMLINKS} -c .\; fi)

# Make it so that html and latex directories are removed on clean.
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
   "${CMAKE_SOURCE_DIR}/html"
   "${CMAKE_SOURCE_DIR}/latex"
   "${CMAKE_SOURCE_DIR}/compile_commands.json")
