require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Sequence do

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

  # RPDB::Environment::Settings::Database::Sequence.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Sequence.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Sequence.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Sequence.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Sequence.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Sequence.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Sequence.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Sequence.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Sequence.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Sequence.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Sequence.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Sequence.new.should_not == nil
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

  ################
  #  increasing  #
  ################

  it "" do
    Fail
  end

  #######################
  #  set_as_increasing  #
  #######################

  it "" do
    Fail
  end

  ################
  #  decreasing  #
  ################

  it "" do
    Fail
  end

  #######################
  #  set_as_decreasing  #
  #######################

  it "" do
    Fail
  end

  ##########
  #  wrap  #
  ##########

  it "" do
    Fail
  end

  #################
  #  set_to_wrap  #
  #################

  it "" do
    Fail
  end

  ###################
  #  range_minimum  #
  ###################

  it "" do
    Fail
  end

  #######################
  #  set_range_minimum  #
  #######################

  it "" do
    Fail
  end

  ###################
  #  range_maximum  #
  ###################

  it "" do
    Fail
  end

  #######################
  #  set_range_maximum  #
  #######################

  it "" do
    Fail
  end

  ################
  #  cache_size  #
  ################

  it "" do
    Fail
  end

  ####################
  #  set_cache_size  #
  ####################

  it "" do
    Fail
  end

  ###################
  #  initial_value  #
  ###################

  it "" do
    Fail
  end

  #######################
  #  set_initial_value  #
  #######################

  it "" do
    Fail
  end

  ########################
  #  default_step_value  #
  ########################

  it "" do
    Fail
  end

  ############################
  #  set_default_step_value  #
  ############################

  it "" do
    Fail
  end

end

