require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Cursor::ReadWrite do

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

  # RPDB::Settings::Database::Cursor::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Cursor::ReadWrite.new( @environment ).class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  # RPDB::Settings::Database::Cursor::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller ).class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  # RPDB::Settings::Database::Cursor::ReadWrite.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ) ).class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  # RPDB::Settings::Database::Cursor::ReadWrite.new( database_cursor_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ).cursor_controller ).class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  # RPDB::Settings::Database::Cursor::ReadWrite.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ).cursor ).class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  # RPDB::Settings::Database::Cursor::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Settings.new ).class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  # RPDB::Settings::Database::Cursor::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Settings::Database.new ).class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  # RPDB::Settings::Database::Cursor::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Cursor::ReadWrite.new.class.should == RPDB::Settings::Database::Cursor::ReadWrite
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    RPDB::Settings::Database::Cursor::ReadWrite.new.parent_environment.class.should == RPDB::Environment
    # with database
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ) ).parent_environment.class.should == RPDB::Environment
    # with database cursor
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ).cursor ).parent_environment.class.should == RPDB::Environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    RPDB::Settings::Database::Cursor::ReadWrite.new.parent_database.should == nil
    # with database
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ) ).parent_database.class.should == RPDB::Database
    # with database cursor
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ).cursor ).parent_database.class.should == RPDB::Database
  end

  ############################
  #  parent_database_cursor  #
  ############################

  it "can return its parent database cursor" do
    # with settings controller
    RPDB::Settings::Database::Cursor::ReadWrite.new.parent_database_cursor.should == nil
    # with database
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ) ).parent_database_cursor.should == nil
    # with database cursor
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ).cursor ).parent_database_cursor.class.should == RPDB::Database::Cursor
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    RPDB::Settings::Database::Cursor::ReadWrite.new.parent_settings_controller.class.should == RPDB::Settings
    # with database
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ) ).parent_settings_controller.class.should == RPDB::Settings
    # with database cursor
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ).cursor ).parent_settings_controller.class.should == RPDB::Settings
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    RPDB::Settings::Database::Cursor::ReadWrite.new.parent_database_settings_controller.class.should == RPDB::Settings::Database
    # with database
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ) ).parent_database_settings_controller.class.should == RPDB::Settings::Database
    # with database cursor
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ).cursor ).parent_database_settings_controller.class.should == RPDB::Settings::Database
  end

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  it "can return its parent database cursor settings controller" do
    # with settings controller
    RPDB::Settings::Database::Cursor::ReadWrite.new.parent_database_cursor_settings_controller.class.should == RPDB::Settings::Database::Cursor
    # with database
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ) ).parent_database_cursor_settings_controller.class.should == RPDB::Settings::Database::Cursor
    # with database cursor
    RPDB::Settings::Database::Cursor::ReadWrite.new( RPDB::Database.new( $database_name ).cursor ).parent_database_cursor_settings_controller.class.should == RPDB::Settings::Database::Cursor
  end

  ###########################
  #  permit_write?          #
	#  turn_permit_write_on   #
	#  turn_permit_write_off  #
  ###########################

  it "can be a read-only cursor or it can permit writing" do
    raise "Failed."
  end

  ############################
  #  ignore_lease?           #
	#  turn_ignore_lease_on    #
	#  turn_ignore_lease_off   #
  ############################

  it "can be set to ignore its replication status (regarding master leases)" do
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

  #########################################
  #  return_multiple_data_items?          #
	#  turn_return_multiple_data_items_on   #
	#  turn_return_multiple_data_items_off  #
  #########################################

  it "can return multiple data items in a single data parameter" do
    raise "Failed."
  end

  #############################################
  #  return_multiple_key_data_pairs?          #
	#  turn_return_multiple_key_data_pairs_on   #
	#  turn_return_multiple_key_data_pairs_off  #
  #############################################

  it "can return multiple key and data items in a single data parameter" do
    raise "Failed."
  end

end

