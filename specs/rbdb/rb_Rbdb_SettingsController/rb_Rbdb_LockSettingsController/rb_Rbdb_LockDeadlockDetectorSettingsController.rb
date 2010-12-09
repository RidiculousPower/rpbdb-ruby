require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Settings::Lock::DeadlockDetector do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
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

  # Rbdb::Settings::Lock::DeadlockDetector.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Lock::DeadlockDetector.new( @environment ).should_not == nil
  end

  # Rbdb::Settings::Lock::DeadlockDetector.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Lock::DeadlockDetector.new( Rbdb::Settings.new ).should_not == nil
  end

  # Rbdb::Settings::Lock::DeadlockDetector.new( lock_settings_controller )
  it "can be created with a lock settings controller" do
    Rbdb::Settings::Lock::DeadlockDetector.new( Rbdb::Settings::Lock.new ).should_not == nil
  end

  # Rbdb::Settings::Lock::DeadlockDetector.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Lock::DeadlockDetector.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    Rbdb::Settings::Lock::DeadlockDetector.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    Rbdb::Settings::Lock::DeadlockDetector.new.parent_settings_controller.should_not == nil
  end

  #####################################
  #  parent_lock_settings_controller  #
  #####################################

  it "can return its parent lock settings controller" do
    Rbdb::Settings::Lock::DeadlockDetector.new.parent_lock_settings_controller.should_not == nil
  end

  ####################
	#  set_to_default  #
  #  is_default?     #
  ####################

  it "can be set to default settings and report whether it is currently set to default" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_default
    deadlock_detector_settings.is_default?.should == true
  end

  ###########################
	#  set_to_reject_expired  #
  #  reject_expired?        #
  ###########################

  it "can be set to reject expired locks and report whether it is currently set to reject all expired locks" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_expired
    deadlock_detector_settings.reject_expired?.should == true
  end

  ##########################################
	#  set_to_reject_locker_with_most_locks  #
  #  reject_locker_with_most_locks?        #
  ##########################################

  it "can be set to reject locker with most locks and report whether it is currently set to reject locker with most locks locks" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_locker_with_most_locks
    deadlock_detector_settings.reject_locker_with_most_locks?.should == true
  end

  ################################################
	#  set_to_reject_locker_with_most_write_locks  #
  #  reject_locker_with_most_write_locks?        #
  ################################################

  it "can be set to reject locker with most write locks and report whether it is currently set to reject locker with most write locks locks" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_locker_with_most_write_locks
    deadlock_detector_settings.reject_locker_with_most_write_locks?.should == true
  end

  ############################################
	#  set_to_reject_locker_with_fewest_locks  #
  #  reject_locker_with_fewest_locks?        #
  ############################################

  it "can be set to reject locker with fewest locks and report whether it is currently set to reject locker with fewest locks" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_locker_with_fewest_locks
    deadlock_detector_settings.reject_locker_with_fewest_locks?.should == true
  end

  ##################################################
	#  set_to_reject_locker_with_fewest_write_locks  #
  #  reject_locker_with_fewest_write_locks?        #
  ##################################################

  it "can be set to reject locker with fewest write locks and report whether it is currently set to reject locker with fewest locks" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_locker_with_fewest_write_locks
    deadlock_detector_settings.reject_locker_with_fewest_write_locks?.should == true
  end

  ###########################################
	#  set_to_reject_locker_with_oldest_lock  #
  #  reject_locker_with_oldest_lock?        #
  ###########################################

  it "can be set to reject locker with oldest lock and report whether it is currently set to reject locker with oldest lock" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_locker_with_oldest_lock
    deadlock_detector_settings.reject_locker_with_oldest_lock?.should == true
  end

  #############################################
	#  set_to_reject_locker_with_youngest_lock  #
  #  reject_locker_with_youngest_lock?        #
  #############################################

  it "can be set to reject locker with youngest lock and report whether it is currently set to reject locker with youngest lock" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_locker_with_youngest_lock
    deadlock_detector_settings.reject_locker_with_youngest_lock?.should == true
  end

  ###############################
	#  set_to_reject_random_lock  #
  #  reject_random_lock?        #
  ###############################

  it "can be set to reject random lock and report whether it is currently set to reject random lock" do
    raise "Lock priority"
    deadlock_detector_settings  = Rbdb::Settings::Lock::DeadlockDetector.new
    deadlock_detector_settings.set_to_reject_random_lock
    deadlock_detector_settings.reject_random_lock?.should == true
  end

  ###################################
  #  verbosity_settings_controller  #
  ###################################

  it "can return its verbosity settings controller" do
    Rbdb::Settings::Lock::DeadlockDetector.new.verbosity_settings_controller.is_a?( Rbdb::Settings::Lock::DeadlockDetector::Verbosity ).should == true
  end

end

