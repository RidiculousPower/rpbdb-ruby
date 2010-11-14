require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Type::Hash do

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

  # RPDB::Settings::Database::Type::Hash.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Type::Hash.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Hash.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Type::Hash.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Hash.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Type::Hash.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Hash.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Type::Hash.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Hash.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Type::Hash.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Hash.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Type::Hash.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Type::Hash.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Type::Hash.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Type::Hash.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Type::Hash.new.parent_database_settings_controller.should_not == nil
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    RPDB::Settings::Database::Type::Hash.new.parent_database_type_settings_controller.should_not == nil
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    RPDB::Settings::Database::Type::Hash.new.database_type.should == RPDB::Database::Type::Hash
  end

  ##################
  #  is_btree?     #
  ##################

  it "can report whether the type is btree" do
    RPDB::Settings::Database::Type::Hash.new.is_btree?.should == false
  end

  #################
  #  is_hash?     #
  #################

  it "can report whether the type is hash" do
    RPDB::Settings::Database::Type::Hash.new.is_hash?.should == true
  end

  ##################
  #  is_recno?     #
  ##################

  it "can report whether the type is queue" do
    RPDB::Settings::Database::Type::Hash.new.is_recno?.should == false
  end

  ##################
  #  is_queue?     #
  ##################

  it "can report whether the type is recno" do
    RPDB::Settings::Database::Type::Hash.new.is_queue?.should == false
  end

  ####################
  #  set_table_size  #
  #  table_size      #
  ####################

  it "can set and return its table size" do
    hash_settings = RPDB::Settings::Database::Type::Hash.new
    hash_settings.set_table_size  = 42
    hash_settings.table_size.should == 42
  end

  #############################
  #  set_hash_density_factor  #
  #  hash_density_factor      #
  #############################

  it "can set and return its hash density factor" do
    hash_settings = RPDB::Settings::Database::Type::Hash.new
    hash_settings.set_hash_density_factor  = 42
    hash_settings.hash_density_factor.should == 42
  end

  #####################
  #  set_hash_method  #
  #  hash_method      #
  #####################

  # fix name for callback
  it "can set and return a method for hashing" do
    raise "Callback."
  end

  #########################
  #  set_compare_method   #
  #  compare_method       #
  #########################

  # fix name for callback
  it "can set and return a comparison method" do
    raise "Callback."
  end

  ##################################
  #  set_duplicate_compare_method  #
  #  duplicate_compare_method      #
  ##################################

  # fix name for callback
  it "can set and return a duplicate comparison method" do
    raise "Callback."
  end

end
