# CMakeList.txt : CMake project for hanoi2, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (hanoi2 "hanoi2.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hanoi2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
