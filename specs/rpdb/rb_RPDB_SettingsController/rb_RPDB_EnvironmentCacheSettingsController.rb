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

  ################
  #  buffering?  #
  ################

  it "" do
    Fail
  end

  	#######################
  	#  turn_buffering_on  #
  	#######################

    it "" do
      Fail
    end

  	########################
  	#  turn_buffering_off  #
  	########################

    it "" do
      Fail
    end

  #######################
  #  max_size_in_bytes  #
  #######################

  it "" do
    Fail
  end

  ########################
  #  max_size_in_kbytes  #
  ########################

  it "" do
    Fail
  end

  ########################
  #  max_size_in_mbytes  #
  ########################

  it "" do
    Fail
  end

  ########################
  #  max_size_in_gbytes  #
  ########################

  it "" do
    Fail
  end

  	###########################
  	#  set_max_size_in_bytes  #
  	###########################

    it "" do
      Fail
    end

  	############################
  	#  set_max_size_in_kbytes  #
  	############################

    it "" do
      Fail
    end

  	############################
  	#  set_max_size_in_mbytes  #
  	############################

    it "" do
      Fail
    end

  	############################
  	#  set_max_size_in_gbytes  #
  	############################

    it "" do
      Fail
    end

  	################################################
  	#  set_max_size_in_gbytes_mbytes_kbytes_bytes  #
  	################################################

    it "" do
      Fail
    end

  	#########################################
  	#  set_max_size_in_mbytes_kbytes_bytes  #
  	#########################################

    it "" do
      Fail
    end

  	##################################
  	#  set_max_size_in_kbytes_bytes  #
  	##################################

    it "" do
      Fail
    end

end

