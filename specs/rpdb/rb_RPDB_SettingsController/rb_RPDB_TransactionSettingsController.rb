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

  ##############
  #  self.new  #
  ##############


  ########################
  #  parent_environment  #
  ########################

  ################################
  #  parent_settings_controller  #
  ################################

  #########
  #  on?  #
  #########


  ##########
  #  off?  #
  ##########


  	#############
  	#  turn_on  #
  	#############


  	##############
  	#  turn_off  #
  	##############

  #############################
  #  prohibit_sync_on_write?  #
  #############################


  	####################################
  	#  turn_prohibit_sync_on_write_on  #
  	####################################


  	#####################################
  	#  turn_prohibit_sync_on_write_off  #
  	#####################################


  ##########################################
  #  prohibit_sync_on_commit_transaction?  #
  ##########################################


  	#################################################
  	#  turn_prohibit_sync_on_commit_transaction_on  #
  	#################################################


  	##################################################
  	#  turn_prohibit_sync_on_commit_transaction_off  #
  	##################################################


  ########################################
  #  timeout_returns_deny_not_deadlock?  #
  ########################################


  	###############################################
  	#  turn_timeout_returns_deny_not_deadlock_on  #
  	###############################################


  	################################################
  	#  turn_timeout_returns_deny_not_deadlock_off  #
  	################################################


  ####################################
  #  concurrent_data_store_locking?  #
  ####################################


  	###########################################
  	#  turn_concurrent_data_store_locking_on  #
  	###########################################

  	############################################
  	#  turn_concurrent_data_store_locking_off  #
  	############################################


  #########################
  #  snapshot_isolation?  #
  #########################


  	################################
  	#  turn_snapshot_isolation_on  #
  	################################


  	#################################
  	#  turn_snapshot_isolation_off  #
  	#################################


  ###########################
  #  degree_one_isolation?  #
  ###########################


  	##################################
  	#  turn_degree_one_isolation_on  #
  	##################################


  	###################################
  	#  turn_degree_one_isolation_off  #
  	###################################


  ###########################
  #  degree_two_isolation?  #
  ###########################


  	##################################
  	#  turn_degree_two_isolation_on  #
  	##################################


  	###################################
  	#  turn_degree_two_isolation_off  #
  	###################################


  ##########################################
  #  enclose_all_activity_in_transaction?  #
  ##########################################

  	#################################################
  	#  turn_enclose_all_activity_in_transaction_on  #
  	#################################################


  	##################################################
  	#  turn_enclose_all_activity_in_transaction_off  #
  	##################################################

  #######################################
  #  environmental_snapshot_isolation?  #
  #######################################


  	##############################################
  	#  turn_environmental_snapshot_isolation_on  #
  	##############################################

  	###############################################
  	#  turn_environmental_snapshot_isolation_off  #
  	###############################################

  ####################
  #  sync_on_commit  #
  ####################

  	############################
  	#  turn_sync_on_commit_on  #
  	############################

  	#############################
  	#  turn_sync_on_commit_off  #
  	#############################

  ####################
  #  wait_for_locks  #
  ####################

  	############################
  	#  turn_wait_for_locks_on  #
  	############################

  	#############################
  	#  turn_wait_for_locks_off  #
  	#############################

  ###############################################
  #  maximum_number_of_transactions_to_recover  #
  ###############################################

  ###################################################
  #  set_maximum_number_of_transactions_to_recover  #
  ###################################################

  #############
  #  timeout  #
  #############

  #################
  #  set_timeout  #
  #################

  ##############
  #  max_open  #
  ##############

  ##################
  #  set_max_open  #
  ##################

  ###############
  #  timestamp  #
  ###############

  ###################
  #  set_timestamp  #
  ###################

  ######################################
  #  set_rollbackward_callback_method  #
  ######################################

  ##################################
  #  rollbackward_callback_method  #
  ##################################

  #####################################
  #  set_rollforward_callback_method  #
  #####################################

  #################################
  #  rollforward_callback_method  #
  #################################

  ###############################
  #  set_abort_callback_method  #
  ###############################

  ###########################
  #  abort_callback_method  #
  ###########################

  ###############################
  #  set_apply_callback_method  #
  ###############################

  ###########################
  #  apply_callback_method  #
  ###########################

  ###############################
  #  set_print_callback_method  #
  ###############################

  ###########################
  #  print_callback_method  #
  ###########################

end

