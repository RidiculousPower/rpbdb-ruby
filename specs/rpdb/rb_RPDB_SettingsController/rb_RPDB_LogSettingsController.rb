require_relative '../../../lib/rpdb.rb'

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
    RPDB::Settings::Log.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Log.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
	#  turn_on   #
	#  turn_off  #
  ##############

  it "can turn on and off and report whether it is on or off" do
    raise "Failed."
  end

  ########################
  #  buffering           #
	#  turn_buffering_on   #
	#  turn_buffering_off  #
  ########################

  it "can turn buffering on and off" do
    raise "Failed."
  end

  #############################################
  #  flush_before_return_from_write           #
	#  turn_flush_before_return_from_write_on   #
	#  turn_flush_before_return_from_write_off  #
  #############################################

  it "can be set to flush before returning from a write" do
    raise "Failed."
  end

  #########################
  #  autoremove_logs      #
	#  turn_autoremove_on   #
	#  turn_autoremove_off  #
  #########################

  it "can be set to autoremove logs" do
    raise "Failed."
  end

  ############################
  #  log_in_memory           #
	#  turn_log_in_memory_on   #
	#  turn_log_in_memory_off  #
  ############################

  it "can be set to log in memory rather than on disk" do
    raise "Failed."
  end

  ###############################
  #  zero_at_creation?          #
	#  turn_zero_at_creation_on   #
	#  turn_zero_at_creation_off  #
  ###############################

  it "can be set to zero the log at creation" do
    raise "Failed."
  end

  #############################################
  #  force_flush_after_record_write?          #
	#  turn_force_flush_after_record_write_on   #
	#  turn_force_flush_after_record_write_off  #
  #############################################

  it "can be set to force a flush after record write" do
    raise "Failed."
  end

  #####################
	#  set_buffer_size  #
  #  buffer_size      #
  #####################

  it "can set and return its buffer size" do
    raise "Failed."
  end

  ###################
	#  set_directory  #
  #  directory      #
  ###################

  it "can set and return its directory" do
    raise "Failed."
  end

  ##############
	#  set_mode  #
  #  mode      #
  ##############

  it "can set and return its mode" do
    raise "Failed."
  end

  ######################
	#  set_max_log_size  #
  #  max_log_size      #
  ######################

  it "can set and return its maximum log size" do
    raise "Failed."
  end

  #########################
	#  set_max_region_size  #
  #  max_region_size      #
  #########################

  it "can set and return its maximum region size" do
    raise "Failed."
  end

end

