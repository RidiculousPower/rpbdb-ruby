require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Type::Recno do

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

  # RPDB::Settings::Database::Type::Recno.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Type::Recno.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Recno.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Type::Recno.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Recno.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Type::Recno.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Recno.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Type::Recno.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Recno.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Type::Recno.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type::Recno.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Type::Recno.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Type::Recno.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Type::Recno.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Type::Recno.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Type::Recno.new.parent_database_settings_controller.should_not == nil
  end

  ##############################################
  #  parent_database_type_settings_controller  #
  ##############################################

  it "can return its parent database type settings controller" do
    RPDB::Settings::Database::Type::Recno.new.parent_database_type_settings_controller.should_not == nil
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    RPDB::Settings::Database::Type::Recno.new.database_type.should == RPDB::Database::Type::Recno
  end

  ##################
  #  is_btree?     #
  ##################

  it "can report whether the type is btree" do
    RPDB::Settings::Database::Type::Recno.new.is_btree?.should == false
  end

  #################
  #  is_hash?     #
  #################

  it "can report whether the type is hash" do
    RPDB::Settings::Database::Type::Recno.new.is_hash?.should == false
  end

  ##################
  #  is_recno?     #
  ##################

  it "can report whether the type is queue" do
    RPDB::Settings::Database::Type::Recno.new.is_recno?.should == true
  end

  ##################
  #  is_queue?     #
  ##################

  it "can report whether the type is recno" do
    RPDB::Settings::Database::Type::Recno.new.is_queue?.should == false
  end

  #################################
  #  record_renumbering?          #
	#  turn_record_renumbering_on   #
	#  turn_record_renumbering_off  #
  #################################

  it "can allow renumbering of record numbers" do
    recno_settings  = RPDB::Settings::Database::Type::Recno.new
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
    recno_settings  = RPDB::Settings::Database::Type::Recno.new
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

  it "can set and return the record source file that will be read during database opening" do
    recno_settings  = RPDB::Settings::Database::Type::Recno.new
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
  end

end

