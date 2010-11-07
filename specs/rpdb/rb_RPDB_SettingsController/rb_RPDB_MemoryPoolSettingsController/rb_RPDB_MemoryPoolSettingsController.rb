require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::MemoryPool do

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

  # RPDB::Environment::Settings::MemoryPool.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::MemoryPool.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::MemoryPool.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::MemoryPool.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::MemoryPool.new.should_not == nil
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

  #########
  #  on?  #
  #########

  it "" do
    Fail
  end

  ##########
  #  off?  #
  ##########

  it "" do
    Fail
  end

  	#############
  	#  turn_on  #
  	#############

    it "" do
      Fail
    end

  	##############
  	#  turn_off  #
  	##############

    it "" do
      Fail
    end

  ####################
  #  memory_mapping  #
  ####################

  it "" do
    Fail
  end

  	############################
  	#  turn_memory_mapping_on  #
  	############################

    it "" do
      Fail
    end

  	#############################
  	#  turn_memory_mapping_off  #
  	#############################

    it "" do
      Fail
    end

  #####################################
  #  remove_file_with_last_reference  #
  #####################################

  it "" do
    Fail
  end

  	#############################################
  	#  turn_remove_file_with_last_reference_on  #
  	#############################################

    it "" do
      Fail
    end

  	##############################################
  	#  turn_remove_file_with_last_reference_off  #
  	##############################################

    it "" do
      Fail
    end

  ##########################################
  #  pagesize_factor_mismatch_should_fail  #
  ##########################################

  it "" do
    Fail
  end

  	##################################################
  	#  turn_pagesize_factor_mismatch_should_fail_on  #
  	##################################################

    it "" do
      Fail
    end

  	###################################################
  	#  turn_pagesize_factor_mismatch_should_fail_off  #
  	###################################################

    it "" do
      Fail
    end

  ##############################
  #  file_settings_controller  #
  ##############################

  it "" do
    Fail
  end

  ####################################
  #  read_write_settings_controller  #
  ####################################

  it "" do
    Fail
  end

end

