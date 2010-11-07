require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Mutex do

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

  # RPDB::Environment::Settings::Mutex.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Mutex.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Mutex.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Mutex.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Mutex.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Mutex.new.should_not == nil
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

  ##########################################################
  #  spin_times_before_blocking_for_test_and_spin_mutexes  #
  ##########################################################

  it "" do
    Fail
  end

  	##############################################################
  	#  set_spin_times_before_blocking_for_test_and_spin_mutexes  #
  	##############################################################

    it "" do
      Fail
    end

  ###########################
  #  max_allowable_mutexes  #
  ###########################

  it "" do
    Fail
  end

  	###############################
  	#  set_max_allowable_mutexes  #
  	###############################

    it "" do
      Fail
    end

  ##################################
  #  increment_for_adding_mutexes  #
  ##################################

  it "" do
    Fail
  end

  	######################################
  	#  set_increment_for_adding_mutexes  #
  	######################################

    it "" do
      Fail
    end

  #####################
  #  mutex_alignment  #
  #####################

  it "" do
    Fail
  end

  	#########################
  	#  set_mutex_alignment  #
  	#########################

    it "" do
      Fail
    end

  #####################################
  #  associated_with_single_process?  #
  #####################################

  it "" do
    Fail
  end

  	############################################
  	#  turn_associated_with_single_process_on  #
  	############################################

    it "" do
      Fail
    end

  	#############################################
  	#  turn_associated_with_single_process_off  #
  	#############################################

    it "" do
      Fail
    end

  ###################
  #  self_blocking  #
  ###################

  it "" do
    Fail
  end

  	###########################
  	#  turn_self_blocking_on  #
  	###########################

    it "" do
      Fail
    end

  	############################
  	#  turn_self_blocking_off  #
  	############################

    it "" do
      Fail
    end


end

