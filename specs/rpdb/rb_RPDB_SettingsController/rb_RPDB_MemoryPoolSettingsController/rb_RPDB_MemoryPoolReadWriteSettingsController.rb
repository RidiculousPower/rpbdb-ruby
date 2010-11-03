require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::MemoryPool::ReadWrite do

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

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new( RPDB::Environment::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new.should_not == nil
  end

end

