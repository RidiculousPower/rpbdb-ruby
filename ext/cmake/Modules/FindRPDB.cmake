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
FIND_PATH( RPDB_INCLUDE_DIR	rpdb/rpdb.h
														/usr/local/include
														/usr/include
)

#	Look for lib in paths:
SET( RPDB_NAMES ${RPDB_NAMES} rpdb )
FIND_LIBRARY(RPDB_LIBRARY
  NAMES ${RPDB_NAMES}
  PATHS /usr/local/lib /usr/lib
)

#	set whether we found both headers and lib
IF (RPDB_LIBRARY AND RPDB_INCLUDE_DIR)
    SET(RPDB_LIBRARIES ${RPDB_LIBRARY})
    SET(RPDB_FOUND "YES")
ELSE (RPDB_LIBRARY AND RPDB_INCLUDE_DIR)
  SET(RPDB_FOUND "NO")
ENDIF (RPDB_LIBRARY AND RPDB_INCLUDE_DIR)


IF (RPDB_FOUND)
   IF (NOT RPDB_FIND_QUIETLY)
      MESSAGE(STATUS "Found RPDB: ${RPDB_LIBRARIES}")
   ENDIF (NOT RPDB_FIND_QUIETLY)
ELSE (RPDB_FOUND)
   IF (RPDB_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find RPDB library")
   ENDIF (RPDB_FIND_REQUIRED)
ENDIF (RPDB_FOUND)

# Deprecated declarations.
SET (NATIVE_RPDB_INCLUDE_PATH ${RPDB_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_RPDB_LIB_PATH ${RPDB_LIBRARY} PATH)

MARK_AS_ADVANCED(
  RPDB_LIBRARY
  RPDB_INCLUDE_DIR
)