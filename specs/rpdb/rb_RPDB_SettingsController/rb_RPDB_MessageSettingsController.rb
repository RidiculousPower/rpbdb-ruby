require_relative '../../../lib/rbdb.rb'

describe Rbdb::Settings::Message do

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

  # Rbdb::Settings::Message.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Message.new( @environment ).should_not == nil
  end

  # Rbdb::Settings::Message.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Message.new( Rbdb::Settings.new ).should_not == nil
  end

  # Rbdb::Settings::Message.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Message.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    Rbdb::Settings::Message.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    Rbdb::Settings::Message.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  set_file  #
  #  file      #
  ##############

  # FIX - FILE
  it "can set and return its message file" do
    raise "File"
    message_settings  = Rbdb::Settings::Message.new
    message_settings.set_file( '/tmp/file.tmp' )
    message_settings.file.should == '/tmp/file.tmp'
  end

  #################################
  #  set_message_callback_method  #
  #  message_callback_method      #
  #################################

  it "can set and return its message callback method" do
    raise "Callback."
  end

 
end

