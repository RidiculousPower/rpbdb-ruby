require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Cursor do

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

  # RPDB::Settings::Database::Cursor.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Cursor.new( @environment ).is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  # RPDB::Settings::Database::Cursor.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Cursor.new( @environment.database_controller ).is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  # RPDB::Settings::Database::Cursor.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  # RPDB::Settings::Database::Cursor.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Cursor.new( RPDB::Settings.new ).is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  # RPDB::Settings::Database::Cursor.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Cursor.new( RPDB::Settings::Database.new ).is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  # RPDB::Settings::Database::Cursor.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Cursor.new.is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    RPDB::Settings::Database::Cursor.new.parent_environment.is_a?( RPDB::Environment ).should == true
    # with database
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).parent_environment.is_a?( RPDB::Environment ).should == true
    # with database cursor
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor ).parent_environment.is_a?( RPDB::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    RPDB::Settings::Database::Cursor.new.parent_database.should == nil
    # with database
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).parent_database.is_a?( RPDB::Database ).should == true
    # with database cursor
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor ).parent_database.is_a?( RPDB::Database ).should == true
  end

  ############################
  #  parent_database_cursor  #
  ############################

  it "can return its parent database cursor" do
    # with settings controller
    RPDB::Settings::Database::Cursor.new.parent_database_cursor.should == nil
    # with database
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).parent_database_cursor.should == nil
    # with database cursor
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor ).parent_database_cursor.is_a?( RPDB::Database::Cursor ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    RPDB::Settings::Database::Cursor.new.parent_settings_controller.is_a?( RPDB::Settings ).should == true
    # with database
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPDB::Settings ).should == true
    # with database cursor
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor ).parent_settings_controller.is_a?( RPDB::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    RPDB::Settings::Database::Cursor.new.parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
    # with database
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
    # with database cursor
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor ).parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
  end

  #########################################
  #  duplicate_retains_location?          #
	#  turn_duplicate_retains_location_on   #
	#  turn_duplicate_retains_location_off  #
  #########################################

  it "can retain cursor position when a cursor is duplicated (on by default)" do
      
    # with settings controller
    cursor_settings = RPDB::Settings::Database::Cursor.new
    cursor_settings.duplicate_retains_location?.should == true
    cursor_settings.turn_duplicate_retains_location_off
    cursor_settings.duplicate_retains_location?.should == false
    cursor_settings.turn_duplicate_retains_location_on
    cursor_settings.duplicate_retains_location?.should == true

    # with database
    cursor_settings = RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) )
    cursor_settings.duplicate_retains_location?.should == true
    cursor_settings.turn_duplicate_retains_location_off
    cursor_settings.duplicate_retains_location?.should == false
    cursor_settings.turn_duplicate_retains_location_on
    cursor_settings.duplicate_retains_location?.should == true

    # with database cursor
    cursor_settings = RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor )
    cursor_settings.duplicate_retains_location?.should == true
    cursor_settings.turn_duplicate_retains_location_off
    cursor_settings.duplicate_retains_location?.should == false
    cursor_settings.turn_duplicate_retains_location_on
    cursor_settings.duplicate_retains_location?.should == true
    
  end

  ###############################
  #  cache_settings_controller  #
  ###############################

  it "can return its cache settings controller" do
    # with settings controller
    RPDB::Settings::Database::Cursor.new.cache_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
    # with database
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).cache_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
    # with database cursor
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor ).cache_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  ####################################
  #  read_write_settings_controller  #
  ####################################

  it "can return its read/write settings controller" do
    # with settings controller
    RPDB::Settings::Database::Cursor.new.read_write_settings_controller.is_a?( RPDB::Settings::Database::Cursor::ReadWrite ).should == true
    # with database
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ) ).read_write_settings_controller.is_a?( RPDB::Settings::Database::Cursor::ReadWrite ).should == true
    # with database cursor
    RPDB::Settings::Database::Cursor.new( RPDB::Database.new( $database_name ).cursor ).read_write_settings_controller.is_a?( RPDB::Settings::Database::Cursor::ReadWrite ).should == true
  end

end

