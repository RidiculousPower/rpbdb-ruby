require_relative '../../../../../lib/rpdb/rpdb'

describe RPDB::Database do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $unsorted_duplicates_database_name   = :unsorted_duplicates_db
  $sorted_duplicates_database_name   = :sorted_duplicates_db
  
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

  # RPDB::Database.new( name, environment )
  it "can be created with a name and a parent environment" do
    RPDB::Database.new( $database_name, @environment ).is_a?( RPDB::Database ).should == true
    RPDB::Database::Btree.new( $database_name, @environment ).is_a?( RPDB::Database::Btree ).should == true
    RPDB::Database::Hash.new( $database_name, @environment ).is_a?( RPDB::Database::Hash ).should == true
    RPDB::Database::Queue.new( $database_name, @environment ).is_a?( RPDB::Database::Queue ).should == true
    RPDB::Database::Recno.new( $database_name, @environment ).is_a?( RPDB::Database::Recno ).should == true
  end

  # RPDB::Database.new( name, environment_name ) 
  it "can be created with a name and a parent environment directory" do
    RPDB::Database.new( $database_name, $environment_path ).is_a?( RPDB::Database ).should == true  
    RPDB::Database::Btree.new( $database_name, $environment_path ).is_a?( RPDB::Database::Btree ).should == true  
    RPDB::Database::Hash.new( $database_name, $environment_path ).is_a?( RPDB::Database::Hash ).should == true  
    RPDB::Database::Queue.new( $database_name, $environment_path ).is_a?( RPDB::Database::Queue ).should == true  
    RPDB::Database::Recno.new( $database_name, $environment_path ).is_a?( RPDB::Database::Recno ).should == true  
  end

  # RPDB::Database.new( name, database_controller ) 
  it "can be created with a name and a parent database controller" do
    RPDB::Database.new( $database_name, @database_controller ).is_a?( RPDB::Database ).should == true
    RPDB::Database::Btree.new( $database_name, @database_controller ).is_a?( RPDB::Database::Btree ).should == true
    RPDB::Database::Hash.new( $database_name, @database_controller ).is_a?( RPDB::Database::Hash ).should == true
    RPDB::Database::Queue.new( $database_name, @database_controller ).is_a?( RPDB::Database::Queue ).should == true
    RPDB::Database::Recno.new( $database_name, @database_controller ).is_a?( RPDB::Database::Recno ).should == true
  end

  # RPDB::Database.new( name )  
  it "can be created with a name (using the default environment)" do
    RPDB::Database.new( $database_name ).is_a?( RPDB::Database ).should == true
    RPDB::Database::Btree.new( $database_name ).is_a?( RPDB::Database::Btree ).should == true
    RPDB::Database::Hash.new( $database_name ).is_a?( RPDB::Database::Hash ).should == true
    RPDB::Database::Queue.new( $database_name ).is_a?( RPDB::Database::Queue ).should == true
    RPDB::Database::Recno.new( $database_name ).is_a?( RPDB::Database::Recno ).should == true
  end

  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    # create a database
    database = @database_controller.new_database( $database_name )
    # make sure it has a settings controller
    # and that it's not the same settings controller that our environment owns
    database.settings.is_a?( RPDB::Settings::Database ).should == true
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

  ##########
  #  name  #
  ##########
  
  it "can report its name, by which it is uniquely identified" do
    database = @environment.database.new( $database_name )
    database.name.should == $database_name.to_s
  end

  ############
  #  handle  #
  ############
  
  it "can report its handle, which is the symbol version of its name" do
    database = @environment.database.new( $database_name )
    database.handle.should == $database_name
  end
  
  ##############
  #  filename  #
  ##############

  it "can report its filename, which is based on its name" do
    database = @environment.database.new( $database_name )
    # FIX - import constants from configuration and use here
    database.filename.should == $database_name.to_s + $database_extension
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
    database = @environment.database.new( $database_name ).open
    database_name = database.name
    database.rename( $database_new_name )
    database.filename.should == new_filename
    database.name.should == $database_new_name.to_s
    # delete renamed database to avoid clutter
    renamed_filename = $environment_path + '/' + new_filename
    File.delete( renamed_filename ) if renamed_filename
  end

  ############
  #  empty!  #
  ############

  it "can empty itself of records" do
    database = @environment.database.new( $database_name ).open
    10.times do |this_time|
      database.write( this_time.to_s => 'some data' )
    end
    database.empty!
    10.times do |this_time|
      database.retrieve( this_time.to_s ).should == nil
    end
  end

  ############
  #  erase!  #
  ############
  
  it "can erase itself" do
    database = @environment.database.new( $database_name ).open
    database_name = database.name
    database.erase!
    File.exists?( $environment_path + '/' + database_name + $database_extension ).should == false
  end
  
  ###########
  #  sync!  #
  ###########

  it "can synchronize" do
    database = @environment.database.new( $database_name ).open
    10.times do |this_time|
      database.write( this_time.to_s => 'some data' )
    end
    database.sync!
    database.empty!
  end

  #######################
  #  cursor_controller  #
  #######################

  it "has a cursor controller" do
    database = @environment.database.new( $database_name ).cursor_controller
  end

  #####################
  #  join_controller  #
  #####################

  it "has a join controller" do
    @environment.database.new( $database_name ).join_controller.is_a?( RPDB::Database::Join::Controller ).should == true
  end

  ############
  #  cursor  #
  ############

  it "can return a cursor from its cursor controller" do
    @environment.database.new( $database_name ).cursor.is_a?( RPDB::Database::Cursor ).should == true
  end

  ###################
  #  object_cursor  #
  ###################

  it "can return an object cursor (which automatically handles serialization) from its cursor controller" do
    cursor = @environment.database.new( $database_name ).object_cursor.is_a?( RPDB::Database::Cursor::ObjectCursor ).should == true
  end

  ##########
  #  each  #
  ##########

  it "can iterate each record in the current index" do
    duplicates_database = @database_controller.new( $sorted_duplicates_database_name )

    duplicates_database.set.readwrite.turn_sorted_duplicates_on
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    duplicates_database.write( records )
    duplicates_database.each do |key, data, index|
      key.should_not == nil
      data.should_not == nil
    end
  end

  ####################
  #  each_duplicate  #
  ####################

  it "can iterate each duplicate record for the current key" do
    duplicates_database = @database_controller.new( $sorted_duplicates_database_name )
    duplicates_database.set.readwrite.sorted_duplicates_on

    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    duplicates_database.write( records )
    duplicates_database.each_key do |key, data, index|
      key.should_not == nil
      duplicates_database.each_duplicate do |duplicate_data, duplicate_index|
        duplicate_data.should_not == nil
      end
    end    
  end

  ##############
  #  each_key  #
  ##############

  it "can iterate each key in the current index" do
    duplicates_database = @database_controller.new( $sorted_duplicates_database_name )
    duplicates_database.set.readwrite.turn_sorted_duplicates_on

    cursor = duplicates_database.cursor
    key_one = 'key'
    key_two = 'some other key'
    records = [ { key_one => 'a' },
                { key_one => 'b' },
                { key_one => 'c' },
                { key_one => 'd' },
                { key_two => 'e' },
                { key_two => 'f' },
                { key_two => 'g' } ]
    duplicates_database.write( records )
    duplicates_database.each_key do |key, data, index|
      key.should_not == nil
      data.should_not == nil
    end    
  end

end
