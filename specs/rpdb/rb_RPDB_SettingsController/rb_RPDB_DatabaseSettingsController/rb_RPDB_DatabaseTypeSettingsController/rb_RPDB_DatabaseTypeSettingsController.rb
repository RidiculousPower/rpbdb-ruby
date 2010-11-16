require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Type do

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

  # RPDB::Settings::Database::Type.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Type.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Type.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Type.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Type.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Type.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Type.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Type.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Type.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Type.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Type.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Type.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Type.new( RPDB::Database.new( $database_name ) ).parent_database.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Type.new.parent_settings_controller.should_not == nil
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Type.new.parent_database_settings_controller.should_not == nil
  end

  ###################
  #  database_type  #
  ###################

  it "can return its database type" do
    RPDB::Settings::Database::Type.new.database_type.should_not == 0
  end

  #######################
  #  set_type_to_btree  #
  #  is_btree?          #
  #######################

  it "can set the default type to btree and report whether the type is btree" do
    type_settings = RPDB::Settings::Database::Type.new
    type_settings.set_type_to_btree
    type_settings.is_btree?.should == true
  end

  ######################
  #  set_type_to_hash  #
  #  is_hash?          #
  ######################

  it "can set the default type to hash and report whether the type is hash" do
    type_settings = RPDB::Settings::Database::Type.new
    type_settings.set_type_to_hash
    type_settings.is_hash?.should == true
  end

  #######################
  #  set_type_to_recno  #
  #  is_recno?          #
  #######################

  it "can set the default type to queue and report whether the type is queue" do
    type_settings = RPDB::Settings::Database::Type.new
    type_settings.set_type_to_recno
    type_settings.is_recno?.should == true
  end

  #######################
  #  set_type_to_queue  #
  #  is_queue?          #
  #######################

  it "can set the default type to recno and report whether the type is recno" do
    type_settings = RPDB::Settings::Database::Type.new
    type_settings.set_type_to_queue
    type_settings.is_queue?.should == true
  end

  ######################
  #  btree_controller  #
  ######################

  it "can return its btree settings controller" do
    RPDB::Settings::Database::Type.new.btree_controller.is_a?( RPDB::Settings::Database::Type::Btree ).should == true
  end

  #####################
  #  hash_controller  #
  #####################

  it "can return its hash settings controller" do
    RPDB::Settings::Database::Type.new.hash_controller.is_a?( RPDB::Settings::Database::Type::Hash ).should == true
  end

  ######################
  #  queue_controller  #
  ######################

  it "can return its queue settings controller" do
    RPDB::Settings::Database::Type.new.queue_controller.is_a?( RPDB::Settings::Database::Type::Queue ).should == true
  end

  ######################
  #  recno_controller  #
  ######################

  it "can return its recno settings controller" do
    RPDB::Settings::Database::Type.new.recno_controller.is_a?( RPDB::Settings::Database::Type::Recno ).should == true
  end

end

