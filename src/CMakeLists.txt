cmake_minimum_required (VERSION 3.4)

project (program CXX)

# Add external projects
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(SeqAn3_DIR "${CMAKE_SOURCE_DIR}/deps/seqan3/build_system")
find_package (SeqAn3 REQUIRED)

add_executable (program main.cpp)

target_link_libraries(program LINK_PUBLIC seqan3::seqan3)

