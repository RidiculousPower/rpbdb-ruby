require_relative '../../../lib/rpbdb.rb'

describe RPbdb::Settings::Transaction do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )

  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPbdb::Settings::Transaction.new( environment )
  it "can be created with an environment" do
    @environment.open
    RPbdb::Settings::Transaction.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Transaction.new( settings_controller )
  it "can be created with a settings controller" do
    @environment.open
    RPbdb::Settings::Transaction.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Transaction.new
  it "can be created with no argument specified" do
    @environment.open
    RPbdb::Settings::Transaction.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    @environment.open
    RPbdb::Settings::Transaction.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    @environment.open
    RPbdb::Settings::Transaction.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
	#  turn_on   #
	#  turn_off  #
  ##############

  it "can be turned on and off as well as report whether it is on or off" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.on?.should == false
    transaction_settings.turn_on
    transaction_settings.on?.should == true
    transaction_settings.off?.should == false
    transaction_settings.turn_off
    transaction_settings.off?.should == true
  end

  #####################################
  #  prohibit_sync_on_write?          #
	#  turn_prohibit_sync_on_write_on   #
	#  turn_prohibit_sync_on_write_off  #
  #####################################

  it "can prohibit sync on writing" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.prohibit_sync_on_write?.should == false
    transaction_settings.turn_prohibit_sync_on_write_on
    transaction_settings.prohibit_sync_on_write?.should == true
    transaction_settings.turn_prohibit_sync_on_write_off
    transaction_settings.prohibit_sync_on_write?.should == false
  end

  ##################################################
  #  prohibit_sync_on_commit_transaction?          #
	#  turn_prohibit_sync_on_commit_transaction_on   #
	#  turn_prohibit_sync_on_commit_transaction_off  #
  ##################################################

  it "can prohibit sync on commiting a transaction" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.prohibit_sync_on_commit_transaction?.should == false
    transaction_settings.turn_prohibit_sync_on_commit_transaction_on
    transaction_settings.prohibit_sync_on_commit_transaction?.should == true
    transaction_settings.turn_prohibit_sync_on_commit_transaction_off
    transaction_settings.prohibit_sync_on_commit_transaction?.should == false
  end

  ################################################################
  #  timeout_in_microseconds_returns_deny_not_deadlock?          #
	#  turn_timeout_in_microseconds_returns_deny_not_deadlock_on   #
	#  turn_timeout_in_microseconds_returns_deny_not_deadlock_off  #
  ################################################################

  it "can return deny instead of deadlock on timeout" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.timeout_in_microseconds_returns_deny_not_deadlock?.should == false
    transaction_settings.turn_timeout_in_microseconds_returns_deny_not_deadlock_on
    transaction_settings.timeout_in_microseconds_returns_deny_not_deadlock?.should == true
    transaction_settings.turn_timeout_in_microseconds_returns_deny_not_deadlock_off
    transaction_settings.timeout_in_microseconds_returns_deny_not_deadlock?.should == false
  end

  ############################################
  #  concurrent_data_store_locking?          #
	#  turn_concurrent_data_store_locking_on   #
	#  turn_concurrent_data_store_locking_off  #
  ############################################

  it "can be set as a concurrent data store for locking strategies" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.concurrent_data_store_locking?.should == false
    transaction_settings.turn_concurrent_data_store_locking_on
    transaction_settings.concurrent_data_store_locking?.should == true
    transaction_settings.turn_concurrent_data_store_locking_off
    transaction_settings.concurrent_data_store_locking?.should == false
  end

  #################################
  #  snapshot_isolation?          #
	#  turn_snapshot_isolation_on   #
	#  turn_snapshot_isolation_off  #
  #################################

  it "can be set for snapshot isolation, ..." do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.snapshot_isolation?.should == false
    transaction_settings.turn_snapshot_isolation_on
    transaction_settings.snapshot_isolation?.should == true
    transaction_settings.turn_snapshot_isolation_off
    transaction_settings.snapshot_isolation?.should == false
  end

  ###################################
  #  degree_one_isolation?          #
	#  turn_degree_one_isolation_on   #
	#  turn_degree_one_isolation_off  #
  ###################################

  it "can be set for degree one isolation, ..." do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.degree_one_isolation?.should == false
    transaction_settings.turn_degree_one_isolation_on
    transaction_settings.degree_one_isolation?.should == true
    transaction_settings.turn_degree_one_isolation_off
    transaction_settings.degree_one_isolation?.should == false
  end

  ###################################
  #  degree_two_isolation?          #
	#  turn_degree_two_isolation_on   #
	#  turn_degree_two_isolation_off  #
  ###################################

  it "can be set for degree two isolation, ..." do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.degree_two_isolation?.should == false
    transaction_settings.turn_degree_two_isolation_on
    transaction_settings.degree_two_isolation?.should == true
    transaction_settings.turn_degree_two_isolation_off
    transaction_settings.degree_two_isolation?.should == false
  end

  ##################################################
  #  enclose_all_activity_in_transaction?          #
	#  turn_enclose_all_activity_in_transaction_on   #
	#  turn_enclose_all_activity_in_transaction_off  #
  ##################################################

  it "can be set to enclose all activity in a transaction" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.enclose_all_activity_in_transaction?.should == false
    transaction_settings.turn_enclose_all_activity_in_transaction_on
    transaction_settings.enclose_all_activity_in_transaction?.should == true
    transaction_settings.turn_enclose_all_activity_in_transaction_off
    transaction_settings.enclose_all_activity_in_transaction?.should == false
  end

  ###############################################
  #  environmental_snapshot_isolation?          #
	#  turn_environmental_snapshot_isolation_on   #
	#  turn_environmental_snapshot_isolation_off  #
  ###############################################

  it "can be set for environmental snapshot isolation" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.environmental_snapshot_isolation?.should == false
    transaction_settings.turn_environmental_snapshot_isolation_on
    transaction_settings.environmental_snapshot_isolation?.should == true
    transaction_settings.turn_environmental_snapshot_isolation_off
    transaction_settings.environmental_snapshot_isolation?.should == false
  end

  #############################
  #  sync_on_commit?          #
	#  turn_sync_on_commit_on   #
	#  turn_sync_on_commit_off  #
  #############################

  it "can be set to sync on commit" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.sync_on_commit?.should == false
    transaction_settings.turn_sync_on_commit_on
    transaction_settings.sync_on_commit?.should == true
    transaction_settings.turn_sync_on_commit_off
    transaction_settings.sync_on_commit?.should == false
  end

  #############################
  #  wait_for_locks?          #
	#  turn_wait_for_locks_on   #
	#  turn_wait_for_locks_off  #
  #############################

  it "can be set to wait for locks" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.wait_for_locks?.should == false
    transaction_settings.turn_wait_for_locks_on
    transaction_settings.wait_for_locks?.should == true
    transaction_settings.turn_wait_for_locks_off
    transaction_settings.wait_for_locks?.should == false
  end

  ###################################################
  #  set_maximum_number_of_transactions_to_recover  #
  #  maximum_number_of_transactions_to_recover      #
  ###################################################

  it "can set and return its maximum number of transactions to recover" do
    transaction_settings  = RPbdb::Settings::Transaction.new( @environment )
    transaction_settings.set_maximum_number_of_transactions_to_recover( 42 )
    transaction_settings.maximum_number_of_transactions_to_recover.should == 42
    @environment.open
  end

  #################################
  #  set_timeout_in_microseconds  #
  #  timeout_in_microseconds      #
  #################################

  it "can set and return its timeout" do
    @environment.open
    transaction_settings  = RPbdb::Settings::Transaction.new
    transaction_settings.set_timeout_in_microseconds( 42 )
    transaction_settings.timeout_in_microseconds.should == 42
  end

  ##################
  #  set_max_open  #
  #  max_open      #
  ##################

  it "can set and return its maximum number of open transactions" do
    transaction_settings  = RPbdb::Settings::Transaction.new( @environment )
    transaction_settings.set_max_open( 42 )
    transaction_settings.max_open.should == 42
  end

  ############################
  #  set_recovery_timestamp  #
  #  recovery_timestamp      #
  ############################

  it "can set and return its timestamp" do
    transaction_settings  = RPbdb::Settings::Transaction.new( @environment )
    transaction_settings.set_recovery_timestamp( 42 )
    transaction_settings.recovery_timestamp.should == 42
  end

  ######################################
  #  set_rollbackward_callback_method  #
  #  rollbackward_callback_method      #
  ######################################

  it "can set and return its calback method for rolling a transaction backward" do
    @environment.open
    raise "Callback."
  end

  #####################################
  #  set_rollforward_callback_method  #
  #  rollforward_callback_method      #
  #####################################

  it "can set and return its calback method for rolling a transaction forward" do
    @environment.open
    raise "Callback."
  end

  ###############################
  #  set_abort_callback_method  #
  #  abort_callback_method      #
  ###############################

  it "can set and return its callback method for aborting" do
    @environment.open
    raise "Callback."
  end

  ###############################
  #  set_apply_callback_method  #
  #  apply_callback_method      #
  ###############################

  it "can set and return its callback method for applying" do
    @environment.open
    raise "Callback."
  end

  ###############################
  #  set_print_callback_method  #
  #  print_callback_method      #
  ###############################

  it "can set and return its callback method for printing" do
    @environment.open
    raise "Callback."
  end

end

