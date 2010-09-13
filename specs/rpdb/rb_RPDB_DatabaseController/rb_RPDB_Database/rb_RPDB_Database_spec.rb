require_relative '../../../../lib/rpdb/rpdb'

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

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Environment::DatabaseController::Database.new( name, environment )
  it "can be created with a name and a parent environment" do
    RPDB::Environment::DatabaseController::Database.new( $database_name, @environment ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database.new( name, environment_name ) 
  it "can be created with a name and a parent environment directory" do
    RPDB::Environment::DatabaseController::Database.new( $database_name, $environment_path ).should_not == nil  
  end

  # RPDB::Environment::DatabaseController::Database.new( name, database_controller ) 
  it "can be created with a name and a parent database controller" do
    RPDB::Environment::DatabaseController::Database.new( $database_name, @database_controller ).should_not == nil
  end

  # RPDB::Environment::DatabaseController::Database.new( name )  
  it "can be created with a name (using the default environment)" do
    RPDB::Environment::DatabaseController::Database.new( $database_name ).should_not == nil
  end
  
  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    # create a database
    database = @database_controller.new_database( $database_name )
    # make sure it has a settings controller
    # and that it's not the same settings controller that our environment owns
    database.settings.should_not == nil
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
    File.delete( $environment_path + '/' + new_filename )
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
    
  def verify_callback( secondary_database, object, method )
    secondary_database.secondary_key_creation_callback_method[ :object ].should == object
    secondary_database.secondary_key_creation_callback_method[ :method ].should == method    

    secondary_database.erase! if File.exists?( secondary_database.filename )
    secondary_database.primary.erase! if File.exists?( secondary_database.primary.filename )
  end

  def verify_secondary( primary_database, secondary_database, object, method, primary_key, data, secondary_key )

    secondary_database.is_secondary?.should == true
    secondary_database.primary_database.should == primary_database
    
    primary_database.empty!
    
    primary_key = primary_key
    secondary_database.primary.write( primary_key, data )
    secondary_database.retrieve( secondary_key ).should == data
    secondary_database.primary.retrieve( :index, secondary_key ).should == data    

    verify_callback( secondary_database, object, method )
  end

  ################################################
  #  set_secondary_key_creation_callback_method  #
  #  secondary_key_creation_callback_method      #
  ################################################

  # secondary_key_creation_callback_method( :method_in_self )
  it "can set and report its secondary key creation callback information for a method with one parameter (data)." do
    database        = @database_controller.new( $database_name )
    database_two    = @database_controller.new( $secondary_database_name )

    metaclass = class << database_two ; self ; end
    metaclass.__send__( :define_method, :callback_method, & key_from_data__lambda )
    database_two.set_secondary_key_creation_callback_method( :callback_method )

    verify_callback( database_two, database_two, :callback_method )
  end

  # secondary_key_creation_callback_method( callback_object, :method_in_callback_object )
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

  # secondary_key_creation_callback_method( lambda { |data| ... } )
  it "can set and report its secondary key creation callback information by passing a lambda or proc with one parameter (data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
    
    callback_lambda  = key_from_data__lambda
    database_two.set_secondary_key_creation_callback_method( callback_lambda )

    verify_callback( database_two, callback_lambda, nil )
  end

  # secondary_key_creation_callback_method( lambda { |key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a lambda or proc with two parameters (key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
    
    callback_lambda  = key_from_key__lambda
    database_two.set_secondary_key_creation_callback_method( callback_lambda )

    verify_callback( database_two, callback_lambda, nil )
  end

  # secondary_key_creation_callback_method( lambda { |database, key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a lambda or proc with three parameters (database, key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
    
    callback_lambda  = key_from_database__lambda
    database_two.set_secondary_key_creation_callback_method( callback_lambda )

    verify_callback( database_two, callback_lambda, nil )
  end

  # secondary_key_creation_callback_method( & lambda { |data| ... } )
  it "can set and report its secondary key creation callback information by passing a block with one parameter (data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
    
    callback_lambda  = key_from_data__lambda
    database_two.set_secondary_key_creation_callback_method( & callback_lambda )

    verify_callback( database_two, callback_lambda, nil )
  end

  # secondary_key_creation_callback_method( & lambda { |key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a block with two parameters (key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
    
    callback_lambda  = key_from_key__lambda
    database_two.set_secondary_key_creation_callback_method( & callback_lambda )

    verify_callback( database_two, callback_lambda, nil )
  end

  # secondary_key_creation_callback_method( & lambda { |database, key, data| ... } )
  it "can set and report its secondary key creation callback information by passing a block with three parameters (database, key, data)." do
    database      = @database_controller.new( $database_name )
    database_two  = @database_controller.new( $secondary_database_name )
    
    callback_lambda  = key_from_database__lambda
    database_two.set_secondary_key_creation_callback_method( & callback_lambda )

    verify_callback( database_two, callback_lambda, nil )
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

    database_two.secondary_key_creation_callback_method[ :object ].should == callback_instance
    database_two.secondary_key_creation_callback_method[ :method ].should == :callback_method

    verify_secondary( database, database_two, callback_instance, :callback_method, 'primary key', 'some data', 'some data' )
  end

  # create_secondary_index( :index_name, lambda { |data| ... } ) 
  it "can create and associate a secondary index with a callback lambda or proc with one paramter (data)" do
    
  end

  # create_secondary_index( :index_name, lambda { |key, data| ... } )
  it "can create and associate a secondary index with a callback lambda or proc with two paramters (key, data)" do
    
  end

  # create_secondary_index( :index_name, lambda { |database, key, data| ... } )
  it "can create and associate a secondary index with a callback lambda or proc with three paramters (database, key, data)" do
    
  end

  # create_secondary_index( :index_name, & lambda { |key| ... } ) 
  it "can create a secondary index with a block, automatically associating the secondary database with the primary" do

  end

  # create_secondary_index( :index_name, & lambda { |key, data| ... } )

  # create_secondary_index( :index_name, & lambda { |database, key, data| ... } )

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
  it "" do
    
  end

  ###########
  #  write  #
  ###########

  # write( primary_key, data_value )
  it "can write using a string key and a string data item" do
    database = @environment.database.new( $database_name ).open
    database.write( "key", 'some data' )
    database.key_exists?( "key" ).should == true    
  end
  
  # write( primary_key => data_value )
  it "can write using a hash argument string key => string data" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.key_exists?( "key" ).should == true    
  end

  # write( primary_key => [ data_value, ... ] )
  it "can retrieve multiple primary key values" do
    
  end

  # write( :index, secondary_key => [ data_value, ... ] )
  it "" do
    
    # make sure that the record already exists or throws error
    
  end
  
  # write( [ any_arg_form, ... ] )
  it "" do
    
  end  

  #################
  #  key_exists?  #
  #  keys_exist?  #
  #################

  # key_exists?( primary_key )
  it "can report whether a key exists" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.key_exists?( "key" ).should == true
  end

  # key_exists?( :index, secondary_key )
  
  # key_exists?( :index => secondary_key )
  
  # key_exists?( :index => [ secondary_key, ... ] )

  ##############
  #  retrieve  #
  ##############

  # retrieve( primary_key )
  it "can retrieve using a primary key" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.retrieve( "key" ).should == 'some data'    
  end

  # retrieve( :index, secondary_key )
  it "can retrieve using an index specifying a secondary database and a secondary key" do
    database = @environment.database.new( $database_name ).open
    database.empty!
    database.create_secondary( :value ) do |key, value|
      return value
    end
    secondary_database = database.index( :value )
    database.write( 'key' => 'value' )
    database.retrieve( 'key' ).should == 'value'
    database.retrieve( :value => 'value' ).should == 'value'
  end

  # retrieve( :index => secondary_key )
  it "can retrieve using a secondary index pointing to a secondary key in a hash" do
    
  end
  
  # retrieve( [ any_arg_form, ... ] )
  it "" do
    
  end
  
  ###########
  #  shift  #
  ###########
  
  # shift
  it "can shift the first record" do
    
  end
  
  #############
  #  unshift  #
  #############

  # unshift
  it "can unshift to become the first record" do
    
  end

  #########
  #  pop  #
  #########

  # pop
  it "can pop the last record" do
    
  end

  ##########
  #  push  #
  ##########

  # push
  it "can push to become the last record" do
    
  end
  
  ############
  #  delete  #
  ############

  # delete( primary_key )
  it "can delete using a string key" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.delete( "key" )
    database.retrieve( "key" ).should == nil        
  end
  
  # delete( :index, secondary_key )
  it "" do
    database = @environment.database.new( $database_name ).open
    database.create_secondary_index( :value ) do |key, value|
      return value
    end
    database.write( "key" => 'some data' )
    database.delete( :value => 'some data' )
    database.retrieve( "key" ).should == nil    
  end
  
  # delete( :index => secondary_key )
  it "" do
    
  end
  
  # delete( [ any_arg_form, ... ] )
  it "" do
    
  end

  #######################
  #  cursor_controller  #
  #######################

  it "has a cursor controller" do
    database = @environment.database.new( $database_name ).cursor_controller
  end

  ############
  #  cursor  #
  ############

  it "can return a cursor from its cursor controller" do
    database = @environment.database.new( $database_name ).cursor
  end

  ###################
  #  object_cursor  #
  ###################

  it "can return an object cursor (which automatically handles serialization) from its cursor controller" do
    database = @environment.database.new( $database_name ).object_cursor
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
      duplicates_database.each_duplicate do |data, duplicate_index|
        data.should_not == nil
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

  #####################
  #  join_controller  #
  #####################

  it "has a join controller" do
    database = @environment.database.new( $database_name ).join_controller
  end

end
