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

  it "can set and return its blcoking time for test and spin mutexes" do
    mutex_settings  = RPDB::Settings::Mutex.new
    mutex_settings.set_spin_times_before_blocking_for_test_and_spin_mutexes( 42 )
    mutex_settings.spin_times_before_blocking_for_test_and_spin_mutexes.should == 42
  end

  ###############################
	#  set_max_allowable_mutexes  #
  #  max_allowable_mutexes      #
  ###############################

  it "can set its maximum allowable mutex limit" do
    mutex_settings  = RPDB::Settings::Mutex.new
    mutex_settings.set_max_allowable_mutexes( 42 )
    mutex_settings.max_allowable_mutexes.should == 42
  end

  ######################################
	#  set_increment_for_adding_mutexes  #
  #  increment_for_adding_mutexes      #
  ######################################

  it "can set and return its increment for adding mutexes" do
    mutex_settings  = RPDB::Settings::Mutex.new
    mutex_settings.set_increment_for_adding_mutexes( 42 )
    mutex_settings.increment_for_adding_mutexes.should == 42
  end

  #########################
	#  set_mutex_alignment  #
  #  mutex_alignment      #
  #########################

  it "can set and return its mutex alignment" do
    mutex_settings  = RPDB::Settings::Mutex.new
    mutex_settings.set_mutex_alignment( 42 )
    mutex_settings.mutex_alignment.should == 42
  end

  #############################################
  #  associated_with_single_process?          #
	#  turn_associated_with_single_process_on   #
	#  turn_associated_with_single_process_off  #
  ##############################################

  it "can be set to associate with a single process" do
    mutex_settings  = RPDB::Settings::Mutex.new
    mutex_settings.associated_with_single_process?.should == false
    mutex_settings.turn_associated_with_single_process_on
    mutex_settings.associated_with_single_process?.should == true
    mutex_settings.turn_associated_with_single_process_off
    mutex_settings.associated_with_single_process?.should == false
  end

  ############################
  #  self_blocking?          #
	#  turn_self_blocking_on   #
	#  turn_self_blocking_off  #
  ############################

  it "can be set to be self-blocking" do
    mutex_settings  = RPDB::Settings::Mutex.new
    mutex_settings.self_blocking?.should == false
    mutex_settings.turn_self_blocking_on
    mutex_settings.self_blocking?.should == true
    mutex_settings.turn_self_blocking_off
    mutex_settings.self_blocking?.should == false
  end

end

