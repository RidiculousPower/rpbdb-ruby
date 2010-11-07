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

  ##############
  #  self.new  #
  ##############

  it "" do
    Fail
  end

  ################
  #  initialize  #
  ################

  it "" do
    Fail
  end

  ########################
  #  parent_environment  #
  ########################

  it "" do
    Fail
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "" do
    Fail
  end

  ############################################
  #  parent_replication_settings_controller  #
  ############################################

  it "" do
    Fail
  end

  ###########################################
  #  number_of_sites_required_for_election  #
  ###########################################

  it "" do
    Fail
  end

  	###############################################
  	#  set_number_of_sites_required_for_election  #
  	###############################################

    it "" do
      Fail
    end

  ###########################################
  #  number_of_votes_required_for_election  #
  ###########################################

  it "" do
    Fail
  end

  	###############################################
  	#  set_number_of_votes_required_for_election  #
  	###############################################

    it "" do
      Fail
    end

  ##########################
  #  wait_for_all_clients  #
  ##########################

  it "" do
    Fail
  end

  	##################################
  	#  turn_wait_for_all_clients_on  #
  	##################################

    it "" do
      Fail
    end

  	###################################
  	#  turn_wait_for_all_clients_off  #
  	###################################

    it "" do
      Fail
    end

  ###################################
  #  wait_for_all_electable_peers?  #
  ###################################

  it "" do
    Fail
  end

  	##########################################
  	#  turn_wait_for_all_electable_peers_on  #
  	##########################################

    it "" do
      Fail
    end

  	###########################################
  	#  turn_wait_for_all_electable_peers_off  #
  	###########################################

    it "" do
      Fail
    end

  ###################
  #  wait_for_none  #
  ###################

  it "" do
    Fail
  end

  	###########################
  	#  turn_wait_for_none_on  #
  	###########################

    it "" do
      Fail
    end

  	############################
  	#  turn_wait_for_none_off  #
  	############################

    it "" do
      Fail
    end

  ###################################
  #  wait_for_at_least_one_client?  #
  ###################################

  it "" do
    Fail
  end

  	##########################################
  	#  turn_wait_for_at_least_one_client_on  #
  	##########################################

    it "" do
      Fail
    end

  	###########################################
  	#  turn_wait_for_at_least_one_client_off  #
  	###########################################

    it "" do
      Fail
    end

  ###########################################
  #  wait_for_at_least_one_electable_peer?  #
  ###########################################

  it "" do
    Fail
  end

  	##################################################
  	#  turn_wait_for_at_least_one_electable_peer_on  #
  	##################################################

    it "" do
      Fail
    end

  	###################################################
  	#  turn_wait_for_at_least_one_electable_peer_off  #
  	###################################################

    it "" do
      Fail
    end

  ############################################################
  #  wait_for_minimum_electable_peers_for_durable_election?  #
  ############################################################

  it "" do
    Fail
  end

  	###################################################################
  	#  turn_wait_for_minimum_electable_peers_for_durable_election_on  #
  	###################################################################

    it "" do
      Fail
    end

  	####################################################################
  	#  turn_wait_for_minimum_electable_peers_for_durable_election_off  #
  	####################################################################

    it "" do
      Fail
    end

end

