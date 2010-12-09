require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Error do

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

  # Rbdb::Settings::Database::Error.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Error.new( @environment ).is_a?( Rbdb::Settings::Database::Error ).should == true
  end

  # Rbdb::Settings::Database::Error.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Error.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Error ).should == true
  end

  # Rbdb::Settings::Database::Error.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Error.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Error ).should == true
  end

  # Rbdb::Settings::Database::Error.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Error.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Error ).should == true
  end

  # Rbdb::Settings::Database::Error.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Error.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Error ).should == true
  end

  # Rbdb::Settings::Database::Error.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Error.new.is_a?( Rbdb::Settings::Database::Error ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    Rbdb::Settings::Database::Error.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with database
    Rbdb::Settings::Database::Error.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    Rbdb::Settings::Database::Error.new.parent_database.should == nil
    # with database
    Rbdb::Settings::Database::Error.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Error.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with database
    Rbdb::Settings::Database::Error.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Error.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with database
    Rbdb::Settings::Database::Error.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  ##############
  #  set_file  #
  #  file      #
  ##############

  # FIX - FILE
  it "can set and return a file for error output by path" do
    # with settings controller
    raise "File"
    test_file( error_settings )
    # with database
    test_file( error_settings )
  end

  def test_file( error_settings )

    error_settings  = Rbdb::Settings::Database::Error.new
    error_settings.file.should == nil
    error_settings.set_file( '/tmp/file.tmp' )
    error_settings.file.is_a?( File ).should == true
    
  end

  it "can set and return a file for error output by file object" do
    # with settings controller
    raise "File"
    test_file_name( error_settings )
    # with database
    test_file_name( error_settings )
  end

  def test_file_name( error_settings )
    
    error_settings  = Rbdb::Settings::Database::Error.new
    error_settings.file.should == nil
    file_object = File.open( '/tmp/file.tmp', 'r' )
    error_settings.set_file( file_object )
    error_settings.file.should == file_object
    file_object.close

  end

  ################
  #  set_prefix  #
  #  prefix      #
  ################

  it "can set and return a prefix to prepend to all errors" do
    # with settings controller
    error_settings  = Rbdb::Settings::Database::Error.new
    test_prefix( error_settings )
    # with database
    error_settings  = Rbdb::Settings::Database::Error.new( Rbdb::Database.new( $database_name ) )
    test_prefix( error_settings )
  end
  
  def test_prefix( error_settings )
    
    error_settings.prefix.should == nil
    error_settings.set_prefix( 'error prefix' )
    error_settings.prefix.should == 'error prefix'

  end

  ###############################
  #  set_error_callback_method  #
  #  error_callback_method      #
  ###############################

  it "can set and return a callback method for error handling" do
    # with settings controller
    raise "Callback."
    test_error_callback_method( error_settings )
    # with database
    test_error_callback_method( error_settings )
  end

  def test_error_callback_method( error_settings )
    
  end

end

