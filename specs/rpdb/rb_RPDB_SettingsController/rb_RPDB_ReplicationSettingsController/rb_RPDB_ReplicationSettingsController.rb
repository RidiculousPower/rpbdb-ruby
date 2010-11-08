require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Replication do

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

  # RPDB::Settings::Replication.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Replication.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Replication.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Replication.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Replication.new
  it "can be created with no argument specified" do
    RPDB::Settings::Replication.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Replication.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Replication.new.parent_settings_controller.should_not == nil
  end

  #########
  #  on?  #
  #########

  it "" do
    Fail
  end

  #############
  #  turn_on  #
  #############

  it "" do
    Fail
  end

  ##########
  #  off?  #
  ##########

  it "" do
    Fail
  end

  ##############
  #  turn_off  #
  ##############

  it "" do
    Fail
  end

  ######################################
  #  client_to_client_synchronization  #
  ######################################

  it "" do
    Fail
  end

  	##############################################
  	#  turn_client_to_client_synchronization_on  #
  	##############################################

    it "" do
      Fail
    end

  	##############################################
  	#  turn_client_to_client_synchronization_on  #
  	##############################################

    it "" do
      Fail
    end

  ##########################
  #  single_bulk_transfer  #
  ##########################

  it "" do
    Fail
  end

  	##################################
  	#  turn_single_bulk_transfer_on  #
  	##################################

    it "" do
      Fail
    end

  	###################################
  	#  turn_single_bulk_transfer_off  #
  	###################################

    it "" do
      Fail
    end

  ########################################
  #  delay_new_sync_until_explicit_call  #
  ########################################

  it "" do
    Fail
  end

  	################################################
  	#  turn_delay_new_sync_until_explicit_call_on  #
  	################################################

    it "" do
      Fail
    end

  	#################################################
  	#  turn_delay_new_sync_until_explicit_call_off  #
  	#################################################

    it "" do
      Fail
    end

  #######################
  #  use_master_leases  #
  #######################

  it "" do
    Fail
  end

  	###############################
  	#  turn_use_master_leases_on  #
  	###############################

    it "" do
      Fail
    end

  	################################
  	#  turn_use_master_leases_off  #
  	################################

    it "" do
      Fail
    end

  ###################################
  #  reinitialize_outdated_clients  #
  ###################################

  it "" do
    Fail
  end

  	###########################################
  	#  turn_reinitialize_outdated_clients_on  #
  	###########################################

    it "" do
      Fail
    end

  	############################################
  	#  turn_reinitialize_outdated_clients_off  #
  	############################################

    it "" do
      Fail
    end

  ####################
  #  prohibit_wait?  #
  ####################

  it "" do
    Fail
  end

  	###########################
  	#  turn_prohibit_wait_on  #
  	###########################

    it "" do
      Fail
    end

  	############################
  	#  turn_prohibit_wait_off  #
  	############################

    it "" do
      Fail
    end

  ##############################
  #  require_strict_majority?  #
  ##############################

  it "" do
    Fail
  end

  	#####################################
  	#  turn_require_strict_majority_on  #
  	#####################################

    it "" do
      Fail
    end

  	######################################
  	#  turn_require_strict_majority_off  #
  	######################################

    it "" do
      Fail
    end

  ################
  #  is_master?  #
  ################

  it "" do
    Fail
  end

  	###################
  	#  set_is_master  #
  	###################

    it "" do
      Fail
    end

  ################
  #  is_client?  #
  ################

  it "" do
    Fail
  end

  	###################
  	#  set_is_client  #
  	###################

    it "" do
      Fail
    end

  #######################################
  #  start_as_client_or_rally_election  #
  #######################################

  it "" do
    Fail
  end

  	###########################################
  	#  set_start_as_client_or_rally_election  #
  	###########################################

    it "" do
      Fail
    end

  ###########
  #  limit  #
  ###########

  it "" do
    Fail
  end

  	###############
  	#  set_limit  #
  	###############

    it "" do
      Fail
    end

  ##########
  #  host  #
  ##########

  it "" do
    Fail
  end

  	##############
  	#  set_host  #
  	##############

    it "" do
      Fail
    end

  ##########
  #  port  #
  ##########

  it "" do
    Fail
  end

  	##############
  	#  set_port  #
  	##############

    it "" do
      Fail
    end

  ################
  #  site_count  #
  ################

  it "" do
    Fail
  end

  	####################
  	#  set_site_count  #
  	####################

    it "" do
      Fail
    end

  ###########################
  #  priority_order_number  #
  ###########################

  it "" do
    Fail
  end

  	###############################
  	#  set_priority_order_number  #
  	###############################

    it "" do
      Fail
    end

  ######################################
  #  retransmission_threshold_minimum  #
  ######################################

  it "" do
    Fail
  end

  	##########################################
  	#  set_retransmission_threshold_minimum  #
  	##########################################

    it "" do
      Fail
    end

  ######################################
  #  retransmission_threshold_maximum  #
  ######################################

  it "" do
    Fail
  end

  	##########################################
  	#  set_retransmission_threshold_maximum  #
  	##########################################

    it "" do
      Fail
    end

  #########################
  #  slowest_clock_value  #
  #########################

  it "" do
    Fail
  end

  	#############################
  	#  set_slowest_clock_value  #
  	#############################

    it "" do
      Fail
    end

  ##############################
  #  fastest_clock_skew_value  #
  ##############################

  it "" do
    Fail
  end

  	##################################
  	#  set_fastest_clock_skew_value  #
  	##################################

    it "" do
      Fail
    end

  ##################################
  #  election_settings_controller  #
  ##################################

  it "" do
    Fail
  end

  #################################
  #  timeout_settings_controller  #
  #################################

  it "" do
    Fail
  end


end

