require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Lock::DeadlockDetector do

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

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( lock_settings_controller )
  it "can be created with a lock settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( RPDB::Environment::Settings::Lock.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new.should_not == nil
  end

end

