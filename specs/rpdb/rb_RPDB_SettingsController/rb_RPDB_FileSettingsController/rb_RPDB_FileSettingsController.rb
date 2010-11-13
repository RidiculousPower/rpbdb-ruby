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

  #####################################
	#  set_intermediate_directory_mode  #
  #  intermediate_directory_mode      #
  #####################################

  it "can be set to create intermediate directories needed for recovery" do
    raise "Failed."
  end

  ########################
	#  set_temp_directory  #
  #  temp_directory      #
  ########################

  it "can specify its temp directory" do
    raise "Failed."
  end

  ########################################
  #  permit_environment_naming?          #
	#  turn_permit_environment_naming_on   #
	#  turn_permit_environment_naming_off  #
  ########################################

  it "can permit the use of environment information in the naming of files" do
    raise "Failed."
  end

  ###################################
  #  use_environment_home?          #
	#  turn_use_environment_home_on   #
	#  turn_use_environment_home_off  #
  ###################################

  # FIX - create file permissions controller
  it "can permit root users the use of environment information in the naming of files" do
    raise "Failed."
  end

  ##################################
  #  create_if_necessary?          #
	#  turn_create_if_necessary_on   #
	#  turn_create_if_necessary_off  #
  ##################################

  it "can be set to create files if necessary" do
    raise "Failed."
  end

  ########################################################
  #  is_error_if_database_exists_before_create?          #
	#  turn_is_error_if_database_exists_before_create_on   #
	#  turn_is_error_if_database_exists_before_create_off  #
  ########################################################

  it "can be set to throw an error if a database exists before create is called" do
    raise "Failed."
  end

  #############################
  #  open_read_only?          #
	#  turn_open_read_only_on   #
	#  turn_open_read_only_off  #
  #############################

  it "can be set to open read-only" do
    raise "Failed."
  end

  ############################
  #  force_removal?          #
	#  turn_force_removal_on   #
	#  turn_force_removal_off  #
  ############################

  it "can be set to force environment removal" do
    raise "Failed."
  end

  ############################
	#  set_file_creation_mode  #
  #  file_creation_mode      #
  ############################

  it "can set the file creation mode" do
    raise "Failed."
  end

  ###################################
  #  verbosity_settings_controller  #
  ###################################

  it "can return its verbosity settings controller" do
    raise "Failed."
  end

end

