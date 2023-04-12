# CMakeList.txt : CMake project for find-celebrity, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (find-celebrity "find-celebrity.cpp" "find-celebrity.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET find-celebrity PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
