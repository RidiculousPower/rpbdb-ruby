require_relative '../../../../lib/rpbdb.rb'

describe RPbdb::Database do

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

  # RPbdb::Settings::Debug::Verbosity.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Debug::Verbosity.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Debug::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Debug::Verbosity.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Debug::Verbosity.new( debug_settings_controller )
  it "can be created with a debug settings controller" do
    RPbdb::Settings::Debug::Verbosity.new( RPbdb::Settings::Debug.new ).should_not == nil
  end

  # RPbdb::Settings::Debug::Verbosity.new
  it "can be created with no environment specified" do
    RPbdb::Settings::Debug::Verbosity.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::Debug::Verbosity.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPbdb::Settings::Debug::Verbosity.new.parent_settings_controller.should_not == nil
  end

  ######################################
  #  parent_debug_settings_controller  #
  ######################################

  it "can return its parent debug settings controller" do
    RPbdb::Settings::Debug::Verbosity.new.parent_debug_settings_controller.should_not == nil
  end

  #############################################################
  #  display_additional_information_during_recovery?          #
	#  turn_display_additional_information_during_recovery_on   #
	#  turn_display_additional_information_during_recovery_off  #
  #############################################################

  it "can display additional information during recovery" do
    verbosity__settings  = RPbdb::Settings::Debug::Verbosity.new
    verbosity__settings.display_additional_information_during_recovery?.should == false
    verbosity__settings.turn_display_additional_information_during_recovery_on
    verbosity__settings.display_additional_information_during_recovery?.should == true
    verbosity__settings.turn_display_additional_information_during_recovery_off
    verbosity__settings.display_additional_information_during_recovery?.should == false
  end

end

