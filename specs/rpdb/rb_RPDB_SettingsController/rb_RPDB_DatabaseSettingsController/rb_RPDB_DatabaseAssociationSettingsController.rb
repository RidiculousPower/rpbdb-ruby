require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Association do

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

  # RPDB::Settings::Database::Association.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Association.new( @environment ).class.should == RPDB::Settings::Database::Association
  end

  # RPDB::Settings::Database::Association.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Association.new( @environment ).class.should == RPDB::Settings::Database::Association
  end

  # RPDB::Settings::Database::Association.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Association.new( @environment.database_controller.new( $database_name ) ).class.should == RPDB::Settings::Database::Association
  end

  # RPDB::Settings::Database::Association.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Association.new( RPDB::Settings.new ).class.should == RPDB::Settings::Database::Association
  end

  # RPDB::Settings::Database::Association.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Association.new( RPDB::Settings::Database.new ).class.should == RPDB::Settings::Database::Association
  end

  # RPDB::Settings::Database::Association.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Association.new.class.should == RPDB::Settings::Database::Association
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    RPDB::Settings::Database::Association.new.parent_environment.class.should == RPDB::Environment
    # with a database
    RPDB::Settings::Database::Association.new( RPDB::Database.new( $database_name ) ).parent_environment.class.should == RPDB::Environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller - none exists
    RPDB::Settings::Database::Association.new.parent_database.should == nil
    # with a database
    RPDB::Settings::Database::Association.new( RPDB::Database.new( $database_name ) ).parent_database.class.should == RPDB::Database
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Association.new.parent_settings_controller.class.should == RPDB::Settings
    # with a database
    RPDB::Settings::Database::Association.new( RPDB::Database.new( $database_name ) ).parent_settings_controller.class.should == RPDB::Settings
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Association.new.parent_database_settings_controller.class.should == RPDB::Settings::Database
    # with a database
    RPDB::Settings::Database::Association.new( RPDB::Database.new( $database_name ) ).parent_database_settings_controller.class.should == RPDB::Settings::Database
  end

  ##################################################
  #  secondary_association_creates_index?          #
	#  turn_secondary_association_creates_index_on   #
	#  turn_secondary_association_creates_index_off  #
  ##################################################

  it "can automatically create the contents of a secondary index upon initial association" do

    # with a settings controller
    association_settings = RPDB::Settings::Database::Association.new
    association_settings.secondary_association_creates_index?.should == false
    association_settings.turn_secondary_association_creates_index_on
    association_settings.secondary_association_creates_index?.should == true
    association_settings.turn_secondary_association_creates_index_off
    association_settings.secondary_association_creates_index?.should == false

    # with a database
    association_settings = RPDB::Database.new( $database_name ).settings_controller.association_settings_controller
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
    association_settings = RPDB::Settings::Database::Association.new
    association_settings.immutable_secondary_key?.should == false
    association_settings.turn_immutable_secondary_key_on
    association_settings.immutable_secondary_key?.should == true
    association_settings.turn_immutable_secondary_key_off
    association_settings.immutable_secondary_key?.should == false

    # with a database
    association_settings = RPDB::Database.new( $database_name ).settings_controller.association_settings_controller
    association_settings.immutable_secondary_key?.should == false
    association_settings.turn_immutable_secondary_key_on
    association_settings.immutable_secondary_key?.should == true
    association_settings.turn_immutable_secondary_key_off
    association_settings.immutable_secondary_key?.should == false

  end

end

