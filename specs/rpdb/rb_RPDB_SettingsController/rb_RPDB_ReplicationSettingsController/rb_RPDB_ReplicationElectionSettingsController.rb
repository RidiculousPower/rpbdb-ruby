require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Replication::Election do

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

  # RPDB::Environment::Settings::Replication::Election.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Replication::Election.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Election.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Replication::Election.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Election.new( replication_settings_controller )
  it "can be created with a replication settings controller" do
    RPDB::Environment::Settings::Replication::Election.new( RPDB::Environment::Settings::Replication.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Replication::Election.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Replication::Election.new.should_not == nil
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
  *  parent_replication_settings_controller  *
  *******************************************/

  /******************************************
  *  number_of_sites_required_for_election  *
  ******************************************/

  	/**********************************************
  	*  set_number_of_sites_required_for_election  *
  	**********************************************/

  /******************************************
  *  number_of_votes_required_for_election  *
  ******************************************/

  	/**********************************************
  	*  set_number_of_votes_required_for_election  *
  	**********************************************/

  /*************************
  *  wait_for_all_clients  *
  *************************/

  	/*********************************
  	*  turn_wait_for_all_clients_on  *
  	*********************************/

  	/**********************************
  	*  turn_wait_for_all_clients_off  *
  	**********************************/

  /**********************************
  *  wait_for_all_electable_peers?  *
  **********************************/

  	/*****************************************
  	*  turn_wait_for_all_electable_peers_on  *
  	*****************************************/

  	/******************************************
  	*  turn_wait_for_all_electable_peers_off  *
  	******************************************/

  /******************
  *  wait_for_none  *
  ******************/

  	/**************************
  	*  turn_wait_for_none_on  *
  	**************************/

  	/***************************
  	*  turn_wait_for_none_off  *
  	***************************/

  /**********************************
  *  wait_for_at_least_one_client?  *
  **********************************/


  	/*****************************************
  	*  turn_wait_for_at_least_one_client_on  *
  	*****************************************/


  	/******************************************
  	*  turn_wait_for_at_least_one_client_off  *
  	******************************************/


  /******************************************
  *  wait_for_at_least_one_electable_peer?  *
  ******************************************/


  	/*************************************************
  	*  turn_wait_for_at_least_one_electable_peer_on  *
  	*************************************************/


  	/**************************************************
  	*  turn_wait_for_at_least_one_electable_peer_off  *
  	**************************************************/

  /***********************************************************
  *  wait_for_minimum_electable_peers_for_durable_election?  *
  ***********************************************************/

  	/******************************************************************
  	*  turn_wait_for_minimum_electable_peers_for_durable_election_on  *
  	******************************************************************/

  	/*******************************************************************
  	*  turn_wait_for_minimum_electable_peers_for_durable_election_off  *
  	*******************************************************************/

end

