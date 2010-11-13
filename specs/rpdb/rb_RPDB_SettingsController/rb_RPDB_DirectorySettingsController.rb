require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings::Directory do

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

  # RPDB::Settings::Directory.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Directory.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Directory.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Directory.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Directory.new
  it "can be created with no argument specified" do
    RPDB::Settings::Directory.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Directory.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Directory.new.parent_settings_controller.should_not == nil
  end

  ####################
  #  home_directory  #
  ####################

  it "can return its home directory" do
    raise "Failed."
  end

  ########################
  #  add_data_directory  #
  ########################

  it "can add a data directory to the data directories array" do
    raise "Failed."
  end

  ######################
  #  data_directories  #
  ######################

  it "can return an array of current data directories" do
    raise "Failed."
  end

end

