require_relative 'lib/rpdb.rb'

describe RPDB::Database::Controller do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db

  $unsorted_duplicates_database_name   = :unsorted_duplicates_db
  $sorted_duplicates_database_name   = :sorted_duplicates_db
  
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path ).open
    @database_controller = @environment.database_controller

  end

  after( :each ) do
    @environment.close
  end


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


end
