require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Compact do

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

  # RPDB::Environment::Settings::Database::Compact.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Compact.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Compact.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Compact.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Compact.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Compact.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Compact.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Compact.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Compact.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Compact.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Compact.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Compact.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  it "" do
    Fail
  end

  ################
  #  initialize  #
  ################

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

  ##################
  #  fill_percent  #
  ##################

  it "" do
    Fail
  end

  ######################
  #  set_fill_percent  #
  ######################

  it "" do
    Fail
  end

  ##########################
  #  max_pages_to_compact  #
  ##########################

  it "" do
    Fail
  end

  ##############################
  #  set_max_pages_to_compact  #
  ##############################

  it "" do
    Fail
  end

  #############
  #  timeout  #
  #############

  it "" do
    Fail
  end

  #################
  #  set_timeout  #
  #################

  it "" do
    Fail
  end

end

