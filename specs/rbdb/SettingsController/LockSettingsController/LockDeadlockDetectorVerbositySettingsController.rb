require_relative '../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Lock::DeadlockDetector::Verbosity do

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

  # RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( lock_settings_controller )
  it "can be created with a lock settings controller" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( RPbdb::Settings::Lock.new ).should_not == nil
  end

  # RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( lock_settings_controller )
  it "can be created with a lock deadlock detector settings controller" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new( RPbdb::Settings::Lock::DeadlockDetector.new ).should_not == nil
  end

  # RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new.parent_settings_controller.should_not == nil
  end

  #####################################
  #  parent_lock_settings_controller  #
  #####################################

  it "can return its parent lock settings controller" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new.parent_lock_settings_controller.should_not == nil
  end

  #######################################################
  #  parent_lock_deadlock_detector_settings_controller  #
  #######################################################

  it "can return its parent lock deadlock settings controller" do
    RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new.parent_lock_deadlock_detector_settings_controller.should_not == nil
  end

  #######################################################################
  #  display_additional_information_during_deadlock_detection?          #
	#  turn_display_additional_information_during_deadlock_detection_on   #
	#  turn_display_additional_information_during_deadlock_detection_off  #
  #######################################################################

  it "can display additional information during deadlock detection" do
    verbosity_settings  = RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new
    verbosity_settings.display_additional_information_during_deadlock_detection?.should == false
    verbosity_settings.turn_display_additional_information_during_deadlock_detection_on
    verbosity_settings.display_additional_information_during_deadlock_detection?.should == true
    verbosity_settings.turn_display_additional_information_during_deadlock_detection_off
    verbosity_settings.display_additional_information_during_deadlock_detection?.should == false
  end

  ###########################################################
  #  display_wait_table_during_deadlock_detection?          #
	#  turn_display_wait_table_during_deadlock_detection_on   #
	#  turn_display_wait_table_during_deadlock_detection_off  #
  ###########################################################

  it "can display wait table during deadlock detection" do
    verbosity_settings  = RPbdb::Settings::Lock::DeadlockDetector::Verbosity.new
    verbosity_settings.display_wait_table_during_deadlock_detection?.should == false
    verbosity_settings.turn_display_wait_table_during_deadlock_detection_on
    verbosity_settings.display_wait_table_during_deadlock_detection?.should == true
    verbosity_settings.turn_display_wait_table_during_deadlock_detection_off
    verbosity_settings.display_wait_table_during_deadlock_detection?.should == false
  end

end

