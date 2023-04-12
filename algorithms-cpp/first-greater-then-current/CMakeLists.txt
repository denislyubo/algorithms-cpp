# CMakeList.txt : CMake project for first-greater-then-current, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (first-greater-then-current "first-greater-then-current.cpp" "first-greater-then-current.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET first-greater-then-current PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
