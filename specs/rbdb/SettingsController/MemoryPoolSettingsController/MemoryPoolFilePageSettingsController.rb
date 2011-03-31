require_relative '../../../../lib/rpbdb.rb'

describe RPbdb::Settings::MemoryPool::File::Page do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
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

  # RPbdb::Settings::MemoryPool::File::Page.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::MemoryPool::File::Page.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Page.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::MemoryPool::File::Page.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Page.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPbdb::Settings::MemoryPool::File::Page.new( RPbdb::Settings::MemoryPool.new ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Page.new( memory_pool_settings_controller )
  it "can be created with a memory pool file settings controller" do
    RPbdb::Settings::MemoryPool::File::Page.new( RPbdb::Settings::MemoryPool::File.new ).should_not == nil
  end

  # RPbdb::Settings::MemoryPool::File::Page.new
  it "can be created with no argument specified" do
    RPbdb::Settings::MemoryPool::File::Page.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::MemoryPool::File::Page.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPbdb::Settings::MemoryPool::File::Page.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "can return its parent memory pool settings controller" do
    RPbdb::Settings::MemoryPool::File::Page.new.parent_memory_pool_settings_controller.should_not == nil
  end

  #################################################
  #  parent_memory_pool_file_settings_controller  #
  #################################################

  it "can return its parent memory pool file settings controller" do
    RPbdb::Settings::MemoryPool::File::Page.new.parent_memory_pool_file_settings_controller.should_not == nil
  end

  ######################################################
  #  get_page_creates_page_if_does_not_exist?          #
	#  turn_get_page_creates_page_if_does_not_exist_on   #
	#  turn_get_page_creates_page_if_does_not_exist_off  #
  ######################################################

  it "can be set so get page creates the given memory page if it does not already exist" do
    memory_page_settings  = RPbdb::Settings::MemoryPool::File::Page.new
    memory_page_settings.get_page_creates_page_if_does_not_exist?.should == false
    memory_page_settings.turn_get_page_creates_page_if_does_not_exist_on
    memory_page_settings.get_page_creates_page_if_does_not_exist?.should == true
    memory_page_settings.turn_get_page_creates_page_if_does_not_exist_off
    memory_page_settings.get_page_creates_page_if_does_not_exist?.should == false
  end

  ###################################################
  #  get_page_writes_copy_before_eviction?          #
	#  turn_get_page_writes_copy_before_eviction_on   #
	#  turn_get_page_writes_copy_before_eviction_off  #
  ###################################################

  it "can be set so get page writes a copy before eviction" do
    memory_page_settings  = RPbdb::Settings::MemoryPool::File::Page.new
    memory_page_settings.get_page_writes_copy_before_eviction?.should == false
    memory_page_settings.turn_get_page_writes_copy_before_eviction_on
    memory_page_settings.get_page_writes_copy_before_eviction?.should == true
    memory_page_settings.turn_get_page_writes_copy_before_eviction_off
    memory_page_settings.get_page_writes_copy_before_eviction?.should == false
  end

  ###########################################################
  #  get_page_writes_before_eviction_without_copy?          #
	#  turn_get_page_writes_before_eviction_without_copy_on   #
	#  turn_get_page_writes_before_eviction_without_copy_off  #
  ###########################################################

  it "can be set so get page writes before evicting pages without copying" do
    memory_page_settings  = RPbdb::Settings::MemoryPool::File::Page.new
    memory_page_settings.get_page_writes_before_eviction_without_copy?.should == false
    memory_page_settings.turn_get_page_writes_before_eviction_without_copy_on
    memory_page_settings.get_page_writes_before_eviction_without_copy?.should == true
    memory_page_settings.turn_get_page_writes_before_eviction_without_copy_off
    memory_page_settings.get_page_writes_before_eviction_without_copy?.should == false
  end

  #########################################
  #  get_page_returns_last_page?          #
	#  turn_get_page_returns_last_page_on   #
	#  turn_get_page_returns_last_page_off  #
  #########################################

  it "can be set so get page returns the last page" do
    memory_page_settings  = RPbdb::Settings::MemoryPool::File::Page.new
    memory_page_settings.get_page_returns_last_page?.should == false
    memory_page_settings.turn_get_page_returns_last_page_on
    memory_page_settings.get_page_returns_last_page?.should == true
    memory_page_settings.turn_get_page_returns_last_page_off
    memory_page_settings.get_page_returns_last_page?.should == false
  end

  ########################################
  #  get_page_creates_new_page?          #
	#  turn_get_page_creates_new_page_on   #
	#  turn_get_page_creates_new_page_off  #
  ########################################

  it "can be set so get page creates a new page" do
    memory_page_settings  = RPbdb::Settings::MemoryPool::File::Page.new
    memory_page_settings.get_page_creates_new_page?.should == false
    memory_page_settings.turn_get_page_creates_new_page_on
    memory_page_settings.get_page_creates_new_page?.should == true
    memory_page_settings.turn_get_page_creates_new_page_off
    memory_page_settings.get_page_creates_new_page?.should == false
  end

end

