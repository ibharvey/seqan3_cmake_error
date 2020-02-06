## parse the VERSION file in the sdsl directory
set (VERSION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/include/sdsl/version.hpp")

if (NOT EXISTS ${VERSION_FILE})
  message ("")
  message ("ERROR: Could not determine SDSL version.")
  message ("Could not find file: ${VERSION_FILE}")
else ()
    file (READ ${VERSION_FILE} LIBRARY_VERSION_CODE)
    string (REGEX MATCH "define SDSL_VERSION_MAJOR ([0-9]+)" _ ${LIBRARY_VERSION_CODE})
    set(LIBRARY_VERSION_MAJOR ${CMAKE_MATCH_1})
    string (REGEX MATCH "define SDSL_VERSION_MINOR ([0-9]+)" _ ${LIBRARY_VERSION_CODE})
    set(LIBRARY_VERSION_MINOR ${CMAKE_MATCH_1})
    string (REGEX MATCH "define SDSL_VERSION_PATCH ([0-9]+)" _ ${LIBRARY_VERSION_CODE})
    set(LIBRARY_VERSION_PATCH ${CMAKE_MATCH_1})
    set(LIBRARY_VERSION_FULL "${LIBRARY_VERSION_MAJOR}.${LIBRARY_VERSION_MINOR}.${LIBRARY_VERSION_PATCH}")
endif ()
