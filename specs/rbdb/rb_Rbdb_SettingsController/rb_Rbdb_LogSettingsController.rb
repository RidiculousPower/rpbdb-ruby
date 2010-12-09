require_relative '../../../lib/rbdb.rb'

describe Rbdb::Settings::Log do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # Rbdb::Settings::Log.new( environment )
  it "can be created with an environment" do
    @environment.open
    Rbdb::Settings::Log.new( @environment ).should_not == nil
  end

  # Rbdb::Settings::Log.new( settings_controller )
  it "can be created with a settings controller" do
    @environment.open
    Rbdb::Settings::Log.new( Rbdb::Settings.new ).should_not == nil
  end

  # Rbdb::Settings::Log.new
  it "can be created with no argument specified" do
    @environment.open
    Rbdb::Settings::Log.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    @environment.open
    Rbdb::Settings::Log.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    @environment.open
    Rbdb::Settings::Log.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
	#  turn_on   #
	#  turn_off  #
  ##############

  it "can turn on and off and report whether it is on or off" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.on?.should == true
    log_settings.turn_off
    log_settings.on?.should == false
    log_settings.off?.should == true
    log_settings.turn_on
    log_settings.off?.should == false
  end

  #######################################
  #  disable_system_buffering?          #
	#  turn_disable_system_buffering_on   #
	#  turn_disable_system_buffering_off  #
  #######################################

  it "can turn system buffering on and off" do
    raise "Log config (log_get_config always returning 0)"
    log_settings  = Rbdb::Settings::Log.new( @environment )
    log_settings.disable_system_buffering?.should == false
    log_settings.turn_disable_system_buffering_on
    log_settings.disable_system_buffering?.should == true
    log_settings.turn_disable_system_buffering_off
    log_settings.disable_system_buffering?.should == false
  end

  #############################################
  #  flush_before_return_from_write?          #
	#  turn_flush_before_return_from_write_on   #
	#  turn_flush_before_return_from_write_off  #
  #############################################

  it "can be set to flush before returning from a write" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.flush_before_return_from_write?.should == false
    log_settings.turn_flush_before_return_from_write_on
    log_settings.flush_before_return_from_write?.should == true
    log_settings.turn_flush_before_return_from_write_off
    log_settings.flush_before_return_from_write?.should == false
  end

  #########################
  #  autoremove_logs?     #
	#  turn_autoremove_on   #
	#  turn_autoremove_off  #
  #########################

  it "can be set to autoremove logs" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.autoremove_logs?.should == false
    log_settings.turn_autoremove_on
    log_settings.autoremove_logs?.should == true
    log_settings.turn_autoremove_off
    log_settings.autoremove_logs?.should == false
  end

  ############################
  #  log_in_memory?          #
	#  turn_log_in_memory_on   #
	#  turn_log_in_memory_off  #
  ############################

  it "can be set to log in memory rather than on disk" do
    raise "Log config (log_get_config always returning 0)"
    log_settings  = Rbdb::Settings::Log.new( @environment )
    log_settings.log_in_memory?.should == false
    log_settings.turn_log_in_memory_on
    log_settings.log_in_memory?.should == true
    log_settings.turn_log_in_memory_off
    log_settings.log_in_memory?.should == false
  end

  ###############################
  #  zero_at_creation?          #
	#  turn_zero_at_creation_on   #
	#  turn_zero_at_creation_off  #
  ###############################

  it "can be set to zero the log at creation" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.zero_at_creation?.should == false
    log_settings.turn_zero_at_creation_on
    log_settings.zero_at_creation?.should == true
    log_settings.turn_zero_at_creation_off
    log_settings.zero_at_creation?.should == false
  end

  #############################################
  #  force_flush_after_record_write?          #
	#  turn_force_flush_after_record_write_on   #
	#  turn_force_flush_after_record_write_off  #
  #############################################

  it "can be set to force a flush after record write" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.force_flush_after_record_write?.should == false
    log_settings.turn_force_flush_after_record_write_on
    log_settings.force_flush_after_record_write?.should == true
    log_settings.turn_force_flush_after_record_write_off
    log_settings.force_flush_after_record_write?.should == false
  end

  #####################
	#  set_buffer_size  #
  #  buffer_size      #
  #####################

  it "can set and return its buffer size" do
    log_settings  = Rbdb::Settings::Log.new( @environment )
    log_settings.set_buffer_size( 42 )
    log_settings.buffer_size.should == 42
  end

  ###################
	#  set_directory  #
  #  directory      #
  ###################

  it "can set and return its directory" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.set_directory( '/tmp/file.tmp' )
    log_settings.directory.should == '/tmp/file.tmp'
  end

  ##############
	#  set_mode  #
  #  mode      #
  ##############

  it "can set and return its mode" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.set_mode( 0 )
    log_settings.mode.should == 0
  end

  ######################
	#  set_max_log_size  #
  #  max_log_size      #
  ######################

  it "can set and return its maximum log size" do
    @environment.open
    log_settings  = Rbdb::Settings::Log.new
    log_settings.set_max_log_size( 42 )
    log_settings.max_log_size.should == 42
  end

  #########################
	#  set_max_region_size  #
  #  max_region_size      #
  #########################

  it "can set and return its maximum region size" do
    log_settings  = Rbdb::Settings::Log.new( @environment )
    log_settings.set_max_region_size( 42 )
    log_settings.max_region_size.should == 42
  end

end

