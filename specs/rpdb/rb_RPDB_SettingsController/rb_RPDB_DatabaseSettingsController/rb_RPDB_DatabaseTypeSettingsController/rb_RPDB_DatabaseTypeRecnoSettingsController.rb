require_relative '../../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Type::Recno do

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

  # Rbdb::Settings::Database::Type::Recno.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Type::Recno.new( @environment ).is_a?( Rbdb::Settings::Database::Type::Recno ).should == true
  end

  # Rbdb::Settings::Database::Type::Recno.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Type::Recno.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Type::Recno ).should == true
  end

  # Rbdb::Settings::Database::Type::Recno.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Type::Recno ).should == true
  end

  # Rbdb::Settings::Database::Type::Recno.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Type::Recno ).should == true
  end

  # Rbdb::Settings::Database::Type::Recno.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Type::Recno ).should == true
  end

  # Rbdb::Settings::Database::Type::Recno.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Type::Recno.new.is_a?( Rbdb::Settings::Database::Type::Recno ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.parent_database.should == nil
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.parent_database_type_settings_controller.is_a?( Rbdb::Settings::Database::Type ).should == true
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).parent_database_type_settings_controller.is_a?( Rbdb::Settings::Database::Type ).should == true
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.database_type.should == Rbdb::Database::Type::Recno
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).database_type.should == Rbdb::Database::Type::Recno
  end

  ##################
  #  is_btree?     #
  ##################

  it "can report whether the type is btree" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.is_btree?.should == false
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).is_btree?.should == false
  end

  #################
  #  is_hash?     #
  #################

  it "can report whether the type is hash" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.is_hash?.should == false
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).is_hash?.should == false
  end

  ##################
  #  is_recno?     #
  ##################

  it "can report whether the type is queue" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.is_recno?.should == true
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).is_recno?.should == true
  end

  ##################
  #  is_queue?     #
  ##################

  it "can report whether the type is recno" do
    # with a settings controller
    Rbdb::Settings::Database::Type::Recno.new.is_queue?.should == false
    # with a database
    Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) ).is_queue?.should == false
  end

  #################################
  #  record_renumbering?          #
	#  turn_record_renumbering_on   #
	#  turn_record_renumbering_off  #
  #################################

  it "can allow renumbering of record numbers" do
    # with a settings controller
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new
    test_record_renumbering( recno_settings )
    # with a database
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) )
    test_record_renumbering( recno_settings )
  end

  def test_record_renumbering( recno_settings )

    recno_settings.record_renumbering?.should == false
    recno_settings.turn_record_renumbering_on
    recno_settings.record_renumbering?.should == true
    recno_settings.turn_record_renumbering_off
    recno_settings.record_renumbering?.should == false
    
  end

  #################################
  #  snapshot_isolation?          #
	#  turn_snapshot_isolation_on   #
	#  turn_snapshot_isolation_off  #
  #################################

  it "can provide snapshot isolation, which forces the record source file to be read in its entirety" do
    # with a settings controller
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new
    test_snapshot_isolation( recno_settings )
    # with a database
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) )
    test_snapshot_isolation( recno_settings )
  end

  def test_snapshot_isolation( recno_settings )

    recno_settings.snapshot_isolation?.should == false
    recno_settings.turn_snapshot_isolation_on
    recno_settings.snapshot_isolation?.should == true
    recno_settings.turn_snapshot_isolation_off
    recno_settings.snapshot_isolation?.should == false
    
  end

  #####################
  #  set_source_file  #
  #  source_file      #
  #####################

  # FIX - FILE
  it "can set and return the record source file that will be read during database opening" do
    # with a settings controller
    raise "File"
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new
    test_source_file( recno_settings )
    # with a database
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) )
    test_source_file( recno_settings )
  end

  def test_source_file( recno_settings )
    
    recno_settings.set_source_file( '/tmp/file.tmp' )
    recno_settings.source_file.should == '/tmp/file.tmp'

  end

  ################################
  #  set_append_callback_method  #
  #  append_callback_method      #
  ################################

  # fix name for callback
  it "can set and return a callback method to use for appending records" do
    raise "Callback."
    # with a settings controller
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new
    test_append_callback_method( recno_settings )
    # with a database
    recno_settings  = Rbdb::Settings::Database::Type::Recno.new( Rbdb::Database.new( $database_name ) )
    test_append_callback_method( recno_settings )
  end

  def test_append_callback_method( recno_settings )
    
  end

end

