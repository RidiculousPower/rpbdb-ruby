require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Replication do

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

  # RPDB::Settings::Replication.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Replication.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Replication.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Replication.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Replication.new
  it "can be created with no argument specified" do
    RPDB::Settings::Replication.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Replication.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Replication.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
  #  turn_on   #
  #  turn_off  #
  ##############

  it "can be turned on or off and report whether it is on or off" do
    raise "Failed."
  end

  ###############################################
  #  client_to_client_synchronization           #
	#  turn_client_to_client_synchronization_on   #
	#  turn_client_to_client_synchronization_off  #
  ###############################################

  it "can be set for client-to-client synchronization" do
    raise "Failed."
  end

  ###################################
  #  single_bulk_transfer?          #
	#  turn_single_bulk_transfer_on   #
	#  turn_single_bulk_transfer_off  #
  ###################################

  it "can be set for single bulk transfer" do
    raise "Failed."
  end

  #################################################
  #  delay_new_sync_until_explicit_call?          #
	#  turn_delay_new_sync_until_explicit_call_on   #
	#  turn_delay_new_sync_until_explicit_call_off  #
  #################################################

  it "can be set to delay new sync until an explicit sync call is made" do
    raise "Failed."
  end

  ################################
  #  use_master_leases?          #
	#  turn_use_master_leases_on   #
	#  turn_use_master_leases_off  #
  ################################

  it "can be set to use master leases or not" do
    raise "Failed."
  end

  ############################################
  #  reinitialize_outdated_clients?          #
	#  turn_reinitialize_outdated_clients_on   #
	#  turn_reinitialize_outdated_clients_off  #
  ############################################

  it "can be set to reinitialize any outdated clients" do
    raise "Failed."
  end

  ############################
  #  prohibit_wait?          #
	#  turn_prohibit_wait_on   #
	#  turn_prohibit_wait_off  #
  ############################

  it "can be set to prohibit waiting" do
    raise "Failed."
  end

  ######################################
  #  require_strict_majority?          #
	#  turn_require_strict_majority_on   #
	#  turn_require_strict_majority_off  #
  ######################################

  it "can be set to require a strict majority" do
    raise "Failed."
  end

  ###################
	#  set_is_master  #
  #  is_master?     #
  ###################

  it "can be set as master and report whether it is currently master" do
    raise "Failed."
  end

  ###################
	#  set_is_client  #
  #  is_client?     #
  ###################

  it "can be set as client and report whether it is currently client" do
    raise "Failed."
  end

  ###########################################
	#  set_start_as_client_or_rally_election  #
  #  start_as_client_or_rally_election      #
  ###########################################

  it "can be set to start as client or to rally an election" do
    raise "Failed."
  end

  ###############
	#  set_limit  #
  #  limit      #
  ###############

  it "can set its limit" do
    raise "Failed."
  end

  ##############
	#  set_host  #
  #  host      #
  ##############

  it "can set its host" do
    raise "Failed."
  end

  ##############
	#  set_port  #
  #  port      #
  ##############

  it "can set its port" do
    raise "Failed."
  end

  ####################
	#  set_site_count  #
  #  site_count      #
  ####################

  it "can set and return its site count" do
    raise "Failed."
  end

  ###############################
	#  set_priority_order_number  #
  #  priority_order_number      #
  ###############################

  it "can set and return its priority order number" do
    raise "Failed."
  end

  ##########################################
	#  set_retransmission_threshold_minimum  #
  #  retransmission_threshold_minimum      #
  ##########################################

  it "can set and return its retransmission minimum threshold" do
    raise "Failed."
  end

  ##########################################
	#  set_retransmission_threshold_maximum  #
  #  retransmission_threshold_maximum      #
  ##########################################

  it "can set and return its retransmission maximum threshold" do
    raise "Failed."
  end

  #############################
	#  set_slowest_clock_value  #
  #  slowest_clock_value      #
  #############################

  # FIX - name of fastest/slowest should probably correspond
  it "can set and return the slowest clock value" do
    raise "Failed."
  end

  ##################################
	#  set_fastest_clock_skew_value  #
  #  fastest_clock_skew_value      #
  ##################################

  it "can set and return the fastest clock skew value" do
    raise "Failed."
  end

  ##################################
  #  election_settings_controller  #
  ##################################

  it "can return its election settings controller" do
    raise "Failed."
  end

  #################################
  #  timeout_settings_controller  #
  #################################

  it "can return its timeout settings controller" do
    raise "Failed."
  end

end

