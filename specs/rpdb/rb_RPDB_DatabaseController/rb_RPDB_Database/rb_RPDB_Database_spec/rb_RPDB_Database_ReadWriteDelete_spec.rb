require_relative '../../../../../lib/rbdb/rbdb'

describe Rbdb::Database do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $unsorted_duplicates_database_name   = :unsorted_duplicates_db
  $sorted_duplicates_database_name   = :sorted_duplicates_db
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller
  end

  after( :each ) do
    @environment.close
  end

  require_relative './rb_Rbdb_Database_SecondarySupportFunctions.rb'
  
  ###########
  #  write  #
  ###########

  # write( primary_key, data )
  it "can write using a string key and a string data item" do
    database = @environment.database.new( $database_name )

    database.write( "key", 'some data' )
    database.key_exists?( "key" ).should == true    
    database.empty!
  end

  # write( primary_key, [ data, ... ] )
  it "can write multiple duplicate keys for a single primary key" do
    duplicates_database = @environment.database.new( $sorted_duplicates_database_name )

    duplicates_database.set_to.read_write.turn_sorted_duplicates_on
    duplicates_database.write( "key", [ 'some data', 'other data' ] )
    duplicates_database.empty!
  end
  
  # write( primary_key => data, ... )
  it "can write using a hash argument string key => string data" do
    database = @environment.database.new( $database_name )

    database.write( "key" => 'some data' )
    database.key_exists?( "key" ).should == true    
    database.empty!
    database.write( "key"         => 'some data',
                    "another key" => 'other data' )
    database.key_exists?( "key" ).should == true    
    database.key_exists?( "another key" ).should == true    
    database.empty!
  end

  # write( primary_key => [ data, ... ] )
  it "can write multiple primary key values" do
    duplicates_database = @environment.database.new( $sorted_duplicates_database_name )

    duplicates_database.set_to.read_write.turn_sorted_duplicates_on
    duplicates_database.write( "key" => [ 'some data', 'other data' ] )
    duplicates_database.empty!
  end

  # write( [ any_arg_form ], ... )
  it "can use arrays to group writes of any of these argument forms" do
    duplicates_database = @environment.database.new( $unsorted_duplicates_database_name )

    duplicates_database.set_to.read_write.turn_unsorted_duplicates_on
    duplicates_database.write( [ { "another key" => 'more data' } ], [ { "key" => [ 'some data', 'other data' ] } ] )    
    duplicates_database.key_exists?( "another key" ).should == true
    duplicates_database.key_exists?( "key" ).should == true
    duplicates_database.retrieve( 'key' ).should == 'some data'
    duplicates_database.empty!
  end  

  #################
  #  key_exists?  #
  #################

  # key_exists?( primary_key, ... )
  it "can report whether a key exists" do
    database = @environment.database.new( $database_name )

    database.write( "key" => 'some data' )
    database.key_exists?( "key" ).should == true
    database.empty!
  end

  # key_exists?( :index, secondary_key, ... )
  it "can report whether a secondary key exists" do
    database = @environment.database.new( $database_name )
    callback_lambda  = key_from_data__lambda
    database_two = database.create_secondary_index( :index, & callback_lambda )

    database.write( "key" => 'some data' )
    database.key_exists?( :index, "some data" ).should == true
    database.empty!
  end
  
  # key_exists?( :index => secondary_key, ... )
  it "can report whether a secondary key exists specified with a hash" do
    database = @environment.database.new( $database_name )
    callback_lambda  = key_from_data__lambda
    database_two = database.create_secondary_index( :index, & callback_lambda )

    database.write( "key" => 'some data' )
    database.key_exists?( :index => "some data" ).should == { :index => true }
    database.empty!
  end
  
  # key_exists?( :index => [ secondary_key, ... ] )
  it "can report whether multiple secondary keys exist" do

    duplicates_database = @environment.database.new( $sorted_duplicates_database_name )

    duplicates_database.set_to.read_write.turn_sorted_duplicates_on
    duplicates_database.write( "key" => [ 'some data', 'other data' ] )
    duplicates_database.write( "another key" => [ 'some data', 'other data' ] )
    duplicates_database.key_exists?( 'key' ).should == true
    duplicates_database.key_exists?( 'another key' ).should == true
    duplicates_database.key_exists?( [ 'key', 'another key' ] ).should == [ true, true ]
    duplicates_database.empty!
  end

  # key_exists?( [ any_arg_form ], ... )
  it "can use arrays to group sets these argument forms" do
    database = @environment.database.new( $database_name )
    callback_lambda  = key_from_data__lambda
    database_two = database.create_secondary_index( :index, & callback_lambda )

    database.write( "key" => 'some data' )
    database.key_exists?( [ :index => "some data" ], [ :index, "some data"  ] ).should == [ { :index => true }, true ]
    database.empty!
  end

  #################
  #  keys_exist?  #
  #################

  # keys_exist?( primary key, ... )
  it "can report whether multiple keys exists" do
    database = @environment.database.new( $database_name )

    database.write(   "key"         => 'some data', 
                      "another key" => 'other data' )
    database.keys_exist?( "key", "another key" ).should == true
    database.empty!
  end

  # keys_exist?( :index, secondary_key, ... )
  it "can report whether multiple secondary keys exist in multiple indexes" do
    database = @environment.database.new( $database_name )

    database.create_secondary( :value ) do |key, value|
      return value
    end
    database.write(   "key"         => 'some data', 
                      "another key" => 'other data' )
    database.key_exists?( :value, 'some data' ).should == true
    database.key_exists?( :value, 'other data' ).should == true
    database.keys_exist?( :value, 'some data', 'other data' ).should == true
    database.empty!
  end

  # keys_exist?( :index, [ secondary_key, ... ], ... )
  it "can report whether multiple secondary keys exists specified in an array" do
    database = @environment.database.new( $database_name )

    database.create_secondary( :value ) do |key, value|
      return value
    end
    database.write(   "key"         => 'some data', 
                      "another key" => 'other data' )
    database.keys_exist?( :value, [ 'some data', 'other data' ] ).should == [ true ]
    database.empty!
  end  
  
  # keys_exist?( :index => secondary_key, ... )
  it "can report whether multiple secondary keys exists in multiple indexes specified with a hash" do
    database = @environment.database.new( $database_name )

    database.create_secondary( :value ) do |key, value|
      return value
    end
    database.create_secondary( :first_key_letter ) do |key, value|
      return key.chars.first
    end
    database.write(   "key"         => 'some data', 
                      "another key" => 'other data' )
    database.keys_exist?( :value            => 'some data', 
                          :first_key_letter => 'k' ).should == { :value => true, :first_key_letter => true }
    database.empty!
  end
  
  # keys_exist?( :index => [ secondary_key, ... ], ... )
  it "can report whether multiple secondary keys exist for one or more indexes specified with a hash" do
    database = @environment.database.new( $database_name )

    database.create_secondary( :value ) do |key, value|
      return value
    end
    database.write(   "key"         => 'some data', 
                      "another key" => 'other data' )
    database.keys_exist?( :value => [ 'some data', 'other data' ] ).should == { :value => [ true ] }
    database.empty!
  end

  # keys_exist?( [ any_arg_form ], ... )
  it "can use arrays to group sets these argument forms" do
    database = @environment.database.new( $database_name )

    database.create_secondary( :value ) do |key, value|
      return value
    end
    database.write(   "key"           => 'some data', 
                      "another key"   => 'other data',
                      "one more key"  => 'yet more data' )
    database.keys_exist?( [ { :value => [ 'some data', 'other data' ] } ], [ 'one more key' ] ).should == [ { :value => [ true ] }, true ]
    database.empty!
  end

  ##############
  #  retrieve  #
  ##############

  # retrieve( primary_key, ... )
  it "can retrieve using a primary key" do
    database = @environment.database.new( $database_name )
    database.write( "key" => 'some data' )
    database.retrieve( "key" ).should == 'some data'    
    database.empty!
  end

  # retrieve( :index, secondary_key, ... )
  it "can retrieve using an index specifying a secondary database and a secondary key" do
    database = @environment.database.new( $database_name )

    database.empty!
    database.create_secondary( :value ) do |key, value|
      return value
    end
    secondary_database = database.index( :value )
    database.write( 'key' => 'value' )
    database.retrieve( 'key' ).should == 'value'
    database.retrieve( :value => 'value' ).should == 'value'
    database.empty!
  end
  
  # retrieve( :index => secondary_key, ... )
  it "can retrieve using an index specifying a secondary database and an array with multiple secondary keys" do
    database = @environment.database.new( $database_name )

    database.empty!
    database.create_secondary( :value ) do |key, value|
      return value
    end
    secondary_database = database.index( :value )
    database.write( 'key' => 'value' )
    database.retrieve( :value => 'value' ).should == 'value'
    database.empty!
  end
  
  # retrieve( :index, [ secondary_key, ... ] )
  it "can retrieve using a hash with keys specifying secondary indexes keys or array with multiple secondary keys" do
    database = @environment.database.new( $database_name )

    database.empty!
    database.create_secondary( :value ) do |key, value|
      return value
    end
    secondary_database = database.index( :value )
    database.write( 'key'           => 'value',
                    'another key'   => 'another value' )
    database.retrieve( 'key' ).should == 'value'
    database.retrieve( 'another key' ).should == 'another value'
    database.retrieve( :value, [ 'value', 'another value' ] ).should == [ 'value', 'another value' ]
    database.empty!
  end

  # retrieve( :index => [ secondary_key, ... ] )
  it "can retrieve using a hash with keys specifying secondary indexes keys or array with multiple secondary keys" do
    database = @environment.database.new( $database_name )

    database.empty!
    database.create_secondary( :value ) do |key, value|
      return value
    end
    secondary_database = database.index( :value )
    database.write( 'key'           => 'value',
                    'another key'   => 'another value' )
    database.retrieve( 'key' ).should == 'value'
    database.retrieve( 'another key' ).should == 'another value'
    database.retrieve( :value => [ 'value', 'another value' ] ).should == [ 'value', 'another value' ]
    database.empty!
  end

  # retrieve( [ any_arg_form ], ... )
  it "can use arrays to group sets these argument forms" do
    database = @environment.database.new( $database_name )

    database.empty!
    database.create_secondary( :value ) do |key, value|
      return value
    end
    secondary_database = database.index( :value )
    database.write( 'key' => 'value' )
    database.retrieve( [ :value => 'value' ], [ 'key' ] ).should == [ 'value', 'value' ]
    database.empty!
  end
  
  ############
  #  delete  #
  ############

  # delete( primary_key, ... )
  it "can delete a record by primary key" do
    database = @environment.database.new( $database_name )

    database.write( "key" => 'some data' )
    database.delete( "key" )
    database.retrieve( "key" ).should == nil        
  end
  
  # delete( :index, secondary_key, ... )
  it "can delete a record by secondary key" do
    database = @environment.database.new( $database_name )

    database.create_secondary_index( :value ) do |key, value|
      return value
    end
    database.write( "key" => 'some data' )
    database.delete( :value => 'some data' )
    database.retrieve( "key" ).should == nil
  end

  # delete( :index, [ secondary_key, ...], ... )
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
  
  # delete( :index => secondary_key, ... )
  it "can delete a record by secondary key specified by a hash" do
    database = @environment.database.new( $database_name )

    database.create_secondary_index( :value ) do |key, value|
      return value
    end
    database.write( "key" => 'some data' )
    database.delete( :value => 'some data' )
    database.retrieve( "key" ).should == nil    
  end

  # delete( :index => [ secondary_key, ... ], ... )
  it "can delete records in a hash index corresponding to multiple secondary keys in an array" do
    database = @environment.database.new( $database_name )

    database.create_secondary_index( :value ) do |key, value|
      return value
    end
    database.write( "key"         => 'some data',
                    "another key" => 'other data' )
    database.delete( :value => [ 'some data', 'other data' ] )
    database.retrieve( "key" ).should == nil    
  end
  
  # delete( [ any_arg_form ], ... )
  it "can use arrays to group sets these argument forms" do
    database = @environment.database.new( $database_name )

    database.create_secondary_index( :value ) do |key, value|
      return value
    end
    database.write( "key"         => 'some data',
                    "another key" => 'other data' )
    database.delete( [ :value, 'some data' ], [ "another key" ] )
    database.retrieve( "key" ).should == nil
  end

end

