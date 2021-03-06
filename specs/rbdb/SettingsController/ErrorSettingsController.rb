require_relative '../../../lib/rpbdb.rb'

describe RPbdb::Settings::Error do

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

  # RPbdb::Settings::Error.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Error.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Error.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Error.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Error.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Error.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::Error.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPbdb::Settings::Error.new.parent_settings_controller.should_not == nil
  end

  ##############
	#  set_file  #
  #  file      #
  ##############

  # FIX - FILE
  it "can set and return an error file" do
    raise "File"
    error_settings  = RPbdb::Settings::Error.new
    error_settings.set_file( '/tmp/file.tmp' )
    error_settings.file.should == '/tmp/file.tmp'
  end

  ################
	#  set_prefix  #
  #  prefix      #
  ################

  it "can set and return an error prefix" do
    error_settings  = RPbdb::Settings::Error.new
    error_settings.set_prefix( 'prefix' )
    error_settings.prefix.should == 'prefix'
  end

  ###############################
  #  set_error_callback_method  #
  #  error_callback_method      #
  ###############################

  it "can set and return an error callback method" do
    raise "Callback."
  end

   ###############################
   #  set_panic_callback_method  #
   #  panic_callback_method      #
   ###############################

   # FIX - panic should move to error settings
   it "can set and return its panic callback method" do
     raise "Callback."
   end

end

