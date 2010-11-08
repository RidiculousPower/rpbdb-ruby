require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Lock do

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

  # RPDB::Settings::Lock.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Lock.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Lock.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Lock.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Lock.new
  it "can be created with no argument specified" do
    RPDB::Settings::Lock.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Lock.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Lock.new.parent_settings_controller.should_not == nil
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

  #######################
  #  prohibit_locking?  #
  #######################

  it "" do
    Fail
  end

  	##############################
  	#  turn_prohibit_locking_on  #
  	##############################

    it "" do
      Fail
    end

  	###############################
  	#  turn_prohibit_locking_off  #
  	###############################

    it "" do
      Fail
    end

  ##############################################
  #  timeout_returns_return_deny_not_deadlock  #
  ##############################################

  it "" do
    Fail
  end

  	######################################################
  	#  turn_timeout_returns_return_deny_not_deadlock_on  #
  	######################################################

    it "" do
      Fail
    end

  	#######################################################
  	#  turn_timeout_returns_return_deny_not_deadlock_off  #
  	#######################################################

    it "" do
      Fail
    end

  ###########
  #  wait?  #
  ###########

  it "" do
    Fail
  end

  	##################
  	#  turn_wait_on  #
  	##################

    it "" do
      Fail
    end

  	###################
  	#  turn_wait_off  #
  	###################

    it "" do
      Fail
    end

  ########################################
  #  lock_for_environment_not_database?  #
  ########################################

  it "" do
    Fail
  end

  	###############################################
  	#  turn_lock_for_environment_not_database_on  #
  	###############################################

    it "" do
      Fail
    end

  	################################################
  	#  turn_lock_for_environment_not_database_off  #
  	################################################

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

  #####################
  #  conflict_matrix  #
  #####################

  it "" do
    Fail
  end

  	#########################
  	#  set_conflict_matrix  #
  	#########################

    it "" do
      Fail
    end

  #################
  #  max_lockers  #
  #################

  it "" do
    Fail
  end

  	#####################
  	#  set_max_lockers  #
  	#####################

    it "" do
      Fail
    end

  ###############
  #  max_locks  #
  ###############

  it "" do
    Fail
  end

  	###################
  	#  set_max_locks  #
  	###################

    it "" do
      Fail
    end

  #################
  #  max_objects  #
  #################

  it "" do
    Fail
  end

  	#####################
  	#  set_max_objects  #
  	#####################

    it "" do
      Fail
    end

  ##########################
  #  number_of_partitions  #
  ##########################

  it "" do
    Fail
  end

  	##############################
  	#  set_number_of_partitions  #
  	##############################

    it "" do
      Fail
    end

  ##################################
  #  deadlock_detector_controller  #
  ##################################

  it "" do
    Fail
  end

end

