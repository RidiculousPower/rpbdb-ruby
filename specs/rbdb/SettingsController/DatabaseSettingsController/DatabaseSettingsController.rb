require_relative '../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database do

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

  # RPbdb::Settings::Database.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Database.new( @environment ).is_a?( RPbdb::Settings::Database ).should == true
  end

  # RPbdb::Settings::Database.new( database_controller )
  it "can be created with a database controller" do
    RPbdb::Settings::Database.new( @environment.database_controller ).is_a?( RPbdb::Settings::Database ).should == true
  end

  # RPbdb::Settings::Database.new( database )
  it "can be created with a database" do
    RPbdb::Settings::Database.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database ).should == true
  end

  # RPbdb::Settings::Database.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Database.new( RPbdb::Settings.new ).is_a?( RPbdb::Settings::Database ).should == true
  end

  # RPbdb::Settings::Database.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Database.new.is_a?( RPbdb::Settings::Database ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPbdb::Settings::Database.new.parent_environment.is_a?( RPbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPbdb::Settings::Database.new( RPbdb::Database.new( $database_name ) ).parent_database.is_a?( RPbdb::Database ).should == true
    RPbdb::Settings::Database.new.parent_database.should == nil
  end

  #######################
  #  checksum?          #
	#  turn_checksum_on   #
	#  turn_checksum_off  #
  #######################

  it "can do checksum verification of pages when loaded into cache" do
    
    # with a settings controller
    database_settings = RPbdb::Settings::Database.new
    test_checksum( database_settings )

    # with a database
    database_settings = RPbdb::Database.new( $database_name ).settings
    test_checksum( database_settings )    
    
  end

  def test_checksum( database_settings )
    
    database_settings.checksum?.should == false
    database_settings.turn_checksum_on
    database_settings.checksum?.should == true
    database_settings.turn_checksum_off
    database_settings.checksum?.should == false

  end

  #####################################
  #  transaction_durability?          #
	#  turn_transaction_durability_on   #
	#  turn_transaction_durability_off  #
  #####################################

  it "can enable or disable logging and report on logging status" do
    
    # with a settings controller
    database_settings = RPbdb::Settings::Database.new
    test_transaction_durability( database_settings )

    # with a database
    database_settings = RPbdb::Database.new( $database_name ).settings
    test_transaction_durability( database_settings )

  end

  def test_transaction_durability( database_settings )
    
    database_settings.transaction_durability?.should == false
    database_settings.turn_transaction_durability_on
    database_settings.transaction_durability?.should == true
    database_settings.turn_transaction_durability_off
    database_settings.transaction_durability?.should == false

  end

  ##################
  #  set_pagesize  #
  #  pagesize      #
  ##################

  it "can set and report its page size between 512bytes and 64k bytes (size must be a power of 2); size is specified in bytes" do

    # with a settings controller
    database_settings = RPbdb::Settings::Database.new
    test_pagesize( database_settings )

    # with a database
    database_settings = RPbdb::Database.new( $database_name ).settings
    test_pagesize( database_settings )
  end

  def test_pagesize( database_settings )
    
    database_settings.set_pagesize( 1024 )
    database_settings.pagesize.should == 1024

  end

  #####################################
  #  set_byte_order_to_big_endian     #
  #  is_big_endian?                   #
  #  set_byte_order_to_little_endian  #
  #  is_little_endian?                #
  #  is_byte_swapped?                  #
  #####################################

  it "can set its byte order to big or little endian, report on its order, and report whether it is byteswapped" do

    # with a settings controller
    database_settings = RPbdb::Settings::Database.new

    database_settings.set_byte_order_to_big_endian
    # written for x86
    database_settings.is_big_endian?.should == true
    
    database_settings.set_byte_order_to_little_endian
    database_settings.is_little_endian?.should == true

    ####################################################

    # with a database
    
    database = RPbdb::Database.new( $database_name )
    database_settings = database.settings
    
    # before a database is created or any specification takes place, neither big nor little endian are true
    database_settings.is_big_endian?.should == false
    # written for x86
    database_settings.is_little_endian?.should == true
    
    # when we open then we can check actual state (compared to default settings)

    database_settings.set_byte_order_to_big_endian
    database.open
    database_settings.is_big_endian?.should == true
    database_settings.is_byte_swapped?.should == false
    database.close
    
    File.delete( $environment_path + database.filename )

    database_settings.set_byte_order_to_little_endian
    database.open
    database_settings.is_little_endian?.should == true
    database_settings.is_byte_swapped?.should == false
    database.close

    # FIX - is_byte_swapped? seems to be returning false no matter what?
    
  end

  ##############################
  #  join_settings_controller  #
  ##############################

  it "can return its join settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.join_settings_controller.is_a?( RPbdb::Settings::Database::Join ).should == true
    # with a database
    RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Join ).should == true
  end

  ###############################
  #  cache_settings_controller  #
  ###############################

  it "can return its cache settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.cache_settings_controller.is_a?( RPbdb::Settings::Database::Cache ).should == true
    # with a database
    RPbdb::Settings::Database::Cache.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Cache ).should == true
  end

  ################################
  #  cursor_settings_controller  #
  ################################

  it "can return its cursor settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.cursor_settings_controller.is_a?( RPbdb::Settings::Database::Cursor ).should == true
    # with a database
    RPbdb::Settings::Database::Cursor.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Cursor ).should == true
  end
  
  ###############################
  #  error_settings_controller  #
  ###############################

  it "can return its error settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.error_settings_controller.is_a?( RPbdb::Settings::Database::Error ).should == true
    # with a database
    RPbdb::Settings::Database::Error.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Error ).should == true
  end

  #####################################
  #  association_settings_controller  #
  #####################################

  it "can return its association settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.association_settings_controller.is_a?( RPbdb::Settings::Database::Association ).should == true
    # with a database
    RPbdb::Settings::Database::Association.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Association ).should == true
  end
 
  ##################################
  #  sequence_settings_controller  #
  ##################################

  it "can return its sequence settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.sequence_settings_controller.is_a?( RPbdb::Settings::Database::Sequence ).should == true
    # with a database
    RPbdb::Settings::Database::Sequence.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Sequence ).should == true
  end

  ##############################
  #  type_settings_controller  #
  ##############################

  it "can return its type settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.type_settings_controller.is_a?( RPbdb::Settings::Database::Type ).should == true
    # with a database
    RPbdb::Settings::Database::Type.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Type::Btree ).should == true
  end

  ################################
  #  record_settings_controller  #
  ################################

  it "can return its record settings controller" do
    # with a settings controller
    RPbdb::Settings::Database.new.record_settings_controller.is_a?( RPbdb::Settings::Database::Record ).should == true
    # with a database
    RPbdb::Settings::Database::Record.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Record ).should == true
  end

end

