require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Lock do

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

  # RPDB::Settings::Lock.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Lock.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Lock.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Lock.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Lock.new
  it "can be created with no argument specified" do
    RPDB::Settings::Lock.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Lock.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Lock.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
	#  turn_on   #
	#  turn_off  #
  ##############

  it "can be turned on and off and report whether it is on or off" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.on?.should == true
    lock_settings.turn_off
    lock_settings.on?.should == false
    lock_settings.off?.should == true
    lock_settings.turn_on
    lock_settings.off?.should == false
  end

  ###############################
  #  prohibit_locking?          #
	#  turn_prohibit_locking_on   #
	#  turn_prohibit_locking_off  #
  ###############################

  it "can prohibit locking" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.prohibit_locking?.should == false
    lock_settings.turn_prohibit_locking_on
    lock_settings.prohibit_locking?.should == true
    lock_settings.turn_prohibit_locking_off
    lock_settings.prohibit_locking?.should == false
  end

  #######################################################
  #  timeout_returns_return_deny_not_deadlock?          #
	#  turn_timeout_returns_return_deny_not_deadlock_on   #
	#  turn_timeout_returns_return_deny_not_deadlock_off  #
  #######################################################

  it "can return deny rather than deadlock on timeout" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.timeout_returns_return_deny_not_deadlock?.should == false
    lock_settings.turn_timeout_returns_return_deny_not_deadlock_on
    lock_settings.timeout_returns_return_deny_not_deadlock?.should == true
    lock_settings.turn_timeout_returns_return_deny_not_deadlock_off
    lock_settings.timeout_returns_return_deny_not_deadlock?.should == false
  end

  ###################
  #  wait?          #
	#  turn_wait_on   #
	#  turn_wait_off  #
  ###################

  it "can be set to wait on deadlock" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.wait?.should == false
    lock_settings.turn_wait_on
    lock_settings.wait?.should == true
    lock_settings.turn_wait_off
    lock_settings.wait?.should == false
  end

  ################################################
  #  lock_for_environment_not_database?          #
	#  turn_lock_for_environment_not_database_on   #
	#  turn_lock_for_environment_not_database_off  #
  ################################################

  it "can lock for environment rather than for database" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.lock_for_environment_not_database?.should == false
    lock_settings.turn_lock_for_environment_not_database_on
    lock_settings.lock_for_environment_not_database?.should == true
    lock_settings.turn_lock_for_environment_not_database_off
    lock_settings.lock_for_environment_not_database?.should == false
  end

  #################
	#  set_timeout  #
  #  timeout      #
  #################

  it "can set and return its deadlock timeout" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.set_timeout( 42 )
    lock_settings.timeout.should == 42
  end

  #########################
	#  set_conflict_matrix  #
  #  conflict_matrix      #
  #########################

  it "can set and return its conflict matrix" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.set_conflict_matrix( 42 )
    lock_settings.conflict_matrix.should == 42
  end

  #####################
	#  set_max_lockers  #
  #  max_lockers      #
  #####################

  it "can set and return its maximum locker limit" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.set_max_lockers( 42 )
    lock_settings.max_lockers.should == 42
  end

  ###################
	#  set_max_locks  #
  #  max_locks      #
  ###################

  it "can set and return it maximum lock limit" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.set_max_locks( 42 )
    lock_settings.max_locks.should == 42
  end

  #####################
	#  set_max_objects  #
  #  max_objects      #
  #####################

  it "can set and return its maximum object limit" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.set_max_objects( 42 )
    lock_settings.max_objects.should == 42
  end

  ##############################
	#  set_number_of_partitions  #
  #  number_of_partitions      #
  ##############################

  it "can set and return its number of partitions" do
    lock_settings  = RPDB::Settings::Lock.new
    lock_settings.set_number_of_partitions( 42 )
    lock_settings.number_of_partitions.should == 42
  end

  ###########################################
  #  deadlock_detector_settings_controller  #
  ###########################################

  it "can return its deadlock detector settings controller" do
    RPDB::Settings::Lock.new.deadlock_detector_settings_controller.is_a?( RPDB::Settings::Lock::DeadlockDetector ).should == true
  end

end

