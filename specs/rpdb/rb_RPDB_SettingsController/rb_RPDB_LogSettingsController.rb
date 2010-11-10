require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings::Lock do

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

  # RPDB::Settings::Lock.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Lock.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Lock.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Lock.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Lock.new
  it "can be created with no argument specified" do
    RPDB::Settings::Lock.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Log.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Log.new.parent_settings_controller.should_not == nil
  end

  #########
  #  on?  #
  #########

  it "" do
    raise "Failed."
  end

  	#############
  	#  turn_on  #
  	#############

    it "" do
      raise "Failed."
    end

  ##########
  #  off?  #
  ##########

  it "" do
    raise "Failed."
  end

  	##############
  	#  turn_off  #
  	##############

    it "" do
      raise "Failed."
    end

  ###############
  #  buffering  #
  ###############

  it "" do
    raise "Failed."
  end

  	#######################
  	#  turn_buffering_on  #
  	#######################

    it "" do
      raise "Failed."
    end

  	########################
  	#  turn_buffering_off  #
  	########################

    it "" do
      raise "Failed."
    end

  ####################################
  #  flush_before_return_from_write  #
  ####################################

  it "" do
    raise "Failed."
  end

  	############################################
  	#  turn_flush_before_return_from_write_on  #
  	############################################

    it "" do
      raise "Failed."
    end

  	#############################################
  	#  turn_flush_before_return_from_write_off  #
  	#############################################

    it "" do
      raise "Failed."
    end

  #####################
  #  autoremove_logs  #
  #####################

  it "" do
    raise "Failed."
  end

  	########################
  	#  turn_autoremove_on  #
  	########################

    it "" do
      raise "Failed."
    end

  	#########################
  	#  turn_autoremove_off  #
  	#########################

    it "" do
      raise "Failed."
    end

  ###################
  #  log_in_memory  #
  ###################

  it "" do
    raise "Failed."
  end

  	###########################
  	#  turn_log_in_memory_on  #
  	###########################

    it "" do
      raise "Failed."
    end

  	############################
  	#  turn_log_in_memory_off  #
  	############################

    it "" do
      raise "Failed."
    end

  #######################
  #  zero_at_creation?  #
  #######################

  it "" do
    raise "Failed."
  end

  	##############################
  	#  turn_zero_at_creation_on  #
  	##############################

    it "" do
      raise "Failed."
    end

  	###############################
  	#  turn_zero_at_creation_off  #
  	###############################

    it "" do
      raise "Failed."
    end

  #####################################
  #  force_flush_after_record_write?  #
  #####################################

  it "" do
    raise "Failed."
  end

  	############################################
  	#  turn_force_flush_after_record_write_on  #
  	############################################

    it "" do
      raise "Failed."
    end

  	#############################################
  	#  turn_force_flush_after_record_write_off  #
  	#############################################

    it "" do
      raise "Failed."
    end

  #################
  #  buffer_size  #
  #################

  it "" do
    raise "Failed."
  end

  	#####################
  	#  set_buffer_size  #
  	#####################

    it "" do
      raise "Failed."
    end

  ###############
  #  directory  #
  ###############

  it "" do
    raise "Failed."
  end

  	###################
  	#  set_directory  #
  	###################

    it "" do
      raise "Failed."
    end

  ##########
  #  mode  #
  ##########

  it "" do
    raise "Failed."
  end

  	##############
  	#  set_mode  #
  	##############

    it "" do
      raise "Failed."
    end

  ##################
  #  max_log_size  #
  ##################

  it "" do
    raise "Failed."
  end

  	######################
  	#  set_max_log_size  #
  	######################

    it "" do
      raise "Failed."
    end

  #####################
  #  max_region_size  #
  #####################

  it "" do
    raise "Failed."
  end

  	#########################
  	#  set_max_region_size  #
  	#########################

    it "" do
      raise "Failed."
    end

end

