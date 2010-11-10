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

  it "" do
    raise "Failed."
  end

  ##############################################
  #  client_to_client_synchronization          #
	#  turn_client_to_client_synchronization_on  #
  ##############################################

  it "" do
    raise "Failed."
  end

  ###################################
  #  single_bulk_transfer?          #
	#  turn_single_bulk_transfer_on   #
	#  turn_single_bulk_transfer_off  #
  ###################################

  it "" do
    raise "Failed."
  end

  #################################################
  #  delay_new_sync_until_explicit_call?          #
	#  turn_delay_new_sync_until_explicit_call_on   #
	#  turn_delay_new_sync_until_explicit_call_off  #
  #################################################

  it "" do
    raise "Failed."
  end

  ################################
  #  use_master_leases?          #
	#  turn_use_master_leases_on   #
	#  turn_use_master_leases_off  #
  ################################

  it "" do
    raise "Failed."
  end

  ############################################
  #  reinitialize_outdated_clients?          #
	#  turn_reinitialize_outdated_clients_on   #
	#  turn_reinitialize_outdated_clients_off  #
  ############################################

  it "" do
    raise "Failed."
  end

  ############################
  #  prohibit_wait?          #
	#  turn_prohibit_wait_on   #
	#  turn_prohibit_wait_off  #
  ############################

  it "" do
    raise "Failed."
  end

  ######################################
  #  require_strict_majority?          #
	#  turn_require_strict_majority_on   #
	#  turn_require_strict_majority_off  #
  ######################################

  it "" do
    raise "Failed."
  end

  ###################
	#  set_is_master  #
  #  is_master?     #
  ###################

  it "" do
    raise "Failed."
  end

  ###################
	#  set_is_client  #
  #  is_client?     #
  ###################

  it "" do
    raise "Failed."
  end

  ###########################################
	#  set_start_as_client_or_rally_election  #
  #  start_as_client_or_rally_election      #
  ###########################################

  it "" do
    raise "Failed."
  end

  ###############
	#  set_limit  #
  #  limit      #
  ###############

  it "" do
    raise "Failed."
  end

  ##############
	#  set_host  #
  #  host      #
  ##############

  it "" do
    raise "Failed."
  end

  ##############
	#  set_port  #
  #  port      #
  ##############

  it "" do
    raise "Failed."
  end

  ####################
	#  set_site_count  #
  #  site_count      #
  ####################

  it "" do
    raise "Failed."
  end

  ###############################
	#  set_priority_order_number  #
  #  priority_order_number      #
  ###############################

  it "" do
    raise "Failed."
  end

  ##########################################
	#  set_retransmission_threshold_minimum  #
  #  retransmission_threshold_minimum      #
  ##########################################

  it "" do
    raise "Failed."
  end

  ##########################################
	#  set_retransmission_threshold_maximum  #
  #  retransmission_threshold_maximum      #
  ##########################################

  it "" do
    raise "Failed."
  end

  #############################
	#  set_slowest_clock_value  #
  #  slowest_clock_value      #
  #############################

  it "" do
    raise "Failed."
  end

  ##################################
	#  set_fastest_clock_skew_value  #
  #  fastest_clock_skew_value      #
  ##################################

  it "" do
    raise "Failed."
  end

  ##################################
  #  election_settings_controller  #
  ##################################

  it "" do
    raise "Failed."
  end

  #################################
  #  timeout_settings_controller  #
  #################################

  it "" do
    raise "Failed."
  end

end

