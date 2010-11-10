require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Replication::Verbosity do

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

  # RPDB::Settings::Replication::Verbosity.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Replication::Verbosity.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Replication::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Replication::Verbosity.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Replication::Verbosity.new( replication_settings_controller )
  it "can be created with a replication settings controller" do
    RPDB::Settings::Replication::Verbosity.new( RPDB::Settings::Replication.new ).should_not == nil
  end

  # RPDB::Settings::Replication::Verbosity.new
  it "can be created with no argument specified" do
    RPDB::Settings::Replication::Verbosity.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Replication::Verbosity.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Replication::Verbosity.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_replication_settings_controller  #
  ############################################

  it "can return its parent replication settings controller" do
    RPDB::Settings::Replication::Verbosity.new.parent_replication_settings_controller.should_not == nil
  end

  ##################################################
  #  display_all_replication_information?          #
	#  turn_display_all_replication_information_on   #
	#  turn_display_all_replication_information_off  #
  ##################################################

  it "" do
    raise "Failed."
  end

  ###########################################
  #  display_election_information?          #
	#  turn_display_election_information_on   #
	#  turn_display_election_information_off  #
  ###########################################

  it "" do
    raise "Failed."
  end

  ###########################################################
  #  display_replication_master_lease_information?          #
	#  turn_display_replication_master_lease_information_on   #
	#  turn_display_replication_master_lease_information_off  #
  ###########################################################

  it "" do
    raise "Failed."
  end

  ##################################################
  #  display_misc_processing_information?          #
	#  turn_display_misc_processing_information_on   #
	#  turn_display_misc_processing_information_off  #
  ##################################################

  it "" do
    raise "Failed."
  end

  #####################################################
  #  display_message_processing_information?          #
	#  turn_display_message_processing_information_on   #
	#  turn_display_message_processing_information_off  #
  #####################################################

  it "" do
    raise "Failed."
  end

  #########################################################
  #  display_client_synchronization_information?          #
	#  turn_display_client_synchronization_information_on   #
	#  turn_display_client_synchronization_information_off  #
  #########################################################

  it "" do
    raise "Failed."
  end

  #############################################################
  #  display_manager_connection_failure_information?          #
	#  turn_display_manager_connection_failure_information_on   #
	#  turn_display_manager_connection_failure_information_off  #
  #############################################################

  it "" do
    raise "Failed."
  end

  ##############################################
  #  display_manager_misc_processing           #
	#  turn_display_manager_misc_processing_on   #
	#  turn_display_manager_misc_processing_off  #
  ##############################################

  it "" do
    raise "Failed."
  end

end

