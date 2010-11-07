require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Record::ReadWrite do

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

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new.should_not == nil
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
  *  parent_database_record_settings_controller  *
  ***********************************************/

  /*************
  *  filename  *
  *************/

  /*****************
  *  set_filename  *
  *****************/

  /***************************
  *  prohibit_sync_on_close  *
  ***************************/

  	/***********************************
  	*  turn_prohibit_sync_on_close_on  *
  	***********************************/

  	/************************************
  	*  turn_prohibit_sync_on_close_off  *
  	************************************/

  /*****************
  *  ignore_lease  *
  *****************/

  	/*************************
  	*  turn_ignore_lease_on  *
  	*************************/

  	/**************************
  	*  turn_ignore_lease_off  *
  	**************************/

  /********************
  *  return_multiple  *
  ********************/

  	/******************************
  	*  turn_return_multiple_on  *
  	******************************/

  	/*****************************
  	*  turn_return_multiple_off  *
  	*****************************/

  /****************************
  *  prohibit_duplicate_data  *
  ****************************/

  	/************************************
  	*  turn_prohibit_duplicate_data_on  *
  	************************************/

  	/*************************************
  	*  turn_prohibit_duplicate_data_off  *
  	*************************************/

  /***********************
  *  prohibit_overwrite  *
  ***********************/

  	/*******************************
  	*  turn_prohibit_overwrite_on  *
  	*******************************/

  	/********************************
  	*  turn_prohibit_overwrite_off  *
  	********************************/

  /*****************************
  *  prohibit_page_compaction  *
  *****************************/

  	/*************************************
  	*  turn_prohibit_page_compaction_on  *
  	*************************************/

  	/**************************************
  	*  turn_prohibit_page_compaction_off  *
  	**************************************/

  /*******************************
  *  return_pages_to_filesystem  *
  *******************************/

  	/***************************************
  	*  turn_return_pages_to_filesystem_on  *
  	***************************************/

  	/****************************************
  	*  turn_return_pages_to_filesystem_off  *
  	****************************************/

  /**************************
  *  truncate_file_on_open  *
  **************************/

  	/**********************************
  	*  turn_truncate_file_on_open_on  *
  	**********************************/

  	/***********************************
  	*  turn_truncate_file_on_open_off  *
  	***********************************/

  /**************************************
  *  write_locks_instead_of_read_locks  *
  **************************************/

  	/**********************************************
  	*  turn_write_locks_instead_of_read_locks_on  *
  	**********************************************/

  	/***********************************************
  	*  turn_write_locks_instead_of_read_locks_off  *
  	***********************************************/

  /*******************
  *  partial_access  *
  *******************/

  	/***************************
  	*  turn_partial_access_on  *
  	***************************/

  	/****************************
  	*  turn_partial_access_off  *
  	****************************/

  /*******************************************
  *  database_allocates_memory_using_malloc  *
  *******************************************/

  	/***************************************************
  	*  turn_database_allocates_memory_using_malloc_on  *
  	***************************************************/

  	/****************************************************
  	*  turn_database_allocates_memory_using_malloc_off  *
  	****************************************************/

  /********************************************
  *  database_allocates_memory_using_realloc  *
  ********************************************/

  	/****************************************************
  	*  turn_database_allocates_memory_using_realloc_on  *
  	****************************************************/

  	/*****************************************************
  	*  turn_database_allocates_memory_using_realloc_off  *
  	*****************************************************/

  /*********************************
  *  application_allocates_memory  *
  *********************************/

  	/*****************************************
  	*  turn_application_allocates_memory_on  *
  	*****************************************/

  	/******************************************
  	*  turn_application_allocates_memory_off  *
  	******************************************/

  /**************************
  *  database_frees_memory  *
  **************************/

  	/**********************************
  	*  turn_database_frees_memory_on  *
  	**********************************/

  	/***********************************
  	*  turn_database_frees_memory_off  *
  	***********************************/

  /*******************************
  *  sync_prior_to_write_return  *
  *******************************/

  	/***************************************
  	*  turn_sync_prior_to_write_return_on  *
  	***************************************/

  	/****************************************
  	*  turn_sync_prior_to_write_return_off  *
  	****************************************/

  /*********************
  *  data_buffer_size  *
  *********************/

  /*************************
  *  set_data_buffer_size  *
  *************************/

  /****************************
  *  partial_read_write_size  *
  ****************************/

  /********************************
  *  set_partial_read_write_size  *
  ********************************/

  /*****************************
  *  partial_read_write_offset  *
  *****************************/

  /**********************************
  *  set_partial_read_write_offset  *
  **********************************/

  /**********************
  *  permit_duplicates  *
  **********************/

  	/*******************************
  	 *  turn_permit_duplicates_on  *
  	 ******************************/

  	/********************************
  	 *  turn_permit_duplicates_off  *
  	 *******************************/

  /********************
  *  sort_duplicates  *
  ********************/

  	/*****************************
  	 *  turn_sort_duplicates_on  *
  	 ****************************/

  	/******************************
  	 *  turn_sort_duplicates_off  *
  	 *****************************/

  /*******************
  *  serialize_data  *
  *******************/

  	/****************************
  	 *  turn_serialize_data_on  *
  	 ***************************/

  	/*****************************
  	 *  turn_serialize_data_off  *
  	 ****************************/

  /*****************
  *  storage_type  *
  *****************/

  /*********************
  *  set_storage_type  *
  *********************/

end

