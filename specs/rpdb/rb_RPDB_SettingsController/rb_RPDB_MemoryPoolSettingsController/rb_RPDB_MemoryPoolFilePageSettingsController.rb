require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::MemoryPool::File::Page do

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

  # RPDB::Settings::MemoryPool::File::Page.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::MemoryPool::File::Page.new( @environment ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Page.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::MemoryPool::File::Page.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Page.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Settings::MemoryPool::File::Page.new( RPDB::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Page.new( memory_pool_settings_controller )
  it "can be created with a memory pool file settings controller" do
    RPDB::Settings::MemoryPool::File::Page.new( RPDB::Settings::MemoryPool::File.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Page.new
  it "can be created with no argument specified" do
    RPDB::Settings::MemoryPool::File::Page.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::MemoryPool::File::Page.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::MemoryPool::File::Page.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "can return its parent memory pool settings controller" do
    RPDB::Settings::MemoryPool::File::Page.new.parent_memory_pool_settings_controller.should_not == nil
  end

  #################################################
  #  parent_memory_pool_file_settings_controller  #
  #################################################

  it "can return its parent memory pool file settings controller" do
    RPDB::Settings::MemoryPool::File::Page.new.parent_memory_pool_file_settings_controller.should_not == nil
  end

  #############################################
  #  get_page_creates_page_if_does_not_exist  #
  #############################################

  it "" do
    Fail
  end

  	#####################################################
  	#  turn_get_page_creates_page_if_does_not_exist_on  #
  	#####################################################

    it "" do
      Fail
    end

  	######################################################
  	#  turn_get_page_creates_page_if_does_not_exist_off  #
  	######################################################

    it "" do
      Fail
    end

  ##########################################
  #  get_page_writes_copy_before_eviction  #
  ##########################################

  it "" do
    Fail
  end

  	##################################################
  	#  turn_get_page_writes_copy_before_eviction_on  #
  	##################################################

    it "" do
      Fail
    end

  	###################################################
  	#  turn_get_page_writes_copy_before_eviction_off  #
  	###################################################

    it "" do
      Fail
    end

  ##################################################
  #  get_page_writes_before_eviction_without_copy  #
  ##################################################

  it "" do
    Fail
  end

  	##########################################################
  	#  turn_get_page_writes_before_eviction_without_copy_on  #
  	##########################################################

    it "" do
      Fail
    end

  	###########################################################
  	#  turn_get_page_writes_before_eviction_without_copy_off  #
  	###########################################################

    it "" do
      Fail
    end

  ################################
  #  get_page_returns_last_page  #
  ################################

  it "" do
    Fail
  end

  	########################################
  	#  turn_get_page_returns_last_page_on  #
  	########################################

    it "" do
      Fail
    end

  	#########################################
  	#  turn_get_page_returns_last_page_off  #
  	#########################################

    it "" do
      Fail
    end

  ###############################
  #  get_page_creates_new_page  #
  ###############################

  it "" do
    Fail
  end

  	#######################################
  	#  turn_get_page_creates_new_page_on  #
  	#######################################

    it "" do
      Fail
    end

  	########################################
  	#  turn_get_page_creates_new_page_off  #
  	########################################

    it "" do
      Fail
    end

end

