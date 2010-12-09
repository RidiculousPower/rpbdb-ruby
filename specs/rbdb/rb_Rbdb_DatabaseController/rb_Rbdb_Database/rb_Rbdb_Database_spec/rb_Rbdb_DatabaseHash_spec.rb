require_relative '../../../../../lib/rbdb/rbdb'

describe Rbdb::Database::Hash do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
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

  # Rbdb::Database.new( name, environment )
  it "can be created with a name and a parent environment" do
    Rbdb::Database::Hash.new( $database_name, @environment ).is_a?( Rbdb::Database::Hash ).should == true
  end

  # Rbdb::Database.new( name, environment_name ) 
  it "can be created with a name and a parent environment directory" do
    Rbdb::Database::Hash.new( $database_name, $environment_path ).is_a?( Rbdb::Database::Hash ).should == true  
  end

  # Rbdb::Database.new( name, database_controller ) 
  it "can be created with a name and a parent database controller" do
    Rbdb::Database::Hash.new( $database_name, @database_controller ).is_a?( Rbdb::Database::Hash ).should == true
  end

  # Rbdb::Database.new( name )  
  it "can be created with a name (using the default environment)" do
    Rbdb::Database::Hash.new( $database_name ).is_a?( Rbdb::Database::Hash ).should == true
  end

end
