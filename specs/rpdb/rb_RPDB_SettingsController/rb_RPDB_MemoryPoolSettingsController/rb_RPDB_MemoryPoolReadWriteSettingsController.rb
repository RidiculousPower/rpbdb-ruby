require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::MemoryPool::ReadWrite do

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

  # RPDB::Settings::MemoryPool::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::MemoryPool::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::MemoryPool::ReadWrite.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::ReadWrite.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Settings::MemoryPool::ReadWrite.new( RPDB::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Settings::MemoryPool::ReadWrite.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::MemoryPool::ReadWrite.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::MemoryPool::ReadWrite.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "can return its parent memory pool settings controller" do
    RPDB::Settings::MemoryPool::ReadWrite.new.parent_memory_pool_settings_controller.should_not == nil
  end

  ########################
	#  set_max_open_files  #
  #  max_open_files      #
  ########################

  it "can set and return its maximum open file limit" do
    raise "Failed."
  end

  ###############################
	#  set_max_sequential_writes  #
  #  max_sequential_writes      #
  ###############################

  it "can set and return its maximum sequential write limit" do
    raise "Failed."
  end

  #########################################
	#  set_time_to_sleep_before_next_write  #
  #  time_to_sleep_before_next_write      #
  #########################################

  it "can set and return its maximum time to sleep before next write" do
    raise "Failed."
  end

  ##################################
	#  set_max_mapped_database_size  #
  #  max_mapped_database_size      #
  ##################################

  it "can set maximum mapped database size limit" do
    raise "Failed."
  end

  #######################################
  #  pagefault_shared_regions?          #
	#  turn_pagefault_shared_regions_on   #
	#  turn_pagefault_shared_regions_off  #
  #######################################

  it "can be set to pagefault shared regions" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.pagefault_shared_regions?.should == false
    read_write_settings.turn_pagefault_shared_regions_on
    read_write_settings.pagefault_shared_regions?.should == true
    read_write_settings.turn_pagefault_shared_regions_off
    read_write_settings.pagefault_shared_regions?.should == false
  end

  #####################################################
  #  do_not_write_to_temporary_backing_file?          #
	#  turn_do_not_write_to_temporary_backing_file_on   #
	#  turn_do_not_write_to_temporary_backing_file_off  #
  #####################################################

  it "can be set not to write temporary backing file" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.do_not_write_to_temporary_backing_file?.should == false
    read_write_settings.turn_do_not_write_to_temporary_backing_file_on
    read_write_settings.do_not_write_to_temporary_backing_file?.should == true
    read_write_settings.turn_do_not_write_to_temporary_backing_file_off
    read_write_settings.do_not_write_to_temporary_backing_file?.should == false
  end

  ############################################
  #  use_system_memory_for_storage?          #
	#  turn_use_system_memory_for_storage_on   #
	#  turn_use_system_memory_for_storage_off  #
  ############################################

  it "can be set to use system memory for storage" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.use_system_memory_for_storage?.should == false
    read_write_settings.turn_use_system_memory_for_storage_on
    read_write_settings.use_system_memory_for_storage?.should == true
    read_write_settings.turn_use_system_memory_for_storage_off
    read_write_settings.use_system_memory_for_storage?.should == false
  end

  ###############################################
  #  application_has_exclusive_access?          #
	#  turn_application_has_exclusive_access_on   #
	#  turn_application_has_exclusive_access_off  #
  ###############################################

  it "can declare that application has exclusive access to permit optimizations" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.application_has_exclusive_access?.should == false
    read_write_settings.turn_application_has_exclusive_access_on
    read_write_settings.application_has_exclusive_access?.should == true
    read_write_settings.turn_application_has_exclusive_access_off
    read_write_settings.application_has_exclusive_access?.should == false
  end

  #####################################################
  #  database_allocates_memory_using_malloc?          #
	#  turn_database_allocates_memory_using_malloc_on   #
	#  turn_database_allocates_memory_using_malloc_off  #
  #####################################################

  it "can allocate memory using malloc" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.database_allocates_memory_using_malloc?.should == false
    read_write_settings.turn_database_allocates_memory_using_malloc_on
    read_write_settings.database_allocates_memory_using_malloc?.should == true
    read_write_settings.turn_database_allocates_memory_using_malloc_off
    read_write_settings.database_allocates_memory_using_malloc?.should == false
  end

  ######################################################
  #  database_allocates_memory_using_realloc?          #
	#  turn_database_allocates_memory_using_realloc_on   #
	#  turn_database_allocates_memory_using_realloc_off  #
  ######################################################

  it "can allocate memory using realloc" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.database_allocates_memory_using_realloc?.should == false
    read_write_settings.turn_database_allocates_memory_using_realloc_on
    read_write_settings.database_allocates_memory_using_realloc?.should == true
    read_write_settings.turn_database_allocates_memory_using_realloc_off
    read_write_settings.database_allocates_memory_using_realloc?.should == false
  end

  ###########################################
  #  application_allocates_memory?          #
	#  turn_application_allocates_memory_on   #
	#  turn_application_allocates_memory_off  #
  ###########################################

  it "can depend on application to allocate memory" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.application_allocates_memory?.should == false
    read_write_settings.turn_application_allocates_memory_on
    read_write_settings.application_allocates_memory?.should == true
    read_write_settings.turn_application_allocates_memory_off
    read_write_settings.application_allocates_memory?.should == false
  end

  ####################################
  #  database_frees_memory?          #
	#  turn_database_frees_memory_on   #
	#  turn_database_frees_memory_off  #
  ####################################

  it "can depend on database to free memory when finished with it" do
    read_write_settings  = RPDB::Settings::MemoryPool::ReadWrite.new
    read_write_settings.database_frees_memory?.should == false
    read_write_settings.turn_database_frees_memory_on
    read_write_settings.database_frees_memory?.should == true
    read_write_settings.turn_database_frees_memory_off
    read_write_settings.database_frees_memory?.should == false
  end

end

