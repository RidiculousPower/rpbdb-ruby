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
FIND_PATH( RBDB_INCLUDE_DIR	rbdb.h
														/usr/local/include
														/usr/include
)
MESSAGE( STATUS "include dir: ${RBDB_INCLUDE_DIR}")

#	Look for lib in paths:
SET( RBDB_NAMES ${RBDB_NAMES} RBDB )
FIND_LIBRARY(RBDB_LIBRARY
  NAMES ${RBDB_NAMES}
  PATHS /usr/local/lib /usr/lib
)

#	set whether we found both headers and lib
IF (RBDB_LIBRARY AND RBDB_INCLUDE_DIR)
    SET(RBDB_LIBRARIES ${RBDB_LIBRARY})
    SET(RBDB_FOUND "YES")
ELSE (RBDB_LIBRARY AND RBDB_INCLUDE_DIR)
  SET(RBDB_FOUND "NO")
ENDIF (RBDB_LIBRARY AND RBDB_INCLUDE_DIR)


IF (RBDB_FOUND)
   IF (NOT RBDB_FIND_QUIETLY)
      MESSAGE(STATUS "Found RBDB: ${RBDB_LIBRARIES}")
   ENDIF (NOT RBDB_FIND_QUIETLY)
ELSE (RBDB_FOUND)
   IF (RBDB_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find RBDB library")
   ENDIF (RBDB_FIND_REQUIRED)
ENDIF (RBDB_FOUND)

# Deprecated declarations.
SET (NATIVE_RBDB_INCLUDE_PATH ${RBDB_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_RBDB_LIB_PATH ${RBDB_LIBRARY} PATH)

MARK_AS_ADVANCED(
  RBDB_LIBRARY
  RBDB_INCLUDE_DIR
)