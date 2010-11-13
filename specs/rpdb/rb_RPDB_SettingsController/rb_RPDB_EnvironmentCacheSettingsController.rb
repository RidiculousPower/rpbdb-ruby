require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings::Cache do

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

  # RPDB::Settings::Cache.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Cache.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Cache.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Cache.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Cache.new
  it "can be created with no argument specified" do
    RPDB::Settings::Cache.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Cache.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Cache.new.parent_settings_controller.should_not == nil
  end

  ########################
  #  buffering?          #
	#  turn_buffering_on   #
	#  turn_buffering_off  #
  ########################

  it "can turn buffering on and off" do
    raise "Failed."
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
    database_cache_settings = RPDB::Settings::Cache.new

    database_cache_settings.set_max_size_in_bytes( 12 )
    database_cache_settings.max_size_in_bytes.should == 12

    database_cache_settings.set_max_size_in_kbytes( 42 )
    database_cache_settings.max_size_in_kbytes.should == 42 * 1024

    database_cache_settings.set_max_size_in_mbytes( 37 )
    database_cache_settings.max_size_in_mbytes.should == 37 * ( 1024 * 1024 )

    database_cache_settings.set_max_size_in_gbytes( 420 )
    database_cache_settings.max_size_in_gbytes.should == 420 * ( 1024 * 1024 * 1024 )

    database_cache_settings.set_max_size_in_gbytes_mbytes_kbytes_bytes( 420, 37, 42, 12 )
    database_cache_settings.max_size_in_bytes.should == 420 * ( 1024 * 1024 * 1024 ) + 37 * ( 1024 * 1024 ) + 42 * 1024 + 12

    database_cache_settings.set_max_size_in_mbytes_kbytes_bytes( 37, 42, 12 )
    database_cache_settings.max_size_in_bytes.should == 37 * ( 1024 * 1024 )

    database_cache_settings.set_max_size_in_kbytes_bytes( 42, 12 )
    database_cache_settings.max_size_in_bytes.should == 42 * 1024 + 12
    
  end

end

