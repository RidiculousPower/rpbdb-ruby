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
    @environment.open
    RPDB::Settings::Replication.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Replication.new( settings_controller )
  it "can be created with a settings controller" do
    @environment.open
    RPDB::Settings::Replication.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Replication.new
  it "can be created with no argument specified" do
    @environment.open
    RPDB::Settings::Replication.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    @environment.open
    RPDB::Settings::Replication.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    @environment.open
    RPDB::Settings::Replication.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
  #  turn_on   #
  #  turn_off  #
  ##############

  it "can be turned on or off and report whether it is on or off" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.on?.should == false
    replication_settings.turn_on
    replication_settings.on?.should == true
    replication_settings.off?.should == false
    replication_settings.turn_off
    replication_settings.off?.should == true
  end

  ###############################################
  #  client_to_client_synchronization?          #
	#  turn_client_to_client_synchronization_on   #
	#  turn_client_to_client_synchronization_off  #
  ###############################################

  it "can be set for client-to-client synchronization" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.client_to_client_synchronization?.should == false
    replication_settings.turn_client_to_client_synchronization_on
    replication_settings.client_to_client_synchronization?.should == true
    replication_settings.turn_client_to_client_synchronization_off
    replication_settings.client_to_client_synchronization?.should == false
  end

  ###################################
  #  single_bulk_transfer?          #
	#  turn_single_bulk_transfer_on   #
	#  turn_single_bulk_transfer_off  #
  ###################################

  it "can be set for single bulk transfer" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.single_bulk_transfer?.should == false
    replication_settings.turn_single_bulk_transfer_on
    replication_settings.single_bulk_transfer?.should == true
    replication_settings.turn_single_bulk_transfer_off
    replication_settings.single_bulk_transfer?.should == false
  end

  #################################################
  #  delay_new_sync_until_explicit_call?          #
	#  turn_delay_new_sync_until_explicit_call_on   #
	#  turn_delay_new_sync_until_explicit_call_off  #
  #################################################

  it "can be set to delay new sync until an explicit sync call is made" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.delay_new_sync_until_explicit_call?.should == false
    replication_settings.turn_delay_new_sync_until_explicit_call_on
    replication_settings.delay_new_sync_until_explicit_call?.should == true
    replication_settings.turn_delay_new_sync_until_explicit_call_off
    replication_settings.delay_new_sync_until_explicit_call?.should == false
  end

  ################################
  #  use_master_leases?          #
	#  turn_use_master_leases_on   #
	#  turn_use_master_leases_off  #
  ################################

  it "can be set to use master leases or not" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.use_master_leases?.should == false
    replication_settings.turn_use_master_leases_on
    replication_settings.use_master_leases?.should == true
    replication_settings.turn_use_master_leases_off
    replication_settings.use_master_leases?.should == false
  end

  ############################################
  #  reinitialize_outdated_clients?          #
	#  turn_reinitialize_outdated_clients_on   #
	#  turn_reinitialize_outdated_clients_off  #
  ############################################

  it "can be set to reinitialize any outdated clients" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.reinitialize_outdated_clients?.should == false
    replication_settings.turn_reinitialize_outdated_clients_on
    replication_settings.reinitialize_outdated_clients?.should == true
    replication_settings.turn_reinitialize_outdated_clients_off
    replication_settings.reinitialize_outdated_clients?.should == false
  end

  ############################
  #  prohibit_wait?          #
	#  turn_prohibit_wait_on   #
	#  turn_prohibit_wait_off  #
  ############################

  it "can be set to prohibit waiting" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.prohibit_wait?.should == false
    replication_settings.turn_prohibit_wait_on
    replication_settings.prohibit_wait?.should == true
    replication_settings.turn_prohibit_wait_off
    replication_settings.prohibit_wait?.should == false
  end

  ######################################
  #  require_strict_majority?          #
	#  turn_require_strict_majority_on   #
	#  turn_require_strict_majority_off  #
  ######################################

  it "can be set to require a strict majority" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.require_strict_majority?.should == false
    replication_settings.turn_require_strict_majority_on
    replication_settings.require_strict_majority?.should == true
    replication_settings.turn_require_strict_majority_off
    replication_settings.require_strict_majority?.should == false
  end

  ###################
	#  set_is_master  #
  #  is_master?     #
  ###################

  it "can be set as master and report whether it is currently master" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.set_is_master
    replication_settings.is_master?.should == true
  end

  ###################
	#  set_is_client  #
  #  is_client?     #
  ###################

  it "can be set as client and report whether it is currently client" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.set_is_client
    replication_settings.is_client?.should == true
  end

  ###########################################
	#  set_start_as_client_or_rally_election  #
  #  start_as_client_or_rally_election?     #
  ###########################################

  it "can be set to start as client or to rally an election" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.set_start_as_client_or_rally_election
    replication_settings.start_as_client_or_rally_election?.should == true
  end

  ###############
	#  set_limit  #
  #  limit      #
  ###############

  it "can set its limit" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.set_limit( 42 )
    replication_settings.limit.should == 42
  end

  ##############
	#  set_host  #
  #  host      #
  ##############

  it "can set its host" do
    @environment.open
    replication_settings  = RPDB::Settings::Replication.new
    replication_settings.set_host( 'host.com' )
    replication_settings.host.should == 'host.com'
  end

  ##############
	#  set_port  #
  #  port      #
  ##############

  it "can set its port" do
    @environment.open
    replication_settings  = RPDB::Settings::Replication.new
    replication_settings.set_port( 42 )
    replication_settings.port.should == 42
  end

  ####################
	#  set_site_count  #
  #  site_count      #
  ####################

  it "can set and return its site count" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.set_site_count( 42 )
    replication_settings.site_count.should == 42
  end

  ###############################
	#  set_priority_order_number  #
  #  priority_order_number      #
  ###############################

  it "can set and return its priority order number" do
    replication_settings  = RPDB::Settings::Replication.new( @environment )
    replication_settings.turn_on
    replication_settings.set_priority_order_number( 42 )
    replication_settings.priority_order_number.should == 42
  end

  ##########################################
	#  set_retransmission_threshold_minimum  #
  #  retransmission_threshold_minimum      #
  ##########################################

  it "can set and return its retransmission minimum threshold" do
    @environment.open
    replication_settings  = RPDB::Settings::Replication.new
    replication_settings.set_retransmission_threshold_minimum( 42 )
    replication_settings.retransmission_threshold_minimum.should == 42
  end

  ##########################################
	#  set_retransmission_threshold_maximum  #
  #  retransmission_threshold_maximum      #
  ##########################################

  it "can set and return its retransmission maximum threshold" do
    @environment.open
    replication_settings  = RPDB::Settings::Replication.new
    replication_settings.set_retransmission_threshold_maximum( 42 )
    replication_settings.retransmission_threshold_maximum.should == 42
  end

  #############################
	#  set_slowest_clock_value  #
  #  slowest_clock_value      #
  #############################

  # FIX - name of fastest/slowest should probably correspond
  it "can set and return the slowest clock value" do
    @environment.open
    replication_settings  = RPDB::Settings::Replication.new
    replication_settings.set_slowest_clock_value( 42 )
    replication_settings.slowest_clock_value.should == 42
  end

  ##################################
	#  set_fastest_clock_skew_value  #
  #  fastest_clock_skew_value      #
  ##################################

  it "can set and return the fastest clock skew value" do
    @environment.open
    replication_settings  = RPDB::Settings::Replication.new
    replication_settings.set_fastest_clock_skew_value( 42 )
    replication_settings.fastest_clock_skew_value.should == 42
  end

  ##################################
  #  election_settings_controller  #
  ##################################

  it "can return its election settings controller" do
    @environment.open
    RPDB::Settings::Replication.new.election_settings_controller.is_a?( RPDB::Settings::Replication::Election ).should == true
  end

  #################################
  #  timeout_settings_controller  #
  #################################

  it "can return its timeout settings controller" do
    @environment.open
    RPDB::Settings::Replication.new.timeout_settings_controller.is_a?( RPDB::Settings::Replication::Timeout ).should == true
  end

end

