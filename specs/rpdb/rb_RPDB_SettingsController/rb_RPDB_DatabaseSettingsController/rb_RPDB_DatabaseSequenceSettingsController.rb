require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Sequence do

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

  # Rbdb::Settings::Database::Sequence.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Sequence.new( @environment ).is_a?( Rbdb::Settings::Database::Sequence ).should == true
  end

  # Rbdb::Settings::Database::Sequence.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Sequence.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Sequence ).should == true
  end

  # Rbdb::Settings::Database::Sequence.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Sequence ).should == true
  end

  # Rbdb::Settings::Database::Sequence.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Sequence.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Sequence ).should == true
  end

  # Rbdb::Settings::Database::Sequence.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Sequence.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Sequence ).should == true
  end

  # Rbdb::Settings::Database::Sequence.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Sequence.new.is_a?( Rbdb::Settings::Database::Sequence ).should == true
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    Rbdb::Settings::Database::Sequence.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with database
    Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    Rbdb::Settings::Database::Sequence.new.parent_database.should == nil
    # with database
    Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Sequence.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with database
    Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Sequence.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with database
    Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  #######################
  #  set_as_increasing  #
  #  increasing?        #
  #######################

  it "can be set as an increasing sequence" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_increasing( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_increasing( sequence_settings )
  end

  def test_increasing( sequence_settings )
    
    sequence_settings.set_as_increasing
    sequence_settings.increasing?.should == true

  end

  #######################
  #  set_as_decreasing  #
  #  decreasing?        #
  #######################

  it "can be set as a decreasing sequence" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_decreasing( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_decreasing( sequence_settings )
  end

  def test_decreasing( sequence_settings )

    sequence_settings.set_as_decreasing
    sequence_settings.decreasing?.should == true
    
  end

  #################
  #  set_to_wrap  #
  #  wrap?        #
  #################

  it "can be set to wrap at a given value" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_wrap( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_wrap( sequence_settings )
  end

  def test_wrap( sequence_settings )

    sequence_settings.set_to_wrap
    sequence_settings.wrap?.should == true
    
  end

  #######################
  #  set_range_minimum  #
  #  range_minimum      #
  #######################

  it "can set the minimum value for a sequence range" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_range_minimum( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_range_minimum( sequence_settings )
  end

  def test_range_minimum( sequence_settings )
    
    sequence_settings.set_range_minimum( 42 )
    sequence_settings.range_minimum.should == 42

  end

  #######################
  #  set_range_maximum  #
  #  range_maximum      #
  #######################

  it "can set the maximum value for a sequence range" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_range_maximum( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_range_maximum( sequence_settings )
  end

  def test_range_maximum( sequence_settings )

    sequence_settings.set_range_maximum( 42 )
    sequence_settings.range_maximum.should == 42
    
  end

  ####################
  #  set_cache_size  #
  #  cache_size      #
  ####################

  it "can set the sequence cache size" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_cache_size( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_cache_size( sequence_settings )
  end

  def test_cache_size( sequence_settings )
    
    sequence_settings.set_cache_size( 42 )
    sequence_settings.cache_size.should == 42

  end

  ##########################
  #  set_to_initial_value  #
  #  initial_value         #
  ##########################

  it "can set the initial sequence value" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_initial_value( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_initial_value( sequence_settings )
  end

  def test_initial_value( sequence_settings )
    
    sequence_settings.set_to_initial_value( 42 )
    sequence_settings.initial_value.should == 42

  end

  ############################
  #  set_to_default_step_value  #
  #  default_step_value      #
  ############################

  it "can set the default step value" do
    # with settings controller
    sequence_settings = Rbdb::Settings::Database::Sequence.new
    test_default_step_value( sequence_settings )
    # with database
    sequence_settings = Rbdb::Settings::Database::Sequence.new( Rbdb::Database.new( $database_name ) )
    test_default_step_value( sequence_settings )
  end

  def test_default_step_value( sequence_settings )

    sequence_settings.set_to_default_step_value( 42 )
    sequence_settings.default_step_value.should == 42
    
  end

end

