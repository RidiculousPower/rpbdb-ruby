require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Sequence do

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

  # RPDB::Settings::Database::Sequence.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Sequence.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Sequence.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Sequence.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Sequence.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Sequence.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Sequence.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Sequence.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Sequence.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Sequence.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Sequence.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Sequence.new.should_not == nil
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Sequence.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Sequence.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Sequence.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Sequence.new.parent_database_settings_controller.should_not == nil
  end

  #######################
  #  set_as_increasing  #
  #  increasing?        #
  #######################

  it "can be set as an increasing sequence" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_as_increasing
    sequence_settings.increasing?.should == true
  end

  #######################
  #  set_as_decreasing  #
  #  decreasing?        #
  #######################

  it "can be set as a decreasing sequence" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_as_decreasing
    sequence_settings.decreasing?.should == true
  end

  #################
  #  set_to_wrap  #
  #  wrap?         #
  #################

  it "can be set to wrap at a given value" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_to_wrap
    sequence_settings.wrap?.should == true
  end

  #######################
  #  set_range_minimum  #
  #  range_minimum      #
  #######################

  it "can set the minimum value for a sequence range" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_range_minimum( 42 )
    sequence_settings.range_minimum.should == 42
  end

  #######################
  #  set_range_maximum  #
  #  range_maximum      #
  #######################

  it "can set the maximum value for a sequence range" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_range_maximum( 42 )
    sequence_settings.range_maximum.should == 42
  end

  ####################
  #  set_cache_size  #
  #  cache_size      #
  ####################

  it "can set the sequence cache size" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_cache_size( 42 )
    sequence_settings.cache_size.should == 42
  end

  ##########################
  #  set_to_initial_value  #
  #  initial_value         #
  ##########################

  it "can set the initial sequence value" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_to_initial_value( 42 )
    sequence_settings.initial_value.should == 42
  end

  ############################
  #  set_to_default_step_value  #
  #  default_step_value      #
  ############################

  it "can set the default step value" do
    sequence_settings = RPDB::Settings::Database::Sequence.new
    sequence_settings.set_to_default_step_value( 42 )
    sequence_settings.default_step_value.should == 42
  end

end

