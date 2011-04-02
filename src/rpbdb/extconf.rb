require 'mkmfmf'

target  = "rpbdb"
  
# find libs:
# * RPbdb
# * cerialize
# * rcerialize
# * rargs

default_cflags  = "-march=x86-64 -g -fno-common -fsigned-char -pipe"

# Create our makefile from sources
with_cflags( default_cflags ) do

  if ! find_library( 'rpbdb', 'RPbdb_version' )
    raise "Requires librpbdb."
  end
  if ! find_library( 'cerialize', 'CerializedData_new' )
    raise "Requires libcerialize."
  end
  if ! find_library( 'rcerialize', 'Rcerialize_packRubyInstance' )
    raise "Requires librcerialize."
  end
  if ! find_library( 'rargs', 'RARG_define_ParameterSets' )
    raise "Requires librargs."
  end

  create_makefile( target + '/' + target )
end
