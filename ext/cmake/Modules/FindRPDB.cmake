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
FIND_PATH( Rbdb_INCLUDE_DIR	rbdb/rbdb.h
														/usr/local/include
														/usr/include
)

#	Look for lib in paths:
SET( Rbdb_NAMES ${Rbdb_NAMES} rbdb )
FIND_LIBRARY(Rbdb_LIBRARY
  NAMES ${Rbdb_NAMES}
  PATHS /usr/local/lib /usr/lib
)

#	set whether we found both headers and lib
IF (Rbdb_LIBRARY AND Rbdb_INCLUDE_DIR)
    SET(Rbdb_LIBRARIES ${Rbdb_LIBRARY})
    SET(Rbdb_FOUND "YES")
ELSE (Rbdb_LIBRARY AND Rbdb_INCLUDE_DIR)
  SET(Rbdb_FOUND "NO")
ENDIF (Rbdb_LIBRARY AND Rbdb_INCLUDE_DIR)


IF (Rbdb_FOUND)
   IF (NOT Rbdb_FIND_QUIETLY)
      MESSAGE(STATUS "Found Rbdb: ${Rbdb_LIBRARIES}")
   ENDIF (NOT Rbdb_FIND_QUIETLY)
ELSE (Rbdb_FOUND)
   IF (Rbdb_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find Rbdb library")
   ENDIF (Rbdb_FIND_REQUIRED)
ENDIF (Rbdb_FOUND)

# Deprecated declarations.
SET (NATIVE_Rbdb_INCLUDE_PATH ${Rbdb_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_Rbdb_LIB_PATH ${Rbdb_LIBRARY} PATH)

MARK_AS_ADVANCED(
  Rbdb_LIBRARY
  Rbdb_INCLUDE_DIR
)