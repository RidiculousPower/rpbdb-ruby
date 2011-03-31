require_relative '../../../../../lib/rpbdb/rpbdb'

describe RPbdb::Database::Cursor do

  $environment_path                   = '/tmp/rpbdb_spec_environment_home/'

  $database_name                      = :spec_database
  $duplicates_database_name           = :duplicates_db
  $unsorted_duplicates_database_name  = :unsorted_duplicates_db
  $database_new_name                  = :spec_database_renamed
  $database_extension                 = '.db'
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path ).open
    @database_controller = @environment.database_controller
    @database = @database_controller.database( $database_name )
    @database.open
    @cursor_controller = @database.cursor_controller

    @duplicates_database = @database_controller.new( $duplicates_database_name )
    @duplicates_database.set.readwrite.sorted_duplicates_on
    @duplicates_database.open

    @unsorted_duplicates_database = @database_controller.new( $unsorted_duplicates_database_name )
    @unsorted_duplicates_database.set.readwrite.unsorted_duplicates_on
    @unsorted_duplicates_database.open
  end

  after( :each ) do
    @database.cursors.close_all
    @database.erase!
    @duplicates_database.cursors.close_all
    @duplicates_database.erase!
    @unsorted_duplicates_database.cursors.close_all
    @unsorted_duplicates_database.erase!
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPbdb::Database::Cursor.new( database_cursor_controller )
  it "can be created with a parent cursor controller " do
    RPbdb::Database::Cursor.new( @cursor_controller ).should_not == nil
  end

  # RPbdb::Database::Cursor.new( database )
  it "can be created with a parent database " do
    RPbdb::Database::Cursor.new( @database ).should_not == nil
  end

  # RPbdb::Database::Cursor.new( database_controller, database_name ) 
  it "can be created with a database controller and a database name" do
    RPbdb::Database::Cursor.new( @database_controller, @database.name ).should_not == nil  
  end

  # RPbdb::Database::Cursor.new( environment, database_name ) 
  it "can be created with an environment and a database name" do
    RPbdb::Database::Cursor.new( @environment, @database.name ).should_not == nil  
  end

  # RPbdb::Database::Cursor.new( environment_directory, database_name ) 
  it "can be created with an environment directory and a database name" do
    RPbdb::Database::Cursor.new( @environment.directory, @database.name ).should_not == nil  
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

  # FIX
  it "can be duplicated so a second cursor points at the same location" do
    write_values  = { 'first key'   => 'first value',
                      'second key'  => 'second value'}
    @database.write( write_values )
    cursor_one = @database.cursor.open
    cursor_one.next
    cursor_two = cursor_one.duplicate
    # FIX - currently fails and creates new cursor instead of duplicating cursor
