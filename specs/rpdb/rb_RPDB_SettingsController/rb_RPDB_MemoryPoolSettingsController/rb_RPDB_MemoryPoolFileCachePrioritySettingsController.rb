require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::MemoryPool::File::Cache::Priority do

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

  # RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Environment::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_file_settings_controller )
  it "can be created with a memory pool file settings controller" do
    RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Environment::Settings::MemoryPool::File.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_file_cache_settings_controller )
  it "can be created with a memory pool file cache settings controller" do
    RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Environment::Settings::MemoryPool::File::Cache.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::MemoryPool::File::Cache::Priority.new.should_not == nil
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

  #################################################
  #  parent_memory_pool_file_settings_controller  #
  #################################################

  it "" do
    Fail
  end

  #######################################################
  #  parent_memory_pool_file_cache_settings_controller  #
  #######################################################

  it "" do
    Fail
  end

  ######################
  #  current_priority  #
  ######################

  it "" do
    Fail
  end

  ##############
  #  very_low  #
  ##############

  it "" do
    Fail
  end

  	##################
  	#  set_very_low  #
  	##################

    it "" do
      Fail
    end

  	#######################
  	#  at_least_very_low  #
  	#######################

    it "" do
      Fail
    end

  	######################
  	#  at_most_very_low  #
  	######################

    it "" do
      Fail
    end

  #########
  #  low  #
  #########

  it "" do
    Fail
  end

  	#############
  	#  set_low  #
  	#############

    it "" do
      Fail
    end

  	##################
  	#  at_least_low  #
  	##################

    it "" do
      Fail
    end

  	#################
  	#  at_most_low  #
  	#################

    it "" do
      Fail
    end

  #############
  #  default  #
  #############

  it "" do
    Fail
  end

  	#################
  	#  set_default  #
  	#################

    it "" do
      Fail
    end

  	######################
  	#  at_least_default  #
  	######################

    it "" do
      Fail
    end

  	#####################
  	#  at_most_default  #
  	#####################

    it "" do
      Fail
    end

  ##########
  #  high  #
  ##########

  it "" do
    Fail
  end

  	##############
  	#  set_high  #
  	##############

    it "" do
      Fail
    end

  	###################
  	#  at_least_high  #
  	###################

    it "" do
      Fail
    end

  	##################
  	#  at_most_high  #
  	##################

    it "" do
      Fail
    end

  ###############
  #  very_high  #
  ###############

  it "" do
    Fail
  end

  	###################
  	#  set_very_high  #
  	###################

    it "" do
      Fail
    end

  	########################
  	#  at_least_very_high  #
  	########################

    it "" do
      Fail
    end

  	#######################
  	#  at_most_very_high  #
  	#######################

    it "" do
      Fail
    end

end

