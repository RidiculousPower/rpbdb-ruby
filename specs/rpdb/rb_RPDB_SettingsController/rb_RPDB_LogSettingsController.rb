require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Lock do

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

  # RPDB::Environment::Settings::Lock.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Lock.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Lock.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Lock.new.should_not == nil
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

  /********
  *  on?  *
  ********/

  	/************
  	*  turn_on  *
  	************/

  /*********
  *  off?  *
  *********/

  	/*************
  	*  turn_off  *
  	*************/

  /**************
  *  buffering  *
  **************/

  	/**********************
  	*  turn_buffering_on  *
  	**********************/

  	/***********************
  	*  turn_buffering_off  *
  	***********************/

  /***********************************
  *  flush_before_return_from_write  *
  ***********************************/

  	/*******************************************
  	*  turn_flush_before_return_from_write_on  *
  	*******************************************/

  	/********************************************
  	*  turn_flush_before_return_from_write_off  *
  	********************************************/

  /********************
  *  autoremove_logs  *
  ********************/

  	/***********************
  	*  turn_autoremove_on  *
  	***********************/

  	/************************
  	*  turn_autoremove_off  *
  	************************/

  /******************
  *  log_in_memory  *
  ******************/

  	/**************************
  	*  turn_log_in_memory_on  *
  	**************************/

  	/***************************
  	*  turn_log_in_memory_off  *
  	***************************/

  /**********************
  *  zero_at_creation?  *
  **********************/

  	/*****************************
  	*  turn_zero_at_creation_on  *
  	*****************************/

  	/******************************
  	*  turn_zero_at_creation_off  *
  	******************************/

  /************************************
  *  force_flush_after_record_write?  *
  ************************************/

  	/*******************************************
  	*  turn_force_flush_after_record_write_on  *
  	*******************************************/

  	/********************************************
  	*  turn_force_flush_after_record_write_off  *
  	********************************************/

  /****************
  *  buffer_size  *
  ****************/

  	/********************
  	*  set_buffer_size  *
  	********************/

  /**************
  *  directory  *
  **************/

  	/******************
  	*  set_directory  *
  	******************/

  /*********
  *  mode  *
  *********/

  	/*************
  	*  set_mode  *
  	*************/

  /*****************
  *  max_log_size  *
  *****************/

  	/*********************
  	*  set_max_log_size  *
  	*********************/

  /********************
  *  max_region_size  *
  ********************/

  	/************************
  	*  set_max_region_size  *
  	************************/

end

