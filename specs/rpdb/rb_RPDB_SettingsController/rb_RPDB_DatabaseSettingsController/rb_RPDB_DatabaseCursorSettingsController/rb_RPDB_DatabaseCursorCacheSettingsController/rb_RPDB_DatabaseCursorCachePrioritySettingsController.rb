require_relative '../../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Cursor::Cache::Priority do

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

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_cursor_controller )
  it "can be created with a database cursor controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller.new( $database_name ).cursor_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller.new( $database_name ).cursor ).should_not == nil
  end


  # RPDB::Settings::Database::Cursor::Cache::Priority.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database cursor settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings::Database::Cursor.new ).should_not == nil
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database cursor cache settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings::Database::Cursor::Cache.new ).should_not == nil
  end
  
  # RPDB::Settings::Database::Cursor::Cache::Priority.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_database_settings_controller.should_not == nil
  end

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  it "can return its parent database cursor settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_database_cursor_settings_controller.should_not == nil
  end

  ######################################################
  #  parent_database_cursor_cache_settings_controller  #
  ######################################################

  it "can return its parent database cursor cache settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_database_cursor_cache_settings_controller.should_not == nil
  end

  ######################
  #  current_priority  #
  ######################

  it "" do
    raise "Failed."
  end

  ###################
	#  set_very_low   #
	#  set_low        #
  #  very_low       #
  #  low            #
	#  set_default    #
  #  default        #
	#  set_high       #
  #  high           #
	#  set_very_high  #
  #  very_high      #
  ###################

  it "" do
    raise "Failed."
  end

  ########################
  #  at_least_very_low   #
  #  at_most_very_low    #
  #  at_least_low        #
  #  at_most_low         #
  #  at_least_default    #
  #  at_most_default     #
  #  at_least_high       #
  #  at_most_high        #
  #  at_least_very_high  #
  #  at_most_very_high   #
  ########################

  it "" do
    raise "Failed."
  end

end

