require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Type::Btree do

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

  # RPDB::Settings::Database::Type::Btree.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Type::Btree.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Btree.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Type::Btree.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Btree.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Type::Btree.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Btree.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Type::Btree.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Btree.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Type::Btree.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Btree.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Type::Btree.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Type::Btree.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Type::Btree.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Type::Btree.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Type::Btree.new.parent_database_settings_controller.should_not == nil
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    RPDB::Settings::Database::Type::Btree.new.parent_database_type_settings_controller.should_not == nil
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    RPDB::Settings::Database::Type::Btree.new.database_type.should == RPDB::Database::Type::Btree
  end

  ##################
  #  is_btree?     #
  ##################

  it "can report whether the type is btree" do
    RPDB::Settings::Database::Type::Btree.new.is_btree?.should == true
  end

  #################
  #  is_hash?     #
  #################

  it "can report whether the type is hash" do
    RPDB::Settings::Database::Type::Btree.new.is_hash?.should == false
  end

  ##################
  #  is_recno?     #
  ##################

  it "can report whether the type is queue" do
    RPDB::Settings::Database::Type::Btree.new.is_recno?.should == false
  end

  ##################
  #  is_queue?     #
  ##################

  it "can report whether the type is recno" do
    RPDB::Settings::Database::Type::Btree.new.is_queue?.should == false
  end

  #######################################
  #  record_number_retrieval?           #
	#  turn_record_number_retrieval_on    #
	#  turn_record_number_retrieval_off   #
  #######################################

  it "can be set for record number retrieval (restricted in type from general key retrieval)" do
    btree_settings  = RPDB::Settings::Database::Type::Btree.new
    btree_settings.record_number_retrieval?.should == false
    btree_settings.turn_record_number_retrieval_on
    btree_settings.record_number_retrieval?.should == true
    btree_settings.turn_record_number_retrieval_off
    btree_settings.record_number_retrieval?.should == false
  end

  #################################
  #  reverse_splitting?           #
	#  turn_reverse_splitting_on    #
	#  turn_reverse_splitting_off   #
  #################################

  it "can perform reverse splitting of b-tree nodes" do
    btree_settings  = RPDB::Settings::Database::Type::Btree.new
    btree_settings.reverse_splitting?.should == false
    btree_settings.turn_reverse_splitting_on
    btree_settings.reverse_splitting?.should == true
    btree_settings.turn_reverse_splitting_off
    btree_settings.reverse_splitting?.should == false
  end

  ###############################
  #  set_minimum_keys_per_page  #
  #  minimum_keys_per_page      #
  ###############################

  it "can set and return the minimum number of keys per page" do
    btree_settings  = RPDB::Settings::Database::Type::Btree.new
    btree_settings.set_minimum_keys_per_page  = 42
    btree_settings.minimum_keys_per_page.should == 42
  end

  ###############################
  #  set_prefix_compare_method  #
  #  prefix_compare_method      #
  ###############################

  # fix name for callback
  it "can set and return a prefix comparison method" do
    raise "Callback."
  end

  ########################
  #  set_compare_method  #
  #  compare_method      #
  ########################

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

