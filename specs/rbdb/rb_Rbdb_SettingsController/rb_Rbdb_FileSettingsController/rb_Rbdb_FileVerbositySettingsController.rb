require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Database do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
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

  # Rbdb::Settings::File::Verbosity.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::File::Verbosity.new( @environment ).should_not == nil
  end

  # Rbdb::Settings::File::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::File::Verbosity.new( Rbdb::Settings.new ).should_not == nil
  end

  # Rbdb::Settings::File::Verbosity.new( settings_controller )
  it "can be created with a file settings controller" do
    Rbdb::Settings::File::Verbosity.new( Rbdb::Settings::File.new ).should_not == nil
  end

  # Rbdb::Settings::File::Verbosity.new
  it "can be created with no environment specified" do
    Rbdb::Settings::File::Verbosity.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    Rbdb::Settings::File::Verbosity.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    Rbdb::Settings::File::Verbosity.new.parent_settings_controller.should_not == nil
  end

  #####################################
  #  parent_file_settings_controller  #
  #####################################

  it "can return its parent file settings controller" do
    Rbdb::Settings::File::Verbosity.new.parent_file_settings_controller.should_not == nil
  end

  ######################################################################################
  #  display_additional_information_during_open_close_rename_file_operations?          #
	#  turn_display_additional_information_during_open_close_rename_file_operations_on   #
	#  turn_display_additional_information_during_open_close_rename_file_operations_off  #
  ######################################################################################

  it "can be set to display additional information during open/close/rename file operations" do
    verbosity_settings  = Rbdb::Settings::File::Verbosity.new
    verbosity_settings.display_additional_information_during_open_close_rename_file_operations?.should == false
    verbosity_settings.turn_display_additional_information_during_open_close_rename_file_operations_on
    verbosity_settings.display_additional_information_during_open_close_rename_file_operations?.should == true
    verbosity_settings.turn_display_additional_information_during_open_close_rename_file_operations_off
    verbosity_settings.display_additional_information_during_open_close_rename_file_operations?.should == false
  end

  ########################################################################
  #  display_additional_information_during_all_file_operations?          #
	#  turn_display_additional_information_during_all_file_operations_on   #
	#  turn_display_additional_information_during_all_file_operations_off  #
  ########################################################################

  it "can display additional information during all file operations" do
    verbosity_settings  = Rbdb::Settings::File::Verbosity.new
    verbosity_settings.display_additional_information_during_all_file_operations?.should == false
    verbosity_settings.turn_display_additional_information_during_all_file_operations_on
    verbosity_settings.display_additional_information_during_all_file_operations?.should == true
    verbosity_settings.turn_display_additional_information_during_all_file_operations_off
    verbosity_settings.display_additional_information_during_all_file_operations?.should == false
  end

end

