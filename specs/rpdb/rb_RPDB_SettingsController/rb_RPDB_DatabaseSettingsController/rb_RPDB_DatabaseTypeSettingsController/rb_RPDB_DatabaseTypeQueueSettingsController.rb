require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Type::Queue do

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

  # RPDB::Settings::Database::Type::Queue.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Type::Queue.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Queue.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Type::Queue.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Queue.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Type::Queue.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Queue.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Type::Queue.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Queue.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Type::Queue.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Queue.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Type::Queue.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Type::Queue.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Type::Queue.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Type::Queue.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Type::Queue.new.parent_database_settings_controller.should_not == nil
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    RPDB::Settings::Database::Type::Queue.new.parent_database_type_settings_controller.should_not == nil
  end

  #############################################
  #  return_key_data_pairs_in_order?          #
	#  turn_return_key_data_pairs_in_order_on   #
	#  turn_return_key_data_pairs_in_order_off  #
  #############################################

  it "can be set to return key/data pairs in order" do
    raise "Failed."
  end

  #############################################
  #  set_number_of_pages_for_underlying_data  #
  #  number_of_pages_for_underlying_data      #
  #############################################

  it "can set the number of pages used for underlying data" do
    raise "Failed."
  end

end

