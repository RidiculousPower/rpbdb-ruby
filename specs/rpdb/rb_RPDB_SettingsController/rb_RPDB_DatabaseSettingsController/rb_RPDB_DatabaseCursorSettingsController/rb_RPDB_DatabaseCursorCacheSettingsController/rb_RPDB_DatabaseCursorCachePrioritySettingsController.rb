require_relative '../../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Cursor::Cache::Priority do

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

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( database_cursor_controller )
  it "can be created with a database cursor controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller.new( $database_name ).cursor_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller.new( $database_name ).cursor ).should_not == nil
  end


  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database cursor settings controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( RPDB::Environment::Settings::Database::Cursor.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database cursor cache settings controller" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new( RPDB::Environment::Settings::Database::Cursor::Cache.new ).should_not == nil
  end
  
  # RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Cursor::Cache::Priority.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  it "" do
    Fail
  end

  ##############
  #  self.new  #
  ##############

  it "" do
    Fail
  end

  ########################
  #  parent_environment  #
  ########################

  it "" do
    Fail
  end

  #####################
  #  parent_database  #
  #####################

  it "" do
    Fail
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "" do
    Fail
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "" do
    Fail
  end

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  it "" do
    Fail
  end

  ######################################################
  #  parent_database_cursor_cache_settings_controller  #
  ######################################################

  it "" do
    Fail
  end

  ##############
  #  priority  #
  ##############

  it "" do
    Fail
  end

  ##############
  #  very_low  #
  ##############

  it "" do
    Fail
  end

  ##################
  #  set_very_low  #
  ##################

  it "" do
    Fail
  end

  #######################
  #  at_least_very_low  #
  #######################

  it "" do
    Fail
  end

  ######################
  #  at_most_very_low  #
  ######################

  it "" do
    Fail
  end

  #########
  #  low  #
  #########

  it "" do
    Fail
  end

  #############
  #  set_low  #
  #############

  it "" do
    Fail
  end

  ##################
  #  at_least_low  #
  ##################

  it "" do
    Fail
  end

  #################
  #  at_most_low  #
  #################

  it "" do
    Fail
  end

  #############
  #  default  #
  #############

  it "" do
    Fail
  end

  #################
  #  set_default  #
  #################

  it "" do
    Fail
  end

  ######################
  #  at_least_default  #
  ######################

  it "" do
    Fail
  end

  ######################
  #  at_most_default  #
  ######################

  it "" do
    Fail
  end

  ##########
  #  high  #
  ##########

  it "" do
    Fail
  end

  ##############
  #  set_high  #
  ##############

  it "" do
    Fail
  end

  ###################
  #  at_least_high  #
  ###################

  it "" do
    Fail
  end

  ##################
  #  at_most_high  #
  ##################

  it "" do
    Fail
  end

  ###############
  #  very_high  #
  ###############

  it "" do
    Fail
  end

  ###################
  #  set_very_high  #
  ###################

  it "" do
    Fail
  end

  #####################
  #  atLeastVeryHigh  #
  #####################

  it "" do
    Fail
  end

  #######################
  #  at_most_very_high  #
  #######################

  it "" do
    Fail
  end

end

