require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Lock::DeadlockDetector do

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

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new( lock_settings_controller )
  it "can be created with a lock settings controller" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new( RPDB::Environment::Settings::Lock.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock::DeadlockDetector.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Lock::DeadlockDetector.new.should_not == nil
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

  #####################################
  #  parent_lock_settings_controller  #
  #####################################

  it "" do
    Fail
  end

  #################
  #  is_default?  #
  #################

  it "" do
    Fail
  end

  	####################
  	#  set_to_default  #
  	####################

    it "" do
      Fail
    end

  #####################
  #  reject_expired?  #
  #####################

  it "" do
    Fail
  end

  	###########################
  	#  set_to_reject_expired  #
  	###########################

    it "" do
      Fail
    end

  ####################################
  #  reject_locker_with_most_locks?  #
  ####################################

  it "" do
    Fail
  end

  	##########################################
  	#  set_to_reject_locker_with_most_locks  #
  	##########################################

    it "" do
      Fail
    end

  ##########################################
  #  reject_locker_with_most_write_locks?  #
  ##########################################

  it "" do
    Fail
  end

  	################################################
  	#  set_to_reject_locker_with_most_write_locks  #
  	################################################

    it "" do
      Fail
    end

  ######################################
  #  reject_locker_with_fewest_locks?  #
  ######################################

  it "" do
    Fail
  end

  	############################################
  	#  set_to_reject_locker_with_fewest_locks  #
  	############################################

    it "" do
      Fail
    end

  ############################################
  #  reject_locker_with_fewest_write_locks?  #
  ############################################

  it "" do
    Fail
  end

  	##################################################
  	#  set_to_reject_locker_with_fewest_write_locks  #
  	##################################################

    it "" do
      Fail
    end

  #####################################
  #  reject_locker_with_oldest_lock?  #
  #####################################

  it "" do
    Fail
  end

  	###########################################
  	#  set_to_reject_locker_with_oldest_lock  #
  	###########################################

    it "" do
      Fail
    end

  #######################################
  #  reject_locker_with_youngest_lock?  #
  #######################################

  it "" do
    Fail
  end

  	#############################################
  	#  set_to_reject_locker_with_youngest_lock  #
  	#############################################

    it "" do
      Fail
    end

  ####################
  #  reject_random?  #
  ####################

  it "" do
    Fail
  end

  	##########################
  	#  set_to_reject_random  #
  	##########################

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

