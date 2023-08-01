# CMakeList.txt : CMake project for 2-poly-sum, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (find-celebrity "2-poly-sum.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2-poly-sum PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
