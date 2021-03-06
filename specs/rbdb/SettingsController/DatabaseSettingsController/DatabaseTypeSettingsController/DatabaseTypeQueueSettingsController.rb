require_relative '../../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database::Type::Queue do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
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

  # RPbdb::Settings::Database::Type::Queue.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Database::Type::Queue.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Database::Type::Queue.new( database_controller )
  it "can be created with a database controller" do
    RPbdb::Settings::Database::Type::Queue.new( @environment.database_controller ).should_not == nil
  end

  # RPbdb::Settings::Database::Type::Queue.new( database )
  it "can be created with a database" do
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).should_not == nil
  end

  # RPbdb::Settings::Database::Type::Queue.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Database::Type::Queue.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Settings::Database.new ).should_not == nil
  end

  # RPbdb::Settings::Database::Type::Queue.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Database::Type::Queue.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.parent_environment.should_not == nil
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).parent_database.should_not == nil
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.parent_settings_controller.should_not == nil
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.parent_database_settings_controller.should_not == nil
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).parent_database_settings_controller.should_not == nil
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.parent_database_type_settings_controller.should_not == nil
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).parent_database_type_settings_controller.should_not == nil
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.database_type.should == RPbdb::Database::Type::Queue
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).database_type.should == RPbdb::Database::Type::Queue
  end

  ##################
  #  is_btree?     #
  ##################

  it "can report whether the type is btree" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.is_btree?.should == false
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).is_btree?.should == false
  end

  #################
  #  is_hash?     #
  #################

  it "can report whether the type is hash" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.is_hash?.should == false
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).is_hash?.should == false
  end

  ##################
  #  is_recno?     #
  ##################

  it "can report whether the type is queue" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.is_recno?.should == false
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).is_recno?.should == false
  end

  ##################
  #  is_queue?     #
  ##################

  it "can report whether the type is recno" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Queue.new.is_queue?.should == true
    # with a database
    RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) ).is_queue?.should == true
  end

  #############################################
  #  return_key_data_pairs_in_order?          #
	#  turn_return_key_data_pairs_in_order_on   #
	#  turn_return_key_data_pairs_in_order_off  #
  #############################################

  it "can be set to return key/data pairs in order" do
    # with a settings controller
    queue_settings  = RPbdb::Settings::Database::Type::Queue.new
    # with a database
    queue_settings  = RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) )
  end
  
  def test_return_key_data_pairs_in_order( queue_settings )

    queue_settings.return_key_data_pairs_in_order?.should == false
    queue_settings.turn_return_key_data_pairs_in_order_on
    queue_settings.return_key_data_pairs_in_order?.should == true
    queue_settings.turn_return_key_data_pairs_in_order_off
    queue_settings.return_key_data_pairs_in_order?.should == false
    
  end

  #############################################
  #  set_number_of_pages_for_underlying_data  #
  #  number_of_pages_for_underlying_data      #
  #############################################

  it "can set the number of pages used for underlying data" do
    # with a settings controller
    queue_settings = RPbdb::Settings::Database::Type::Queue.new
    # with a database
    queue_settings = RPbdb::Settings::Database::Type::Queue.new( RPbdb::Database.new( $database_name ) )
  end

  def test_number_of_pages_for_underlying_data( queue_settings )
    
    queue_settings.set_number_of_pages_for_underlying_data( 42 )
    queue_settings.number_of_pages_for_underlying_data.should == 42

  end

end

