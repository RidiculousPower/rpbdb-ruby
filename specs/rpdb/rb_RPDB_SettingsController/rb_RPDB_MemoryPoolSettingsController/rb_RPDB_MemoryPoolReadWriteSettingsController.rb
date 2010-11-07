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

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "" do
    Fail
  end

  ####################
  #  max_open_files  #
  ####################

  it "" do
    Fail
  end

  	########################
  	#  set_max_open_files  #
  	########################

    it "" do
      Fail
    end

  ###########################
  #  max_sequential_writes  #
  ###########################

  it "" do
    Fail
  end

  	###############################
  	#  set_max_sequential_writes  #
  	###############################

    it "" do
      Fail
    end

  #####################################
  #  time_to_sleep_before_next_write  #
  #####################################

  it "" do
    Fail
  end

  	#########################################
  	#  set_time_to_sleep_before_next_write  #
  	#########################################

    it "" do
      Fail
    end

  ##############################
  #  max_mapped_database_size  #
  ##############################

  it "" do
    Fail
  end

  	##################################
  	#  set_max_mapped_database_size  #
  	##################################

    it "" do
      Fail
    end

  ###############################
  #  pagefault_shared_regions?  #
  ###############################

  it "" do
    Fail
  end

  	######################################
  	#  turn_pagefault_shared_regions_on  #
  	######################################

    it "" do
      Fail
    end

  	#######################################
  	#  turn_pagefault_shared_regions_off  #
  	#######################################

    it "" do
      Fail
    end

  ############################################
  #  do_not_write_to_temporary_backing_file  #
  ############################################

  it "" do
    Fail
  end

  	####################################################
  	#  turn_do_not_write_to_temporary_backing_file_on  #
  	####################################################

    it "" do
      Fail
    end

  	#####################################################
  	#  turn_do_not_write_to_temporary_backing_file_off  #
  	#####################################################

    it "" do
      Fail
    end

  ###################################
  #  use_system_memory_for_storage  #
  ###################################

  it "" do
    Fail
  end

  	###########################################
  	#  turn_use_system_memory_for_storage_on  #
  	###########################################

    it "" do
      Fail
    end

  	############################################
  	#  turn_use_system_memory_for_storage_off  #
  	############################################

    it "" do
      Fail
    end

  #######################################
  #  application_has_exclusive_access?  #
  #######################################

  it "" do
    Fail
  end

  	##############################################
  	#  turn_application_has_exclusive_access_on  #
  	##############################################

    it "" do
      Fail
    end

  	###############################################
  	#  turn_application_has_exclusive_access_off  #
  	###############################################

    it "" do
      Fail
    end

  #############################################
  #  database_allocates_memory_using_malloc?  #
  #############################################

  it "" do
    Fail
  end

  	####################################################
  	#  turn_database_allocates_memory_using_malloc_on  #
  	####################################################

    it "" do
      Fail
    end

  	#####################################################
  	#  turn_database_allocates_memory_using_malloc_off  #
  	#####################################################

    it "" do
      Fail
    end

  #############################################
  #  database_allocates_memory_using_realloc  #
  #############################################

  it "" do
    Fail
  end

  	#####################################################
  	#  turn_database_allocates_memory_using_realloc_on  #
  	#####################################################

    it "" do
      Fail
    end

  	######################################################
  	#  turn_database_allocates_memory_using_realloc_off  #
  	######################################################

    it "" do
      Fail
    end

  ##################################
  #  application_allocates_memory  #
  ##################################

  it "" do
    Fail
  end

  	##########################################
  	#  turn_application_allocates_memory_on  #
  	##########################################

    it "" do
      Fail
    end

  	###########################################
  	#  turn_application_allocates_memory_off  #
  	###########################################

    it "" do
      Fail
    end

  ###########################
  #  database_frees_memory  #
  ###########################

  it "" do
    Fail
  end

  	###################################
  	#  turn_database_frees_memory_on  #
  	###################################

    it "" do
      Fail
    end

  	####################################
  	#  turn_database_frees_memory_off  #
  	####################################

    it "" do
      Fail
    end


end

