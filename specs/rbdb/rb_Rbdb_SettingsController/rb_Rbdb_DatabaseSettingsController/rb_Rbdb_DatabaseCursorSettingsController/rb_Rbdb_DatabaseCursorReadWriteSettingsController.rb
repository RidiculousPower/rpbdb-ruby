require_relative '../../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Cursor::ReadWrite do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
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

  # Rbdb::Settings::Database::Cursor::ReadWrite.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new( @environment ).is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  # Rbdb::Settings::Database::Cursor::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  # Rbdb::Settings::Database::Cursor::ReadWrite.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  # Rbdb::Settings::Database::Cursor::ReadWrite.new( database_cursor_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor_controller ).is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  # Rbdb::Settings::Database::Cursor::ReadWrite.new( database_cursor )
  it "can be created with a database cursor" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor ).is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  # Rbdb::Settings::Database::Cursor::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  # Rbdb::Settings::Database::Cursor::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  # Rbdb::Settings::Database::Cursor::ReadWrite.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Cursor::ReadWrite.new.is_a?( Rbdb::Settings::Database::Cursor::ReadWrite ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    Rbdb::Settings::Database::Cursor::ReadWrite.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with database
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
    # with database cursor
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    Rbdb::Settings::Database::Cursor::ReadWrite.new.parent_database.should == nil
    # with database
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
    # with database cursor
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ############################
  #  parent_database_cursor  #
  ############################

  it "can return its parent database cursor" do
    # with settings controller
    Rbdb::Settings::Database::Cursor::ReadWrite.new.parent_database_cursor.should == nil
    # with database
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) ).parent_database_cursor.should == nil
    # with database cursor
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor ).parent_database_cursor.is_a?( Rbdb::Database::Cursor ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Cursor::ReadWrite.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with database
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with database cursor
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Cursor::ReadWrite.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with database
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with database cursor
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  it "can return its parent database cursor settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Cursor::ReadWrite.new.parent_database_cursor_settings_controller.is_a?( Rbdb::Settings::Database::Cursor ).should == true
    # with database
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) ).parent_database_cursor_settings_controller.is_a?( Rbdb::Settings::Database::Cursor ).should == true
    # with database cursor
    Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor ).parent_database_cursor_settings_controller.is_a?( Rbdb::Settings::Database::Cursor ).should == true
  end

  ###########################
  #  permit_write?          #
	#  turn_permit_write_on   #
	#  turn_permit_write_off  #
  ###########################

  it "can be a read-only cursor or it can permit writing" do
    # with settings controller
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new
    test_permit_write( read_write_settings )
    # with database
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) )
    test_permit_write( read_write_settings )
    # with database cursor
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor )
    test_permit_write( read_write_settings )
  end
  
  def test_permit_write( read_write_settings )
    
    read_write_settings.permit_write?.should == false
    read_write_settings.turn_permit_write_on
    read_write_settings.permit_write?.should == true
    read_write_settings.turn_permit_write_off
    read_write_settings.permit_write?.should == false

  end

  ############################
  #  ignore_lease?           #
	#  turn_ignore_lease_on    #
	#  turn_ignore_lease_off   #
  ############################

  it "can be set to ignore its replication status (regarding master leases)" do
    # with settings controller
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new
    test_ignore_lease( read_write_settings )
    # with database
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) )
    test_ignore_lease( read_write_settings )
    # with database cursor
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor )
    test_ignore_lease( read_write_settings )
  end

  def test_ignore_lease( read_write_settings )
    
    read_write_settings.ignore_lease?.should == false
    read_write_settings.turn_ignore_lease_on
    read_write_settings.ignore_lease?.should == true
    read_write_settings.turn_ignore_lease_off
    read_write_settings.ignore_lease?.should == false

  end

  ################################################
  #  write_locks_instead_of_read_locks?          #
	#  turn_write_locks_instead_of_read_locks_on   #
	#  turn_write_locks_instead_of_read_locks_off  #
  ################################################

  it "can use write locks instead of read locks" do
    # with settings controller
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new
    test_write_locks_instead_of_read_locks( read_write_settings )
    # with database
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) )
    test_ignore_lease( read_write_settings )
    # with database cursor
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor )
    test_ignore_lease( read_write_settings )
  end

  def test_write_locks_instead_of_read_locks( read_write_settings )
    
    read_write_settings.write_locks_instead_of_read_locks?.should == false
    read_write_settings.turn_write_locks_instead_of_read_locks_on
    read_write_settings.write_locks_instead_of_read_locks?.should == true
    read_write_settings.turn_write_locks_instead_of_read_locks_off
    read_write_settings.write_locks_instead_of_read_locks?.should == false

  end

  #########################################
  #  return_multiple_data_items?          #
	#  turn_return_multiple_data_items_on   #
	#  turn_return_multiple_data_items_off  #
  #########################################

  it "can return multiple data items in a single data parameter" do
    # with settings controller
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new
    test_return_multiple_data_items( read_write_settings )
    # with database
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) )
    test_return_multiple_data_items( read_write_settings )
    # with database cursor
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor )
    test_return_multiple_data_items( read_write_settings )
  end

  def test_return_multiple_data_items( read_write_settings )
    
    read_write_settings.return_multiple_data_items?.should == false
    read_write_settings.turn_return_multiple_data_items_on
    read_write_settings.return_multiple_data_items?.should == true
    read_write_settings.turn_return_multiple_data_items_off
    read_write_settings.return_multiple_data_items?.should == false

  end

  #############################################
  #  return_multiple_key_data_pairs?          #
	#  turn_return_multiple_key_data_pairs_on   #
	#  turn_return_multiple_key_data_pairs_off  #
  #############################################

  it "can return multiple key and data items in a single data parameter" do
    # with settings controller
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new
    test_return_multiple_key_data_pairs( read_write_settings )
    # with database
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ) )
    test_return_multiple_key_data_pairs( read_write_settings )
    # with database cursor
    read_write_settings = Rbdb::Settings::Database::Cursor::ReadWrite.new( Rbdb::Database.new( $database_name ).cursor )
    test_return_multiple_key_data_pairs( read_write_settings )
  end

  def test_return_multiple_key_data_pairs( read_write_settings )
    
    read_write_settings.return_multiple_key_data_pairs?.should == false
    read_write_settings.turn_return_multiple_key_data_pairs_on
    read_write_settings.return_multiple_key_data_pairs?.should == true
    read_write_settings.turn_return_multiple_key_data_pairs_off
    read_write_settings.return_multiple_key_data_pairs?.should == false

  end

end

