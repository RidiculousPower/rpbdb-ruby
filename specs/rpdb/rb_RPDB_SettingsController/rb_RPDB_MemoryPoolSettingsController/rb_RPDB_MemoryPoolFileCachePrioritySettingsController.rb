require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::MemoryPool::File::Cache::Priority do

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

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( @environment ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_settings_controller )
  it "can be created with a memory pool settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings::MemoryPool.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_file_settings_controller )
  it "can be created with a memory pool file settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings::MemoryPool::File.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new( memory_pool_file_cache_settings_controller )
  it "can be created with a memory pool file cache settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new( RPDB::Settings::MemoryPool::File::Cache.new ).should_not == nil
  end

  # RPDB::Settings::MemoryPool::File::Cache::Priority.new
  it "can be created with no argument specified" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_memory_pool_settings_controller  #
  ############################################

  it "can return its parent memory pool settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_memory_pool_settings_controller.should_not == nil
  end

  #################################################
  #  parent_memory_pool_file_settings_controller  #
  #################################################

  it "can return its parent memory pool file settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_memory_pool_file_settings_controller.should_not == nil
  end

  #######################################################
  #  parent_memory_pool_file_cache_settings_controller  #
  #######################################################

  it "can return its parent memory pool file cache settings controller" do
    RPDB::Settings::MemoryPool::File::Cache::Priority.new.parent_memory_pool_file_cache_settings_controller.should_not == nil
  end

  ######################
	#  set_very_low      #
	#  set_low           #
	#  set_default       #
	#  set_high          #
	#  set_very_high     #
  #  very_low?         #
  #  low?              #
  #  default?          #
  #  high?             #
  #  very_high?        #
  #  current_priority  #
  ######################

  it "can set priority and report whether a priority level is currently set as well as report its current priority" do
    priority_settings_controller  = RPDB::Settings::MemoryPool::File::Cache::Priority.new
    priority_settings_controller.current_priority.should == 0
    priority_settings_controller.set_very_low
    priority_settings_controller.very_low?.should == true
    priority_settings_controller.set_low
    priority_settings_controller.low?.should == true
    priority_settings_controller.set_default
    priority_settings_controller.default?.should == true
    priority_settings_controller.set_high
    priority_settings_controller.high?.should == true
    priority_settings_controller.set_very_high
    priority_settings_controller.very_high?.should == true
  end

  #########################
  #  at_least_very_low?   #
  #  at_most_very_low?    #
  #  at_least_low?        #
  #  at_most_low?         #
  #  at_least_default?    #
  #  at_most_default?     #
  #  at_least_high?       #
  #  at_most_high?        #
  #  at_least_very_high?  #
  #  at_most_very_high?   #
  #########################

  it "can report on relative priority levels" do
    priority_settings_controller  = RPDB::Settings::MemoryPool::File::Cache::Priority.new
    priority_settings_controller.set_very_low
    priority_settings_controller.at_least_very_low?.should == true
    priority_settings_controller.at_most_very_low?.should == true
    priority_settings_controller.at_least_low?.should == false
    priority_settings_controller.at_most_low?.should == true
    priority_settings_controller.at_least_default?.should == false
    priority_settings_controller.at_most_default?.should == true
    priority_settings_controller.at_least_high?.should == false
    priority_settings_controller.at_most_high?.should == true
    priority_settings_controller.at_least_very_high?.should == false
    priority_settings_controller.at_most_very_high?.should == true

    priority_settings_controller.set_low
    priority_settings_controller.at_least_very_low?.should == true
    priority_settings_controller.at_most_very_low?.should == false
    priority_settings_controller.at_least_low?.should == true
    priority_settings_controller.at_most_low?.should == true
    priority_settings_controller.at_least_default?.should == false
    priority_settings_controller.at_most_default?.should == true
    priority_settings_controller.at_least_high?.should == false
    priority_settings_controller.at_most_high?.should == true
    priority_settings_controller.at_least_very_high?.should == false
    priority_settings_controller.at_most_very_high?.should == true

    priority_settings_controller.set_default
    priority_settings_controller.at_least_very_low?.should == true
    priority_settings_controller.at_most_very_low?.should == false
    priority_settings_controller.at_least_low?.should == true
    priority_settings_controller.at_most_low?.should == false
    priority_settings_controller.at_least_default?.should == true
    priority_settings_controller.at_most_default?.should == true
    priority_settings_controller.at_least_high?.should == false
    priority_settings_controller.at_most_high?.should == true
    priority_settings_controller.at_least_very_high?.should == false
    priority_settings_controller.at_most_very_high?.should == true

    priority_settings_controller.set_high
    priority_settings_controller.at_least_very_low?.should == true
    priority_settings_controller.at_most_very_low?.should == false
    priority_settings_controller.at_least_low?.should == true
    priority_settings_controller.at_most_low?.should == false
    priority_settings_controller.at_least_default?.should == true
    priority_settings_controller.at_most_default?.should == false
    priority_settings_controller.at_least_high?.should == true
    priority_settings_controller.at_most_high?.should == true
    priority_settings_controller.at_least_very_high?.should == false
    priority_settings_controller.at_most_very_high?.should == true

    priority_settings_controller.set_very_high
    priority_settings_controller.at_least_very_low?.should == true
    priority_settings_controller.at_most_very_low?.should == false
    priority_settings_controller.at_least_low?.should == true
    priority_settings_controller.at_most_low?.should == false
    priority_settings_controller.at_least_default?.should == true
    priority_settings_controller.at_most_default?.should == false
    priority_settings_controller.at_least_high?.should == true
    priority_settings_controller.at_most_high?.should == false
    priority_settings_controller.at_least_very_high?.should == true
    priority_settings_controller.at_most_very_high?.should == true

  end

end

