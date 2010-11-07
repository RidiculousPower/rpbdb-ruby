require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Replication::Verbosity do

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

  # RPDB::Environment::Settings::Replication::Verbosity.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Replication::Verbosity.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Replication::Verbosity.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Verbosity.new( replication_settings_controller )
  it "can be created with a replication settings controller" do
    RPDB::Environment::Settings::Replication::Verbosity.new( RPDB::Environment::Settings::Replication.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Verbosity.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Replication::Verbosity.new.should_not == nil
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

  #########################################
  #  display_all_replication_information  #
  #########################################


  	#################################################
  	#  turn_display_all_replication_information_on  #
  	#################################################

  	##################################################
  	#  turn_display_all_replication_information_off  #
  	##################################################

  ##################################
  #  display_election_information  #
  ##################################

  	##########################################
  	#  turn_display_election_information_on  #
  	##########################################


  	###########################################
  	#  turn_display_election_information_off  #
  	###########################################

  ##################################################
  #  display_replication_master_lease_information  #
  ##################################################


  	##########################################################
  	#  turn_display_replication_master_lease_information_on  #
  	##########################################################

  	###########################################################
  	#  turn_display_replication_master_lease_information_off  #
  	###########################################################

  #########################################
  #  display_misc_processing_information  #
  #########################################

  	#################################################
  	#  turn_display_misc_processing_information_on  #
  	#################################################

  	##################################################
  	#  turn_display_misc_processing_information_off  #
  	##################################################

  ############################################
  #  display_message_processing_information  #
  ############################################

  	####################################################
  	#  turn_display_message_processing_information_on  #
  	####################################################

  	#####################################################
  	#  turn_display_message_processing_information_off  #
  	#####################################################


  ################################################
  #  display_client_synchronization_information  #
  ################################################

  	########################################################
  	#  turn_display_client_synchronization_information_on  #
  	########################################################

  	#########################################################
  	#  turn_display_client_synchronization_information_off  #
  	#########################################################

  ####################################################
  #  display_manager_connection_failure_information  #
  ####################################################

  	############################################################
  	#  turn_display_manager_connection_failure_information_on  #
  	############################################################

  	#############################################################
  	#  turn_display_manager_connection_failure_information_off  #
  	#############################################################

  #####################################
  #  display_manager_misc_processing  #
  #####################################

  	#############################################
  	#  turn_display_manager_misc_processing_on  #
  	#############################################


  	##############################################
  	#  turn_display_manager_misc_processing_off  #
  	##############################################

end

