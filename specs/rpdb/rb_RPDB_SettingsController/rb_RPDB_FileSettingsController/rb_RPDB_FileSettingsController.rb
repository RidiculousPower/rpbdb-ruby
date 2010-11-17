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
    @environment.open
    RPDB::Settings::File.new( @environment ).should_not == nil
  end

  # RPDB::Settings::File.new( settings_controller )
  it "can be created with a settings controller" do
    @environment.open
    RPDB::Settings::File.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::File.new
  it "can be created with no environment specified" do
    @environment.open
    RPDB::Settings::File.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    @environment.open
    RPDB::Settings::File.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    @environment.open
    RPDB::Settings::File.new.parent_settings_controller.should_not == nil
  end

  #####################################
	#  set_intermediate_directory_mode  #
  #  intermediate_directory_mode      #
  #####################################

  it "can be set to create intermediate directories needed for recovery (9 character unix-style permissions)" do
    file_settings = RPDB::Settings::File.new( @environment )
    file_settings.set_intermediate_directory_mode( "rwxrwx---" )
    file_settings.intermediate_directory_mode.should == "rwxrwx---"
  end

  ############################
	#  set_file_creation_mode  #
  #  file_creation_mode      #
  ############################

  it "can set the file creation mode" do
    file_settings = RPDB::Settings::File.new( @environment )
    file_settings.set_intermediate_directory_mode( "rwxrwx---" )
    file_settings.intermediate_directory_mode.should == "rwxrwx---"
  end

  ########################
	#  set_temp_directory  #
  #  temp_directory      #
  ########################

  it "can specify its temp directory" do
    @environment.open
    file_settings = RPDB::Settings::File.new
    file_settings.set_temp_directory( '/tmp/file.tmp' )
    file_settings.temp_directory.should == '/tmp/file.tmp'
  end

  ###################################################
  #  permit_environment_based_file_naming?          #
	#  turn_permit_environment_based_file_naming_on   #
	#  turn_permit_environment_based_file_naming_off  #
  ###################################################

  it "can permit the use of environment information in the naming of files" do
    @environment.open
    file_settings  = RPDB::Settings::File.new
    file_settings.permit_environment_based_file_naming?.should == false
    file_settings.turn_permit_environment_based_file_naming_on
    file_settings.permit_environment_based_file_naming?.should == true
    file_settings.turn_permit_environment_based_file_naming_off
    file_settings.permit_environment_based_file_naming?.should == false
  end

  ###############################################################
  #  use_environment_home_permissions_for_file_naming?          #
	#  turn_use_environment_home_permissions_for_file_naming_on   #
	#  turn_use_environment_home_permissions_for_file_naming_off  #
  ###############################################################

  # FIX - create file permissions controller
  it "can permit root users the use of environment information in the naming of files" do
    @environment.open
    file_settings  = RPDB::Settings::File.new
    file_settings.use_environment_home_permissions_for_file_naming?.should == false
    file_settings.turn_use_environment_home_permissions_for_file_naming_on
    file_settings.use_environment_home_permissions_for_file_naming?.should == true
    file_settings.turn_use_environment_home_permissions_for_file_naming_off
    file_settings.use_environment_home_permissions_for_file_naming?.should == false
  end

  ##################################
  #  create_if_necessary?          #
	#  turn_create_if_necessary_on   #
	#  turn_create_if_necessary_off  #
  ##################################

  it "can be set to create files if necessary" do
    @environment.open
    file_settings  = RPDB::Settings::File.new
    file_settings.create_if_necessary?.should == true
    file_settings.turn_create_if_necessary_off
    file_settings.create_if_necessary?.should == false
    file_settings.turn_create_if_necessary_on
    file_settings.create_if_necessary?.should == true
  end

  ########################################################
  #  is_error_if_database_exists_before_create?          #
	#  turn_is_error_if_database_exists_before_create_on   #
	#  turn_is_error_if_database_exists_before_create_off  #
  ########################################################

  it "can be set to throw an error if a database exists before create is called" do
    @environment.open
    file_settings  = RPDB::Settings::File.new
    file_settings.is_error_if_database_exists_before_create?.should == false
    file_settings.turn_is_error_if_database_exists_before_create_on
    file_settings.is_error_if_database_exists_before_create?.should == true
    file_settings.turn_is_error_if_database_exists_before_create_off
    file_settings.is_error_if_database_exists_before_create?.should == false
  end

  #############################
  #  open_read_only?          #
	#  turn_open_read_only_on   #
	#  turn_open_read_only_off  #
  #############################

  it "can be set to open read-only" do
    @environment.open
    file_settings  = RPDB::Settings::File.new
    file_settings.open_read_only?.should == false
    file_settings.turn_open_read_only_on
    file_settings.open_read_only?.should == true
    file_settings.turn_open_read_only_off
    file_settings.open_read_only?.should == false
  end

  ############################
  #  force_removal?          #
	#  turn_force_removal_on   #
	#  turn_force_removal_off  #
  ############################

  it "can be set to force environment removal" do
    @environment.open
    file_settings  = RPDB::Settings::File.new
    file_settings.force_removal?.should == false
    file_settings.turn_force_removal_on
    file_settings.force_removal?.should == true
    file_settings.turn_force_removal_off
    file_settings.force_removal?.should == false
  end

  ###################################
  #  verbosity_settings_controller  #
  ###################################

  it "can return its verbosity settings controller" do
    @environment.open
    RPDB::Settings::File.new.verbosity_settings_controller.is_a?( RPDB::Settings::File::Verbosity ).should == true
  end

end

