# CMakeList.txt : CMake project for find-two-el-equal-k, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (find-two-el-equal-k "find-two-el-equal-k.cpp" "find-two-el-equal-k.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET find-two-el-equal-k PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
