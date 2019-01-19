cmake_minimum_required (VERSION 3.7)
project (dungeon)
add_subdirectory (src)

# Make dox target that runs doxygen.
add_custom_target(dox
   cd ${CMAKE_SOURCE_DIR}\;
   (cat Doxyfile\; echo "OUTPUT_DIRECTORY=${CMAKE_BINARY_DIR}") | doxygen -)

# Make it so that html and latex directories are removed on clean.
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
   "${CMAKE_BINARY_DIR}/html"
   "${CMAKE_BINARY_DIR}/latex")
