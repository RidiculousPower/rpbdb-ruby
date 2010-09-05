require_relative '../../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database::CursorController::Cursor do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller
    @database = @database_controller.database( $database_name ).open
    @cursor_controller = @database.cursor_controller
  end

  after( :each ) do
    @database.close
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Environment::DatabaseController::Database::Cursor.new( database_cursor_controller )
  it "can be created with a parent database " do
    RPDB::Environment::DatabaseController::Database::CursorController::Cursor.new( @cursor_controller ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database::Cursor.new( database )
  it "can be created with a parent database " do
    RPDB::Environment::DatabaseController::Database::CursorController::Cursor.new( @database ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database::Cursor.new( database_controller, database_name ) 
  it "can be created with a name and a parent environment directory" do
    RPDB::Environment::DatabaseController::Database::CursorController::Cursor.new( @database_controller, @database.name ).should_not == nil  
  end

  # RPDB::Environment::DatabaseController::Database::Cursor.new( environment, database_name ) 
  it "can be created with a name and a parent environment directory" do
    RPDB::Environment::DatabaseController::Database::CursorController::Cursor.new( @environment, @database.name ).should_not == nil  
  end

  # RPDB::Environment::DatabaseController::Database::Cursor.new( environment_directory, database_name ) 
  it "can be created with a name and a parent environment directory" do
    RPDB::Environment::DatabaseController::Database::CursorController::Cursor.new( @environment.directory, @database.name ).should_not == nil  
  end

  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    @database.cursors.cursor.settings_controller.should_not == nil
    @database.cursors.cursor.settings_controller.should_not == @database.cursors.settings_controller
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    @database.cursors.cursor.parent_environment.should == @environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can refer to its parent database" do
    @database.cursors.cursor.parent_database.should == @database
  end

  #######################################
  #  parent_database_cursor_controller  #
  #######################################

  it "can refer to its parent cursor controller" do
    @database.cursors.cursor.parent_database_cursor_controller.should == @cursor_controller
  end
  
end
