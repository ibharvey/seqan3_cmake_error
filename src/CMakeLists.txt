cmake_minimum_required (VERSION 3.4)

project (program CXX)


# Add external projects
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(SeqAn3_DIR "${CMAKE_SOURCE_DIR}/deps/seqan3/build_system")
find_package (SeqAn3 REQUIRED)

add_executable (program main.cpp)

# segment library
add_library(segment segment.cpp)
target_include_directories( segment PRIVATE
  "${CMAKE_SOURCE_DIR}/include"
  )
target_link_libraries(segment LINK_PUBLIC seqan3::seqan3)

# traversal library
add_library(traversal traversal.cpp)

target_include_directories( traversal PRIVATE
  "${CMAKE_SOURCE_DIR}/include"
  "${gfakluge_INCLUDE}"
	"${gfakluge_tinyFA_INCLUDE}"
	"${gfakluge_pliib_INCLUDE}"
  )

target_link_libraries(traversal LINK_PUBLIC segment)

target_include_directories(program PRIVATE
  "${CMAKE_SOURCE_DIR}/include"
  )

target_link_libraries(program LINK_PUBLIC traversal seqan3::seqan3)

