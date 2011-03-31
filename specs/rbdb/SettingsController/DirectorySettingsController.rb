require_relative '../../../lib/rpbdb.rb'

describe RPbdb::Settings::Directory do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
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

  # RPbdb::Settings::Directory.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Directory.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Directory.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Directory.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Directory.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Directory.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::Directory.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPbdb::Settings::Directory.new.parent_settings_controller.should_not == nil
  end

  ####################
  #  home_directory  #
  ####################

  it "can return its home directory" do
    directory_settings  = RPbdb::Settings::Directory.new
    directory_settings.home_directory.should_not == nil
  end

  ########################
  #  add_data_directory  #
  #  data_directories    #
  ########################

  # FIX - FILE
  it "can add a data directory to the data directories array" do
    raise "File"
    directory_settings  = RPbdb::Settings::Directory.new
    directory_settings.add_data_directory( '/tmp' )
    directory_settings.data_directories.include?( '/tmp' ).should == true
  end

end

