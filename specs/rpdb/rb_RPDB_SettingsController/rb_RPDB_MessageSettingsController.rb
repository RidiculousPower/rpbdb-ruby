require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Message do

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

  # RPDB::Environment::Settings::Message.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Message.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Message.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Message.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Message.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Message.new.should_not == nil
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

  ##########
  #  file  #
  ##########

  it "" do
    Fail
  end

  ##############
  #  set_file  #
  ##############

  it "" do
    Fail
  end

  ##########################
  #  set_message_callback  #
  ##########################

  it "" do
    Fail
  end

  ######################
  #  message_callback  #
  ######################

  it "" do
    Fail
  end

  ###############################
  #  set_panic_callback_method  #
  ###############################

  it "" do
    Fail
  end

  ###########################
  #  panic_callback_method  #
  ###########################

  it "" do
    Fail
  end

  ########################################################
  #  set_site_is_now_replication_client_callback_method  #
  ########################################################

  it "" do
    Fail
  end

  ####################################################
  #  site_is_now_replication_client_callback_method  #
  ####################################################

  it "" do
    Fail
  end

  #######################################################
  #  set_site_won_replication_election_callback_method  #
  #######################################################

  it "" do
    Fail
  end

  ###################################################
  #  site_won_replication_election_callback_method  #
  ###################################################

  it "" do
    Fail
  end

  #################################################################
  #  set_site_is_now_master_of_replication_group_callback_method  #
  #################################################################

  it "" do
    Fail
  end

  #############################################################
  #  site_is_now_master_of_replication_group_callback_method  #
  #############################################################

  it "" do
    Fail
  end

  ##########################################################
  #  set_replication_group_has_new_master_callback_method  #
  ##########################################################

  it "" do
    Fail
  end

  ######################################################
  #  replication_group_has_new_master_callback_method  #
  ######################################################

  it "" do
    Fail
  end

  ############################################################
  #  set_replication_acknowledgement_failed_callback_method  #
  ############################################################

  it "" do
    Fail
  end

  ########################################################
  #  replication_acknowledgement_failed_callback_method  #
  ########################################################

  it "" do
    Fail
  end

  #######################################################
  #  set_replication_startup_completed_callback_method  #
  #######################################################

  it "" do
    Fail
  end

  ###################################################
  #  replication_startup_completed_callback_method  #
  ###################################################

  it "" do
    Fail
  end

  ######################################
  #  set_write_failed_callback_method  #
  ######################################

  it "" do
    Fail
  end

  ##################################
  #  write_failed_callback_method  #
  ##################################

  it "" do
    Fail
  end

end

