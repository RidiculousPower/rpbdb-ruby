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

  it "" do
    raise "Failed."
  end

  #############################
  #  memory_mapping?          #
	#  turn_memory_mapping_on   #
	#  turn_memory_mapping_off  #
  #############################

  it "" do
    raise "Failed."
  end

  ##############################################
  #  remove_file_with_last_reference?          #
	#  turn_remove_file_with_last_reference_on   #
	#  turn_remove_file_with_last_reference_off  #
  ##############################################

  it "" do
    raise "Failed."
  end

  ###################################################
  #  pagesize_factor_mismatch_should_fail?          #
	#  turn_pagesize_factor_mismatch_should_fail_on   #
	#  turn_pagesize_factor_mismatch_should_fail_off  #
  ###################################################

  it "" do
    raise "Failed."
  end

  ##############################
  #  file_settings_controller  #
  ##############################

  it "" do
    raise "Failed."
  end

  ####################################
  #  read_write_settings_controller  #
  ####################################

  it "" do
    raise "Failed."
  end

end

