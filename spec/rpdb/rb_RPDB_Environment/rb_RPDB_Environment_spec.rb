require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpdb_spec_environment_home'

#  after( :each ) do
#    environment = nil
#  end
  
  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Environment.new( :name, './directory' )
  # RPDB::Environment.new( 'name', './directory' )
  # RPDB::Environment.new( :name )
  # RPDB::Environment.new( 'name' )
  # RPDB::Environment.new( './directory' )
  # RPDB::Environment.new
  
  it "can be created with a name symbol and home directory string" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.should_not == nil
    environment.is_a?( RPDB::Environment ).should == true
    environment.directory.should == $environment_path
  end
  
  it "can be created with a name string and home directory string" do
    environment = RPDB::Environment.new( $environment_name.to_s, $environment_path )
    environment.should_not == nil
    environment.is_a?( RPDB::Environment ).should == true
    environment.directory.should == $environment_path
  end

  # environment without directory specified will be created in ./
  # this environment will be deleted by the :erase test

  it "can be created with a name symbol" do
    environment = RPDB::Environment.new( $environment_name )
    environment.should_not == nil
    environment.is_a?( RPDB::Environment ).should == true
    environment.directory.should == './'
  end

  it "can be created with a name string" do
    environment = RPDB::Environment.new( $environment_name.to_s )
    environment.should_not == nil
    environment.is_a?( RPDB::Environment ).should == true
    environment.directory.should == './'
  end

  it "can be created with home directory string" do
    environment = RPDB::Environment.new( $environment_path )
    environment.should_not == nil
    environment.is_a?( RPDB::Environment ).should == true
    environment.directory.should == $environment_path
  end

  it "can be created with no arguments" do
    environment = RPDB::Environment.new
    environment.should_not == nil
    environment.is_a?( RPDB::Environment ).should == true
    environment.directory.should == './'
  end

  ################################
  #  init_for_storage_in_memory  #
  ################################

  # environment.init_for_storage_in_memory

  it "can be initialized for storage in memory" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.init_for_storage_in_memory
    
    # now we have to check settings to verify
    
    # make sure app-exclusive memory access is on
    environment.settings.memory_pool.exclusive_access?.should == true
    # make sure backing file is off (no flushing from memory)
    environment.settings.memory_pool.no_temporary_backing_file?.should == true
    # make sure logging in memory is on or logging as a whole is off
    if environment.settings.logging.in_memory? == false
      environment.settings.logging.off?.should == true
    else
      environment.settings.logging.in_memory?.should == true
    end
  end

  ##########################
  #  identify_for_rpdb_as  #
  ##########################

  # environment.identify_for_rpdb_as
  
  it "can identify as any number or type of arbitrary objects" do
    environment  = RPDB::Environment.new( $environment_name, $environment_path )
    identifiers   = [ :a_symbol, 
                      'a_string', 
                      :another_symbol, 
                      'another_string', 
                      self, 
                      environment, 
                      RPDB::Environment, 
                      [ 'an_array' ], 
                      { :a_hash => 'with an item' } ]
    environment.identify_for_rpdb_as( *identifiers )
    environment.identifiers.should == identifiers  
  end

  ##########
  #  open  #
  ##########

  # environment.open

  it "can open" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.is_open?.should == false
    environment.open
    environment.is_open?.should == true
    environment.close
  end

  ###########
  #  close  #
  ###########

  # environment.close

  it "can close" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.open
    environment.is_open?.should == true
    environment.close
    environment.is_open?.should == false    
  end

  ##########
  #  name  #
  ##########

  # environment.name
  
  it "can report its name" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.name.should_not == nil
  end

  ###########
  #  erase  #
  ###########

  # environment.erase

  it "can erase itself" do
    # create an environment
    environment = RPDB::Environment.new
    # won't create files until it's opened
    environment.open
    environment.erase
  end
  
  #########################
  #  database_controller  #
  #########################

  # environment.database_controller

  it "has a database controller" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.open
    database_controller = environment.database_controller
    database_controller.should_not == nil
    database_controller.is_a?( RPDB::Environment::DatabaseController ).should == true
    environment.close
  end

  ############################
  #  transaction_controller  #
  ############################

  # environment.transaction_controller

  it "has a transaction controller" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.open
    transaction_controller = environment.transaction_controller
    transaction_controller.should_not == nil
    transaction_controller.is_a?( RPDB::Environment::TransactionController ).should == true
    environment.close
  end

  #########################
  #  settings_controller  #
  #########################

  # environment.settings_controller
  
  it "has a settings controller" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    environment.open
    settings_controller = environment.settings_controller
    settings_controller.should_not == nil
    # settings controller has two names - primary class name
    settings_controller.is_a?( RPDB::Environment::SettingsController ).should == true
    # convenience name
    settings_controller.is_a?( RPDB::Environment::Settings ).should == true
    environment.close
  end

end
