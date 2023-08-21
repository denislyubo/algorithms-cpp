# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("algorithms-cpp")

# Include sub-projects.
add_subdirectory ("find-two-el-equal-k")
add_subdirectory ("first-greater-then-current")
add_subdirectory ("find-celebrity")
add_subdirectory ("robot-dynamic-programming")
add_subdirectory ("atomic")
add_subdirectory ("poly-sum")
add_subdirectory ("max_2_in_array")
add_subdirectory ("change")
add_subdirectory ("permutations-num")
add_subdirectory ("combinations")
add_subdirectory ("booking-room")
add_subdirectory ("stones")
add_subdirectory ("stones2")
add_subdirectory ("hanoi")
add_subdirectory ("hanoi2")
add_subdirectory("selection-sort")
add_subdirectory("merge-sorted")
add_subdirectory("merge-sort")
add_subdirectory("lomuto")
add_subdirectory("quick-sort")
add_subdirectory("max-prod")
add_subdirectory("max-prod-3")
