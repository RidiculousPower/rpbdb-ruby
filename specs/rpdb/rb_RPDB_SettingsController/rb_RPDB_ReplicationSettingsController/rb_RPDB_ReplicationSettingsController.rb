require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Replication do

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

  # RPDB::Environment::Settings::Replication.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Replication.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Replication.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Replication.new.should_not == nil
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

  /*************************************
  *  client_to_client_synchronization  *
  *************************************/

  	/*********************************************
  	*  turn_client_to_client_synchronization_on  *
  	*********************************************/

  	/*********************************************
  	*  turn_client_to_client_synchronization_on  *
  	*********************************************/

  /*************************
  *  single_bulk_transfer  *
  *************************/

  	/*********************************
  	*  turn_single_bulk_transfer_on  *
  	*********************************/

  	/**********************************
  	*  turn_single_bulk_transfer_off  *
  	**********************************/

  /***************************************
  *  delay_new_sync_until_explicit_call  *
  ***************************************/

  	/***********************************************
  	*  turn_delay_new_sync_until_explicit_call_on  *
  	***********************************************/

  	/************************************************
  	*  turn_delay_new_sync_until_explicit_call_off  *
  	************************************************/

  /**********************
  *  use_master_leases  *
  **********************/

  	/******************************
  	*  turn_use_master_leases_on  *
  	******************************/

  	/*******************************
  	*  turn_use_master_leases_off  *
  	*******************************/

  /**********************************
  *  reinitialize_outdated_clients  *
  **********************************/


  	/******************************************
  	*  turn_reinitialize_outdated_clients_on  *
  	******************************************/

  	/*******************************************
  	*  turn_reinitialize_outdated_clients_off  *
  	*******************************************/

  /*******************
  *  prohibit_wait?  *
  *******************/

  	/**************************
  	*  turn_prohibit_wait_on  *
  	**************************/

  	/***************************
  	*  turn_prohibit_wait_off  *
  	***************************/

  /*****************************
  *  require_strict_majority?  *
  *****************************/

  	/************************************
  	*  turn_require_strict_majority_on  *
  	************************************/

  	/*************************************
  	*  turn_require_strict_majority_off  *
  	*************************************/

  /***************
  *  is_master?  *
  ***************/


  	/******************
  	*  set_is_master  *
  	******************/


  /***************
  *  is_client?  *
  ***************/


  	/******************
  	*  set_is_client  *
  	******************/

  /**************************************
  *  start_as_client_or_rally_election  *
  **************************************/

  	/******************************************
  	*  set_start_as_client_or_rally_election  *
  	******************************************/

  /**********
  *  limit  *
  **********/

  	/**************
  	*  set_limit  *
  	**************/

  /*********
  *  host  *
  *********/

  	/*************
  	*  set_host  *
  	*************/

  /*********
  *  port  *
  *********/

  	/*************
  	*  set_port  *
  	*************/

  /***************
  *  site_count  *
  ***************/

  	/*******************
  	*  set_site_count  *
  	*******************/

  /**************************
  *  priority_order_number  *
  **************************/

  	/******************************
  	*  set_priority_order_number  *
  	******************************/

  /*************************************
  *  retransmission_threshold_minimum  *
  *************************************/


  	/*****************************************
  	*  set_retransmission_threshold_minimum  *
  	*****************************************/

  /*************************************
  *  retransmission_threshold_maximum  *
  *************************************/

  	/*****************************************
  	*  set_retransmission_threshold_maximum  *
  	*****************************************/

  /************************
  *  slowest_clock_value  *
  ************************/

  	/****************************
  	*  set_slowest_clock_value  *
  	****************************/

  /*****************************
  *  fastest_clock_skew_value  *
  *****************************/

  	/*********************************
  	*  set_fastest_clock_skew_value  *
  	*********************************/

  /***********************************************
  *  acknowledgement_policy_settings_controller  *
  ***********************************************/

  /********************************
  *  timeout_settings_controller  *
  ********************************/


end

