require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Thread do

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

  # RPDB::Environment::Settings::Thread.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Thread.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Thread.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Thread.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Thread.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Thread.new.should_not == nil
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

  ##################
  #  thread_count  #
  ##################

  it "" do
    Fail
  end

  ######################
  #  set_thread_count  #
  ######################

  it "" do
    Fail
  end

  ##################################################
  #  set_unique_thread_identifier_callback_method  #
  ##################################################

  it "" do
    Fail
  end

  ##############################################
  #  unique_thread_identifier_callback_method  #
  ##############################################

  it "" do
    Fail
  end

  ##########################################################################
  #  set_format_thread_and_process_identifier_for_display_callback_method  #
  ##########################################################################

  it "" do
    Fail
  end

  ######################################################################
  #  format_thread_and_process_identifier_for_display_callback_method  #
  ######################################################################

  it "" do
    Fail
  end

  #########################################
  #  set_is_thread_alive_callback_method  #
  #########################################

  it "" do
    Fail
  end

  #####################################
  #  is_thread_alive_callback_method  #
  #####################################

  it "" do
    Fail
  end

end

