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
    @database.cursors.close_all
    @database.empty!
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
    @database.cursor.settings_controller.should_not == nil
    @database.cursor.settings_controller.should_not == @database.cursors.settings_controller
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    @database.cursor.parent_environment.should == @environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can refer to its parent database" do
    @database.cursor.parent_database.should == @database
  end

  #######################################
  #  parent_database_cursor_controller  #
  #######################################

  it "can refer to its parent cursor controller" do
    @database.cursor.parent_database_cursor_controller.should == @cursor_controller
  end

  ##############
  #  open      #
  #  is_open?  #
  #  close     #
  ##############

  it "can open, report whether it is open, and close" do
    cursor = @database.cursor
    cursor.open.is_open?.should == true
    cursor.close.is_open?.should == false
  end

  ######################
  #  duplicate_cursor  #
  ######################

  it "can be duplicated so a second cursor points at the same location" do
    write_values  = { 'first key'   => 'first value',
                      'second key'  => 'second value'}
    @database.write( write_values )
    cursor_one = @database.cursor.open
    cursor_one.next
    cursor_two = cursor_one.duplicate
    # FIX - currently fails and creates new cursor instead of duplicating cursor
    cursor_two.current.should == cursor_one.current
  end

  ###########
  #  write  #
  ###########

  it "can write to the database" do
    @database.cursor.write( 'key' => 'value' )
  end

  #######################
  #  overwrite_current  #
  #######################

  it "can write to the database overwriting the current record" do
    cursor = @database.cursor
    cursor.write( 'key' => 'value' )
    first_value = cursor.retrieve( 'key' )
    cursor.overwrite_current( 'new value' )
    cursor.current.should == 'new value'
    cursor.retrieve( 'key' ).should == 'new value'
  end

  ######################################
  #  write_as_duplicate_after_current  #
  ######################################

  it "can write to the database, inserting as a duplicate key after the current record" do
    
  end

  #######################################
  #  write_as_duplicate_before_current  #
  #######################################

  it "can write to the database, inserting as a duplicate key before the current record" do
    
  end

  #################################
  #  write_before_any_duplicates  #
  #################################

  it "can write to the database, inserting as a duplicate key before any other duplicate records" do
    
  end

  ################################
  #  write_after_any_duplicates  #
  ################################

  it "can write to the database, inserting as a duplicate key after any other duplicate records" do
    
  end

  ###################################
  #  write_only_if_not_in_database  #
  ###################################

  it "write to the database only if not already in the database" do
    
  end

  #################
  #  key_exists?  #
  #################

  it "can report whether a key already exists in the database" do
    
  end

  ##############
  #  retrieve  #
  ##############

  it "can retrieve a record from the database" do
    
  end

  ##################
  #  retrieve_key  #
  ##################

  it "can retrieve a key from the database" do
    
  end

  ##########################
  #  retrieve_partial_key  #
  #  partial_key           #         
  #  retrieve_partial      #    
  ##########################

  it "can retrieve all keys matching a partial description" do
    
  end

  ###########################
  #  retrieve_partial_data  #
  #  partial_data           #         
  ###########################

  it "can retrieve all records matching a partial description" do
    
  end

  ######################
  #  retrieve_current  #
  #  current           #         
  ######################

  it "can retrieve the current record" do
    
  end

  ##########################
  #  retrieve_current_key  #
  #  current_key           #         
  ##########################

  it "can retrieve the key corresponding to the current record" do
    
  end

  ####################
  #  retrieve_first  #
  #  first          #         
  ####################

  it "can retrieve the first record for the current index" do
    
  end

  ########################
  #  retrieve_first_key  #
  #  first_key           #         
  ########################

  it "can retrieve the key corresponding to the first record for the current index" do
    
  end

  ###################
  #  retrieve_last  #
  #  last           #         
  ###################

  it "can retrieve the last record for the current index" do
    
  end

  #######################
  #  retrieve_last_key  #
  #  last_key           #         
  #######################

  it "can retrieve the key corresponding to the last record for the current index" do
    
  end

  ###################
  #  retrieve_next  #
  #  next           #         
  ###################

  it "can retrieve the next record for the current index relative to the current position" do
    
  end

  #######################
  #  retrieve_next_key  #
  #  next_key           #         
  #######################

  it "can retrieve the key corresponding to the next record for the current index relative to the current position" do
    
  end

  #######################
  #  retrieve_previous  #
  #  previous           #         
  #######################

  it "can retrieve the previous record for the current index relative to the current position" do
    
  end

  ###########################
  #  retrieve_previous_key  #
  #  previous_key           #         
  ###########################

  it "can retrieve the key corresponding to the previous record for the current index, relative to the current position" do
    
  end

  ######################################
  #  count_duplicates_for_current_key  #
  ######################################

  it "can count how many duplicates exist for the key corresponding to the current position" do
    
  end

  #############################
  #  retrieve_next_duplicate  #
  #  next_duplicate           #         
  #############################

  it "can retrieve the next duplicate record for the current key, relative to the current position" do
    
  end

  #################################
  #  retrieve_previous_duplicate  #
  #  previous_duplicate           #         
  #################################

  it "can retrieve the previous duplicate record for the current key, relative to the current position" do
    
  end

  #################################
  #  retrieve_next_non_duplicate  #
  #  next_non_duplicate           #         
  #################################

  it "can retrieve the next non-duplicate record for the current key, relative to the current position" do
    
  end

  #####################################
  #  retrieve_previous_non_duplicate  #
  #  previous_non_duplicate           #         
  #####################################

  it "can retrieve the previous non-duplicate record for the current key, relative to the current position" do
    
  end

  ##########
  #  each  #
  ##########

  it "can iterate each record in the current index" do
    
  end

  ################
  #  each_slice  #
  ################

  it "can iterate each record in the current index a slice of records at a time" do
    
  end

  ####################
  #  each_duplicate  #
  ####################

  it "can iterate each duplicate record for the current key" do
    
  end

  ##########################
  #  each_duplicate_slice  #
  ##########################

  it "can iterate each duplicate record for the current key a slice of records at a time" do
    
  end

  ##############
  #  each_key  #
  ##############

  it "can iterate each key in the current index" do
    
  end

  ####################
  #  each_key_slice  #
  ####################

  it "can iterate each key in the current index a slice of records at a time" do
    
  end

  ############
  #  delete  #
  ############

  it "can delete the record at the current position" do
    
  end
  
end
