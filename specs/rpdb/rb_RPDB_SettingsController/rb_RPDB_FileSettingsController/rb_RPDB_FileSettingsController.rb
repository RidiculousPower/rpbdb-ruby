require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::DatabaseController::Database do

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

  # RPDB::Environment::Settings::File.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::File.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::File.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::File.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::File.new
  it "can be created with no environment specified" do
    RPDB::Environment::Settings::File.new.should_not == nil
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

  #################################
  #  intermediate_directory_mode  #
  #################################

  	#####################################
  	#  set_intermediate_directory_mode  #
  	#####################################

  ####################
  #  temp_directory  #
  ####################

  	########################
  	#  set_temp_directory  #
  	########################

  ###############################
  #  permit_environment_naming  #
  ###############################

  	#######################################
  	#  turn_permit_environment_naming_on  #
  	#######################################

  	########################################
  	#  turn_permit_environment_naming_off  #
  	########################################

  ###########################
  #  use_environment_home?  #
  ###########################

  	##################################
  	#  turn_use_environment_home_on  #
  	##################################

  	###################################
  	#  turn_use_environment_home_off  #
  	###################################

  #########################
  #  create_if_necessary  #
  #########################

  	#################################
  	#  turn_create_if_necessary_on  #
  	#################################

  	##################################
  	#  turn_create_if_necessary_off  #
  	##################################

  ###############################################
  #  is_error_if_database_exists_before_create  #
  ###############################################

  	#######################################################
  	#  turn_is_error_if_database_exists_before_create_on  #
  	#######################################################

  	########################################################
  	#  turn_is_error_if_database_exists_before_create_off  #
  	########################################################

  ####################
  #  open_read_only  #
  ####################

  	############################
  	#  turn_open_read_only_on  #
  	############################

  	#############################
  	#  turn_open_read_only_off  #
  	#############################

  ###################
  #  force_removal  #
  ###################

  	###########################
  	#  turn_force_removal_on  #
  	###########################

  	############################
  	#  turn_force_removal_off  #
  	############################

  ########################
  #  file_creation_mode  #
  ########################

  	############################
  	#  set_file_creation_mode  #
  	############################

  ###################################
  #  verbosity_settings_controller  #
  ###################################

end

