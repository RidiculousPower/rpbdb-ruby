require_relative '../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database do

  $environment_path           = '/tmp/rpdb_spec_environment_home'

  $database_name              = :spec_database
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  
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

  # RPDB::Environment::DatabaseController::Database.new( name, environment )
  it "can be created with a name and a parent environment" do
    RPDB::Environment::DatabaseController::Database.new( $database_name, @environment ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database.new( name, environment_name ) 
  it "can be created with a name and a parent environment directory" do
    RPDB::Environment::DatabaseController::Database.new( $database_name, $environment_path ).should_not == nil  
  end

  # RPDB::Environment::DatabaseController::Database.new( name, database_controller ) 
  it "can be created with a name and a parent database controller" do
    RPDB::Environment::DatabaseController::Database.new( $database_name, @database_controller ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database.new( name )  
  it "can be created with a name (using the default environment)" do
    RPDB::Environment::DatabaseController::Database.new( $database_name ).should_not == nil
  end
  
  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    # create a database
    database = @database_controller.new_database( $database_name )
    # make sure it has a settings controller
    # and that it's not the same settings controller that our environment owns
    database.settings.should_not == nil
    database.settings.should_not == @environment.settings.database
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    @database_controller.new_database( $database_name ).parent_environment.should == @environment
  end

  ##############
  #  open      #
  #  is_open?  #
  #  close     #
  ##############
  
  it "can open" do
    database = @environment.database.new( $database_name ).open
    database.is_open?.should == true
    database.close
    database.is_open?.should == false
  end

  ############
  #  rename  #
  ############
  
  it "can rename itself" do
    new_filename  = $database_new_name.to_s + $database_extension
    # delete old renamed database if it exists from prior testing remnants
    if File.exists?( new_filename )
      File.delete( new_filename )
    end
    database = @environment.database.new( $database_name )
    database_name = database.name
    database.rename( $database_new_name )
    database.filename.should == new_filename
    database.name.should == $database_new_name.to_s
    # delete renamed database to avoid clutter
    File.delete( $environment_path + '/' + new_filename )
  end

  ###########
  #  empty  #
  ###########

  it "can empty itself of records" do
    
  end

  ###########
  #  erase  #
  ###########

  ##########
  #  sync  #
  ##########

  #################
  #  key_exists?  #
  #################

  ########################
  #  write  #
  ########################

  ########################
  #  retrieve  #
  ########################

  ########################
  #  delete  #
  ########################

  ########################
  #  associate_secondary_database  #
  ########################

  ########################
  #  is_secondary_database  #
  ########################

  ########################
  #  secondary_key_creation_callback_method  #
  ########################

  ########################
  #  secondary_key_creation_callback_method  #
  ########################

  ########################
  #  create_secondary_index  #
  ########################

  ########################
  #  cursor_controller  #
  ########################

  ########################
  #  cursor  #
  ########################

  ########################
  #  object_cursor  #
  ########################

end
