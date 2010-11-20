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


  it "can return its parent database" do
    RPDB::Settings::Database::Type.new( RPDB::Database::Hash.new( $database_name ) ).is_a?( RPDB::Settings::Database::Type::Hash ).should == true
  end


end
