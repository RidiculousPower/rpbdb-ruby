require_relative '../../../lib/rbdb.rb'

describe Rbdb::Database::Controller do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database

  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
    @environment.open
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # Rbdb::Database::Controller.new( environment )
  # Rbdb::Database::Controller.new( environment_name ) 
  # Rbdb::Database::Controller.new
  
  it "can be created with a parent environment" do 
    database_controller = Rbdb::Database::Controller.new( @environment )
    database_controller.should_not == nil
    database_controller.is_a?.should == Rbdb::Database::Controller
  end

  it "can be created without any arguments, which implies default environment" do 
    database_controller = Rbdb::Database::Controller.new
    database_controller.should_not == nil
    database_controller.is_a?.should == Rbdb::Database::Controller
  end
  
  it "can be retrieved from an environment instance" do
    database_controller = @environment.database_controller
    database_controller.should_not == nil
    database_controller.is_a?.should == Rbdb::Database::Controller
  end

  #########################
  #  settings_controller  #
  #########################

  it "can refer to its parent environment's database settings controller" do
    database_controller = @environment.database_controller
    database_controller.should_not == nil
    # make sure we have a settings controller
    settings_controller = database_controller.settings_controller
    settings_controller.should_not == nil
    settings_controller.is_a?.should == Rbdb::Settings::Database
    # make sure that our settings controller is the environment's database settings controller
    settings_controller.should == @environment.settings.database
  end

  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    parent_environment = @environment.database_controller.parent_environment
    parent_environment.should_not == nil
    parent_environment.is_a?.should == Rbdb::Environment
  end

  ##################
  #  new_database  #
  #  new           #
  #  database      #
  ##################

  it "can create a new database corresponding to a string name" do
    database_controller = @environment.database_controller
    database = database_controller.new( $database_name )
    database.should_not == nil
    database.is_a?.should == Rbdb::Database
    database.handle.should == $database_name
    database.name.should == $database_name.to_s
  end

  it "can create a new database corresponding to a symbol name" do
    database_controller = @environment.database_controller
    database = database_controller.new( $database_name.to_s )
    database.should_not == nil
    database.is_a?.should == Rbdb::Database
    database.handle.should == $database_name
    database.name.should == $database_name.to_s
  end

  #########################
  #  close_all_databases  #
  #########################

  it "can close all databases it controls" do
    # databases is a convenience alias for database_controller
    database1 = @environment.database.new( 'database_' + 1.to_s ).open
    database2 = @environment.database.new( 'database_' + 2.to_s ).open
    database3 = @environment.database.new( 'database_' + 3.to_s ).open
    database4 = @environment.database.new( 'database_' + 4.to_s ).open
    database1.is_open?.should == true
    database2.is_open?.should == true
    database3.is_open?.should == true
    database4.is_open?.should == true
    @environment.databases.close_all
    database1.is_open?.should == false
    database2.is_open?.should == false
    database3.is_open?.should == false
    database4.is_open?.should == false
    database1.erase!
    database2.erase!
    database3.erase!
    database4.erase!
    @environment.erase!
  end

end
