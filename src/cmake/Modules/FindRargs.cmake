
# - Find Rargs
# Find the Rargs includes and library
# This module defines
#  RARGS_INCLUDE_DIR, where to find db.h, etc.
#  RARGS_LIBRARIES, the libraries needed to use Rargs.
#  RARGS_FOUND, If false, do not try to use Rargs.
# also defined, but not for general use are
#  RARGS_LIBRARY, where to find the Rargs library.

#	Look for header in paths:
FIND_PATH( RARGS_INCLUDE_DIR	rargs.h
															/usr/local/include
															/usr/include
)

#	Look for lib in paths:
SET( RARGS_NAMES ${RARGS_NAMES} rargs )
FIND_LIBRARY( RARGS_LIBRARY
  NAMES ${RARGS_NAMES}
  PATHS /usr/local/lib 
				/usr/lib
)
message( STATUS "rargs lib now: ${RARGS_LIBRARY}" )

#	set whether we found both headers and lib
IF (RARGS_LIBRARY AND RARGS_INCLUDE_DIR)
    SET(RARGS_LIBRARIES ${RARGS_LIBRARY})
    SET(RARGS_FOUND "YES")
ELSE (RARGS_LIBRARY AND RARGS_INCLUDE_DIR)
  SET(RARGS_FOUND "NO")
ENDIF (RARGS_LIBRARY AND RARGS_INCLUDE_DIR)


IF (RARGS_FOUND)
   IF (NOT RARGS_FIND_QUIETLY)
      MESSAGE(STATUS "Found Rargs: ${RARGS_LIBRARIES}")
   ENDIF (NOT RARGS_FIND_QUIETLY)
ELSE (RARGS_FOUND)
   IF (RARGS_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find Rargs library")
   ENDIF (RARGS_FIND_REQUIRED)
ENDIF (RARGS_FOUND)

# Deprecated declarations.
SET (NATIVE_RARGS_INCLUDE_PATH ${RARGS_INCLUDE_DIR} )
GET_FILENAME_COMPONENT (NATIVE_RARGS_LIB_PATH ${RARGS_LIBRARY} PATH)

MARK_AS_ADVANCED(
  RARGS_LIBRARY
  RARGS_INCLUDE_DIR
)