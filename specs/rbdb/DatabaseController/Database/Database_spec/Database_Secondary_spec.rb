require_relative '../../../../../lib/rpbdb/rpbdb'

describe RPbdb::Database do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $unsorted_duplicates_database_name   = :unsorted_duplicates_db
  $sorted_duplicates_database_name   = :sorted_duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller
  end

  after( :each ) do
    @environment.close
  end

  require_relative './rb_RPbdb_Database_SecondarySupportFunctions.rb'

  ################################################
  #  set_secondary_key_creation_callback_method  #
  #  secondary_key_creation_callback_method      #
  ################################################

  # set_secondary_key_creation_callback_method( :method_in_self )
  it "can set and report its secondary key creation callback information for a method with one parameter (data)." do
    database        = @database_controller.new( $database_name )
    database_two    = @database_controller.new( $secondary_database_name )

    metaclass = class << database_two ; self ; end
    metaclass.__send__( :define_method, :callback_method, & key_from_data__lambda )
    database_two.set_secondary_key_creation_callback_method( :callback_method )

    verify_callback( database_two, database_two, :callback_method )
  end

  # set_secondary_key_creation_callback_method( callback_object, :method_in_callback_object )
  it "can set and report its secondary key creation callback information for a method in a callback object." do
    database        = @database_controller.new( $database_name )
    database_two    = @database_controller.new( $secondary_database_name )

    class TestClass
    end
    TestClass.__send__( :define_method, :callback_method, & key_from_data__lambda )
    test_object = TestClass.new
    database_two.set_secondary_key_creation_callback_method( test_object, :callback_method )

    verify_callback( database_two, test_object, :callback_method )
  end

  # set_secondary_key_creation_callback_method( lambda { |data| ... } )
  it "can set and report its secondary key creation callback information by passing a lambda or proc with one parameter (data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
  
    callback_lambda  = key_from_data__lambda
    database_two.set_secondary_key_creation_callback_method( callback_lambda )

    verify_callback( database_two, callback_lambda, callback_lambda )
  end

  # set_secondary_key_creation_callback_method( lambda { |key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a lambda or proc with two parameters (key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
  
    callback_lambda  = key_from_key__lambda
    database_two.set_secondary_key_creation_callback_method( callback_lambda )

    verify_callback( database_two, callback_lambda, callback_lambda )
  end

  # set_secondary_key_creation_callback_method( lambda { |database, key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a lambda or proc with three parameters (database, key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
  
    callback_lambda  = key_from_database__lambda
    database_two.set_secondary_key_creation_callback_method( callback_lambda )

    verify_callback( database_two, callback_lambda, callback_lambda )
  end

  # set_secondary_key_creation_callback_method( & lambda { |data| ... } )
  it "can set and report its secondary key creation callback information by passing a block with one parameter (parameters: key)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
  
    callback_lambda  = key_from_data__lambda
    database_two.set_secondary_key_creation_callback_method( & callback_lambda )

    verify_callback( database_two, callback_lambda, callback_lambda )
  end

  # set_secondary_key_creation_callback_method( & lambda { |key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a block with two parameters (parameters: key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
  
    callback_lambda  = key_from_key__lambda
    database_two.set_secondary_key_creation_callback_method( & callback_lambda )

    verify_callback( database_two, callback_lambda, callback_lambda )
  end

  # set_secondary_key_creation_callback_method( & lambda { |database, key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a block with three parameters (parameters: database, key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
  
    callback_lambda  = key_from_database__lambda
    database_two.set_secondary_key_creation_callback_method( & callback_lambda )

    verify_callback( database_two, callback_lambda, callback_lambda )
  end

  ############################
  #  create_secondary_index  #
  #  create_secondary        #
  #  new_secondary           #
  #  new_index               #
  ############################

  # create_secondary_index( :index_name, :callback_method_in_primary )
  it "can create and associate a secondary index with a callback method in the primary database" do
    database        = @database_controller.new( $database_name )

    metaclass = class << database ; self ; end
    metaclass.__send__( :define_method, :callback_method, & key_from_data__lambda )
    database_two = database.create_secondary_index( :index, :callback_method )
  
    verify_secondary( database, database_two, database, :callback_method, 'primary key', 'some data', 'some data' )
  end

  # create_secondary
  # new_secondary
  # new_index
  it "can also use several aliases to do the same thing" do
    database      = @environment.database.new( $database_name ).open
    primary_name  = database.method( :create_secondary_index )
    database.method( :create_secondary ).should == primary_name
    database.method( :new_secondary ).should    == primary_name
    database.method( :new_index ).should        == primary_name
  end

  # create_secondary_index( :index_name, callback_object, :callback_method_in_object )  
  it "can create and associate a secondary index with a callback method in a callback object" do
    database        = @database_controller.new( $database_name )

    class TestClass
    end
    callback_instance = TestClass.new
    metaclass = class << callback_instance ; self ; end
    metaclass.__send__( :define_method, :callback_method, & key_from_data__lambda )
    database_two = database.create_secondary_index( :index, callback_instance, :callback_method )

    verify_secondary( database, database_two, callback_instance, :callback_method, 'primary key', 'some data', 'some data' )
  end

  # create_secondary_index( :index_name, lambda { |data| ... } ) 
  it "can create and associate a secondary index with a callback lambda or proc with one paramter (parameters: key)" do
    database      = @database_controller.new( $database_name )
  
    callback_lambda  = key_from_data__lambda
    database_two = database.create_secondary_index( :index, callback_lambda )

    verify_secondary( database, database_two, callback_lambda, callback_lambda, 'primary key', 'some data', 'some data' )
  end

  # create_secondary_index( :index_name, lambda { |key, data| ... } )
  it "can create and associate a secondary index with a callback lambda or proc with two paramters (parameters: key, data)" do
    database      = @database_controller.new( $database_name )
  
    callback_lambda  = key_from_key__lambda
    database_two = database.create_secondary_index( :index, callback_lambda )

    verify_secondary( database, database_two, callback_lambda, callback_lambda, 'primary key', 'some data', 'primary key' )    
  end

  # create_secondary_index( :index_name, lambda { |database, key, data| ... } )
  it "can create and associate a secondary index with a callback lambda or proc with three paramters (parameters: database, key, data)" do
    database      = @database_controller.new( $database_name )
  
    callback_lambda  = key_from_database__lambda
    database_two = database.create_secondary_index( :index, callback_lambda )

    verify_secondary( database, database_two, callback_lambda, callback_lambda, 'primary key', 'some data', database_two.name )    
  end

  # create_secondary_index( :index_name, & lambda { |key| ... } ) 
  it "can create a secondary index with a block, automatically associating the secondary database with the primary (parameters: key)" do
    database      = @database_controller.new( $database_name )
  
    callback_lambda  = key_from_data__lambda
    database_two = database.create_secondary_index( :index, & callback_lambda )

    verify_secondary( database, database_two, callback_lambda, callback_lambda, 'primary key', 'some data', 'some data' )
  end

  # create_secondary_index( :index_name, & lambda { |key, data| ... } )
  it "can create a secondary index with a block, automatically associating the secondary database with the primary (parameters: key, data)" do
    database      = @database_controller.new( $database_name )
  
    callback_lambda  = key_from_key__lambda
    database_two = database.create_secondary_index( :index, & callback_lambda )

    verify_secondary( database, database_two, callback_lambda, callback_lambda, 'primary key', 'some data', 'primary key' )    
  end

  # create_secondary_index( :index_name, & lambda { |database, key, data| ... } )
  it "can create a secondary index with a block, automatically associating the secondary database with the primary (parameters: database, key, data)" do
    database      = @database_controller.new( $database_name )
  
    callback_lambda  = key_from_database__lambda
    database_two = database.create_secondary_index( :index, & callback_lambda )

    verify_secondary( database, database_two, callback_lambda, callback_lambda, 'primary key', 'some data', database_two.name )    
  end

  ############################
  #  is_secondary_database?  #
  #  is_secondary_index?     #
  #  secondary_database?     #
  #  secondary_index?        #
  ############################

  # is_secondary_database?
  it "can answer whether it is a secondary database" do
    database        = @database_controller.new( $database_name )
    metaclass = class << database ; self ; end
    metaclass.__send__( :define_method, :callback_method, & key_from_data__lambda )
    database_two = database.create_secondary_index( :index, :callback_method )
    database_two.is_secondary?.should == true
  end

  # secondary_database?
  it "also has an alias to do the same thing" do
    database = @database_controller.new( $database_name )
    database.method( :is_secondary_database? ).should == database.method( :secondary_database? )    
  end

  #######################
  #  primary_database   #
  #######################

  # primary_database
  it "it can return its primary database, which is itself if it is the primary database" do
    database      = @database_controller.new( $database_name )
  
    callback_lambda  = key_from_data__lambda
    database_two = database.create_secondary_index( :index, & callback_lambda )

    database.primary_database.should == database
    database_two.primary_database.should == database
  end

  ##########################
  #  set_unique_for_index  #
  #  unique_for_index      #
  ##########################

  it "can declare key combinations unique for a set of indexes" do
    database      = @database_controller.new( $database_name )
  
    callback_three  = key_from_key__lambda
    index_three     = database.create_secondary_index( :key, & callback_three )

    database.unique_for_index( :key ).should == true

    callback_two    = key_from_data__lambda
    callback_one    = key_from_database__lambda
    index_one       = database.create_secondary_index_with_unsorted_duplicates( :database, & callback_one )
    index_two       = database.create_secondary_index_with_unsorted_duplicates( :data, & callback_two )

    database.unique_for_index( :database, :data ).should == false
    database.set_unique_for_index( :database, :data )
    database.unique_for_index( :database, :data ).should == true
  end

end
