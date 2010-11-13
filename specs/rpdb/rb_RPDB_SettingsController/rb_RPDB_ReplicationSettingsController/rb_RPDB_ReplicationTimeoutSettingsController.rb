require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Replication::Timeout do

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

  # RPDB::Settings::Replication::Timeout.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Replication::Timeout.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Replication::Timeout.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Replication::Timeout.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Replication::Timeout.new( replication_settings_controller )
  it "can be created with a replication settings controller" do
    RPDB::Settings::Replication::Timeout.new( RPDB::Settings::Replication.new ).should_not == nil
  end

  # RPDB::Settings::Replication::Timeout.new
  it "can be created with no argument specified" do
    RPDB::Settings::Replication::Timeout.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Replication::Timeout.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Replication::Timeout.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_replication_settings_controller  #
  ############################################

  it "can return its parent replication settings controller" do
    RPDB::Settings::Replication::Timeout.new.parent_replication_settings_controller.should_not == nil
  end

  #################
  #  set_timeout  #
  #  timeout      #
  #################

  it "can set and report its timeout" do
    raise "Failed."
  end

  ###########################################
  #  set_wait_time_before_checkpoint_write  #
  #  wait_time_before_checkpoint_write      #
  ###########################################

  it "can set and report its wait time before writing a checkpoint" do
    raise "Failed."
  end

  ###########################################
  #  set_wait_time_before_retry_connection  #
  #  wait_time_before_retry_connection      #
  ###########################################

  it "can set and report its wait time before retrying a connection" do
    raise "Failed."
  end

  ##########################
  #  set_election_timeout  #
  #  election_timeout      #
  ##########################

  it "can set and report its election timeout" do
    raise "Failed."
  end

  #########################################
  #  set_wait_time_before_retry_election  #
  #  wait_time_before_retry_election      #
  #########################################

  it "can set and report its wait time before retrying election" do
    raise "Failed."
  end

  #############################################
  #  set_full_election_participation_timeout  #
  #  full_election_participation_timeout      #
  #############################################

  it "can set and report its timeout for full election participation" do
    raise "Failed."
  end

  #################################
  #  set_heartbeat_monitor_pulse  #
  #  heartbeat_monitor_pulse      #
  #################################

  it "can set and report its heartbeat monitor pulse rate" do
    raise "Failed."
  end

  ###################################
  #  set_heartbeat_broadcast_pulse  #
  #  heartbeat_broadcast_pulse      #
  ###################################

  it "can set and report its heartbeat broadcast pulse" do
    raise "Failed."
  end

  #######################
  #  set_lease_timeout  #
  #  lease_timeout      #
  #######################

  it "can set and report its lease timeout" do
    raise "Failed."
  end

end

