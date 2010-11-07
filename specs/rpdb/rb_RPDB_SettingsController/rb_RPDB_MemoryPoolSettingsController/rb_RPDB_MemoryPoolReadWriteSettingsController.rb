require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::MemoryPool::ReadWrite do

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

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new( RPDB::Environment::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::MemoryPool::ReadWrite.new.should_not == nil
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

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  ####################
  #  max_open_files  #
  ####################

  	########################
  	#  set_max_open_files  #
  	########################

  ###########################
  #  max_sequential_writes  #
  ###########################

  	###############################
  	#  set_max_sequential_writes  #
  	###############################

  #####################################
  #  time_to_sleep_before_next_write  #
  #####################################

  	#########################################
  	#  set_time_to_sleep_before_next_write  #
  	#########################################

  ##############################
  #  max_mapped_database_size  #
  ##############################

  	##################################
  	#  set_max_mapped_database_size  #
  	##################################

  ###############################
  #  pagefault_shared_regions?  #
  ###############################

  	######################################
  	#  turn_pagefault_shared_regions_on  #
  	######################################

  	#######################################
  	#  turn_pagefault_shared_regions_off  #
  	#######################################

  ############################################
  #  do_not_write_to_temporary_backing_file  #
  ############################################

  	####################################################
  	#  turn_do_not_write_to_temporary_backing_file_on  #
  	####################################################

  	#####################################################
  	#  turn_do_not_write_to_temporary_backing_file_off  #
  	#####################################################

  ###################################
  #  use_system_memory_for_storage  #
  ###################################

  	###########################################
  	#  turn_use_system_memory_for_storage_on  #
  	###########################################

  	############################################
  	#  turn_use_system_memory_for_storage_off  #
  	############################################

  #######################################
  #  application_has_exclusive_access?  #
  #######################################

  	##############################################
  	#  turn_application_has_exclusive_access_on  #
  	##############################################

  	###############################################
  	#  turn_application_has_exclusive_access_off  #
  	###############################################

  #############################################
  #  database_allocates_memory_using_malloc?  #
  #############################################

  	####################################################
  	#  turn_database_allocates_memory_using_malloc_on  #
  	####################################################

  	#####################################################
  	#  turn_database_allocates_memory_using_malloc_off  #
  	#####################################################

  #############################################
  #  database_allocates_memory_using_realloc  #
  #############################################

  	#####################################################
  	#  turn_database_allocates_memory_using_realloc_on  #
  	#####################################################

  	######################################################
  	#  turn_database_allocates_memory_using_realloc_off  #
  	######################################################

  ##################################
  #  application_allocates_memory  #
  ##################################

  	##########################################
  	#  turn_application_allocates_memory_on  #
  	##########################################

  	###########################################
  	#  turn_application_allocates_memory_off  #
  	###########################################

  ###########################
  #  database_frees_memory  #
  ###########################

  	###################################
  	#  turn_database_frees_memory_on  #
  	###################################

  	####################################
  	#  turn_database_frees_memory_off  #
  	####################################


end

