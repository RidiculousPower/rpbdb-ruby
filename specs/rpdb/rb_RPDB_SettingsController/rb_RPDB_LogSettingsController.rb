require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Lock do

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

  # RPDB::Environment::Settings::Lock.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Lock.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Lock.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Lock.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Lock.new.should_not == nil
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

  	#############
  	#  turn_on  #
  	#############

    it "" do
      Fail
    end

  ##########
  #  off?  #
  ##########

  it "" do
    Fail
  end

  	##############
  	#  turn_off  #
  	##############

    it "" do
      Fail
    end

  ###############
  #  buffering  #
  ###############

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

  ####################################
  #  flush_before_return_from_write  #
  ####################################

  it "" do
    Fail
  end

  	############################################
  	#  turn_flush_before_return_from_write_on  #
  	############################################

    it "" do
      Fail
    end

  	#############################################
  	#  turn_flush_before_return_from_write_off  #
  	#############################################

    it "" do
      Fail
    end

  #####################
  #  autoremove_logs  #
  #####################

  it "" do
    Fail
  end

  	########################
  	#  turn_autoremove_on  #
  	########################

    it "" do
      Fail
    end

  	#########################
  	#  turn_autoremove_off  #
  	#########################

    it "" do
      Fail
    end

  ###################
  #  log_in_memory  #
  ###################

  it "" do
    Fail
  end

  	###########################
  	#  turn_log_in_memory_on  #
  	###########################

    it "" do
      Fail
    end

  	############################
  	#  turn_log_in_memory_off  #
  	############################

    it "" do
      Fail
    end

  #######################
  #  zero_at_creation?  #
  #######################

  it "" do
    Fail
  end

  	##############################
  	#  turn_zero_at_creation_on  #
  	##############################

    it "" do
      Fail
    end

  	###############################
  	#  turn_zero_at_creation_off  #
  	###############################

    it "" do
      Fail
    end

  #####################################
  #  force_flush_after_record_write?  #
  #####################################

  it "" do
    Fail
  end

  	############################################
  	#  turn_force_flush_after_record_write_on  #
  	############################################

    it "" do
      Fail
    end

  	#############################################
  	#  turn_force_flush_after_record_write_off  #
  	#############################################

    it "" do
      Fail
    end

  #################
  #  buffer_size  #
  #################

  it "" do
    Fail
  end

  	#####################
  	#  set_buffer_size  #
  	#####################

    it "" do
      Fail
    end

  ###############
  #  directory  #
  ###############

  it "" do
    Fail
  end

  	###################
  	#  set_directory  #
  	###################

    it "" do
      Fail
    end

  ##########
  #  mode  #
  ##########

  it "" do
    Fail
  end

  	##############
  	#  set_mode  #
  	##############

    it "" do
      Fail
    end

  ##################
  #  max_log_size  #
  ##################

  it "" do
    Fail
  end

  	######################
  	#  set_max_log_size  #
  	######################

    it "" do
      Fail
    end

  #####################
  #  max_region_size  #
  #####################

  it "" do
    Fail
  end

  	#########################
  	#  set_max_region_size  #
  	#########################

    it "" do
      Fail
    end

end

