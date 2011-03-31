require_relative '../../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database::Record::FixedLength do

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

  # RPbdb::Settings::Database::Record::FixedLength.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Database::Record::FixedLength.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::FixedLength.new( database_controller )
  it "can be created with a database controller" do
    RPbdb::Settings::Database::Record::FixedLength.new( @environment.database_controller ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::FixedLength.new( database )
  it "can be created with a database" do
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::FixedLength.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::FixedLength.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Settings::Database.new ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::FixedLength.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Database::Record::FixedLength.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    RPbdb::Settings::Database::Record::FixedLength.new.parent_environment.is_a?( RPbdb::Environment ).should == true
    # with database
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) ).parent_environment.is_a?( RPbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    RPbdb::Settings::Database::Record::FixedLength.new.parent_database.should == nil
    # with database
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) ).parent_database.is_a?( RPbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Record::FixedLength.new.parent_settings_controller.is_a?( RPbdb::Settings ).should == true
    # with database
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Record::FixedLength.new.parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
    # with database
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
  end

  ################################################
  #  parent_database_record_settings_controller  #
  ################################################

  it "can return its parent database settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Record::FixedLength.new.parent_database_record_settings_controller.is_a?( RPbdb::Settings::Database::Record ).should == true
    # with database
    RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) ).parent_database_record_settings_controller.is_a?( RPbdb::Settings::Database::Record ).should == true
  end

  #######################
  #  set_record_length  #
  #  record_length      #
  #######################

  it "can set and return a fixed length for records" do
    # with settings controller
    fixed_length_settings = RPbdb::Settings::Database::Record::FixedLength.new
    test_record_length( fixed_length_settings )
    # with database
    fixed_length_settings = RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) )
    test_record_length( fixed_length_settings )
  end

  def test_record_length( fixed_length_settings )
    
    fixed_length_settings.set_record_length( 42 )
    fixed_length_settings.record_length.should == 42

  end

  ######################
  #  set_padding_byte  #
  #  padding_byte      #
  ######################

  it "can set and return which character will be used for padding records shorter than fixed length" do
    # with settings controller
    fixed_length_settings = RPbdb::Settings::Database::Record::FixedLength.new
    test_padding_byte( fixed_length_settings )
    # with database
    fixed_length_settings = RPbdb::Settings::Database::Record::FixedLength.new( RPbdb::Database.new( $database_name ) )
    test_padding_byte( fixed_length_settings )
  end

  def test_padding_byte( fixed_length_settings )
    
    fixed_length_settings.set_padding_byte( '.' )
    fixed_length_settings.padding_byte.should == '.'

  end

end

