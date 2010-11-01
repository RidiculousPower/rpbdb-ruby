include( RecursivelyIncludeSource )

set( _RUBY_DEBUG_OUTPUT ON)
#	make sure we have libdb
find_package( RPDB REQUIRED )
find_package( Ruby REQUIRED )
find_package( Rargs REQUIRED )

message( STATUS "Using RPDB Lib: ${RPDB_LIBRARY}" )
message( STATUS "Using Ruby Lib: ${RUBY_LIBRARY}" )
message( STATUS "Using Rargs Lib: ${RARGS_LIBRARY}" )

message( STATUS "Using RPDB Headers: ${RPDB_INCLUDE_DIR}" )
message( STATUS "Using Ruby Headers: ${RUBY_INCLUDE_DIRS}" )
message( STATUS "Using Rargs Headers: ${RARGS_INCLUDE_DIR}" )

get_directory_property( CMAKE_CURRENT_INCLUDE_DIR INCLUDE_DIRECTORIES )

recursively_include_src( ${CMAKE_CURRENT_INCLUDE_DIR} "headers" )
recursively_include_src( ${CMAKE_CURRENT_SOURCE_DIR} "source" )

LINK_DIRECTORIES( "/usr/local/lib" )
set( RPDB_INCLUDE_DIRS ${RPDB_INCLUDE_DIRS} include ${RUBY_INCLUDE_DIRS} ${RPDB_INCLUDE_DIR} ${RARGS_INCLUDE_DIR} )
include_directories( ${RPDB_INCLUDE_DIRS} )

#	define shared library with sources
add_library( rb_rpdb MODULE ${rb_rpdb_src} )
target_link_libraries( rb_rpdb ${RPDB_LIBRARY} )
target_link_libraries( rb_rpdb ${RUBY_LIBRARY} )
target_link_libraries( rb_rpdb ${RARGS_LIBRARY} )

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
set_target_properties( rb_rpdb	PROPERTIES	LINKER_LANGUAGE C 
																						OUTPUT_NAME "../rpdb"
																						PREFIX ""
																						SUFFIX ".bundle"
																						LINK_FLAGS "-Wl,-rpath,-L${CMAKE_INSTALL_RPATH}"
																						INSTALL_RPATH ${CMAKE_INSTALL_RPATH}
																						INSTALL_NAME_DIR ${CMAKE_INSTALL_NAME_DIR}
																						C_FLAGS "-ggdb -fsigned-char -Wall -W -Wshadow -Wstrict-prototypes -Wpointer-arith -Wcast-qual -Winline -Werror" )

# Installation of the library
#install( TARGETS rb_rpdb DESTINATION lib PERMISSIONS OWNER_READ GROUP_READ WORLD_READ )
