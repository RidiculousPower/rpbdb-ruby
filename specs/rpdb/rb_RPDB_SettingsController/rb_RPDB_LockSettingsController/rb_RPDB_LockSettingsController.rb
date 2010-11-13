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
    raise "Failed."
  end

  ###############################
  #  prohibit_locking?          #
	#  turn_prohibit_locking_on   #
	#  turn_prohibit_locking_off  #
  ###############################

  it "can prohibit locking" do
    raise "Failed."
  end

  #######################################################
  #  timeout_returns_return_deny_not_deadlock           #
	#  turn_timeout_returns_return_deny_not_deadlock_on   #
	#  turn_timeout_returns_return_deny_not_deadlock_off  #
  #######################################################

  it "can return deny rather than deadlock on timeout" do
    raise "Failed."
  end

  ###################
  #  wait?          #
	#  turn_wait_on   #
	#  turn_wait_off  #
  ###################

  it "can be set to wait on deadlock" do
    raise "Failed."
  end

  ################################################
  #  lock_for_environment_not_database?          #
	#  turn_lock_for_environment_not_database_on   #
	#  turn_lock_for_environment_not_database_off  #
  ################################################

  it "can lock for environment rather than for database" do
    raise "Failed."
  end

  #################
	#  set_timeout  #
  #  timeout      #
  #################

  it "can set and return its deadlock timeout" do
    raise "Failed."
  end

  #########################
	#  set_conflict_matrix  #
  #  conflict_matrix      #
  #########################

  it "can set and return its conflict matrix" do
    raise "Failed."
  end

  #####################
	#  set_max_lockers  #
  #  max_lockers      #
  #####################

  it "can set and return its maximum locker limit" do
    raise "Failed."
  end

  ###################
	#  set_max_locks  #
  #  max_locks      #
  ###################

  it "can set and return it maximum lock limit" do
    raise "Failed."
  end

  #####################
	#  set_max_objects  #
  #  max_objects      #
  #####################

  it "can set and return its maximum object limit" do
    raise "Failed."
  end

  ##############################
	#  set_number_of_partitions  #
  #  number_of_partitions      #
  ##############################

  it "can set and return its number of partitions" do
    raise "Failed."
  end

  ###########################################
  #  deadlock_detector_settings_controller  #
  ###########################################

  it "can return its deadlock detector settings controller" do
    raise "Failed."
  end

end

