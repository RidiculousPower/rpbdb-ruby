include( RecursivelyIncludeSource )

set( _RUBY_DEBUG_OUTPUT ON)
#	make sure we have libdb
find_package( RPbdb REQUIRED )
find_package( Ruby REQUIRED )
find_package( Rargs REQUIRED )
find_package( Cerialize REQUIRED )
find_package( Rcerialize REQUIRED )

message( STATUS "Using RPbdb Lib: ${RPBDB_LIBRARY}" )
message( STATUS "Using Ruby Lib: ${RUBY_LIBRARY}" )
message( STATUS "Using Rargs Lib: ${RARGS_LIBRARY}" )
message( STATUS "Using Cerialize Lib: ${CERIALIZE_LIBRARY}" )
message( STATUS "Using Rcerialize Lib: ${RCERIALIZE_LIBRARY}" )

message( STATUS "Using RPbdb Headers: ${RPBDB_INCLUDE_DIR}" )
message( STATUS "Using Ruby Headers: ${RUBY_INCLUDE_DIRS}" )
message( STATUS "Using Rargs Headers: ${RARGS_INCLUDE_DIR}" )
message( STATUS "Using Cerialize Headers: ${CERIALIZE_INCLUDE_DIR}" )
message( STATUS "Using Rcerialize Headers: ${RCERIALIZE_INCLUDE_DIR}" )

get_directory_property( CMAKE_CURRENT_INCLUDE_DIR INCLUDE_DIRECTORIES )

recursively_include_src( ${CMAKE_CURRENT_INCLUDE_DIR} "headers" )
recursively_include_src( ${CMAKE_CURRENT_SOURCE_DIR} "source" )

LINK_DIRECTORIES( "/usr/local/lib" )
set( RPBDB_INCLUDE_DIRS ${RPBDB_INCLUDE_DIRS} include ${RUBY_INCLUDE_DIRS} ${RPBDB_INCLUDE_DIR} ${RARGS_INCLUDE_DIR} )
include_directories( ${RPBDB_INCLUDE_DIRS} )

#	define shared library with sources
add_library( rb_rpbdb MODULE ${rb_rpbdb_src} )
target_link_libraries( rb_rpbdb ${RPBDB_LIBRARY} )
target_link_libraries( rb_rpbdb ${RUBY_LIBRARY} )
target_link_libraries( rb_rpbdb ${RARGS_LIBRARY} )
target_link_libraries( rb_rpbdb ${CERIALIZE_LIBRARY} )
target_link_libraries( rb_rpbdb ${RCERIALIZE_LIBRARY} )

# use, i.e. don't skip the full RPATH for the build tree
set( CMAKE_SKIP_BUILD_RPATH  OFF )

# when building, don't use the install RPATH already
# (but later on when installing)
set( CMAKE_BUILD_WITH_INSTALL_RPATH ON )

set( CMAKE_INSTALL_NAME_DIR "@rpath" )

# the RPATH to be used when installing
set( CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" )

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
set( CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE )

# Set the build version (VERSION) and the API version (SOVERSION)
set_target_properties( rb_rpbdb	PROPERTIES	LINKER_LANGUAGE C 
																						OUTPUT_NAME "../rpbdb"
																						PREFIX ""
																						SUFFIX ".bundle"
																						LINK_FLAGS "-Wl,-rpath,-L${CMAKE_INSTALL_RPATH}"
																						INSTALL_RPATH ${CMAKE_INSTALL_RPATH}
																						INSTALL_NAME_DIR ${CMAKE_INSTALL_NAME_DIR}
																						C_FLAGS "-ggdb -fsigned-char -Wall -W -Wshadow -Wstrict-prototypes -Wpointer-arith -Wcast-qual -Winline -Werror" )

# Installation of the library
#install( TARGETS rb_rpbdb DESTINATION ../../lib/rpbdb PERMISSIONS OWNER_READ GROUP_READ WORLD_READ )
