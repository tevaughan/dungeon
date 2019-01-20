set (CMAKE_CXX_FLAGS
   "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g -O0 -std=c++14")

add_subdirectory (test)
add_subdirectory (lib)

# Make format target that runs clang-format on sources.
add_custom_target (format
   cd ${CMAKE_CURRENT_SOURCE_DIR}\;
   find . -name '*.cpp' -exec clang-format -i {} \\\;\;
   find . -name '*.hpp' -exec clang-format -i {} \\\;)

# Make dox target that runs doxygen.
add_custom_target(dox
   cd ${CMAKE_CURRENT_SOURCE_DIR}\;
   (cat Doxyfile\; echo "OUTPUT_DIRECTORY=${CMAKE_CURRENT_BINARY_DIR}") | doxygen -)

# Make it so that html and latex directories are removed on clean.
set_property (DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
   "${CMAKE_CURRENT_BINARY_DIR}/html"
   "${CMAKE_CURRENT_BINARY_DIR}/latex")
