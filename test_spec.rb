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




  it "can delete records specified by multiple secondary keys in an array" do
    database = @environment.database.new( $database_name )

    database.create_secondary_index( :value ) do |key, value|
      return value
    end
    database.write( "key" => 'some data',
                    "another key" => 'other data' )
    database.delete( :value, [ 'some data', 'other data' ] )
    database.retrieve( "key" ).should == nil    
  end
  


end
