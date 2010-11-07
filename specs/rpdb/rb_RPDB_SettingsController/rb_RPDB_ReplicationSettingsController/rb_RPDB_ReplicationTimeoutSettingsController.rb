require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Replication::Timeout do

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

  # RPDB::Environment::Settings::Replication::Timeout.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Replication::Timeout.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Timeout.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Replication::Timeout.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Timeout.new( replication_settings_controller )
  it "can be created with a replication settings controller" do
    RPDB::Environment::Settings::Replication::Timeout.new( RPDB::Environment::Settings::Replication.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Timeout.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Replication::Timeout.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  ################
  #  initialize  #
  ################

  ########################
  #  parent_environment  #
  ########################

  ################################
  #  parent_settings_controller  #
  ################################

  ############################################
  #  parent_replication_settings_controller  #
  ############################################

  #############
  #  timeout  #
  #############

  #################
  #  set_timeout  #
  #################

  #######################################
  #  wait_time_before_checkpoint_write  #
  #######################################

  ###########################################
  #  set_wait_time_before_checkpoint_write  #
  ###########################################

  #######################################
  #  wait_time_before_retry_connection  #
  #######################################

  ###########################################
  #  set_wait_time_before_retry_connection  #
  ###########################################

  ######################
  #  election_timeout  #
  ######################

  ##########################
  #  set_election_timeout  #
  ##########################

  #####################################
  #  wait_time_before_retry_election  #
  #####################################

  #########################################
  #  set_wait_time_before_retry_election  #
  #########################################

  #########################################
  #  full_election_participation_timeout  #
  #########################################

  #############################################
  #  set_full_election_participation_timeout  #
  #############################################

  #############################
  #  heartbeat_monitor_pulse  #
  #############################

  #################################
  #  set_heartbeat_monitor_pulse  #
  #################################

  ###############################
  #  heartbeat_broadcast_pulse  #
  ###############################

  ###################################
  #  set_heartbeat_broadcast_pulse  #
  ###################################

  ###################
  #  lease_timeout  #
  ###################

  #######################
  #  set_lease_timeout  #
  #######################

end

