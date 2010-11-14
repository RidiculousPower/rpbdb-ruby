require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings::Thread do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Settings::Thread.new( environment )
  it "can be created with an environment" do
    @environment.open
    RPDB::Settings::Thread.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Thread.new( settings_controller )
  it "can be created with a settings controller" do
    @environment.open
    RPDB::Settings::Thread.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Thread.new
  it "can be created with no argument specified" do
    @environment.open
    RPDB::Settings::Thread.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    @environment.open
    RPDB::Settings::Thread.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    @environment.open
    RPDB::Settings::Thread.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
  #  turn_on   #
  #  turn_off  #
  ##############

  it "can be turned on or off as well as report whether it is on or off" do
    thread_settings  = RPDB::Settings::Thread.new( @environment )
    thread_settings.on?.should == false
    thread_settings.turn_on
    thread_settings.on?.should == true
    thread_settings.off?.should == false
    thread_settings.turn_off
    thread_settings.off?.should == true
  end

  ######################
  #  set_thread_count  #
  #  thread_count      #
  ######################

  it "can set and return its thread count" do
    thread_settings  = RPDB::Settings::Thread.new( @environment )
    thread_settings.set_thread_count( 42 )
    thread_settings.thread_count.should == 42
  end

  ##################################################
  #  set_unique_thread_identifier_callback_method  #
  #  unique_thread_identifier_callback_method      #
  ##################################################

  it "can set and return its callback method to provide a unique thread identifier" do
    @environment.open
    raise "Callback."
  end

  ##########################################################################
  #  set_format_thread_and_process_identifier_for_display_callback_method  #
  #  format_thread_and_process_identifier_for_display_callback_method      #
  ##########################################################################

  it "can set and return its callback method to format thread and process identifier for display" do
    @environment.open
    raise "Callback."
  end

  #########################################
  #  set_is_thread_alive_callback_method  #
  #  is_thread_alive_callback_method      #
  #########################################

  it "can set and return its callback method to determine whether thread is alive" do
    @environment.open
    raise "Callback."
  end

end

