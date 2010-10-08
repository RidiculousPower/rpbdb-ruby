require_relative 'lib/rpdb.rb'

describe RPDB::Environment::DatabaseController::Database do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller

  end

  after( :each ) do
    @environment.close
  end

  ##########
  #  each  #
  ##########

  it "can iterate each record in the current index" do
    duplicates_database = @database_controller.new( $duplicates_database_name )
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
    duplicates_database.each do |key, data, index|
      key.should_not == nil
      data.should_not == nil
    end
  end

  ####################
  #  each_duplicate  #
  ####################

  it "can iterate each duplicate record for the current key" do
    duplicates_database = @database_controller.new( $duplicates_database_name )
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
    duplicates_database = @database_controller.new( $duplicates_database_name )
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
