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

  ##########################################
  #  Secondary Database Support Functions  #
  ##########################################
  
  def key_from_data__lambda
    return lambda do |data|
      data.should_not == nil
      return data
    end
  end

  def key_from_key__lambda
    return lambda do |key, data|
      key.should_not == nil
      data.should_not == nil
      return key
    end
  end
  
  def key_from_database__lambda
    return lambda do |database, key, data|
      database.should_not == nil
      key.should_not == nil
      data.should_not == nil
      return database.name
    end
  end
    
  def secondary_key_test_elements
    return [  :key_from_data,
              key_from_data__lambda,
              :key_from_key,
              key_from_key__lambda,
              :key_from_database,
              key_from_database__lambda ]
  end

  def verify_secondary( primary_database, secondary_database, object, method, primary_key, data, secondary_key )
    secondary_database.secondary_key_creation_callback_method[ :object ].should == object
    secondary_database.secondary_key_creation_callback_method[ :method ].should == method
    secondary_database.is_secondary?.should == true
    secondary_database.primary_database.should == primary_database

    primary_key = primary_key
    secondary_database.primary.write( primary_key, data )
    secondary_database.retrieve( secondary_key ).should == data
    secondary_database.primary.retrieve( :index, secondary_key ).should == data    
    secondary_database.erase!
    secondary_database.primary.erase!
  end

  it "can create and associate a secondary index with a callback method in the primary database" do
    database = @environment.database.new( $database_name ).open
    database.create_secondary_index( :value ) do |key, value|
      return value
    end
#    database.write( "key" => 'some data' )
#    database.delete( :value => 'some data' )
#    database.retrieve( "key" ).should == nil    
  end

end
