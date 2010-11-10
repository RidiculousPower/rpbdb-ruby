require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::MemoryPool::File::Cache::Priority do

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

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( @environment ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_file_settings_controller )
  it "can be created with a memory pool file settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings::MemoryPool::File.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_file_cache_settings_controller )
  it "can be created with a memory pool file cache settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings::MemoryPool::File::Cache.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new
  it "can be created with no argument specified" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "can return its parent memory pool settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_memory_pool_settings_controller.should_not == nil
  end

  #################################################
  #  parent_memory_pool_file_settings_controller  #
  #################################################

  it "can return its parent memory pool file settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_memory_pool_file_settings_controller.should_not == nil
  end

  #######################################################
  #  parent_memory_pool_file_cache_settings_controller  #
  #######################################################

  it "can return its parent memory pool file cache settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_memory_pool_file_cache_settings_controller.should_not == nil
  end

  ######################
  #  current_priority  #
  ######################

  it "" do
    raise "Failed."
  end

  ###################
	#  set_very_low   #
	#  set_low        #
  #  very_low       #
  #  low            #
	#  set_default    #
  #  default        #
	#  set_high       #
  #  high           #
	#  set_very_high  #
  #  very_high      #
  ###################

  it "" do
    raise "Failed."
  end

  ########################
  #  at_least_very_low   #
  #  at_most_very_low    #
  #  at_least_low        #
  #  at_most_low         #
  #  at_least_default    #
  #  at_most_default     #
  #  at_least_high       #
  #  at_most_high        #
  #  at_least_very_high  #
  #  at_most_very_high   #
  ########################

  it "" do
    raise "Failed."
  end
  
end

