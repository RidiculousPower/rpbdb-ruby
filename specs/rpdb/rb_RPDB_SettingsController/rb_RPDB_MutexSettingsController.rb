require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings::Mutex do

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

  # RPDB::Settings::Mutex.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Mutex.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Mutex.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Mutex.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Mutex.new
  it "can be created with no argument specified" do
    RPDB::Settings::Mutex.new.should_not == nil
  end


  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Mutex.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Mutex.new.parent_settings_controller.should_not == nil
  end
  
  ##############################################################
	#  set_spin_times_before_blocking_for_test_and_spin_mutexes  #
  #  spin_times_before_blocking_for_test_and_spin_mutexes      #
  ##############################################################

  it "" do
    raise "Failed."
  end

  ###############################
	#  set_max_allowable_mutexes  #
  #  max_allowable_mutexes      #
  ###############################

  it "" do
    raise "Failed."
  end

  ######################################
	#  set_increment_for_adding_mutexes  #
  #  increment_for_adding_mutexes      #
  ######################################

  it "" do
    raise "Failed."
  end

  #########################
	#  set_mutex_alignment  #
  #  mutex_alignment      #
  #########################

  it "" do
    raise "Failed."
  end

  #############################################
  #  associated_with_single_process?          #
	#  turn_associated_with_single_process_on   #
	#  turn_associated_with_single_process_off  #
  ##############################################

  it "" do
    raise "Failed."
  end

  ############################
  #  self_blocking           #
	#  turn_self_blocking_on   #
	#  turn_self_blocking_off  #
  ############################

  it "" do
    raise "Failed."
  end

end

