require_relative '../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database::Association do

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

  # RPbdb::Settings::Database::Association.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Database::Association.new( @environment ).is_a?( RPbdb::Settings::Database::Association ).should == true
  end

  # RPbdb::Settings::Database::Association.new( database_controller )
  it "can be created with a database controller" do
    RPbdb::Settings::Database::Association.new( @environment ).is_a?( RPbdb::Settings::Database::Association ).should == true
  end

  # RPbdb::Settings::Database::Association.new( database )
  it "can be created with a database" do
    RPbdb::Settings::Database::Association.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Association ).should == true
  end

  # RPbdb::Settings::Database::Association.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Database::Association.new( RPbdb::Settings.new ).is_a?( RPbdb::Settings::Database::Association ).should == true
  end

  # RPbdb::Settings::Database::Association.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPbdb::Settings::Database::Association.new( RPbdb::Settings::Database.new ).is_a?( RPbdb::Settings::Database::Association ).should == true
  end

  # RPbdb::Settings::Database::Association.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Database::Association.new.is_a?( RPbdb::Settings::Database::Association ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    RPbdb::Settings::Database::Association.new.parent_environment.is_a?( RPbdb::Environment ).should == true
    # with a database
    RPbdb::Settings::Database::Association.new( RPbdb::Database.new( $database_name ) ).parent_environment.is_a?( RPbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller - none exists
    RPbdb::Settings::Database::Association.new.parent_database.should == nil
    # with a database
    RPbdb::Settings::Database::Association.new( RPbdb::Database.new( $database_name ) ).parent_database.is_a?( RPbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Association.new.parent_settings_controller.is_a?( RPbdb::Settings ).should == true
    # with a database
    RPbdb::Settings::Database::Association.new( RPbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    RPbdb::Settings::Database::Association.new.parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
    # with a database
    RPbdb::Settings::Database::Association.new( RPbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
  end

  ##################################################
  #  secondary_association_creates_index?          #
	#  turn_secondary_association_creates_index_on   #
	#  turn_secondary_association_creates_index_off  #
  ##################################################

  it "can automatically create the contents of a secondary index upon initial association" do
    # with a settings controller
    association_settings = RPbdb::Settings::Database::Association.new
    test_secondary_association_creates_index( association_settings )
    # with a database
    association_settings = RPbdb::Database.new( $database_name ).settings_controller.association_settings_controller
    test_secondary_association_creates_index( association_settings )
  end

  def test_secondary_association_creates_index( association_settings )

    association_settings.secondary_association_creates_index?.should == false
    association_settings.turn_secondary_association_creates_index_on
    association_settings.secondary_association_creates_index?.should == true
    association_settings.turn_secondary_association_creates_index_off
    association_settings.secondary_association_creates_index?.should == false
    
  end

  ######################################
  #  immutable_secondary_key?          #
	#  turn_immutable_secondary_key_on   #
	#  turn_immutable_secondary_key_off  #
  ######################################

  it "can specify that it has an immutable secondary key (which permits internal optimizations)" do
    # with a settings controller
    association_settings = RPbdb::Settings::Database::Association.new
    test_immutable_secondary_key( association_settings )
    # with a database
    association_settings = RPbdb::Database.new( $database_name ).settings_controller.association_settings_controller
    test_immutable_secondary_key( association_settings )
  end

  def test_immutable_secondary_key( association_settings )

    association_settings.immutable_secondary_key?.should == false
    association_settings.turn_immutable_secondary_key_on
    association_settings.immutable_secondary_key?.should == true
    association_settings.turn_immutable_secondary_key_off
    association_settings.immutable_secondary_key?.should == false
    
  end

end

