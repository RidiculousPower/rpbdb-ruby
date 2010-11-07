require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::DatabaseController::Database do

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

  # RPDB::Environment::Settings::Debug.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Debug.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Debug.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Debug.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Debug.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Debug.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  ################
  #  initialize  #
  ################

  ########################
  #  parent_environment  #
  ########################

  ################################
  #  parent_settings_controller  #
  ################################

  #####################################################
  #  run_normal_recovery_before_opening_environment?  #
  #####################################################

  	############################################################
  	#  turn_run_normal_recovery_before_opening_environment_on  #
  	############################################################

  	#############################################################
  	#  turn_run_normal_recovery_before_opening_environment_off  #
  	#############################################################

  ###########################################################
  #  run_catastrophic_recovery_before_opening_environment?  #
  ###########################################################

  	##################################################################
  	#  turn_run_catastrophic_recovery_before_opening_environment_on  #
  	##################################################################

  	###################################################################
  	#  turn_run_catastrophic_recovery_before_opening_environment_off  #
  	###################################################################

  #######################
  #  open_in_lockdown?  #
  #######################

  	##############################
  	#  turn_open_in_lockdown_on  #
  	##############################

  	###############################
  	#  turn_open_in_lockdown_off  #
  	###############################

  ####################################################
  #  check_for_recovery_before_opening_environment?  #
  ####################################################

  	###########################################################
  	#  turn_check_for_recovery_before_opening_environment_on  #
  	###########################################################

  	############################################################
  	#  turn_check_for_recovery_before_opening_environment_off  #
  	############################################################

  #####################
  #  prohibit_panic?  #
  #####################

  	############################
  	#  turn_prohibit_panic_on  #
  	############################

  	#############################
  	#  turn_prohibit_panic_off  #
  	#############################

  ############
  #  panic?  #
  ############

  	###################
  	#  turn_panic_on  #
  	###################

  	####################
  	#  turn_panic_off  #
  	####################

  ###############################
  #  yield_cpu_for_stress_test  #
  ###############################

  	#######################################
  	#  turn_yield_cpu_for_stress_test_on  #
  	#######################################

  	########################################
  	#  turn_yield_cpu_for_stress_test_off  #
  	########################################

  ###################################
  #  verbosity_settings_controller  #
  ###################################

end

