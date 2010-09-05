require_relative '../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  
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
    database = @environment.database.new( $database_name )
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
    database = @environment.database.new( $database_name )
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

  #################
  #  key_exists?  #
  #################

  it "can report whether a key exists" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.key_exists?( "key" ).should == true
  end

  ###########
  #  write  #
  ###########

  it "can write using a string key and a string data item" do
    database = @environment.database.new( $database_name ).open
    database.write( "key", 'some data' )
    database.key_exists?( "key" ).should == true    
  end
  
  it "can write using a hash argument string key => string data" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.key_exists?( "key" ).should == true    
  end

  ##############
  #  retrieve  #
  ##############

  it "can retrieve using a string key" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.retrieve( "key" ).should == 'some data'    
  end

  ############
  #  delete  #
  ############

  it "can delete using a string key" do
    database = @environment.database.new( $database_name ).open
    database.write( "key" => 'some data' )
    database.delete( "key" )
    database.retrieve( "key" ).should == nil        
  end

  #############################################
  #  associate_secondary_database             #
  #  secondary_key_creation_callback_method=  #
  #  secondary_key_creation_callback_method   #
  #  is_secondary_database?                   #
  #  primary_database                         #
  #############################################

  it "can have a secondary database associated with it as an index and report whether it is a secondary database, as well as return its primary database" do
    database_one      = @environment.database.new( $database_name ).open
    database_two  = @environment.database.new( $database_name.to_s + '_index' ).open
    class << database_two
      def callback_method( key, data )
        return 'secondary key: ' + key
      end
    end
    database_two.secondary_key_creation_callback_method = :callback_method
    database_two.secondary_key_creation_callback_method[ :object ].should == database_two
    database_two.secondary_key_creation_callback_method[ :method ].should == :callback_method
    database_one.associate_secondary_database( database_two )
    database_two.is_secondary_database?.should == true
    primary_key = 'primary key'
    database_one.write( primary_key, 'some data' )
    database_two.retrieve( 'secondary key: ' + primary_key ).should == 'some data'
    database_two.primary_database.should == database_one
  end

  ############################
  #  create_secondary_index  #
  ############################

  it "can create a secondary index with a callback method, automatically associating the secondary database with the primary" do
    database      = @environment.database.new( $database_name ).open
    class << database
      def callback_method( key, data )
        return 'secondary key: ' + key
      end
    end
    database_two = database.create_secondary_index( :index,
                                                    :callback_method )
    database_two.secondary_key_creation_callback_method[ :object ].should == database
    database_two.secondary_key_creation_callback_method[ :method ].should == :callback_method
    database_two.is_secondary_database?.should == true    
    primary_key = 'primary key'
    database.write( primary_key, 'some data' )
    database_two.retrieve( 'secondary key: ' + primary_key ).should == 'some data'
  end

  it "can create a secondary index with a block, automatically associating the secondary database with the primary" do
    database      = @environment.database.new( $database_name ).open
    database_two  = database.create_secondary_index( :index ) do |key, data|
      return 'secondary key: ' + key
    end
    primary_key = 'primary key'
    database.write( primary_key, 'some data' )
    database_two.retrieve( 'secondary key: ' + primary_key ).should == 'some data'
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

  #####################
  #  join_controller  #
  #####################

  it "has a join controller" do
    database = @environment.database.new( $database_name ).join_controller
  end

end
