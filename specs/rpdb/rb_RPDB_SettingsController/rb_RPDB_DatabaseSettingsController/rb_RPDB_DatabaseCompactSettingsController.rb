require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Compact do

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

  # RPDB::Settings::Database::Compact.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Compact.new( @environment ).class.should == RPDB::Settings::Database::Compact
  end

  # RPDB::Settings::Database::Compact.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Compact.new( @environment.database_controller ).class.should == RPDB::Settings::Database::Compact
  end

  # RPDB::Settings::Database::Compact.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Compact.new( @environment.database_controller.new( $database_name ) ).class.should == RPDB::Settings::Database::Compact
  end

  # RPDB::Settings::Database::Compact.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Compact.new( RPDB::Settings.new ).class.should == RPDB::Settings::Database::Compact
  end

  # RPDB::Settings::Database::Compact.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Compact.new( RPDB::Settings::Database.new ).class.should == RPDB::Settings::Database::Compact
  end

  # RPDB::Settings::Database::Compact.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Compact.new.class.should == RPDB::Settings::Database::Compact
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Compact.new.parent_environment.class.should == RPDB::Environment
    RPDB::Settings::Database::Compact.new( RPDB::Database.new( $database_name ) ).parent_environment.class.should == RPDB::Environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Compact.new.parent_database.class.should == RPDB::Database
    RPDB::Settings::Database::Compact.new( RPDB::Database.new( $database_name ) ).parent_database.class.should == RPDB::Database
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Compact.new.parent_settings_controller.class.should == RPDB::Settings
    RPDB::Settings::Database::Compact.new( RPDB::Database.new( $database_name ) ).parent_settings_controller.class.should == RPDB::Settings
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Compact.new.parent_database_settings_controller.class.should == RPDB::Settings::Database
    RPDB::Settings::Database::Compact.new( RPDB::Database.new( $database_name ) ).parent_database_settings_controller.class.should == RPDB::Settings::Database
  end

  ######################
  #  set_fill_percent  #
  #  fill_percent      #
  ######################

  it "can set and report the level at which compaction should occur" do
    compact_settings  = RPDB::Settings::Database::Compact.new
    compact_settings.set_fill_percent = 42
    compact_settings.fill_percent.should == 42
  end

  ##############################
  #  set_max_pages_to_compact  #
  #  max_pages_to_compact      #
  ##############################

  it "can set and report the maximum amount of pages to be compacted at any time" do
    compact_settings  = RPDB::Settings::Database::Compact.new
    compact_settings.set_max_pages_to_compact = 42
    compact_settings.max_pages_to_compact.should == 42
  end

  #################
  #  set_timeout  #
  #  timeout      #
  #################

  it "can set and report compaction timeout" do
    compact_settings  = RPDB::Settings::Database::Compact.new
    compact_settings.set_timeout = 42
    compact_settings.timeout.should == 42
  end

end

