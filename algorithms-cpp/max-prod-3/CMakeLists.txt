﻿# CMakeList.txt : CMake project for max-prod-3, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (max-prod-3 "max-prod-3.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET max-prod-3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
