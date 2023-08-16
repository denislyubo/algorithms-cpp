# CMakeList.txt : CMake project for max_2_in_array, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (max_2_in_array "max_2_in_array.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET max_2_in_array PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
