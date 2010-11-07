require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Cursor::ReadWrite do

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

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_cursor_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ).cursor_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ).cursor ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new.should_not == nil
  end

  /*************
  *  self.new  *
  *************/

  /***************
  *  initialize  *
  ***************/

  /***********************
  *  parent_environment  *
  ***********************/

  /********************
  *  parent_database  *
  ********************/

  /*******************************
  *  parent_settings_controller  *
  *******************************/

  /****************************************
  *  parent_database_settings_controller  *
  ****************************************/

  /***********************************************
  *  parent_database_cursor_settings_controller  *
  ***********************************************/

  /*****************
  *  permit_write  *
  *****************/

  	/********************
  	*  permit_write_on  *
  	********************/

  	/*********************
  	*  permit_write_off  *
  	*********************/

  /*****************
  *  ignore_lease  *
  *****************/

  	/********************
  	*  ignore_lease_on  *
  	********************/

  	/*********************
  	*  ignore_lease_off  *
  	*********************/

  /**************************************
  *  write_locks_instead_of_read_locks  *
  **************************************/

  	/**********************************************
  	*  turn_write_locks_instead_of_read_locks_on  *
  	**********************************************/

  	/***********************************************
  	*  turn_write_locks_instead_of_read_locks_off  *
  	***********************************************/

  /*******************************
  *  return_multiple_data_items  *
  *******************************/

  	/***************************************
  	*  turn_return_multiple_data_items_on  *
  	***************************************/

  	/****************************************
  	*  turn_return_multiple_data_items_off  *
  	****************************************/

  /***********************************
  *  return_multiple_key_data_pairs  *
  ***********************************/

  	/*******************************************
  	*  turn_return_multiple_key_data_pairs_on  *
  	*******************************************/

  	/********************************************
  	*  turn_return_multiple_key_data_pairs_off  *
  	********************************************/


end

