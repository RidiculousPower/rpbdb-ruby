require_relative '../../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database::Record::ReadWrite do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
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

  # RPbdb::Settings::Database::Record::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Database::Record::ReadWrite.new( @environment ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    RPbdb::Settings::Database::Record::ReadWrite.new( @environment.database_controller ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::ReadWrite.new( database )
  it "can be created with a database" do
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Settings.new ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Settings::Database.new ).should_not == nil
  end

  # RPbdb::Settings::Database::Record::ReadWrite.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Database::Record::ReadWrite.new.should_not == nil
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    RPbdb::Settings::Database::Record::ReadWrite.new.parent_environment.is_a?( RPbdb::Environment ).should == true
    # with database
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) ).parent_environment.is_a?( RPbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    RPbdb::Settings::Database::Record::ReadWrite.new.parent_database.should == nil
    # with database
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) ).parent_database.is_a?( RPbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Record::ReadWrite.new.parent_settings_controller.is_a?( RPbdb::Settings ).should == true
    # with database
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Record::ReadWrite.new.parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
    # with database
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
  end

  ################################################
  #  parent_database_record_settings_controller  #
  ################################################

  it "can return its parent database settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Record::ReadWrite.new.parent_database_record_settings_controller.is_a?( RPbdb::Settings::Database::Record ).should == true
    # with database
    RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) ).parent_database_record_settings_controller.is_a?( RPbdb::Settings::Database::Record ).should == true
  end

  #####################################
  #  prohibit_sync_on_close?          #
	#  turn_prohibit_sync_on_close_on   #
	#  turn_prohibit_sync_on_close_off  #
  #####################################

  it "can prohibit syncing on database close" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_prohibit_sync_on_close( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_prohibit_sync_on_close( read_write_settings )
  end
  
  def test_prohibit_sync_on_close( read_write_settings )

    read_write_settings.prohibit_sync_on_close?.should == false
    read_write_settings.turn_prohibit_sync_on_close_on
    read_write_settings.prohibit_sync_on_close?.should == true
    read_write_settings.turn_prohibit_sync_on_close_off
    read_write_settings.prohibit_sync_on_close?.should == false
    
  end

  ###########################
  #  ignore_lease?          #
	#  turn_ignore_lease_on   #
	#  turn_ignore_lease_off  #
  ###########################

  it "can return data regardless of master leases" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_ignore_lease( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_ignore_lease( read_write_settings )
  end
  
  def test_ignore_lease( read_write_settings )

    read_write_settings.ignore_lease?.should == false
    read_write_settings.turn_ignore_lease_on
    read_write_settings.ignore_lease?.should == true
    read_write_settings.turn_ignore_lease_off
    read_write_settings.ignore_lease?.should == false
    
  end

  ##############################
  #  return_multiple?          #
	#  turn_return_multiple_on   #
	#  turn_return_multiple_off  #
  ##############################

  it "can return multiple data items in the record's data" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_return_multiple( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_return_multiple( read_write_settings )
  end
  
  def test_return_multiple( read_write_settings )

    read_write_settings.return_multiple?.should == false
    read_write_settings.turn_return_multiple_on
    read_write_settings.return_multiple?.should == true
    read_write_settings.turn_return_multiple_off
    read_write_settings.return_multiple?.should == false
    
  end

  ###############################################
  #  write_data_only_if_non_duplicate?          #
	#  turn_write_data_only_if_non_duplicate_on   #
	#  turn_write_data_only_if_non_duplicate_off  #
  ###############################################

  it "can prohibit duplicate data items" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_write_data_only_if_non_duplicate( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_write_data_only_if_non_duplicate( read_write_settings )
  end
  
  def test_write_data_only_if_non_duplicate( read_write_settings )

    read_write_settings.write_data_only_if_non_duplicate?.should == false
    read_write_settings.turn_write_data_only_if_non_duplicate_on
    read_write_settings.write_data_only_if_non_duplicate?.should == true
    read_write_settings.turn_write_data_only_if_non_duplicate_off
    read_write_settings.write_data_only_if_non_duplicate?.should == false
    
  end

  #################################
  #  prohibit_overwrite?          #
	#  turn_prohibit_overwrite_on   #
	#  turn_prohibit_overwrite_off  #
  #################################

  it "can prohibit overwriting existing items" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_prohibit_overwrite( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_prohibit_overwrite( read_write_settings )
  end
  
  def test_prohibit_overwrite( read_write_settings )

    read_write_settings.prohibit_overwrite?.should == false
    read_write_settings.turn_prohibit_overwrite_on
    read_write_settings.prohibit_overwrite?.should == true
    read_write_settings.turn_prohibit_overwrite_off
    read_write_settings.prohibit_overwrite?.should == false
    
  end

  #######################################
  #  prohibit_page_compaction?          #
	#  turn_prohibit_page_compaction_on   #
	#  turn_prohibit_page_compaction_off  #
  #######################################

  it "can prohibit page compaction" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_prohibit_page_compaction( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_prohibit_page_compaction( read_write_settings )
  end
  
  def test_prohibit_page_compaction( read_write_settings )

    read_write_settings.prohibit_page_compaction?.should == false
    read_write_settings.turn_prohibit_page_compaction_on
    read_write_settings.prohibit_page_compaction?.should == true
    read_write_settings.turn_prohibit_page_compaction_off
    read_write_settings.prohibit_page_compaction?.should == false
    
  end

  #########################################
  #  return_pages_to_filesystem?          #
	#  turn_return_pages_to_filesystem_on   #
	#  turn_return_pages_to_filesystem_off  #
  #########################################

  it "can return pages to the filesystem" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_return_pages_to_filesystem( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_return_pages_to_filesystem( read_write_settings )
  end
  
  def test_return_pages_to_filesystem( read_write_settings )

    read_write_settings.return_pages_to_filesystem?.should == false
    read_write_settings.turn_return_pages_to_filesystem_on
    read_write_settings.return_pages_to_filesystem?.should == true
    read_write_settings.turn_return_pages_to_filesystem_off
    read_write_settings.return_pages_to_filesystem?.should == false
    
  end

  ####################################
  #  truncate_file_on_open?          #
	#  turn_truncate_file_on_open_on   #
	#  turn_truncate_file_on_open_off  #
  ####################################

  it "can truncate the database file upon opening" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_truncate_file_on_open( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_truncate_file_on_open( read_write_settings )
  end
  
  def test_truncate_file_on_open( read_write_settings )

    read_write_settings.truncate_file_on_open?.should == false
    read_write_settings.turn_truncate_file_on_open_on
    read_write_settings.truncate_file_on_open?.should == true
    read_write_settings.turn_truncate_file_on_open_off
    read_write_settings.truncate_file_on_open?.should == false
    
  end

  ################################################
  #  write_locks_instead_of_read_locks?          #
	#  turn_write_locks_instead_of_read_locks_on   #
	#  turn_write_locks_instead_of_read_locks_off  #
  ################################################

  it "can use write locks instead of read locks" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_write_locks_instead_of_read_locks( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_write_locks_instead_of_read_locks( read_write_settings )
  end
  
  def test_write_locks_instead_of_read_locks( read_write_settings )

    read_write_settings.write_locks_instead_of_read_locks?.should == false
    read_write_settings.turn_write_locks_instead_of_read_locks_on
    read_write_settings.write_locks_instead_of_read_locks?.should == true
    read_write_settings.turn_write_locks_instead_of_read_locks_off
    read_write_settings.write_locks_instead_of_read_locks?.should == false
    
  end

  #############################
  #  partial_access?          #
	#  turn_partial_access_on   #
	#  turn_partial_access_off  #
  #############################

  it "can write and retrieve data based on partial information" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_partial_access( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_partial_access( read_write_settings )
  end
  
  def test_partial_access( read_write_settings )

    read_write_settings.partial_access?.should == false
    read_write_settings.turn_partial_access_on
    read_write_settings.partial_access?.should == true
    read_write_settings.turn_partial_access_off
    read_write_settings.partial_access?.should == false
    
  end

  #####################################################
  #  database_allocates_memory_using_malloc?          #
	#  turn_database_allocates_memory_using_malloc_on   #
	#  turn_database_allocates_memory_using_malloc_off  #
  #####################################################

  it "can use malloc to allocate memory" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_database_allocates_memory_using_malloc( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_database_allocates_memory_using_malloc( read_write_settings )
  end
  
  def test_database_allocates_memory_using_malloc( read_write_settings )

    read_write_settings.database_allocates_memory_using_malloc?.should == false
    read_write_settings.turn_database_allocates_memory_using_malloc_on
    read_write_settings.database_allocates_memory_using_malloc?.should == true
    read_write_settings.turn_database_allocates_memory_using_malloc_off
    read_write_settings.database_allocates_memory_using_malloc?.should == false
    
  end

  ######################################################
  #  database_allocates_memory_using_realloc?          #
	#  turn_database_allocates_memory_using_realloc_on   #
	#  turn_database_allocates_memory_using_realloc_off  #
  ######################################################

  it "can use realloc to allocate memory" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_database_allocates_memory_using_realloc( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_database_allocates_memory_using_realloc( read_write_settings )
  end
  
  def test_database_allocates_memory_using_realloc( read_write_settings )

    read_write_settings.database_allocates_memory_using_realloc?.should == false
    read_write_settings.turn_database_allocates_memory_using_realloc_on
    read_write_settings.database_allocates_memory_using_realloc?.should == true
    read_write_settings.turn_database_allocates_memory_using_realloc_off
    read_write_settings.database_allocates_memory_using_realloc?.should == false
    
  end

  ###########################################
  #  application_allocates_memory?          #
	#  turn_application_allocates_memory_on   #
	#  turn_application_allocates_memory_off  #
  ###########################################

  it "can require that the application allocates memory" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_application_allocates_memory( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_application_allocates_memory( read_write_settings )
  end
  
  def test_application_allocates_memory( read_write_settings )

    read_write_settings.application_allocates_memory?.should == false
    read_write_settings.turn_application_allocates_memory_on
    read_write_settings.application_allocates_memory?.should == true
    read_write_settings.turn_application_allocates_memory_off
    read_write_settings.application_allocates_memory?.should == false
    
  end

  ####################################
  #  database_frees_memory?          #
	#  turn_database_frees_memory_on   #
	#  turn_database_frees_memory_off  #
  ####################################

  it "can have the database free memory when finished with it" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_database_frees_memory( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_database_frees_memory( read_write_settings )
  end
  
  def test_database_frees_memory( read_write_settings )

    read_write_settings.database_frees_memory?.should == false
    read_write_settings.turn_database_frees_memory_on
    read_write_settings.database_frees_memory?.should == true
    read_write_settings.turn_database_frees_memory_off
    read_write_settings.database_frees_memory?.should == false
    
  end

  #########################################
  #  sync_prior_to_write_return?          #
	#  turn_sync_prior_to_write_return_on   #
	#  turn_sync_prior_to_write_return_off  #
  #########################################

  it "can force sync prior to returning from write" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_sync_prior_to_write_return( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_sync_prior_to_write_return( read_write_settings )
  end
  
  def test_sync_prior_to_write_return( read_write_settings )

    read_write_settings.sync_prior_to_write_return?.should == false
    read_write_settings.turn_sync_prior_to_write_return_on
    read_write_settings.sync_prior_to_write_return?.should == true
    read_write_settings.turn_sync_prior_to_write_return_off
    read_write_settings.sync_prior_to_write_return?.should == false
    
  end

    ##################################
    #  unsorted_duplicates?          #
    #  turn_unsorted_duplicates_on   #
    #  turn_unsorted_duplicates_off  #
    ##################################

    it "can permit duplicates" do
      # with settings controller
      read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
      test_unsorted_duplicates( read_write_settings )
      # with database
      read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
      test_unsorted_duplicates( read_write_settings )
    end
  
  def test_unsorted_duplicates( read_write_settings )

    read_write_settings.unsorted_duplicates?.should == false
    read_write_settings.turn_unsorted_duplicates_on
    read_write_settings.unsorted_duplicates?.should == true
    read_write_settings.turn_unsorted_duplicates_off
    read_write_settings.unsorted_duplicates?.should == false
    
  end

    ################################
    #  sorted_duplicates?          #
  	#  turn_sorted_duplicates_on   #
  	#  turn_sorted_duplicates_off  #
    ################################

    it "can permit sorted duplicates" do
      # with settings controller
      read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
      test_sorted_duplicates( read_write_settings )
      # with database
      read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
      test_sorted_duplicates( read_write_settings )
    end
  
  def test_sorted_duplicates( read_write_settings )
    
    read_write_settings.sorted_duplicates?.should == false
    read_write_settings.turn_sorted_duplicates_on
    read_write_settings.sorted_duplicates?.should == true
    read_write_settings.turn_sorted_duplicates_off
    read_write_settings.sorted_duplicates?.should == false

  end

    #############################
    #  serialize_data?          #
  	#  turn_serialize_data_on   #
  	#  turn_serialize_data_off  #
    #############################

    it "can automatically serialize data to permit implicit storage of objects" do
      # with settings controller
      read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
      test_serialize_data( read_write_settings )
      # with database
      read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
      test_serialize_data( read_write_settings )
    end
  
  def test_serialize_data( read_write_settings )

    read_write_settings.serialize_data?.should == false
    read_write_settings.turn_serialize_data_on
    read_write_settings.serialize_data?.should == true
    read_write_settings.turn_serialize_data_off
    read_write_settings.serialize_data?.should == false
    
  end

  ##################
  #  set_filename  #
  #  filename      #
  ##################

  it "can set the database filename" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_filename( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_filename( read_write_settings )
  end
  
  def test_filename( read_write_settings )

    read_write_settings.set_filename( '/tmp/file.tmp' )
    read_write_settings.filename.should == '/tmp/file.tmp'
    
  end

  ##########################
  #  set_data_buffer_size  #
  #  data_buffer_size      #
  ##########################

  it "can set its data buffer size" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_data_buffer_size( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_data_buffer_size( read_write_settings )
  end
  
  def test_data_buffer_size( read_write_settings )

    read_write_settings.set_data_buffer_size( 42 )
    read_write_settings.data_buffer_size.should == 42
    
  end

  #################################
  #  set_partial_read_write_size  #
  #  partial_read_write_size      #
  #################################

  it "can set partial read/write size" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_partial_read_write_size( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_partial_read_write_size( read_write_settings )
  end
  
  def test_partial_read_write_size( read_write_settings )

    read_write_settings.set_partial_read_write_size( 42 )
    read_write_settings.partial_read_write_size.should == 42
    
  end

  ###################################
  #  set_partial_read_write_offset  #
  #  partial_read_write_offset      #
  ###################################

  it "can set partial read/write offset" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_partial_read_write_offset( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_partial_read_write_offset( read_write_settings )
  end
  
  def test_partial_read_write_offset( read_write_settings )

    read_write_settings.set_partial_read_write_offset( 42 )
    read_write_settings.partial_read_write_offset.should == 42
    
  end

  ################################
  #  store_key_typing?           #
  #  turn_store_key_typing_on    #
  #  turn_store_key_typing_off   #
  #  store_data_typing?          #
  #  turn_store_data_typing_on   #
  #  turn_store_data_typing_off  #
  ################################

  it "can set the key and data type stored in database" do
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
		test_store_typing( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
		test_store_typing( read_write_settings )
  end

	def test_store_typing( read_write_settings )
		# :key => 42.0
		read_write_settings.turn_store_key_typing_on( Symbol )
		read_write_settings.turn_store_data_typing_on( Float )
		# we should now be able to write and retrieve key_symbol => float_value
		database = RPbdb::Database.new( $database_name )
		database.write( :key => 42.0 )
		database.retrieve( :key ).should == 42.0
		# we should not be able to write and retrieve anything else
		database.write( "key" => 42.0 ).should raise_exception
		database.write( :key => 42 ).should raise_exception
	end

  ############################
  #  record_typing?          #
  #  turn_record_typing_on   #
  #  turn_record_typing_off  #
  ############################

  it "can set the key and data type stored in database" do

    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
		read_write_settings.turn_record_typing_on

    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )

  end
  
  ######################################
  #  set_write_failed_callback_method  #
  #  write_failed_callback_method      #
  ######################################
  
  # FIX - move to read-write settings controller
  it "can set its write-failed callback method" do
    raise "Callback."
    # with settings controller
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new
    test_write_failed_callback_method( read_write_settings )
    # with database
    read_write_settings = RPbdb::Settings::Database::Record::ReadWrite.new( RPbdb::Database.new( $database_name ) )
    test_write_failed_callback_method( read_write_settings )
  end
  
  def test_write_failed_callback_method( read_write_settings )
    
  end

end

