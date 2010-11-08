require_relative '../../../../lib/rpdb.rb'

describe RPDB::Database do

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

  # RPDB::Settings::File.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::File.new( @environment ).should_not == nil
  end

  # RPDB::Settings::File.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::File.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::File.new
  it "can be created with no environment specified" do
    RPDB::Settings::File.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::File.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::File.new.parent_settings_controller.should_not == nil
  end

  #################################
  #  intermediate_directory_mode  #
  #################################

  it "" do
    Fail
  end

  	#####################################
  	#  set_intermediate_directory_mode  #
  	#####################################

    it "" do
      Fail
    end

  ####################
  #  temp_directory  #
  ####################

  it "" do
    Fail
  end

  	########################
  	#  set_temp_directory  #
  	########################

    it "" do
      Fail
    end

  ###############################
  #  permit_environment_naming  #
  ###############################

  it "" do
    Fail
  end

  	#######################################
  	#  turn_permit_environment_naming_on  #
  	#######################################

    it "" do
      Fail
    end

  	########################################
  	#  turn_permit_environment_naming_off  #
  	########################################

    it "" do
      Fail
    end

  ###########################
  #  use_environment_home?  #
  ###########################

  it "" do
    Fail
  end

  	##################################
  	#  turn_use_environment_home_on  #
  	##################################

    it "" do
      Fail
    end

  	###################################
  	#  turn_use_environment_home_off  #
  	###################################

    it "" do
      Fail
    end

  #########################
  #  create_if_necessary  #
  #########################

  it "" do
    Fail
  end

  	#################################
  	#  turn_create_if_necessary_on  #
  	#################################

    it "" do
      Fail
    end

  	##################################
  	#  turn_create_if_necessary_off  #
  	##################################

    it "" do
      Fail
    end

  ###############################################
  #  is_error_if_database_exists_before_create  #
  ###############################################

  it "" do
    Fail
  end

  	#######################################################
  	#  turn_is_error_if_database_exists_before_create_on  #
  	#######################################################

    it "" do
      Fail
    end

  	########################################################
  	#  turn_is_error_if_database_exists_before_create_off  #
  	########################################################

    it "" do
      Fail
    end

  ####################
  #  open_read_only  #
  ####################

  it "" do
    Fail
  end

  	############################
  	#  turn_open_read_only_on  #
  	############################

    it "" do
      Fail
    end

  	#############################
  	#  turn_open_read_only_off  #
  	#############################

    it "" do
      Fail
    end

  ###################
  #  force_removal  #
  ###################

  it "" do
    Fail
  end

  	###########################
  	#  turn_force_removal_on  #
  	###########################

    it "" do
      Fail
    end

  	############################
  	#  turn_force_removal_off  #
  	############################

    it "" do
      Fail
    end

  ########################
  #  file_creation_mode  #
  ########################

  it "" do
    Fail
  end

  	############################
  	#  set_file_creation_mode  #
  	############################

    it "" do
      Fail
    end

  ###################################
  #  verbosity_settings_controller  #
  ###################################

  it "" do
    Fail
  end

end

