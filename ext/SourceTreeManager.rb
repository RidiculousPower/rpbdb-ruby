require 'mkmf'

# use env CC var if specified
RbConfig::MAKEFILE_CONFIG['CC'] = ENV['CC'] if ENV['CC']

class SourceTreeManager

  attr_accessor :source_directories, :include_directories, :verbose
  attr_accessor :top_source_directory, :build_directory, :install_directory

  attr_reader   :target
  
  ################
  #  initialize  #
  ################
  
  def initialize
    self.source_directories   = Array.new
    self.include_directories  = Array.new
    self.verbose  = false
  end
  
  #############
  #  target=  #
  #############
  
  def target=( target )
    if self.verbose 
      puts "\n" + 'Target is ' + target + "\n"
    end
    @target = target
    return self
  end
  
  #############################
  #  clean_install_directory  #
  #############################
  
  def clean_install_directory
    # remove all headers and all c source files from install dir
    Dir.glob( '*.h' ).each do |this_file|
      File.delete( this_file )
    end
    Dir.glob( '*.c' ).each do |this_file|
      File.delete( this_file )
    end
    Dir.glob( '*.o' ).each do |this_file|
      File.delete( this_file )
    end
    if File.exists?( 'Makefile' )
      File.delete( 'Makefile' )
    end
  end
  
  ###############
  #  find_libs  #
  ###############
  
  def find_libs
    # Ask for rpdb.h location
    dir_config( 'rpdb' )
  end

  ##################
  #  require_libs  #
  ##################

  def require_libs
    if ! have_library( 'rpdb' )
      puts "\n" + 'Error: Could not find librpdb. RPDB library must be installed! Failing.' + "\n"
      exit
    end
  end

  #####################
  #  require_headers  #
  #####################
  
  def require_headers
    if ! have_header( 'rpdb.h' )
      puts "\n" + 'Error: Could not find rpdb.h. RPDB headers must be installed! Failing.' + "\n"
      exit
    end
  end
  
  ################################
  #  process_source_directories  #
  ################################

  def process_source_directories
    # We want to link to our source files - for now we have files we aren't linking to yet (they don't have headers)
    self.source_directories.each do |this_source_dir|
      self.create_local_links_for_source_tree( this_source_dir + "/**/*.c" )
    end
  end

  #################################
  #  process_include_directories  #
  #################################

  def process_include_directories
    # We want to link to our source files - for now we have files we aren't linking to yet (they don't have headers)
    self.include_directories.each do |this_include_dir|
      self.create_local_links_for_source_tree( this_include_dir + "/**/*.h" )
    end
  end
  
  ########################################
  #  create_local_links_for_source_tree  #
  ########################################

  def create_local_links_for_source_tree( source_glob )
    
    Dir.glob( source_glob  ).each do |this_c_file_path|
      self.create_symbolic_link_for_file_in_install_directory( this_c_file_path )
    end

  end

  ########################################################
  #  create_symbolic_link_for_file_in_install_directory  #
  ########################################################

  def create_symbolic_link_for_file_in_install_directory( c_file_path )
    File.symlink( c_file_path, build_directory + File.basename( c_file_path ) )
  end
  
  ###############
  #  internals  #
  ###############

  def internals
    
    # Make sure we have BDB (libdb.dylib and db.h)
    self.find_libs
    self.require_libs
    self.require_headers
    
    if block_given?
      yield
    end
    
  end

  ###########################
  #  source_prep_internals  #
  ###########################
  
  def source_prep_internals

    # clean directory to start
    self.clean_install_directory

    self.process_source_directories
    self.process_include_directories
    
  end
  
end
