require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::MemoryPool::File::Page do

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

  # RPDB::Environment::Settings::MemoryPool::File::Page.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::MemoryPool::File::Page.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Page.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::MemoryPool::File::Page.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Page.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Environment::Settings::MemoryPool::File::Page.new( RPDB::Environment::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Page.new( memory_pool_settings_controller )
  it "can be created with a memory pool file settings controller" do
    RPDB::Environment::Settings::MemoryPool::File::Page.new( RPDB::Environment::Settings::MemoryPool::File.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Page.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::MemoryPool::File::Page.new.should_not == nil
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

  /*******************************
  *  parent_settings_controller  *
  *******************************/

  /*******************************************
  *  parent_memory_pool_settings_controller  *
  *******************************************/

  /************************************************
  *  parent_memory_pool_file_settings_controller  *
  ************************************************/

  /********************************************
  *  get_page_creates_page_if_does_not_exist  *
  ********************************************/

  	/****************************************************
  	*  turn_get_page_creates_page_if_does_not_exist_on  *
  	****************************************************/

  	/*****************************************************
  	*  turn_get_page_creates_page_if_does_not_exist_off  *
  	*****************************************************/

  /*****************************************
  *  get_page_writes_copy_before_eviction  *
  *****************************************/

  	/*************************************************
  	*  turn_get_page_writes_copy_before_eviction_on  *
  	*************************************************/

  	/**************************************************
  	*  turn_get_page_writes_copy_before_eviction_off  *
  	**************************************************/

  /*************************************************
  *  get_page_writes_before_eviction_without_copy  *
  *************************************************/

  	/*********************************************************
  	*  turn_get_page_writes_before_eviction_without_copy_on  *
  	*********************************************************/

  	/**********************************************************
  	*  turn_get_page_writes_before_eviction_without_copy_off  *
  	**********************************************************/

  /*******************************
  *  get_page_returns_last_page  *
  *******************************/

  	/***************************************
  	*  turn_get_page_returns_last_page_on  *
  	***************************************/

  	/****************************************
  	*  turn_get_page_returns_last_page_off  *
  	****************************************/

  /******************************
  *  get_page_creates_new_page  *
  ******************************/

  	/**************************************
  	*  turn_get_page_creates_new_page_on  *
  	**************************************/

  	/***************************************
  	*  turn_get_page_creates_new_page_off  *
  	***************************************/

end

