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

  it "can be set to create file with initial null bytes numbering ______" do
    raise "Failed."
  end

  #################
	#  set_file_id  #
  #  file_id      #
  #################

  it "can set and return its file id" do
    raise "Failed."
  end

  ###################
	#  set_file_type  #
  #  file_type      #
  ###################

  it "can set and return its file type" do
    raise "Failed."
  end

  ####################################
	#  set_log_sequence_number_offset  #
  #  log_sequence_number_offset      #
  ####################################

  it "can set and return its log sequence number offset" do
    raise "Failed."
  end

  ################################################
  #  set_max_size_in_bytes                       #
	#  set_max_size_in_kbytes                      #
	#  set_max_size_in_mbytes                      #
	#  set_max_size_in_gbytes                      #
	#  set_max_size_in_gbytes_mbytes_kbytes_bytes  #
	#  set_max_size_in_mbytes_kbytes_bytes         #
	#  set_max_size_in_kbytes_bytes                #
  #  max_size_in_bytes                           #
	#  max_size_in_kbytes                          #
	#  max_size_in_mbytes                          #
	#  max_size_in_gbytes                          #
  ################################################

  it "can set its cache size according to various measures" do
    memory_pool_file_settings = RPDB::Settings::MemoryPool::File.new( RPDB::Database( $database_name ) )

    memory_pool_file_settings.set_max_size_in_bytes( 12 )
    memory_pool_file_settings.max_size_in_bytes.should == 12

    memory_pool_file_settings.set_max_size_in_kbytes( 42 )
    memory_pool_file_settings.max_size_in_kbytes.should == 42 * 1024

    memory_pool_file_settings.set_max_size_in_mbytes( 37 )
    memory_pool_file_settings.max_size_in_mbytes.should == 37 * ( 1024 * 1024 )

    memory_pool_file_settings.set_max_size_in_gbytes( 420 )
    memory_pool_file_settings.max_size_in_gbytes.should == 420 * ( 1024 * 1024 * 1024 )

    memory_pool_file_settings.set_max_size_in_gbytes_mbytes_kbytes_bytes( 420, 37, 42, 12 )
    memory_pool_file_settings.max_size_in_bytes.should == 420 * ( 1024 * 1024 * 1024 ) + 37 * ( 1024 * 1024 ) + 42 * 1024 + 12

    memory_pool_file_settings.set_max_size_in_mbytes_kbytes_bytes( 37, 42, 12 )
    memory_pool_file_settings.max_size_in_bytes.should == 37 * ( 1024 * 1024 )

    memory_pool_file_settings.set_max_size_in_kbytes_bytes( 42, 12 )
    memory_pool_file_settings.max_size_in_bytes.should == 42 * 1024 + 12
    
  end

  ################
	#  set_cookie  #
  #  cookie      #
  ################

  it "can set and return its cookie" do
    raise "Failed."
  end

  ###############################
  #  cache_settings_controller  #
  ###############################

  it "can return its cache settings controller" do
    raise "Failed."
  end

  ##############################
  #  page_settings_controller  #
  ##############################

  it "can return its page settings controller" do
    raise "Failed."
  end

end

