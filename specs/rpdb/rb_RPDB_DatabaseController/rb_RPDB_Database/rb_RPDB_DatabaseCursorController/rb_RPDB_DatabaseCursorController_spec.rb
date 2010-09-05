require_relative '../../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database::CursorController do

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

  # RPDB::Environment::DatabaseController::Database::CursorController.new( database )
  it "can be created with a parent database" do
    RPDB::Environment::DatabaseController::Database::CursorController.new( @database ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database::CursorController.new( environment, database_name ) 
  it "can be created with a parent environment and a database name" do
    RPDB::Environment::DatabaseController::Database::CursorController.new( @environment, @database.name ).should_not == nil  
  end

  # RPDB::Environment::DatabaseController::Database::CursorController.new( environment_directory, database_name ) 
  it "can be created with a parent environment home directory and a database name" do
    RPDB::Environment::DatabaseController::Database::CursorController.new( $environment_path, @database.name ).should_not == nil  
  end

  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    @database.cursors.settings_controller.should_not == nil
    @database.cursors.settings_controller.should_not == @environment.settings.database.cursor
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    @database.cursors.parent_environment.should == @environment
  end

  ############
  #  cursor  #
  ############
  
  it "can return a cursor" do
    @database.cursors.cursor.should_not == nil
  end

  ###################
  #  object_cursor  #
  ###################

  it "can return an object cursor (which automatically handles serialization)" do
    @database.cursors.object_cursor.should_not == nil    
  end

  #######################
  #  close_all_cursors  #
  #  close_all          #
  #######################

  it "can close all cursors" do
    cursor1 = @database.cursors.cursor.open
    cursor2 = @database.cursors.cursor.open
    cursor3 = @database.cursors.cursor.open
    cursor4 = @database.cursors.cursor.open
    @database.cursors.close_all
    [ cursor1, cursor2, cursor3, cursor4 ].each { |cursor| cursor.is_open?.should == false }
  end
  
end
