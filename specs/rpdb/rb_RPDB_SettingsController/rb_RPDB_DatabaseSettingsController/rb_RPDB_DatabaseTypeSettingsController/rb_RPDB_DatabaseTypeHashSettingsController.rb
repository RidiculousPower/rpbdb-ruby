require_relative '../../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Type::Hash do

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

  # Rbdb::Settings::Database::Type::Hash.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Type::Hash.new( @environment ).is_a?( Rbdb::Settings::Database::Type::Hash ).should == true
  end

  # Rbdb::Settings::Database::Type::Hash.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Type::Hash.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Type::Hash ).should == true
  end

  # Rbdb::Settings::Database::Type::Hash.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Type::Hash ).should == true
  end

  # Rbdb::Settings::Database::Type::Hash.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Type::Hash ).should == true
  end

  # Rbdb::Settings::Database::Type::Hash.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Type::Hash ).should == true
  end

  # Rbdb::Settings::Database::Type::Hash.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Type::Hash.new.is_a?( Rbdb::Settings::Database::Type::Hash ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.parent_database.should == nil
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.parent_database_type_settings_controller.is_a?( Rbdb::Settings::Database::Type ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).parent_database_type_settings_controller.is_a?( Rbdb::Settings::Database::Type ).should == true
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.database_type.should == Rbdb::Database::Type::Hash
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).database_type.should == Rbdb::Database::Type::Hash
  end

  ##################
  #  is_btree?     #
  ##################

  it "can report whether the type is btree" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.is_btree?.should == false
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).is_btree?.should == false
  end

  #################
  #  is_hash?     #
  #################

  it "can report whether the type is hash" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.is_hash?.should == true
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).is_hash?.should == true
  end

  ##################
  #  is_recno?     #
  ##################

  it "can report whether the type is queue" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.is_recno?.should == false
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).is_recno?.should == false
  end

  ##################
  #  is_queue?     #
  ##################

  it "can report whether the type is recno" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Hash.new.is_queue?.should == false
    # with a database
    Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) ).is_queue?.should == false
  end

  ####################
  #  set_table_size  #
  #  table_size      #
  ####################

  it "can set and return its table size" do
    # with a settings controller
    hash_settings = Rbdb::Settings::Database::Type::Hash.new
    test_table_size( hash_settings )
    # with a database
    hash_settings = Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) )
    test_table_size( hash_settings )
  end

  def test_table_size( hash_settings )
    
    hash_settings.set_table_size( 42 )
    hash_settings.table_size.should == 42

  end

  #############################
  #  set_hash_density_factor  #
  #  hash_density_factor      #
  #############################

  it "can set and return its hash density factor" do
    # with a settings controller
    hash_settings = Rbdb::Settings::Database::Type::Hash.new
    test_hash_density_factor( hash_settings )
    # with a database
    hash_settings = Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) )
    test_hash_density_factor( hash_settings )
  end

  def test_hash_density_factor( hash_settings )
    
    hash_settings.set_hash_density_factor( 42 )
    hash_settings.hash_density_factor.should == 42

  end

  #####################
  #  set_hash_method  #
  #  hash_method      #
  #####################

  # fix name for callback
  it "can set and return a method for hashing" do
    raise "Callback."
    # with a settings controller
    hash_settings = Rbdb::Settings::Database::Type::Hash.new
    test_hash_method( hash_settings )
    # with a database
    hash_settings = Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) )
    test_hash_method( hash_settings )
  end

  def test_hash_method( hash_settings )
    
  end

  #########################
  #  set_compare_method   #
  #  compare_method       #
  #########################

  # fix name for callback
  it "can set and return a comparison method" do
    raise "Callback."
    # with a settings controller
    hash_settings = Rbdb::Settings::Database::Type::Hash.new
    test_compare_method( hash_settings )
    # with a database
    hash_settings = Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) )
    test_compare_method( hash_settings )
  end

  def test_compare_method( hash_settings )
    
  end

  ##################################
  #  set_duplicate_compare_method  #
  #  duplicate_compare_method      #
  ##################################

  # fix name for callback
  it "can set and return a duplicate comparison method" do
    raise "Callback."
    # with a settings controller
    hash_settings = Rbdb::Settings::Database::Type::Hash.new
    test_duplicate_compare_method( hash_settings )
    # with a database
    hash_settings = Rbdb::Settings::Database::Type::Hash.new( Rbdb::Database.new( $database_name ) )
    test_duplicate_compare_method( hash_settings )
  end

  def test_duplicate_compare_method( hash_settings )
    
  end

end
