require_relative '../../../lib/rpbdb.rb'

describe RPbdb::Settings::Cache do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPbdb::Settings::Cache.new( environment )
  it "can be created with an environment" do
    @environment.open
    RPbdb::Settings::Cache.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Cache.new( settings_controller )
  it "can be created with a settings controller" do
    @environment.open
    RPbdb::Settings::Cache.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Cache.new
  it "can be created with no argument specified" do
    @environment.open
    RPbdb::Settings::Cache.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    @environment.open
    RPbdb::Settings::Cache.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    @environment.open
    RPbdb::Settings::Cache.new.parent_settings_controller.should_not == nil
  end

  ########################
  #  buffering?          #
	#  turn_buffering_on   #
	#  turn_buffering_off  #
  ########################

  it "can turn buffering on and off" do
    @environment.open
    cache_settings  = RPbdb::Settings::Cache.new
    cache_settings.buffering?.should == false
    cache_settings.turn_buffering_on
    cache_settings.buffering?.should == true
    cache_settings.turn_buffering_off
    cache_settings.buffering?.should == false
  end

  ################################################
  #  set_max_size_in_bytes                       #
	#  set_max_size_in_kbytes                      #
	#  set_max_size_in_mbytes                      #
	#  set_max_size_in_gbytes                      #
	#  set_max_size_in_gbytes_mbytes_kbytes_bytes  #
	#  set_max_size_in_mbytes_kbytes_bytes         #
	#  set_max_size_in_kbytes_bytes                #
  #  max_size_in_bytes                           #
	#  max_size_in_kbytes                          #
	#  max_size_in_mbytes                          #
	#  max_size_in_gbytes                          #
  ################################################

  it "can set its cache size according to various measures" do

    cache_settings = RPbdb::Settings::Cache.new( @environment )

    cache_settings.set_max_size_in_gbytes( 420 )
    cache_settings.max_size_in_gbytes.should == 420

    cache_settings.set_max_size_in_gbytes_mbytes_kbytes_bytes( 420, 37, 42, 12 )
    cache_settings.max_size_in_bytes.should == ( 420 * ( 1024 * 1024 * 1024 ) ) + ( 37 * ( 1024 * 1024 ) ) + ( 42 * 1024 ) + 12

    cache_settings.set_max_size_in_mbytes_kbytes_bytes( 37, 42, 12 )
    cache_settings.max_size_in_bytes.should == ( 37 * ( 1024 * 1024 ) ) + ( 42 * 1024 ) + 12

    cache_settings.set_max_size_in_kbytes_bytes( 42, 12 )
    cache_settings.max_size_in_bytes.should == ( 42 * 1024 ) + 12
    
  end

end

