# -*- cmake -*-
#	from:
#	http://code.google.com/p/emeraldviewer/source/browse/indra/cmake/FindBerkeleyDB.cmake?spec=svn2d5b87bf61c915011530469add736301acccfd32&r=2d5b87bf61c915011530469add736301acccfd32
#
# modified:
#	* changed paths to suit BerkeleyDB.5.0 installation
# * reversed order for searching /usr/local and /usr

# - Find BerkeleyDB
# Find the BerkeleyDB includes and library
# This module defines
#  DB_INCLUDE_DIR, where to find db.h, etc.
#  DB_LIBRARIES, the libraries needed to use BerkeleyDB.
#  DB_FOUND, If false, do not try to use BerkeleyDB.
# also defined, but not for general use are
#  DB_LIBRARY, where to find the BerkeleyDB library.

#	Look for header in paths:
FIND_PATH( RPBDB_INCLUDE_DIR	rpbdb.h
														/usr/local/include
														/usr/include
)
MESSAGE( STATUS "include dir: ${RPBDB_INCLUDE_DIR}")

#	Look for lib in paths:
SET( RPBDB_NAMES ${RPBDB_NAMES} RPBDB )
FIND_LIBRARY(RPBDB_LIBRARY
  NAMES ${RPBDB_NAMES}
  PATHS /usr/local/lib /usr/lib
)

#	set whether we found both headers and lib
IF (RPBDB_LIBRARY AND RPBDB_INCLUDE_DIR)
    SET(RPBDB_LIBRARIES ${RPBDB_LIBRARY})
    SET(RPBDB_FOUND "YES")
ELSE (RPBDB_LIBRARY AND RPBDB_INCLUDE_DIR)
  SET(RPBDB_FOUND "NO")
ENDIF (RPBDB_LIBRARY AND RPBDB_INCLUDE_DIR)


IF (RPBDB_FOUND)
   IF (NOT RPBDB_FIND_QUIETLY)
      MESSAGE(STATUS "Found RPBDB: ${RPBDB_LIBRARIES}")
   ENDIF (NOT RPBDB_FIND_QUIETLY)
ELSE (RPBDB_FOUND)
   IF (RPBDB_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find RPBDB library")
   ENDIF (RPBDB_FIND_REQUIRED)
ENDIF (RPBDB_FOUND)

# Deprecated declarations.
SET (NATIVE_RPBDB_INCLUDE_PATH ${RPBDB_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_RPBDB_LIB_PATH ${RPBDB_LIBRARY} PATH)

MARK_AS_ADVANCED(
  RPBDB_LIBRARY
  RPBDB_INCLUDE_DIR
)