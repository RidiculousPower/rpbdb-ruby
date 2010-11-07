require_relative '../../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Cursor::Cache do

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

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( database_cursor_controller )
  it "can be created with a database cursor controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( @environment.database_controller.new( $database_name ).cursor_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( @environment.database_controller.new( $database_name ).cursor ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new( database_settings_controller )
  it "can be created with a database cursor settings controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new( RPDB::Environment::Settings::Database::Cursor.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Cursor::Cache.new.should_not == nil
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

  #####################
  #  parent_database  #
  #####################

  ################################
  #  parent_settings_controller  #
  ################################

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  ##################################
  #  priority_settings_controller  #
  ##################################

end


