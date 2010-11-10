require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings::Message do

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

  # RPDB::Settings::Message.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Message.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Message.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Message.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Message.new
  it "can be created with no argument specified" do
    RPDB::Settings::Message.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Message.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Message.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  set_file  #
  #  file      #
  ##############

  it "" do
    raise "Failed."
  end

  ##########################
  #  set_message_callback  #
  #  message_callback      #
  ##########################

  it "" do
    raise "Failed."
  end

  ###############################
  #  set_panic_callback_method  #
  #  panic_callback_method      #
  ###############################

  it "" do
    raise "Failed."
  end

  ########################################################
  #  set_site_is_now_replication_client_callback_method  #
  #  site_is_now_replication_client_callback_method      #
  ########################################################

  it "" do
    raise "Failed."
  end

  #######################################################
  #  set_site_won_replication_election_callback_method  #
  #  site_won_replication_election_callback_method      #
  #######################################################

  it "" do
    raise "Failed."
  end

  #################################################################
  #  set_site_is_now_master_of_replication_group_callback_method  #
  #  site_is_now_master_of_replication_group_callback_method      #
  #################################################################

  it "" do
    raise "Failed."
  end

  ##########################################################
  #  set_replication_group_has_new_master_callback_method  #
  #  replication_group_has_new_master_callback_method      #
  ##########################################################

  it "" do
    raise "Failed."
  end

  ############################################################
  #  set_replication_acknowledgement_failed_callback_method  #
  #  replication_acknowledgement_failed_callback_method      #
  ############################################################

  it "" do
    raise "Failed."
  end

  #######################################################
  #  set_replication_startup_completed_callback_method  #
  #  replication_startup_completed_callback_method      #
  #######################################################

  it "" do
    raise "Failed."
  end

  ######################################
  #  set_write_failed_callback_method  #
  #  write_failed_callback_method      #
  ######################################

  it "" do
    raise "Failed."
  end

end

