require_relative '../../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Cursor::Cache do

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

  # RPDB::Settings::Database::Cursor::Cache.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Cursor::Cache.new( @environment ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Cursor::Cache.new( @environment.database_controller ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ) ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new( database_cursor_controller )
  it "can be created with a database cursor controller" do
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor_controller ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Settings.new ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Settings::Database.new ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new( database_settings_controller )
  it "can be created with a database cursor settings controller" do
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Settings::Database::Cursor.new ).is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Cursor::Cache.new.is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache.new.parent_environment.is_a?( RPDB::Environment ).should == true
    # with a database
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ) ).parent_environment.is_a?( RPDB::Environment ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor ).parent_environment.is_a?( RPDB::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache.new.parent_database.should == nil
    # with a database
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ) ).parent_database.is_a?( RPDB::Database ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor ).parent_database.is_a?( RPDB::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache.new.parent_settings_controller.is_a?( RPDB::Settings ).should == true
    # with a database
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPDB::Settings ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor ).parent_settings_controller.is_a?( RPDB::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache.new.parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
    # with a database
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor ).parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
  end

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  it "can return its parent database cursor settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache.new.parent_database_cursor_settings_controller.is_a?( RPDB::Settings::Database::Cursor ).should == true
    # with a database
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ) ).parent_database_cursor_settings_controller.is_a?( RPDB::Settings::Database::Cursor ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor ).parent_database_cursor_settings_controller.is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  ##################################
  #  priority_settings_controller  #
  ##################################

  it "can return its priority settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache.new.priority_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
    # with a database
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ) ).priority_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache.new( RPDB::Database.new( $database_name ).cursor ).priority_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

end


