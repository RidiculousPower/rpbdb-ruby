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

  #####################################
  #  prohibit_sync_on_close?          #
	#  turn_prohibit_sync_on_close_on   #
	#  turn_prohibit_sync_on_close_off  #
  #####################################

  it "can prohibit syncing on database close" do
    raise "Failed."
  end

  ###########################
  #  ignore_lease?          #
	#  turn_ignore_lease_on   #
	#  turn_ignore_lease_off  #
  ###########################

  it "can return data regardless of master leases" do
    raise "Failed."
  end

  ##############################
  #  return_multiple?          #
	#  turn_return_multiple_on   #
	#  turn_return_multiple_off  #
  ##############################

  it "can return multiple data items in the record's data" do
    raise "Failed."
  end

  ######################################
  #  prohibit_duplicate_data?          #
	#  turn_prohibit_duplicate_data_on   #
	#  turn_prohibit_duplicate_data_off  #
  ######################################

  it "can prohibit duplicate data items" do
    raise "Failed."
  end

  #################################
  #  prohibit_overwrite?          #
	#  turn_prohibit_overwrite_on   #
	#  turn_prohibit_overwrite_off  #
  #################################

  it "can prohibit overwriting existing items" do
    raise "Failed."
  end

  #######################################
  #  prohibit_page_compaction?          #
	#  turn_prohibit_page_compaction_on   #
	#  turn_prohibit_page_compaction_off  #
  #######################################

  it "can prohibit page compaction" do
    raise "Failed."
  end

  #########################################
  #  return_pages_to_filesystem?          #
	#  turn_return_pages_to_filesystem_on   #
	#  turn_return_pages_to_filesystem_off  #
  #########################################

  it "can return pages to the filesystem" do
    raise "Failed."
  end

  ####################################
  #  truncate_file_on_open?          #
	#  turn_truncate_file_on_open_on   #
	#  turn_truncate_file_on_open_off  #
  ####################################

  it "can truncate the database file upon opening" do
    raise "Failed."
  end

  ################################################
  #  write_locks_instead_of_read_locks?          #
	#  turn_write_locks_instead_of_read_locks_on   #
	#  turn_write_locks_instead_of_read_locks_off  #
  ################################################

  it "can use write locks instead of read locks" do
    raise "Failed."
  end

  #############################
  #  partial_access?          #
	#  turn_partial_access_on   #
	#  turn_partial_access_off  #
  #############################

  it "can write and retrieve data based on partial information" do
    raise "Failed."
  end

  #####################################################
  #  database_allocates_memory_using_malloc?          #
	#  turn_database_allocates_memory_using_malloc_on   #
	#  turn_database_allocates_memory_using_malloc_off  #
  #####################################################

  it "can use malloc to allocate memory" do
    raise "Failed."
  end

  ######################################################
  #  database_allocates_memory_using_realloc?          #
	#  turn_database_allocates_memory_using_realloc_on   #
	#  turn_database_allocates_memory_using_realloc_off  #
  ######################################################

  it "can use realloc to allocate memory" do
    raise "Failed."
  end

  ###########################################
  #  application_allocates_memory?          #
	#  turn_application_allocates_memory_on   #
	#  turn_application_allocates_memory_off  #
  ###########################################

  it "can require that the application allocates memory" do
    raise "Failed."
  end

  ####################################
  #  database_frees_memory?          #
	#  turn_database_frees_memory_on   #
	#  turn_database_frees_memory_off  #
  ####################################

  it "can have the database free memory when finished with it" do
    raise "Failed."
  end

  #########################################
  #  sync_prior_to_write_return?          #
	#  turn_sync_prior_to_write_return_on   #
	#  turn_sync_prior_to_write_return_off  #
  #########################################

  it "can force sync prior to returning from write" do
    raise "Failed."
  end

    ################################
    #  permit_duplicates?          #
    #  turn_permit_duplicates_on   #
    #  turn_permit_duplicates_off  #
    ################################

    it "can permit duplicates" do
      raise "Failed."
    end

    ##############################
    #  sort_duplicates?          #
  	#  turn_sort_duplicates_on   #
  	#  turn_sort_duplicates_off  #
    ##############################

    it "can permit sorted duplicates" do
      raise "Failed."
    end

    #############################
    #  serialize_data?          #
  	#  turn_serialize_data_on   #
  	#  turn_serialize_data_off  #
    #############################

    it "can automatically serialize data to permit implicit storage of objects" do
      raise "Failed."
    end

  ##################
  #  set_filename  #
  #  filename      #
  ##################

  it "can set the database filename" do
    raise "Failed."
  end

  ##########################
  #  set_data_buffer_size  #
  #  data_buffer_size      #
  ##########################

  it "can set its data buffer size" do
    raise "Failed."
  end

  #################################
  #  set_partial_read_write_size  #
  #  partial_read_write_size      #
  #################################

  it "can set partial read/write size" do
    raise "Failed."
  end

  ###################################
  #  set_partial_read_write_offset  #
  #  partial_read_write_offset      #
  ###################################

  it "can set partial read/write offset" do
    raise "Failed."
  end

  ######################
  #  set_storage_type  #
  #  storage_type      #
  ######################

  it "can set the type stored in database" do
    raise "Failed."
  end

  ######################################
  #  set_write_failed_callback_method  #
  #  write_failed_callback_method      #
  ######################################
  
  # FIX - move to read-write settings controller
  it "can set its write-failed callback method" do
    raise "Failed."
  end

end

