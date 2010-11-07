require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Transaction do

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

  # RPDB::Environment::Settings::Transaction.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Transaction.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Transaction.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Transaction.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Transaction.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Transaction.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  it "" do
    Fail
  end

  ##############
  #  self.new  #
  ##############

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

  #########
  #  on?  #
  #########

  it "" do
    Fail
  end

  ##########
  #  off?  #
  ##########

  it "" do
    Fail
  end

  	#############
  	#  turn_on  #
  	#############

    it "" do
      Fail
    end

  	##############
  	#  turn_off  #
  	##############

    it "" do
      Fail
    end

  #############################
  #  prohibit_sync_on_write?  #
  #############################

  it "" do
    Fail
  end

  	####################################
  	#  turn_prohibit_sync_on_write_on  #
  	####################################

    it "" do
      Fail
    end

  	#####################################
  	#  turn_prohibit_sync_on_write_off  #
  	#####################################

    it "" do
      Fail
    end

  ##########################################
  #  prohibit_sync_on_commit_transaction?  #
  ##########################################

  it "" do
    Fail
  end

  	#################################################
  	#  turn_prohibit_sync_on_commit_transaction_on  #
  	#################################################

    it "" do
      Fail
    end

  	##################################################
  	#  turn_prohibit_sync_on_commit_transaction_off  #
  	##################################################

    it "" do
      Fail
    end

  ########################################
  #  timeout_returns_deny_not_deadlock?  #
  ########################################

  it "" do
    Fail
  end

  	###############################################
  	#  turn_timeout_returns_deny_not_deadlock_on  #
  	###############################################

    it "" do
      Fail
    end

  	################################################
  	#  turn_timeout_returns_deny_not_deadlock_off  #
  	################################################

    it "" do
      Fail
    end

  ####################################
  #  concurrent_data_store_locking?  #
  ####################################

  it "" do
    Fail
  end

  	###########################################
  	#  turn_concurrent_data_store_locking_on  #
  	###########################################

    it "" do
      Fail
    end

  	############################################
  	#  turn_concurrent_data_store_locking_off  #
  	############################################

    it "" do
      Fail
    end

  #########################
  #  snapshot_isolation?  #
  #########################

  it "" do
    Fail
  end

  	################################
  	#  turn_snapshot_isolation_on  #
  	################################

    it "" do
      Fail
    end

  	#################################
  	#  turn_snapshot_isolation_off  #
  	#################################

    it "" do
      Fail
    end

  ###########################
  #  degree_one_isolation?  #
  ###########################

  it "" do
    Fail
  end

  	##################################
  	#  turn_degree_one_isolation_on  #
  	##################################

    it "" do
      Fail
    end

  	###################################
  	#  turn_degree_one_isolation_off  #
  	###################################

    it "" do
      Fail
    end

  ###########################
  #  degree_two_isolation?  #
  ###########################

  it "" do
    Fail
  end

  	##################################
  	#  turn_degree_two_isolation_on  #
  	##################################

    it "" do
      Fail
    end

  	###################################
  	#  turn_degree_two_isolation_off  #
  	###################################

    it "" do
      Fail
    end

  ##########################################
  #  enclose_all_activity_in_transaction?  #
  ##########################################

  it "" do
    Fail
  end

  	#################################################
  	#  turn_enclose_all_activity_in_transaction_on  #
  	#################################################

    it "" do
      Fail
    end

  	##################################################
  	#  turn_enclose_all_activity_in_transaction_off  #
  	##################################################

    it "" do
      Fail
    end

  #######################################
  #  environmental_snapshot_isolation?  #
  #######################################

  it "" do
    Fail
  end

  	##############################################
  	#  turn_environmental_snapshot_isolation_on  #
  	##############################################

    it "" do
      Fail
    end

  	###############################################
  	#  turn_environmental_snapshot_isolation_off  #
  	###############################################

    it "" do
      Fail
    end

  ####################
  #  sync_on_commit  #
  ####################

  it "" do
    Fail
  end

  	############################
  	#  turn_sync_on_commit_on  #
  	############################

    it "" do
      Fail
    end

  	#############################
  	#  turn_sync_on_commit_off  #
  	#############################

    it "" do
      Fail
    end

  ####################
  #  wait_for_locks  #
  ####################

  it "" do
    Fail
  end

  	############################
  	#  turn_wait_for_locks_on  #
  	############################

    it "" do
      Fail
    end

  	#############################
  	#  turn_wait_for_locks_off  #
  	#############################

    it "" do
      Fail
    end

  ###############################################
  #  maximum_number_of_transactions_to_recover  #
  ###############################################

  it "" do
    Fail
  end

  ###################################################
  #  set_maximum_number_of_transactions_to_recover  #
  ###################################################

  it "" do
    Fail
  end

  #############
  #  timeout  #
  #############

  it "" do
    Fail
  end

  #################
  #  set_timeout  #
  #################

  it "" do
    Fail
  end

  ##############
  #  max_open  #
  ##############

  it "" do
    Fail
  end

  ##################
  #  set_max_open  #
  ##################

  it "" do
    Fail
  end

  ###############
  #  timestamp  #
  ###############

  it "" do
    Fail
  end

  ###################
  #  set_timestamp  #
  ###################

  it "" do
    Fail
  end

  ######################################
  #  set_rollbackward_callback_method  #
  ######################################

  it "" do
    Fail
  end

  ##################################
  #  rollbackward_callback_method  #
  ##################################

  it "" do
    Fail
  end

  #####################################
  #  set_rollforward_callback_method  #
  #####################################

  it "" do
    Fail
  end

  #################################
  #  rollforward_callback_method  #
  #################################

  it "" do
    Fail
  end

  ###############################
  #  set_abort_callback_method  #
  ###############################

  it "" do
    Fail
  end

  ###########################
  #  abort_callback_method  #
  ###########################

  it "" do
    Fail
  end

  ###############################
  #  set_apply_callback_method  #
  ###############################

  it "" do
    Fail
  end

  ###########################
  #  apply_callback_method  #
  ###########################

  it "" do
    Fail
  end

  ###############################
  #  set_print_callback_method  #
  ###############################

  it "" do
    Fail
  end

  ###########################
  #  print_callback_method  #
  ###########################

  it "" do
    Fail
  end

end

