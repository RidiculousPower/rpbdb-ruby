require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::MemoryPool do

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

  # RPDB::Settings::MemoryPool.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::MemoryPool.new( @environment ).should_not == nil
  end

  # RPDB::Settings::MemoryPool.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::MemoryPool.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool.new
  it "can be created with no argument specified" do
    RPDB::Settings::MemoryPool.new.should_not == nil
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::MemoryPool.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::MemoryPool.new.parent_settings_controller.should_not == nil
  end

  ##############
  #  on?       #
  #  off?      #
	#  turn_on   #
	#  turn_off  #
  ##############

  it "it can turn on and off and report whether it is on or off" do
    memory_pool_settings  = RPDB::Settings::MemoryPool.new
    memory_pool_settings.on?.should == true
    memory_pool_settings.off?.should == false
    memory_pool_settings.turn_off
    memory_pool_settings.on?.should == false
    memory_pool_settings.off?.should == true
    memory_pool_settings.turn_on
    memory_pool_settings.on?.should == true
    memory_pool_settings.off?.should == false
  end

  #############################
  #  memory_mapping?          #
	#  turn_memory_mapping_on   #
	#  turn_memory_mapping_off  #
  #############################

  it "can turn memory mapping on and off" do
    memory_pool_settings  = RPDB::Settings::MemoryPool.new
    memory_pool_settings.memory_mapping?.should == false
    memory_pool_settings.turn_memory_mapping_on
    memory_pool_settings.memory_mapping?.should == true
    memory_pool_settings.turn_memory_mapping_off
    memory_pool_settings.memory_mapping?.should == false
  end

  ##############################################
  #  remove_file_with_last_reference?          #
	#  turn_remove_file_with_last_reference_on   #
	#  turn_remove_file_with_last_reference_off  #
  ##############################################

  it "can be set to remove file with last reference" do
    memory_pool_settings  = RPDB::Settings::MemoryPool.new
    memory_pool_settings.remove_file_with_last_reference?.should == false
    memory_pool_settings.turn_remove_file_with_last_reference_on
    memory_pool_settings.remove_file_with_last_reference?.should == true
    memory_pool_settings.turn_remove_file_with_last_reference_off
    memory_pool_settings.remove_file_with_last_reference?.should == false
  end

  ###################################################
  #  pagesize_factor_mismatch_should_fail?          #
	#  turn_pagesize_factor_mismatch_should_fail_on   #
	#  turn_pagesize_factor_mismatch_should_fail_off  #
  ###################################################

  it "can be set to fail in the event of a pagesize factor mismatch" do
    memory_pool_settings  = RPDB::Settings::MemoryPool.new
    memory_pool_settings.pagesize_factor_mismatch_should_fail?.should == false
    memory_pool_settings.turn_pagesize_factor_mismatch_should_fail_on
    memory_pool_settings.pagesize_factor_mismatch_should_fail?.should == true
    memory_pool_settings.turn_pagesize_factor_mismatch_should_fail_off
    memory_pool_settings.pagesize_factor_mismatch_should_fail?.should == false
  end

  ##############################
  #  file_settings_controller  #
  ##############################

  it "can return its file settings controller" do
    RPDB::Settings::MemoryPool.new.file_settings_controller.is_a?( RPDB::Settings::MemoryPool::File ).should == true
  end

  ####################################
  #  read_write_settings_controller  #
  ####################################

  it "can return its read/write settings controller" do
    RPDB::Settings::MemoryPool.new.read_write_settings_controller.is_a?( RPDB::Settings::MemoryPool::ReadWrite ).should == true
  end

end

