require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Database do

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

  # RPDB::Settings::Database.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database.new( @environment ).class.should == RPDB::Settings::Database
  end

  # RPDB::Settings::Database.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database.new( @environment.database_controller ).class.should == RPDB::Settings::Database
  end

  # RPDB::Settings::Database.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database.new( @environment.database_controller.new( $database_name ) ).class.should == RPDB::Settings::Database
  end

  # RPDB::Settings::Database.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database.new( RPDB::Settings.new ).class.should == RPDB::Settings::Database
  end

  # RPDB::Settings::Database.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database.new.class.should == RPDB::Settings::Database
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database.new.parent_environment.class.should == RPDB::Environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database.new( RPDB::Database.new( $database_name ) ).parent_database.class.should == RPDB::Database
    RPDB::Settings::Database.new.parent_database.should == nil
  end

  #######################
  #  checksum?          #
	#  turn_checksum_on   #
	#  turn_checksum_off  #
  #######################

  it "can do checksum verification of pages when loaded into cache" do
    
    # with a settings controller
    database_settings = RPDB::Settings::Database.new
    database_settings.checksum?.should == false
    database_settings.turn_checksum_on
    database_settings.checksum?.should == true
    database_settings.turn_checksum_off
    database_settings.checksum?.should == false
    
    # with a database
    database_settings = RPDB::Database.new( $database_name ).settings
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
    database_settings = RPDB::Settings::Database.new
    database_settings.transaction_durability?.should == false
    database_settings.turn_transaction_durability_on
    database_settings.transaction_durability?.should == true
    database_settings.turn_transaction_durability_off
    database_settings.transaction_durability?.should == false

    # with a database
    database_settings = RPDB::Database.new( $database_name ).settings
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
    database_settings = RPDB::Settings::Database.new
    database_settings.set_pagesize( 1024 )
    database_settings.pagesize.should == 1024

    # with a database
    database_settings = RPDB::Database.new( $database_name ).settings
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
    database_settings = RPDB::Settings::Database.new

    database_settings.set_byte_order_to_big_endian
    # written for x86
    database_settings.is_big_endian?.should == true
    
    database_settings.set_byte_order_to_little_endian
    database_settings.is_little_endian?.should == true

    ####################################################

    # with a database
    
    database = RPDB::Database.new( $database_name )
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
    RPDB::Settings::Database.new.join_settings_controller.should_not == nil
    RPDB::Settings::Database.new.join_settings_controller.class.should == RPDB::Settings::Database::Join
    # with a database
    RPDB::Database.new( $database_name ).settings.join_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.join_settings_controller.class.should == RPDB::Settings::Database::Join
  end

  ###############################
  #  cache_settings_controller  #
  ###############################

  it "can return its cache settings controller" do
    # with a settings controller
    RPDB::Settings::Database.new.cache_settings_controller.should_not == nil
    RPDB::Settings::Database.new.cache_settings_controller.class.should == RPDB::Settings::Database::Cache
    # with a database
    RPDB::Database.new( $database_name ).settings.cache_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.cache_settings_controller.class.should == RPDB::Settings::Database::Cache
  end

  ################################
  #  cursor_settings_controller  #
  ################################

  it "can return its cursor settings controller" do
    # with a settings controller
    RPDB::Settings::Database.new.cursor_settings_controller.should_not == nil
    RPDB::Settings::Database.new.cursor_settings_controller.class.should == RPDB::Settings::Database::Cursor
    # with a database
    RPDB::Database.new( $database_name ).settings.cursor_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.cursor_settings_controller.class.should == RPDB::Settings::Database::Cursor
  end
  
  ###############################
  #  error_settings_controller  #
  ###############################

  it "can return its error settings controller" do
    # with a settings controller
    RPDB::Settings::Database.new.error_settings_controller.should_not == nil
    RPDB::Settings::Database.new.error_settings_controller.class.should == RPDB::Settings::Database::Error
    # with a database
    RPDB::Database.new( $database_name ).settings.error_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.error_settings_controller.class.should == RPDB::Settings::Database::Error
  end

  #####################################
  #  association_settings_controller  #
  #####################################

  it "can return its association settings controller" do
    # with a settings controller
    RPDB::Settings::Database.new.association_settings_controller.should_not == nil
    RPDB::Settings::Database.new.association_settings_controller.class.should == RPDB::Settings::Database::Association
    # with a database
    RPDB::Database.new( $database_name ).settings.association_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.association_settings_controller.class.should == RPDB::Settings::Database::Association
  end
 
  ##################################
  #  sequence_settings_controller  #
  ##################################

  it "can return its sequence settings controller" do
    # with a settings controller
    RPDB::Settings::Database.new.sequence_settings_controller.should_not == nil
    RPDB::Settings::Database.new.sequence_settings_controller.class.should == RPDB::Settings::Database::Sequence
    # with a database
    RPDB::Database.new( $database_name ).settings.sequence_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.sequence_settings_controller.class.should == RPDB::Settings::Database::Sequence
  end

  ##############################
  #  type_settings_controller  #
  ##############################

  it "can return its type settings controller" do
    # with a settings controller
    RPDB::Settings::Database.new.type_settings_controller.should_not == nil
    RPDB::Settings::Database.new.type_settings_controller.class.should == RPDB::Settings::Database::Type
    # with a database
    RPDB::Database.new( $database_name ).settings.type_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.type_settings_controller.class.should == RPDB::Settings::Database::Type::Btree
  end

  ################################
  #  record_settings_controller  #
  ################################

  it "can return its record settings controller" do
    # with a settings controller
    RPDB::Settings::Database.new.record_settings_controller.should_not == nil
    RPDB::Settings::Database.new.record_settings_controller.class.should == RPDB::Settings::Database::Record
    # with a database
    RPDB::Database.new( $database_name ).settings.record_settings_controller.should_not == nil
    RPDB::Database.new( $database_name ).settings.record_settings_controller.class.should == RPDB::Settings::Database::Record
  end

end

