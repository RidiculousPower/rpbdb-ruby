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

  ################
  #  initialize  #
  ################

  ########################
  #  parent_environment  #
  ########################

  ################################
  #  parent_settings_controller  #
  ################################

  #########
  #  on?  #
  #########

  ##########
  #  off?  #
  ##########


  #############
  #  turn_on  #
  #############

  ##############
  #  turn_off  #
  ##############

  ##################
  #  thread_count  #
  ##################

  ######################
  #  set_thread_count  #
  ######################

  ##################################################
  #  set_unique_thread_identifier_callback_method  #
  ##################################################

  ##############################################
  #  unique_thread_identifier_callback_method  #
  ##############################################

  ##########################################################################
  #  set_format_thread_and_process_identifier_for_display_callback_method  #
  ##########################################################################

  ######################################################################
  #  format_thread_and_process_identifier_for_display_callback_method  #
  ######################################################################

  #########################################
  #  set_is_thread_alive_callback_method  #
  #########################################

  #####################################
  #  is_thread_alive_callback_method  #
  #####################################

end

