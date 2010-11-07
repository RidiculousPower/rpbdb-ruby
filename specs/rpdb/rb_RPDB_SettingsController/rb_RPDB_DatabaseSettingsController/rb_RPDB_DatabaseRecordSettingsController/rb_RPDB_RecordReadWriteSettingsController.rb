require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Record::ReadWrite do

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

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Record::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Record::ReadWrite.new.should_not == nil
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

  #####################
  #  parent_database  #
  #####################

  it "" do
    Fail
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "" do
    Fail
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "" do
    Fail
  end

  ################################################
  #  parent_database_record_settings_controller  #
  ################################################

  it "" do
    Fail
  end

  ##############
  #  filename  #
  ##############

  it "" do
    Fail
  end

  ##################
  #  set_filename  #
  ##################

  it "" do
    Fail
  end

  ############################
  #  prohibit_sync_on_close  #
  ############################

  it "" do
    Fail
  end

  	####################################
  	#  turn_prohibit_sync_on_close_on  #
  	####################################

    it "" do
      Fail
    end

  	#####################################
  	#  turn_prohibit_sync_on_close_off  #
  	#####################################

    it "" do
      Fail
    end

  ##################
  #  ignore_lease  #
  ##################

  it "" do
    Fail
  end

  	##########################
  	#  turn_ignore_lease_on  #
  	##########################

    it "" do
      Fail
    end

  	###########################
  	#  turn_ignore_lease_off  #
  	###########################

    it "" do
      Fail
    end

  #####################
  #  return_multiple  #
  #####################

  it "" do
    Fail
  end

  	###############################
  	#  turn_return_multiple_on  #
  	###############################

    it "" do
      Fail
    end

  	##############################
  	#  turn_return_multiple_off  #
  	##############################

    it "" do
      Fail
    end

  #############################
  #  prohibit_duplicate_data  #
  #############################

  it "" do
    Fail
  end

  	#####################################
  	#  turn_prohibit_duplicate_data_on  #
  	#####################################

    it "" do
      Fail
    end

  	######################################
  	#  turn_prohibit_duplicate_data_off  #
  	######################################

    it "" do
      Fail
    end

  ########################
  #  prohibit_overwrite  #
  ########################

  it "" do
    Fail
  end

  	################################
  	#  turn_prohibit_overwrite_on  #
  	################################

    it "" do
      Fail
    end

  	#################################
  	#  turn_prohibit_overwrite_off  #
  	#################################

    it "" do
      Fail
    end

  ##############################
  #  prohibit_page_compaction  #
  ##############################

  it "" do
    Fail
  end

  	######################################
  	#  turn_prohibit_page_compaction_on  #
  	######################################

    it "" do
      Fail
    end

  	#######################################
  	#  turn_prohibit_page_compaction_off  #
  	#######################################

    it "" do
      Fail
    end

  ################################
  #  return_pages_to_filesystem  #
  ################################

  it "" do
    Fail
  end

  	########################################
  	#  turn_return_pages_to_filesystem_on  #
  	########################################

    it "" do
      Fail
    end

  	#########################################
  	#  turn_return_pages_to_filesystem_off  #
  	#########################################

    it "" do
      Fail
    end

  ###########################
  #  truncate_file_on_open  #
  ###########################

  it "" do
    Fail
  end

  	###################################
  	#  turn_truncate_file_on_open_on  #
  	###################################

    it "" do
      Fail
    end

  	####################################
  	#  turn_truncate_file_on_open_off  #
  	####################################

    it "" do
      Fail
    end

  #######################################
  #  write_locks_instead_of_read_locks  #
  #######################################

  it "" do
    Fail
  end

  	###############################################
  	#  turn_write_locks_instead_of_read_locks_on  #
  	###############################################

    it "" do
      Fail
    end

  	################################################
  	#  turn_write_locks_instead_of_read_locks_off  #
  	################################################

    it "" do
      Fail
    end

  ####################
  #  partial_access  #
  ####################

  it "" do
    Fail
  end

  	############################
  	#  turn_partial_access_on  #
  	############################

    it "" do
      Fail
    end

  	#############################
  	#  turn_partial_access_off  #
  	#############################

    it "" do
      Fail
    end

  ############################################
  #  database_allocates_memory_using_malloc  #
  ############################################

  it "" do
    Fail
  end

  	####################################################
  	#  turn_database_allocates_memory_using_malloc_on  #
  	####################################################

    it "" do
      Fail
    end

  	#####################################################
  	#  turn_database_allocates_memory_using_malloc_off  #
  	#####################################################

    it "" do
      Fail
    end

  #############################################
  #  database_allocates_memory_using_realloc  #
  #############################################

  it "" do
    Fail
  end

  	#####################################################
  	#  turn_database_allocates_memory_using_realloc_on  #
  	#####################################################

    it "" do
      Fail
    end

  	######################################################
  	#  turn_database_allocates_memory_using_realloc_off  #
  	######################################################

    it "" do
      Fail
    end

  ##################################
  #  application_allocates_memory  #
  ##################################

  it "" do
    Fail
  end

  	##########################################
  	#  turn_application_allocates_memory_on  #
  	##########################################

    it "" do
      Fail
    end

  	###########################################
  	#  turn_application_allocates_memory_off  #
  	###########################################

    it "" do
      Fail
    end

  ###########################
  #  database_frees_memory  #
  ###########################

  it "" do
    Fail
  end

  	###################################
  	#  turn_database_frees_memory_on  #
  	###################################

    it "" do
      Fail
    end

  	####################################
  	#  turn_database_frees_memory_off  #
  	####################################

    it "" do
      Fail
    end

  ################################
  #  sync_prior_to_write_return  #
  ################################

  it "" do
    Fail
  end

  	########################################
  	#  turn_sync_prior_to_write_return_on  #
  	########################################

    it "" do
      Fail
    end

  	#########################################
  	#  turn_sync_prior_to_write_return_off  #
  	#########################################

    it "" do
      Fail
    end

  ######################
  #  data_buffer_size  #
  ######################

  it "" do
    Fail
  end

  ##########################
  #  set_data_buffer_size  #
  ##########################

  it "" do
    Fail
  end

  #############################
  #  partial_read_write_size  #
  #############################

  it "" do
    Fail
  end

  #################################
  #  set_partial_read_write_size  #
  #################################

  it "" do
    Fail
  end

  ##############################
  #  partial_read_write_offset  #
  ##############################

  it "" do
    Fail
  end

  ###################################
  #  set_partial_read_write_offset  #
  ###################################

  it "" do
    Fail
  end

  #######################
  #  permit_duplicates  #
  #######################

  it "" do
    Fail
  end

  	################################
  	 #  turn_permit_duplicates_on  #
  	 ###############################

     it "" do
       Fail
     end

  	#################################
  	 #  turn_permit_duplicates_off  #
  	 ################################

     it "" do
       Fail
     end

  #####################
  #  sort_duplicates  #
  #####################

  it "" do
    Fail
  end

  	##############################
  	 #  turn_sort_duplicates_on  #
  	 #############################

     it "" do
       Fail
     end

  	###############################
  	 #  turn_sort_duplicates_off  #
  	 ##############################

     it "" do
       Fail
     end

  ####################
  #  serialize_data  #
  ####################

  it "" do
    Fail
  end

  	#############################
  	 #  turn_serialize_data_on  #
  	 ############################

     it "" do
       Fail
     end

  	##############################
  	 #  turn_serialize_data_off  #
  	 #############################

     it "" do
       Fail
     end

  ##################
  #  storage_type  #
  ##################

  it "" do
    Fail
  end

  ######################
  #  set_storage_type  #
  ######################

  it "" do
    Fail
  end

end

