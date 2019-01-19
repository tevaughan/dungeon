cmake_minimum_required (VERSION 3.7)
project (dungeon)
add_subdirectory (src)

# Make dox target that runs doxygen.
add_custom_target(dox
   cd ${CMAKE_SOURCE_DIR}\;
   doxygen)

# Make it so that html and latex directories are removed on clean.
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
   "${CMAKE_SOURCE_DIR}/html"
   "${CMAKE_SOURCE_DIR}/latex")
