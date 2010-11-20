require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Verification do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
    @environment.open
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Settings::Database::Verification.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Verification.new( @environment ).is_a?( RPDB::Settings::Database::Verification ).should == true
  end

  # RPDB::Settings::Database::Verification.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Verification.new( @environment.database_controller ).is_a?( RPDB::Settings::Database::Verification ).should == true
  end

  # RPDB::Settings::Database::Verification.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) ).is_a?( RPDB::Settings::Database::Verification ).should == true
  end

  # RPDB::Settings::Database::Verification.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Verification.new( RPDB::Settings.new ).is_a?( RPDB::Settings::Database::Verification ).should == true
  end

  # RPDB::Settings::Database::Verification.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Verification.new( RPDB::Settings::Database.new ).is_a?( RPDB::Settings::Database::Verification ).should == true
  end

  # RPDB::Settings::Database::Verification.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Verification.new.is_a?( RPDB::Settings::Database::Verification ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    RPDB::Settings::Database::Verification.new.parent_environment.is_a?( RPDB::Environment ).should == true
    # with a database
    RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) ).parent_environment.is_a?( RPDB::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    RPDB::Settings::Database::Verification.new.parent_database.should == nil
    # with a database
    RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) ).parent_database.is_a?( RPDB::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Verification.new.parent_settings_controller.is_a?( RPDB::Settings ).should == true
    # with a database
    RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPDB::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Verification.new.parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
    # with a database
    RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
  end

  ##############
  #  set_file  #
  #  file      #
  ##############

  # FIX - FILE
  it "can set its verification file" do
    raise "File"
    # with a settings controller
    verification_settings = RPDB::Settings::Database::Verification.new
    # with a database
    verification_settings = RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) )
  end
  
  def test_( verification_settings )

    verification_settings.set_file( '/tmp/file.tmp' )
    verification_settings.file.should == '/tmp/file.tmp'
    
  end

  ############################################
  #  aggressive_key_data_pair_dump?          #
	#  turn_aggressive_key_data_pair_dump_on   #
	#  turn_aggressive_key_data_pair_dump_off  #
  ############################################

  it "can be set to do an aggressive key/data pair dump" do
    # with a settings controller
    verification_settings  = RPDB::Settings::Database::Verification.new
    # with a database
    verification_settings  = RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) )
  end
  
  def test_( verification_settings )

    verification_settings.aggressive_key_data_pair_dump?.should == false
    verification_settings.turn_aggressive_key_data_pair_dump_on
    verification_settings.aggressive_key_data_pair_dump?.should == true
    verification_settings.turn_aggressive_key_data_pair_dump_off
    verification_settings.aggressive_key_data_pair_dump?.should == false
    
  end

  ###################################
  #  printable_characters?          #
	#  turn_printable_characters_on   #
	#  turn_printable_characters_off  #
  ###################################

  it "can specify that key and data are printable characters" do
    # with a settings controller
    verification_settings  = RPDB::Settings::Database::Verification.new
    # with a database
    verification_settings  = RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) )
  end
  
  def test_( verification_settings )

    verification_settings.printable_characters?.should == false
    verification_settings.turn_printable_characters_on
    verification_settings.printable_characters?.should == true
    verification_settings.turn_printable_characters_off
    verification_settings.printable_characters?.should == false
    
  end

  ###############################
  #  skip_order_check?          #
	#  turn_skip_order_check_on   #
	#  turn_skip_order_check_off  #
  ###############################

  it "can skip order checking" do
    # with a settings controller
    verification_settings  = RPDB::Settings::Database::Verification.new
    # with a database
    verification_settings  = RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) )
  end
  
  def test_( verification_settings )

    verification_settings.skip_order_check?.should == false
    verification_settings.turn_skip_order_check_on
    verification_settings.skip_order_check?.should == true
    verification_settings.turn_skip_order_check_off
    verification_settings.skip_order_check?.should == false
    
  end

  ###############################
  #  only_order_check?          #
	#  turn_only_order_check_on   #
	#  turn_only_order_check_off  #
  ###############################

  it "can perform order checking alone" do
    # with a settings controller
    verification_settings  = RPDB::Settings::Database::Verification.new
    # with a database
    verification_settings  = RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) )
  end
  
  def test_( verification_settings )

    verification_settings.only_order_check?.should == false
    verification_settings.turn_skip_order_check_on
    verification_settings.parent_database.verify
    verification_settings.turn_only_order_check_on
    verification_settings.only_order_check?.should == true
    verification_settings.turn_only_order_check_off
    verification_settings.only_order_check?.should == false
    
  end

  ################################
  #  force_order_check?          #
	#  turn_force_order_check_on   #
	#  turn_force_order_check_off  #
  ################################

  it "can force an order check to be performed" do
    # with a settings controller
    verification_settings  = RPDB::Settings::Database::Verification.new
    # with a database
    verification_settings  = RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) )
  end
  
  def test_( verification_settings )

    verification_settings.force_order_check?.should == false
    verification_settings.turn_force_order_check_on
    verification_settings.force_order_check?.should == true
    verification_settings.turn_force_order_check_off
    verification_settings.force_order_check?.should == false
    
  end

end

