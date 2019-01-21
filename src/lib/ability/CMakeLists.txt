add_library (ability SHARED
   charis-tab.cpp
   consti-tab.cpp
   dexter-tab.cpp
   initial.cpp
   intell-tab.cpp
   streng-tab.cpp
   wisdom-tab.cpp)

target_include_directories (ability PRIVATE ..)
