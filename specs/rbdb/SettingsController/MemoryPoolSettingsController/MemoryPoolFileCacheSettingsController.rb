require_relative '../../../../lib/rpbdb.rb'

describe RPbdb::Settings::MemoryPool::File::Cache do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
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

  # RPbdb::Settings::MemoryPool::File::Cache.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::MemoryPool::File::Cache.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Cache.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::MemoryPool::File::Cache.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Cache.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPbdb::Settings::MemoryPool::File::Cache.new( RPbdb::Settings::MemoryPool.new ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Cache.new( memory_pool_settings_controller )
  it "can be created with a memory pool file settings controller" do
    RPbdb::Settings::MemoryPool::File::Cache.new( RPbdb::Settings::MemoryPool::File.new ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Cache.new
  it "can be created with no argument specified" do
    RPbdb::Settings::MemoryPool::File::Cache.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::MemoryPool::File::Cache.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPbdb::Settings::MemoryPool::File::Cache.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "can return its parent memory pool settings controller" do
    RPbdb::Settings::MemoryPool::File::Cache.new.parent_memory_pool_settings_controller.should_not == nil
  end

  #################################################
  #  parent_memory_pool_file_settings_controller  #
  #################################################

  it "can return its parent memory pool file settings controller" do
    RPbdb::Settings::MemoryPool::File::Cache.new.parent_memory_pool_file_settings_controller.should_not == nil
  end

  ##################################
  #  priority_settings_controller  #
  ##################################

  it "can return its priority controller" do
    RPbdb::Settings::MemoryPool::File::Cache.new.priority_settings_controller.is_a?( RPbdb::Settings::MemoryPool::File::Cache::Priority ).should == true
  end

end

