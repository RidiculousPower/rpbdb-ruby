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

  ################
  #  initialize  #
  ################

  ########################
  #  parent_environment  #
  ########################


  ################################
  #  parent_settings_controller  #
  ################################

  ##########################################################
  #  spin_times_before_blocking_for_test_and_spin_mutexes  #
  ##########################################################

  	##############################################################
  	#  set_spin_times_before_blocking_for_test_and_spin_mutexes  #
  	##############################################################

  ###########################
  #  max_allowable_mutexes  #
  ###########################


  	###############################
  	#  set_max_allowable_mutexes  #
  	###############################


  ##################################
  #  increment_for_adding_mutexes  #
  ##################################

  	######################################
  	#  set_increment_for_adding_mutexes  #
  	######################################


  #####################
  #  mutex_alignment  #
  #####################

  	#########################
  	#  set_mutex_alignment  #
  	#########################

  #####################################
  #  associated_with_single_process?  #
  #####################################

  	############################################
  	#  turn_associated_with_single_process_on  #
  	############################################

  	#############################################
  	#  turn_associated_with_single_process_off  #
  	#############################################

  ###################
  #  self_blocking  #
  ###################

  	###########################
  	#  turn_self_blocking_on  #
  	###########################

  	############################
  	#  turn_self_blocking_off  #
  	############################


end

