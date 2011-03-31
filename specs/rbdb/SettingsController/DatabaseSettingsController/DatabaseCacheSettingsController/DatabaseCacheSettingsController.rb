require_relative '../../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database::Cache do

  # Database cache is only relevant when a database is opened without an environment

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPbdb::Settings::Database::Cache.new
  it "can be created with no argument specified and no current working environment" do
    RPbdb::Settings::Database::Cache.new.should_not == nil
  end

  # RPbdb::Settings::Database::Cache.new( database_settings_controller )
  it "can be created with a current working environment (of which the database is not part) by passing false" do
    RPbdb::Settings::Database::Cache.new( RPbdb::Settings::Database.new ).should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::Database::Cache.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPbdb::Settings::Database::Cache.new( RPbdb::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPbdb::Settings::Database::Cache.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPbdb::Settings::Database::Cache.new.parent_database_settings_controller.should_not == nil
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
    database_cache_settings = RPbdb::Settings::Database::Cache.new( RPbdb::Database( $database_name ) )

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

  ##############################
  #  set_number_cache_regions  #
  #  number_cache_regions      #
  ##############################

  it "can specify how many regions to divide cache into" do
    database_cache_settings = RPbdb::Settings::Database::Cache.new( RPbdb::Database( $database_name ) )
    database_cache_settings.set_number_cache_regions( 12 )
    database_cache_settings.number_cache_regions.should == 12
  end

  #########################
  #  priority_controller  #
  #########################

  it "can return its priority controller" do
    RPbdb::Settings::Database::Cache.new.priority_controller.is_a?( RPbdb::Settings::Database::Cache::Priority ).should == true
  end

end

