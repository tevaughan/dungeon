set (CMAKE_EXPORT_COMPILE_COMMANDS ON) # For youcompleteme.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -O0 -std=c++14")

include_directories(.)
aux_source_directory(. dungeon_SRCS)
add_executable(tests ${dungeon_SRCS})

# Make format target that runs clang-format on sources.
add_custom_target(format
   cd ${CMAKE_CURRENT_SOURCE_DIR}\;
   for i in *.cpp *.hpp\; do
      clang-format -i $$i\;
   done)

find_program(SYMLINKS symlinks)
if (NOT SYMLINKS)
   message("symlinks program not found; symlinks will not be relativized.")
   set (SYMLINKS "")
endif ()

# Generate link so that vim can find database in source directory.
add_custom_target(ycm_db ALL
   cd ${CMAKE_CURRENT_SOURCE_DIR}\;
   ln -fs ${CMAKE_BINARY_DIR}/compile_commands.json\;
   if test -x ${SYMLINKS}\; then ${SYMLINKS} -c .\; fi)

# Make it so that 'compile_commands.json' is removed on clean.
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
   "${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json")
