require_relative '../../../../lib/rpdb.rb'

describe RPDB::Database do

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

  # RPDB::Settings::Debug.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Debug.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Debug.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Debug.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Debug.new
  it "can be created with no argument specified" do
    RPDB::Settings::Debug.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Debug.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Debug.new.parent_settings_controller.should_not == nil
  end

  #####################################################
  #  run_normal_recovery_before_opening_environment?  #
  #####################################################

  it "" do
    Fail
  end

  	############################################################
  	#  turn_run_normal_recovery_before_opening_environment_on  #
  	############################################################

    it "" do
      Fail
    end

  	#############################################################
  	#  turn_run_normal_recovery_before_opening_environment_off  #
  	#############################################################

    it "" do
      Fail
    end

  ###########################################################
  #  run_catastrophic_recovery_before_opening_environment?  #
  ###########################################################

  it "" do
    Fail
  end

  	##################################################################
  	#  turn_run_catastrophic_recovery_before_opening_environment_on  #
  	##################################################################

    it "" do
      Fail
    end

  	###################################################################
  	#  turn_run_catastrophic_recovery_before_opening_environment_off  #
  	###################################################################

    it "" do
      Fail
    end

  #######################
  #  open_in_lockdown?  #
  #######################

  it "" do
    Fail
  end

  	##############################
  	#  turn_open_in_lockdown_on  #
  	##############################

    it "" do
      Fail
    end

  	###############################
  	#  turn_open_in_lockdown_off  #
  	###############################

    it "" do
      Fail
    end

  ####################################################
  #  check_for_recovery_before_opening_environment?  #
  ####################################################

  it "" do
    Fail
  end

  	###########################################################
  	#  turn_check_for_recovery_before_opening_environment_on  #
  	###########################################################

    it "" do
      Fail
    end

  	############################################################
  	#  turn_check_for_recovery_before_opening_environment_off  #
  	############################################################

    it "" do
      Fail
    end

  #####################
  #  prohibit_panic?  #
  #####################

  it "" do
    Fail
  end

  	############################
  	#  turn_prohibit_panic_on  #
  	############################

    it "" do
      Fail
    end

  	#############################
  	#  turn_prohibit_panic_off  #
  	#############################

    it "" do
      Fail
    end

  ############
  #  panic?  #
  ############

  it "" do
    Fail
  end

  	###################
  	#  turn_panic_on  #
  	###################

    it "" do
      Fail
    end

  	####################
  	#  turn_panic_off  #
  	####################

    it "" do
      Fail
    end

  ###############################
  #  yield_cpu_for_stress_test  #
  ###############################

  it "" do
    Fail
  end

  	#######################################
  	#  turn_yield_cpu_for_stress_test_on  #
  	#######################################

    it "" do
      Fail
    end

  	########################################
  	#  turn_yield_cpu_for_stress_test_off  #
  	########################################

    it "" do
      Fail
    end

  ###################################
  #  verbosity_settings_controller  #
  ###################################

  it "" do
    Fail
  end

end

