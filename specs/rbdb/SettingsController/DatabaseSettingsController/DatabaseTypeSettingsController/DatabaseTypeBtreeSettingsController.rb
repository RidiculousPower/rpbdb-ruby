require_relative '../../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database::Type::Btree do

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

  # RPbdb::Settings::Database::Type::Btree.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Database::Type::Btree.new( @environment ).is_a?( RPbdb::Settings::Database::Type::Btree ).should == true
  end

  # RPbdb::Settings::Database::Type::Btree.new( database_controller )
  it "can be created with a database controller" do
    RPbdb::Settings::Database::Type::Btree.new( @environment.database_controller ).is_a?( RPbdb::Settings::Database::Type::Btree ).should == true
  end

  # RPbdb::Settings::Database::Type::Btree.new( database )
  it "can be created with a database" do
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Type::Btree ).should == true
  end

  # RPbdb::Settings::Database::Type::Btree.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Settings.new ).is_a?( RPbdb::Settings::Database::Type::Btree ).should == true
  end

  # RPbdb::Settings::Database::Type::Btree.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Settings::Database.new ).is_a?( RPbdb::Settings::Database::Type::Btree ).should == true
  end

  # RPbdb::Settings::Database::Type::Btree.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Database::Type::Btree.new.is_a?( RPbdb::Settings::Database::Type::Btree ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.parent_environment.is_a?( RPbdb::Environment ).should == true
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).parent_environment.is_a?( RPbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.parent_database.should == nil
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).parent_database.is_a?( RPbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.parent_settings_controller.is_a?( RPbdb::Settings ).should == true
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.parent_database_type_settings_controller.is_a?( RPbdb::Settings::Database::Type ).should == true
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).parent_database_type_settings_controller.is_a?( RPbdb::Settings::Database::Type ).should == true
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.database_type.should == RPbdb::Database::Type::Btree
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).database_type.should == RPbdb::Database::Type::Btree
  end

  ##################
  #  is_btree?     #
  ##################

  it "can report whether the type is btree" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.is_btree?.should == true
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).is_btree?.should == true
  end

  #################
  #  is_hash?     #
  #################

  it "can report whether the type is hash" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.is_hash?.should == false
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).is_hash?.should == false
  end

  ##################
  #  is_recno?     #
  ##################

  it "can report whether the type is queue" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.is_recno?.should == false
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).is_recno?.should == false
  end

  ##################
  #  is_queue?     #
  ##################

  it "can report whether the type is recno" do
    # with a settings controller
    RPbdb::Settings::Database::Type::Btree.new.is_queue?.should == false
    # with a database
    RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) ).is_queue?.should == false
  end

  #######################################
  #  record_number_retrieval?           #
	#  turn_record_number_retrieval_on    #
	#  turn_record_number_retrieval_off   #
  #######################################

  it "can be set for record number retrieval (restricted in type from general key retrieval)" do
    # with a settings controller
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new
    test_record_number_retrieval( btree_settings )
    # with a database
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) )
    test_record_number_retrieval( btree_settings )
  end
  
  def test_record_number_retrieval( btree_settings )
    
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
    # with a settings controller
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new
    test_reverse_splitting( btree_settings )
    # with a database
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) )
    test_reverse_splitting( btree_settings )
  end
  
  def test_reverse_splitting( btree_settings )
    
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
    # with a settings controller
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new
    test_minimum_keys_per_page( btree_settings )
    # with a database
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) )
    test_minimum_keys_per_page( btree_settings )
  end
  
  def test_minimum_keys_per_page( btree_settings )
    
    btree_settings.set_minimum_keys_per_page( 42 )
    btree_settings.minimum_keys_per_page.should == 42

  end

  ###############################
  #  set_prefix_compare_method  #
  #  prefix_compare_method      #
  ###############################

  # fix name for callback
  it "can set and return a prefix comparison method" do
    raise "Callback."
    # with a settings controller
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new
    test_prefix_compare_method( btree_settings )
    # with a database
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) )
    test_prefix_compare_method( btree_settings )
  end
  
  def test_prefix_compare_method( btree_settings )
    
  end

  ########################
  #  set_compare_method  #
  #  compare_method      #
  ########################

  # fix name for callback
  it "can set and return a comparison method" do
    raise "Callback."
    # with a settings controller
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new
    test_compare_method( btree_settings )
    # with a database
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) )
    test_compare_method( btree_settings )
  end
  
  def test_compare_method( btree_settings )
    
  end

  ##################################
  #  set_duplicate_compare_method  #
  #  duplicate_compare_method      #
  ##################################

  # fix name for callback
  it "can set and return a duplicate comparison method" do
    raise "Callback."
    # with a settings controller
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new
    test_duplicate_compare_method( btree_settings )
    # with a database
    btree_settings  = RPbdb::Settings::Database::Type::Btree.new( RPbdb::Database.new( $database_name ) )
    test_duplicate_compare_method( btree_settings )
  end
  
  def test_duplicate_compare_method( btree_settings )
    
  end

end

