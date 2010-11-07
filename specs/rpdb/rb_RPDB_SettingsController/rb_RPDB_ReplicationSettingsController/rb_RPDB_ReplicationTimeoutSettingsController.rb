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

  it "" do
    Fail
  end

  ################
  #  initialize  #
  ################

  it "" do
    Fail
  end

  ########################
  #  parent_environment  #
  ########################

  it "" do
    Fail
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "" do
    Fail
  end

  ############################################
  #  parent_replication_settings_controller  #
  ############################################

  it "" do
    Fail
  end

  #############
  #  timeout  #
  #############

  it "" do
    Fail
  end

  #################
  #  set_timeout  #
  #################

  it "" do
    Fail
  end

  #######################################
  #  wait_time_before_checkpoint_write  #
  #######################################

  it "" do
    Fail
  end

  ###########################################
  #  set_wait_time_before_checkpoint_write  #
  ###########################################

  it "" do
    Fail
  end

  #######################################
  #  wait_time_before_retry_connection  #
  #######################################

  it "" do
    Fail
  end

  ###########################################
  #  set_wait_time_before_retry_connection  #
  ###########################################

  it "" do
    Fail
  end

  ######################
  #  election_timeout  #
  ######################

  it "" do
    Fail
  end

  ##########################
  #  set_election_timeout  #
  ##########################

  it "" do
    Fail
  end

  #####################################
  #  wait_time_before_retry_election  #
  #####################################

  it "" do
    Fail
  end

  #########################################
  #  set_wait_time_before_retry_election  #
  #########################################

  it "" do
    Fail
  end

  #########################################
  #  full_election_participation_timeout  #
  #########################################

  it "" do
    Fail
  end

  #############################################
  #  set_full_election_participation_timeout  #
  #############################################

  it "" do
    Fail
  end

  #############################
  #  heartbeat_monitor_pulse  #
  #############################

  it "" do
    Fail
  end

  #################################
  #  set_heartbeat_monitor_pulse  #
  #################################

  it "" do
    Fail
  end

  ###############################
  #  heartbeat_broadcast_pulse  #
  ###############################

  it "" do
    Fail
  end

  ###################################
  #  set_heartbeat_broadcast_pulse  #
  ###################################

  it "" do
    Fail
  end

  ###################
  #  lease_timeout  #
  ###################

  it "" do
    Fail
  end

  #######################
  #  set_lease_timeout  #
  #######################

  it "" do
    Fail
  end

end

