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

  #############################################################
  #  run_normal_recovery_before_opening_environment?          #
	#  turn_run_normal_recovery_before_opening_environment_on   #
	#  turn_run_normal_recovery_before_opening_environment_off  #
  #############################################################

  it "can run normal recovery processes during environment open before actually opening environment" do
    debug_settings  = RPDB::Settings::Debug.new
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
    debug_settings.turn_run_normal_recovery_before_opening_environment_on
    debug_settings.run_normal_recovery_before_opening_environment?.should == true
    debug_settings.turn_run_normal_recovery_before_opening_environment_off
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
  end

  ###################################################################
  #  run_catastrophic_recovery_before_opening_environment?          #
	#  turn_run_catastrophic_recovery_before_opening_environment_on   #
	#  turn_run_catastrophic_recovery_before_opening_environment_off  #
  ###################################################################

  it "can run catastrophic recovery processes during environment open before actually opening environment" do
    debug_settings  = RPDB::Settings::Debug.new
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
    debug_settings.turn_run_normal_recovery_before_opening_environment_on
    debug_settings.run_normal_recovery_before_opening_environment?.should == true
    debug_settings.turn_run_normal_recovery_before_opening_environment_off
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
  end

  ###############################
  #  open_in_lockdown?          #
	#  turn_open_in_lockdown_on   #
	#  turn_open_in_lockdown_off  #
  ###############################

  it "can open in lockdown" do
    debug_settings  = RPDB::Settings::Debug.new
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
    debug_settings.turn_run_normal_recovery_before_opening_environment_on
    debug_settings.run_normal_recovery_before_opening_environment?.should == true
    debug_settings.turn_run_normal_recovery_before_opening_environment_off
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
  end

  ############################################################
  #  check_for_recovery_before_opening_environment?          #
	#  turn_check_for_recovery_before_opening_environment_on   #
	#  turn_check_for_recovery_before_opening_environment_off  #
  ############################################################

  it "can check whether it should run recovery processes during environment open before actually opening environment" do
    debug_settings  = RPDB::Settings::Debug.new
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
    debug_settings.turn_run_normal_recovery_before_opening_environment_on
    debug_settings.run_normal_recovery_before_opening_environment?.should == true
    debug_settings.turn_run_normal_recovery_before_opening_environment_off
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
  end

  #############################
  #  prohibit_panic?          #
	#  turn_prohibit_panic_on   #
	#  turn_prohibit_panic_off  #
  #############################

  it "can prohibit panic" do
    debug_settings  = RPDB::Settings::Debug.new
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
    debug_settings.turn_run_normal_recovery_before_opening_environment_on
    debug_settings.run_normal_recovery_before_opening_environment?.should == true
    debug_settings.turn_run_normal_recovery_before_opening_environment_off
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
  end

  ####################
  #  panic?          #
	#  turn_panic_on   #
	#  turn_panic_off  #
  ####################

  it "can panic" do
    debug_settings  = RPDB::Settings::Debug.new
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
    debug_settings.turn_run_normal_recovery_before_opening_environment_on
    debug_settings.run_normal_recovery_before_opening_environment?.should == true
    debug_settings.turn_run_normal_recovery_before_opening_environment_off
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
  end

  ########################################
  #  yield_cpu_for_stress_test           #
	#  turn_yield_cpu_for_stress_test_on   #
	#  turn_yield_cpu_for_stress_test_off  #
  ########################################

  it "can yield cpu for stress test" do
    debug_settings  = RPDB::Settings::Debug.new
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
    debug_settings.turn_run_normal_recovery_before_opening_environment_on
    debug_settings.run_normal_recovery_before_opening_environment?.should == true
    debug_settings.turn_run_normal_recovery_before_opening_environment_off
    debug_settings.run_normal_recovery_before_opening_environment?.should == false
  end

  ###################################
  #  verbosity_settings_controller  #
  ###################################

  it "can return its verbosity settings controller" do
    RPDB::Settings::Debug.new.verbosity_settings_controller.is_a?( RPDB::Settings::Debug::Verbosity ).should == true
  end

end

