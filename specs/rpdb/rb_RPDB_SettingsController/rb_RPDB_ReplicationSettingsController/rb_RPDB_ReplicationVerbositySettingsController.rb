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

  it "can be set to display all replication information" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_all_replication_information?.should == false
    verbosity_settings.turn_display_all_replication_information_on
    verbosity_settings.display_all_replication_information?.should == true
    verbosity_settings.turn_display_all_replication_information_off
    verbosity_settings.display_all_replication_information?.should == false
  end

  ###########################################
  #  display_election_information?          #
	#  turn_display_election_information_on   #
	#  turn_display_election_information_off  #
  ###########################################

  it "can be set to display election information" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_election_information?.should == false
    verbosity_settings.turn_display_election_information_on
    verbosity_settings.display_election_information?.should == true
    verbosity_settings.turn_display_election_information_off
    verbosity_settings.display_election_information?.should == false
  end

  ###########################################################
  #  display_replication_master_lease_information?          #
	#  turn_display_replication_master_lease_information_on   #
	#  turn_display_replication_master_lease_information_off  #
  ###########################################################

  it "can be set to display replication master lease information" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_replication_master_lease_information?.should == false
    verbosity_settings.turn_display_replication_master_lease_information_on
    verbosity_settings.display_replication_master_lease_information?.should == true
    verbosity_settings.turn_display_replication_master_lease_information_off
    verbosity_settings.display_replication_master_lease_information?.should == false
  end

  ##################################################
  #  display_misc_processing_information?          #
	#  turn_display_misc_processing_information_on   #
	#  turn_display_misc_processing_information_off  #
  ##################################################

  it "can be set to display miscellaneous processing information" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_misc_processing_information?.should == false
    verbosity_settings.turn_display_misc_processing_information_on
    verbosity_settings.display_misc_processing_information?.should == true
    verbosity_settings.turn_display_misc_processing_information_off
    verbosity_settings.display_misc_processing_information?.should == false
  end

  #####################################################
  #  display_message_processing_information?          #
	#  turn_display_message_processing_information_on   #
	#  turn_display_message_processing_information_off  #
  #####################################################

  it "can be set to display message processing information" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_message_processing_information?.should == false
    verbosity_settings.turn_display_message_processing_information_on
    verbosity_settings.display_message_processing_information?.should == true
    verbosity_settings.turn_display_message_processing_information_off
    verbosity_settings.display_message_processing_information?.should == false
  end

  #########################################################
  #  display_client_synchronization_information?          #
	#  turn_display_client_synchronization_information_on   #
	#  turn_display_client_synchronization_information_off  #
  #########################################################

  it "can be set to display client synchronization information" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_client_synchronization_information?.should == false
    verbosity_settings.turn_display_client_synchronization_information_on
    verbosity_settings.display_client_synchronization_information?.should == true
    verbosity_settings.turn_display_client_synchronization_information_off
    verbosity_settings.display_client_synchronization_information?.should == false
  end

  #############################################################
  #  display_manager_connection_failure_information?          #
	#  turn_display_manager_connection_failure_information_on   #
	#  turn_display_manager_connection_failure_information_off  #
  #############################################################

  it "can be set to display manager connection failure information" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_manager_connection_failure_information?.should == false
    verbosity_settings.turn_display_manager_connection_failure_information_on
    verbosity_settings.display_manager_connection_failure_information?.should == true
    verbosity_settings.turn_display_manager_connection_failure_information_off
    verbosity_settings.display_manager_connection_failure_information?.should == false
  end

  ##############################################
  #  display_manager_misc_processing?          #
	#  turn_display_manager_misc_processing_on   #
	#  turn_display_manager_misc_processing_off  #
  ##############################################

  it "can be set to display manager miscellaneous processing" do
    verbosity_settings  = RPDB::Settings::Replication::Verbosity.new
    verbosity_settings.display_manager_misc_processing?.should == false
    verbosity_settings.turn_display_manager_misc_processing_on
    verbosity_settings.display_manager_misc_processing?.should == true
    verbosity_settings.turn_display_manager_misc_processing_off
    verbosity_settings.display_manager_misc_processing?.should == false
  end

end

