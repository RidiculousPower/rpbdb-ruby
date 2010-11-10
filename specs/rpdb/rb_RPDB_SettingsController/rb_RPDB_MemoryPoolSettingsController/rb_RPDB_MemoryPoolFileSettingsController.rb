require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::MemoryPool::File do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller

  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Settings::MemoryPool::File.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::MemoryPool::File.new( @environment ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::MemoryPool::File.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Settings::MemoryPool::File.new( RPDB::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File.new
  it "can be created with no argument specified" do
    RPDB::Settings::MemoryPool::File.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::MemoryPool::File.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::MemoryPool::File.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "can return its parent memory pool settings controller" do
    RPDB::Settings::MemoryPool::File.new.parent_memory_pool_settings_controller.should_not == nil
  end

  ##################################################
	#  set_create_with_initial_null_bytes_numbering  #
  #  create_with_initial_null_bytes_numbering      #
  ##################################################

  it "" do
    raise "Failed."
  end

  #################
	#  set_file_id  #
  #  file_id      #
  #################

  it "" do
    raise "Failed."
  end

  ###################
	#  set_file_type  #
  #  file_type      #
  ###################

  it "" do
    raise "Failed."
  end

  ####################################
	#  set_log_sequence_number_offset  #
  #  log_sequence_number_offset      #
  ####################################

  it "" do
    raise "Failed."
  end

  #################################
  #  max_file_size_in_bytes       #
  #  max_file_size_in_kbytes      #
  #  max_file_size_in_mbytes      #
  #  max_file_size_in_gbytes      #
	#  set_max_file_size_in_bytes   #
	#  set_max_file_size_in_kbytes  #
	#  set_max_file_size_in_mbytes  #
	#  set_max_file_size_in_gbytes  #
  #################################

  it "" do
    raise "Failed."
  end

  ################
	#  set_cookie  #
  #  cookie      #
  ################

  it "" do
    raise "Failed."
  end

  ###############################
  #  cache_settings_controller  #
  ###############################

  it "" do
    raise "Failed."
  end

  ##############################
  #  page_settings_controller  #
  ##############################

  it "" do
    raise "Failed."
  end

end

