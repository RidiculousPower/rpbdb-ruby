require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings::Transaction do

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

  # RPDB::Settings::Transaction.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Transaction.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Transaction.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Transaction.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Transaction.new
  it "can be created with no argument specified" do
    RPDB::Settings::Transaction.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Transaction.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Transaction.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
	#  turn_on   #
	#  turn_off  #
  ##############

  it "" do
    raise "Failed."
  end

  #####################################
  #  prohibit_sync_on_write?          #
	#  turn_prohibit_sync_on_write_on   #
	#  turn_prohibit_sync_on_write_off  #
  #####################################

  it "" do
    raise "Failed."
  end

  ##################################################
  #  prohibit_sync_on_commit_transaction?          #
	#  turn_prohibit_sync_on_commit_transaction_on   #
	#  turn_prohibit_sync_on_commit_transaction_off  #
  ##################################################

  it "" do
    raise "Failed."
  end

  ################################################
  #  timeout_returns_deny_not_deadlock?          #
	#  turn_timeout_returns_deny_not_deadlock_on   #
	#  turn_timeout_returns_deny_not_deadlock_off  #
  ################################################

  it "" do
    raise "Failed."
  end

  ############################################
  #  concurrent_data_store_locking?          #
	#  turn_concurrent_data_store_locking_on   #
	#  turn_concurrent_data_store_locking_off  #
  ############################################

  it "" do
    raise "Failed."
  end

  #################################
  #  snapshot_isolation?          #
	#  turn_snapshot_isolation_on   #
	#  turn_snapshot_isolation_off  #
  #################################

  it "" do
    raise "Failed."
  end

  ###################################
  #  degree_one_isolation?          #
	#  turn_degree_one_isolation_on   #
	#  turn_degree_one_isolation_off  #
  ###################################

  it "" do
    raise "Failed."
  end

  ###################################
  #  degree_two_isolation?          #
	#  turn_degree_two_isolation_on   #
	#  turn_degree_two_isolation_off  #
  ###################################

  it "" do
    raise "Failed."
  end

  ##################################################
  #  enclose_all_activity_in_transaction?          #
	#  turn_enclose_all_activity_in_transaction_on   #
	#  turn_enclose_all_activity_in_transaction_off  #
  ##################################################

  it "" do
    raise "Failed."
  end

  ###############################################
  #  environmental_snapshot_isolation?          #
	#  turn_environmental_snapshot_isolation_on   #
	#  turn_environmental_snapshot_isolation_off  #
  ###############################################

  it "" do
    raise "Failed."
  end

  #############################
  #  sync_on_commit           #
	#  turn_sync_on_commit_on   #
	#  turn_sync_on_commit_off  #
  #############################

  it "" do
    raise "Failed."
  end

  #############################
  #  wait_for_locks           #
	#  turn_wait_for_locks_on   #
	#  turn_wait_for_locks_off  #
  #############################

  it "" do
    raise "Failed."
  end

  ###################################################
  #  set_maximum_number_of_transactions_to_recover  #
  #  maximum_number_of_transactions_to_recover      #
  ###################################################

  it "" do
    raise "Failed."
  end

  #################
  #  set_timeout  #
  #  timeout      #
  #################

  it "" do
    raise "Failed."
  end

  ##################
  #  set_max_open  #
  #  max_open      #
  ##################

  it "" do
    raise "Failed."
  end

  ###################
  #  set_timestamp  #
  #  timestamp      #
  ###################

  it "" do
    raise "Failed."
  end

  ######################################
  #  set_rollbackward_callback_method  #
  #  rollbackward_callback_method      #
  ######################################

  it "" do
    raise "Failed."
  end

  #####################################
  #  set_rollforward_callback_method  #
  #  rollforward_callback_method      #
  #####################################

  it "" do
    raise "Failed."
  end

  ###############################
  #  set_abort_callback_method  #
  #  abort_callback_method      #
  ###############################

  it "" do
    raise "Failed."
  end

  ###############################
  #  set_apply_callback_method  #
  #  apply_callback_method      #
  ###############################

  it "" do
    raise "Failed."
  end

  ###############################
  #  set_print_callback_method  #
  #  print_callback_method      #
  ###############################

  it "" do
    raise "Failed."
  end

end

