# CMakeList.txt : CMake project for merge-sort, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (merge-sort "merge_sort.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET merge-sort PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
