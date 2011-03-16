# modified from BerkeleyDB .cmake
#
# -*- cmake -*-
#  from:
#  http://code.google.com/p/emeraldviewer/source/browse/indra/cmake/FindBerkeleyDB.cmake?spec=svn2d5b87bf61c915011530469add736301acccfd32&r=2d5b87bf61c915011530469add736301acccfd32
#
# modified:
#  * changed paths to suit BerkeleyDB.5.0 installation
# * reversed order for searching /usr/local and /usr

# - Find BerkeleyDB
# Find the BerkeleyDB includes and library
# This module defines
#  DB_INCLUDE_DIR, where to find db.h, etc.
#  DB_LIBRARIES, the libraries needed to use BerkeleyDB.
#  DB_FOUND, If false, do not try to use BerkeleyDB.
# also defined, but not for general use are
#  DB_LIBRARY, where to find the BerkeleyDB library.

#  Look for header in paths:
FIND_PATH( RCERIALIZE_INCLUDE_DIR  rcerialize.h
		                              /usr/local/include
		                              /usr/include
)


#  Look for lib in paths:
SET( RCERIALIZE_NAMES ${RCERIALIZE_NAMES} rcerialize )
FIND_LIBRARY(RCERIALIZE_LIBRARY
  NAMES ${RCERIALIZE_NAMES}
  PATHS /usr/local/lib /usr/lib
)

#  set whether we found both headers and lib
IF (RCERIALIZE_LIBRARY AND RCERIALIZE_INCLUDE_DIR)
    SET(RCERIALIZE_LIBRARIES ${RCERIALIZE_LIBRARY})
    SET(RCERIALIZE_FOUND "YES")
ELSE (RCERIALIZE_LIBRARY AND RCERIALIZE_INCLUDE_DIR)
  SET(RCERIALIZE_FOUND "NO")
ENDIF (RCERIALIZE_LIBRARY AND RCERIALIZE_INCLUDE_DIR)


IF (RCERIALIZE_FOUND)
   IF (NOT RCERIALIZE_FIND_QUIETLY)
      MESSAGE(STATUS "Found Rcerialize: ${RCERIALIZE_LIBRARIES}")
   ENDIF (NOT RCERIALIZE_FIND_QUIETLY)
ELSE (RCERIALIZE_FOUND)
   IF (RCERIALIZE_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find Rcerialize library")
   ENDIF (RCERIALIZE_FIND_REQUIRED)
ENDIF (RCERIALIZE_FOUND)

# Deprecated declarations.
SET (NATIVE_RCERIALIZE_INCLUDE_PATH ${RCERIALIZE_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_RCERIALIZE_LIB_PATH ${RCERIALIZE_LIBRARY} PATH)

MARK_AS_ADVANCED(
  RCERIALIZE_LIBRARY
  RCERIALIZE_INCLUDE_DIR
)