#    cursor_two.current.should == cursor_one.current
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
  #  count_duplicates_for_current_key  #
  ######################################

  it "can write to the database, inserting as a duplicate key after the current record, and it can count duplicates for the key" do
    cursor = @unsorted_duplicates_database.cursor
    cursor.write( 'key' => 'value' )
    cursor.count_duplicates_for_current_key.should == 1
    cursor.write_as_duplicate_after_current( 'another value' )
    cursor.count_duplicates_for_current_key.should == 2
  end

  #######################################
  #  write_as_duplicate_before_current  #
  #######################################

  it "can write to the database, inserting as a duplicate key before the current record" do
    cursor = @unsorted_duplicates_database.cursor
    cursor.write( 'key' => 'value' )
    cursor.count_duplicates_for_current_key.should == 1
    cursor.write_as_duplicate_before_current( 'another value' )
    cursor.count_duplicates_for_current_key.should == 2    
  end

  #################################
  #  write_before_any_duplicates  #
  #################################

  it "can write to the database, inserting as a duplicate key before any other duplicate records" do
    cursor = @unsorted_duplicates_database.cursor
    cursor.write( 'key' => 'value' )
    cursor.count_duplicates_for_current_key.should == 1
    cursor.write_before_any_duplicates( 'key' => 'another value' )
    cursor.count_duplicates_for_current_key.should == 2        
  end

  ################################
  #  write_after_any_duplicates  #
  ################################

  it "can write to the database, inserting as a duplicate key after any other duplicate records" do
    cursor = @unsorted_duplicates_database.cursor
    cursor.write( 'key' => 'value' )
    cursor.count_duplicates_for_current_key.should == 1
    cursor.write_after_any_duplicates( 'key' => 'another value' )
    cursor.count_duplicates_for_current_key.should == 2    
  end

  ###################################
  #  write_only_if_not_in_database  #
  ###################################

  # what is the point of this function? 
  # if sorted duplicates already prohibit exact duplicate key/data pairs
  it "can write to the database only if an exact match is not already in the database" do
    cursor = @duplicates_database.cursor
    cursor.write( 'key' => 'value' )
    cursor.write_only_if_not_in_database( 'key' => 'value' ).should == false
  end

  #################
  #  key_exists?  #
  #################

  it "can report whether a key already exists in the database" do
    cursor = @database.cursor
    cursor.write( 'key' => 'value' )
    cursor.key_exists?( 'key' ).should == true
    cursor.key_exists?( 'another key' ).should == false
  end

  ##############
  #  retrieve  #
  ##############

  it "can retrieve a record from the database" do
    @database.write( 'key' => 'value' )
    @database.cursor.retrieve( 'key' ).should == 'value'
  end

  ##################
  #  retrieve_key  #
  ##################

  it "can retrieve a key from the database" do
    @database.write( 'key' => 'value' )
    @database.cursor.retrieve_key( 'key' ).should == 'key'    
  end

  ##########################
  #  retrieve_partial_key  #
  #  partial_key           #         
  #  retrieve_partial      #    
  ##########################

  it "can retrieve all keys matching a partial description" do
    @database.write(  'key'     => 'value' )
    @database.cursor.retrieve_partial_key( 'ke' ).should == 'key'
  end

  ##############################################
  #  retrieve_duplicate_matching_partial_data  #
  #  retrieve_duplicate_for_partial_data       #         
  #  retrieve_partial_data                     #         
  ##############################################

  it "can retrieve all records matching a partial description" do
    cursor = @duplicates_database.cursor
    cursor.write( 'key'   => 'a key' )
    cursor.write( 'key'   => 'b key' )
    cursor.retrieve_duplicate_matching_partial_data( 'key' => 'a' ).should == 'a key'
  end

  ###########################
  #  retrieve_current       #
  #  current                #         
  #                         #
  #  retrieve_first         #
  #  first                  #         
  #                         #
  #  retrieve_first_key     #
  #  first_key              #         
  #                         #
  #  retrieve_current_key   #
  #  current_key            #         
  #                         #
  #  retrieve_next          #
  #  next                   #         
  #                         #
  #  retrieve_next_key      #
  #  next_key               #         
  #                         #
  #  retrieve_previous      #
  #  previous               #         
  #                         #
  #  retrieve_previous_key  #
  #  previous_key           #         
  #                         #
  #  retrieve_last          #
  #  last                   #         
  #                         #
  #  retrieve_last_key      #
  #  last_key               #         
  ###########################

  it "can retrieve the first key and record, the next key and record, the current key and record, the previous key and record, the last key and record" do
    cursor = @duplicates_database.cursor
    cursor.write( 'key'       => 'a' )
    cursor.write( 'next key'  => 'b' )
    cursor.first.should         == 'a'
    cursor.first_key.should     == 'key'
    cursor.current.should       == 'a'
    cursor.current_key.should   == 'key'
    cursor.next.should          == 'b'
    cursor.previous_key.should  == 'key'
    cursor.next_key.should      == 'next key'
    cursor.previous.should      == 'a'
  end

  #####################################
  #  retrieve_next_duplicate          #
  #  next_duplicate                   #         
  #                                   #
  #  retrieve_previous_duplicate      #
  #  previous_duplicate               #         
  #                                   #
  #  retrieve_next_non_duplicate      #
  #  next_non_duplicate               #         
  #                                   #
  #  retrieve_previous_non_duplicate  #
  #  previous_non_duplicate           #         
  #####################################

  it "can retrieve the next duplicate record for the current key, relative to the current position" do
    cursor = @duplicates_database.cursor
    records = [ { 'key' => 'a' },
                { 'key' => 'b' },
                { 'key' => 'c' },
                { 'key' => 'd' },
                { 'some other key' => 'e' },
                { 'some other key' => 'f' },
                { 'some other key' => 'g' } ]
    @duplicates_database.write( records )
    cursor.first.should                   == 'a'
    cursor.next_duplicate.should          == 'b'
    cursor.previous_duplicate.should      == 'a'
    # notice that when we move backward we get the _last_ duplicate of the previous non-duplicate record,
    # not the record we were previously at
    cursor.next_non_duplicate.should      == 'e'
    cursor.previous_non_duplicate.should  == 'd'
  end

  ##########
  #  each  #
  ##########

  it "can iterate each record in the current index" do
    cursor = @duplicates_database.cursor
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    @duplicates_database.write( records )
    cursor.first
    cursor.each do |key, data, index|
      data.should == 'a' if index == 0
      data.should == 'b' if index == 1
      data.should == 'c' if index == 2
      data.should == 'd' if index == 3
      data.should == 'e' if index == 4
      data.should == 'f' if index == 5
      data.should == 'g' if index == 6
      key.should == key_one if (0..3).include?( index )
      key.should == key_two if (4..6).include?( index )
    end
  end

  ####################
  #  each_duplicate  #
  ####################

  it "can iterate each duplicate record for the current key" do
    cursor = @duplicates_database.cursor
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    @duplicates_database.write( records )
    cursor.first
    cursor.each_key do |key, data, index|
      cursor.each_duplicate do |data, duplicate_index|
        data.should_not == nil
      end
    end    
  end

  ##############
  #  each_key  #
  ##############

  it "can iterate each key in the current index" do
    cursor = @duplicates_database.cursor
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    @duplicates_database.write( records )
    cursor.first
    cursor.each_key do |key, data, index|
      key.should_not == nil
      data.should_not == nil
    end    
  end

  ###########
  #  slice  #
  ###########

  it "can return a cursor corresponding to a slice of records" do
    cursor = @duplicates_database.cursor
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    @duplicates_database.write( records )
    cursor.first
    cursor.slice( 3 ) do |key, data, index|
      key.should_not == nil
      data.should_not == nil
      index.should_not >= 2
    end    
  end

  ################
  #  slice_keys  #
  ################

  it "can return a cursor corresponding to a slice of keys" do
    cursor = @duplicates_database.cursor
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    @duplicates_database.write( records )
    cursor.first
    previous_key = nil
    cursor.slice_keys( 2 ) do |key, data, index|
      key.should_not == nil
      key.should_not == previous_key
      data.should_not == nil
      index.should_not >= 2
      previous_key = key
    end
  end

  ######################
  #  slice_duplicates  #
  ######################

  it "can return a cursor corresponding to a slice of duplicate records" do
    cursor = @duplicates_database.cursor
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    @duplicates_database.write( records )
    cursor.first
    cursor.each do |key, data, index|
      cursor.slice_duplicates( 2 ) do |data, index|
        key.should_not == nil
        data.should_not == nil
        index.should_not >= 2
      end
    end
  end

  ############
  #  delete  #
  ############

  it "can delete the record at the current position" do
    cursor = @duplicates_database.cursor
    @duplicates_database.write( 'key' => 'value' )
    cursor.retrieve( 'key' ).should_not == nil
    cursor.delete
    cursor.retrieve( 'key' ).should == nil
  end
  
end
