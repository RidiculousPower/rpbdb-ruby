require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Cache do

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

  # RPDB::Environment::Settings::Database::Cache.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Cache.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cache.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Cache.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cache.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Cache.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cache.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Cache.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cache.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Cache.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cache.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Cache.new.should_not == nil
  end

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

  /**********************
  *  max_size_in_bytes  *
  **********************/

  	/***********************
  	*  max_size_in_kbytes  *
  	***********************/

  	/***********************
  	*  max_size_in_mbytes  *
  	***********************/

  	/***********************
  	*  max_size_in_gbytes  *
  	***********************/

  /**************************
  *  set_max_size_in_bytes  *
  **************************/

  	/***************************
  	*  set_max_size_in_kbytes  *
  	***************************/

  	/***************************
  	*  set_max_size_in_mbytes  *
  	***************************/

  	/***************************
  	*  set_max_size_in_gbytes  *
  	***************************/

  	/***********************************************
  	*  set_max_size_in_gbytes_mbytes_kbytes_bytes  *
  	***********************************************/

  	/****************************************
  	*  set_max_size_in_mbytes_kbytes_bytes  *
  	****************************************/

  	/*********************************
  	*  set_max_size_in_kbytes_bytes  *
  	*********************************/

  /*************************
  *  number_cache_regions  *
  *************************/

  /*****************************
  *  set_number_cache_regions  *
  *****************************/

  /*****************
  *  cache_update  *
  *****************/

  /************************
  *  priority_controller  *
  ************************/

end

