require_relative '../../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database::JoinController do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller
    @database = @database_controller.database( $database_name ).open
  end

  after( :each ) do
    @database.close
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Environment::DatabaseController::Database::JoinController.new( database )
  it "can be created with a parent database" do
    RPDB::Environment::DatabaseController::Database::JoinController.new( @database ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database::JoinController.new( environment, database_name ) 
  it "can be created with a parent environment and a database name" do
    RPDB::Environment::DatabaseController::Database::JoinController.new( @environment, @database.name ).should_not == nil  
  end

  # RPDB::Environment::DatabaseController::Database::JoinController.new( environment_directory, database_name ) 
  it "can be created with a parent environment home directory and a database name" do
    RPDB::Environment::DatabaseController::Database::JoinController.new( $environment_path, @database.name ).should_not == nil  
  end

  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    @database.join.settings_controller.should_not == nil
    @database.join.settings_controller.should_not == @environment.settings.database.join
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    @database.join.parent_environment.should == @environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can refer to its parent database" do
    @database.join.parent_database.should == @database
  end

  ##########
  #  join  #
  ##########
  
  it "can perform a join and return a join cursor" do
    @database.join.cursor.should_not == nil
  end

  ##################
  #  join_cursors  #
  ##################
  
  it "can perform a join and return a join cursor" do
    @database.join.cursor.should_not == nil
  end

  #######################
  #  close_all_cursors  #
  #  close_all          #
  #######################

  it "can close all join" do
    cursor1 = @database.join.cursor.open
    cursor2 = @database.join.cursor.open
    cursor3 = @database.join.cursor.open
    cursor4 = @database.join.cursor.open
    @database.join.close_all
    [ cursor1, cursor2, cursor3, cursor4 ].each { |cursor| cursor.is_open?.should == false }
  end
  
end
