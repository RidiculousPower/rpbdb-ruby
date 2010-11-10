require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Record::ReadWrite do

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

  # RPDB::Settings::Database::Record::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Record::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Record::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Record::ReadWrite.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Record::ReadWrite.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Record::ReadWrite.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Record::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Record::ReadWrite.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Record::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Record::ReadWrite.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Record::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Record::ReadWrite.new.should_not == nil
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Record::ReadWrite.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Record::ReadWrite.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Record::ReadWrite.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Record::ReadWrite.new.parent_database_settings_controller.should_not == nil
  end

  ################################################
  #  parent_database_record_settings_controller  #
  ################################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Record::ReadWrite.new.parent_database_record_settings_controller.should_not == nil
  end

  ##################
  #  set_filename  #
  #  filename      #
  ##################

  it "" do
    raise "Failed."
  end

  #####################################
  #  prohibit_sync_on_close?          #
	#  turn_prohibit_sync_on_close_on   #
	#  turn_prohibit_sync_on_close_off  #
  #####################################

  it "" do
    raise "Failed."
  end

  ###########################
  #  ignore_lease           #
	#  turn_ignore_lease_on   #
	#  turn_ignore_lease_off  #
  ###########################

  it "" do
    raise "Failed."
  end

  ##############################
  #  return_multiple           #
	#  turn_return_multiple_on   #
	#  turn_return_multiple_off  #
  ##############################

  it "" do
    raise "Failed."
  end

  ######################################
  #  prohibit_duplicate_data           #
	#  turn_prohibit_duplicate_data_on   #
	#  turn_prohibit_duplicate_data_off  #
  ######################################

  it "" do
    raise "Failed."
  end

  #################################
  #  prohibit_overwrite           #
	#  turn_prohibit_overwrite_on   #
	#  turn_prohibit_overwrite_off  #
  #################################

  it "" do
    raise "Failed."
  end

  #######################################
  #  prohibit_page_compaction           #
	#  turn_prohibit_page_compaction_on   #
	#  turn_prohibit_page_compaction_off  #
  #######################################

  it "" do
    raise "Failed."
  end

  #########################################
  #  return_pages_to_filesystem           #
	#  turn_return_pages_to_filesystem_on   #
	#  turn_return_pages_to_filesystem_off  #
  #########################################

  it "" do
    raise "Failed."
  end

  ####################################
  #  truncate_file_on_open           #
	#  turn_truncate_file_on_open_on   #
	#  turn_truncate_file_on_open_off  #
  ####################################

  it "" do
    raise "Failed."
  end

  ################################################
  #  write_locks_instead_of_read_locks           #
	#  turn_write_locks_instead_of_read_locks_on   #
	#  turn_write_locks_instead_of_read_locks_off  #
  ################################################

  it "" do
    raise "Failed."
  end

  #############################
  #  partial_access           #
	#  turn_partial_access_on   #
	#  turn_partial_access_off  #
  #############################

  it "" do
    raise "Failed."
  end

  #####################################################
  #  database_allocates_memory_using_malloc           #
	#  turn_database_allocates_memory_using_malloc_on   #
	#  turn_database_allocates_memory_using_malloc_off  #
  #####################################################

  it "" do
    raise "Failed."
  end

  ######################################################
  #  database_allocates_memory_using_realloc           #
	#  turn_database_allocates_memory_using_realloc_on   #
	#  turn_database_allocates_memory_using_realloc_off  #
  ######################################################

  it "" do
    raise "Failed."
  end

  ###########################################
  #  application_allocates_memory           #
	#  turn_application_allocates_memory_on   #
	#  turn_application_allocates_memory_off  #
  ###########################################

  it "" do
    raise "Failed."
  end

  ####################################
  #  database_frees_memory           #
	#  turn_database_frees_memory_on   #
	#  turn_database_frees_memory_off  #
  ####################################

  it "" do
    raise "Failed."
  end

  #########################################
  #  sync_prior_to_write_return           #
	#  turn_sync_prior_to_write_return_on   #
	#  turn_sync_prior_to_write_return_off  #
  #########################################

  it "" do
    raise "Failed."
  end

    ################################
    #  permit_duplicates           #
    #  turn_permit_duplicates_on   #
    #  turn_permit_duplicates_off  #
    ################################

    it "" do
      raise "Failed."
    end

    ##############################
    #  sort_duplicates           #
  	#  turn_sort_duplicates_on   #
  	#  turn_sort_duplicates_off  #
    ##############################

    it "" do
      raise "Failed."
    end

    #############################
    #  serialize_data           #
  	#  turn_serialize_data_on   #
  	#  turn_serialize_data_off  #
    #############################

    it "" do
      raise "Failed."
    end

  ##########################
  #  set_data_buffer_size  #
  #  data_buffer_size      #
  ##########################

  it "" do
    raise "Failed."
  end

  #################################
  #  set_partial_read_write_size  #
  #  partial_read_write_size      #
  #################################

  it "" do
    raise "Failed."
  end

  ###################################
  #  set_partial_read_write_offset  #
  #  partial_read_write_offset      #
  ###################################

  it "" do
    raise "Failed."
  end

  ######################
  #  set_storage_type  #
  #  storage_type      #
  ######################

  it "" do
    raise "Failed."
  end

end

