require_relative '../../../lib/rpbdb.rb'

describe RPbdb::Environment do

  $environment_path             = '/tmp/rpbdb_spec_environment_home/'
  
  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPbdb::Environment.new( './directory' )
  # RPbdb::Environment.new
  
  it "can be created with home directory string" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.should_not == nil
    environment.is_a?.should == RPbdb::Environment
    environment.directory.should == $environment_path
  end

  it "can be created with no arguments" do
    environment = RPbdb::Environment.new
    environment.should_not == nil
    environment.is_a?.should == RPbdb::Environment
    # environment without directory specified will be created in ./
    # this environment will be deleted by the :erase test
    environment.directory.should == './'
  end

  ################################
  #  init_for_storage_in_memory  #
  ################################

  # environment.init_for_storage_in_memory

  it "can be initialized for storage in memory" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.init_for_storage_in_memory
    
    # now we have to check settings to verify
    
    # make sure app-exclusive memory access is on
    environment.settings.memory_pool.read_write.exclusive_access?.should == true
    # make sure backing file is off (no flushing from memory)
    environment.settings.memory_pool.read_write.no_temporary_backing_file?.should == true
    # make sure logging in memory is on or logging as a whole is off
    if environment.settings.logging.in_memory? == false
      environment.settings.logging.off?.should == true
    else
      environment.settings.logging.in_memory?.should == true
    end
  end

  ##########################
  #  identify_for_rpbdb_as  #
  ##########################

  # environment.identify_for_rpbdb_as
  
  it "can identify as any number or type of arbitrary objects" do
    environment  = RPbdb::Environment.new( $environment_path )
    identifiers   = [ :a_symbol, 
                      'a_string', 
                      :another_symbol, 
                      'another_string', 
                      self, 
                      environment, 
                      RPbdb::Environment, 
                      [ 'an_array' ], 
                      { :a_hash => 'with an item' } ]
    environment.identify_for_rpbdb_as( *identifiers )
    environment.identifiers.should == identifiers  
  end

  ##########
  #  open  #
  ##########

  it "can open" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.is_open?.should == false
    environment.open
    environment.is_open?.should == true
    environment.close
  end

  ###########
  #  close  #
  ###########

  it "can close" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.open
    environment.is_open?.should == true
    environment.close
    environment.is_open?.should == false    
  end

  ############
  #  erase!  #
  ############

  it "can erase itself" do
    # create an environment
    environment = RPbdb::Environment.new
    # won't create files until it's opened
    environment.open
    environment.erase!
  end
  
  ####################
  #  home_directory  #
  #  directory       #
  ####################
  
  it "can report its directory" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.directory.should == $environment_path
    environment.home_directory.should == $environment_path
  end
  
  #########################
  #  database_controller  #
  #########################

  # environment.database_controller

  it "has a database controller" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.open
    database_controller = environment.database_controller
    database_controller.should_not == nil
    database_controller.is_a?.should == RPbdb::Database::Controller
    environment.close
  end

  ############################
  #  transaction_controller  #
  ############################

  # environment.transaction_controller

  it "has a transaction controller" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.open
    transaction_controller = environment.transaction_controller
    transaction_controller.should_not == nil
    transaction_controller.is_a?.should == RPbdb::TransactionController
    environment.close
  end

  #########################
  #  settings_controller  #
  #########################

  # environment.settings_controller
  
  it "has a settings controller" do
    environment = RPbdb::Environment.new( $environment_path )
    environment.open
    settings_controller = environment.settings_controller
    settings_controller.should_not == nil
    # settings controller has two names - primary class name
    settings_controller.is_a?.should == RPbdb::Settings
    # convenience name
    settings_controller.is_a?.should == RPbdb::Settings
    environment.close
  end

  ################
  #  self.using  #
  ################

  it "can be used in a block form" do
    RPbdb::Environment.use( $environment_path ) do

    end
  end

end
