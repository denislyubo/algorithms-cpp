# CMakeList.txt : CMake project for booking_room, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (booking_room "booking_room.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET booking_room PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
