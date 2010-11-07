require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::DatabaseController::Database do

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

  # RPDB::Environment::Settings::Debug::Verbosity.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Debug::Verbosity.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Debug::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Debug::Verbosity.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Debug::Verbosity.new( debug_settings_controller )
  it "can be created with a debug settings controller" do
    RPDB::Environment::Settings::Debug::Verbosity.new( RPDB::Environment::Settings::Debug.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Debug::Verbosity.new
  it "can be created with no environment specified" do
    RPDB::Environment::Settings::Debug::Verbosity.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  it "" do
    Fail
  end

  ################
  #  initialize  #
  ################

  it "" do
    Fail
  end

  ########################
  #  parent_environment  #
  ########################

  it "" do
    Fail
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "" do
    Fail
  end

  ######################################
  #  parent_debug_settings_controller  #
  ######################################

  it "" do
    Fail
  end

  ####################################################
  #  display_additional_information_during_recovery  #
  ####################################################

  it "" do
    Fail
  end

  	############################################################
  	#  turn_display_additional_information_during_recovery_on  #
  	############################################################

    it "" do
      Fail
    end

  	#############################################################
  	#  turn_display_additional_information_during_recovery_off  #
  	#############################################################

    it "" do
      Fail
    end

end

