require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Record::VariableLength do

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

  # RPDB::Settings::Database::Record::VariableLength.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Record::VariableLength.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database::Record::VariableLength.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Record::VariableLength.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database::Record::VariableLength.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Record::VariableLength.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database::Record::VariableLength.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Record::VariableLength.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database::Record::VariableLength.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Record::VariableLength.new( RPDB::Settings::Database.new ).should_not == nil
  end

  # RPDB::Settings::Database::Record::VariableLength.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Record::VariableLength.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database::Record::VariableLength.new.parent_environment.is_a?( RPDB::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database::Record::VariableLength.new.parent_database.should == nil
    RPDB::Settings::Database::Record::VariableLength.new( RPDB::Database.new( $database_name ) ).parent_database.is_a?( RPDB::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    RPDB::Settings::Database::Record::VariableLength.new.parent_settings_controller.is_a?( RPDB::Settings ).should == true
    RPDB::Settings::Database::Record::VariableLength.new.parent_settings_controller.is_a?( RPDB::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    RPDB::Settings::Database::Record::VariableLength.new.parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
    RPDB::Settings::Database::Record::VariableLength.new.parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
  end

  ################################################
  #  parent_database_record_settings_controller  #
  ################################################

  it "can return its parent database record settings controller" do
    RPDB::Settings::Database::Record::VariableLength.new.parent_database_record_settings_controller.is_a?( RPDB::Settings::Database::Record ).should == true
    RPDB::Settings::Database::Record::VariableLength.new.parent_database_record_settings_controller.is_a?( RPDB::Settings::Database::Record ).should == true
  end

  	########################
  	#  set_delimeter_byte  #
  	#  delimeter_byte      #
  	########################

    it "can set and return its record delimiter" do
      variable_length_settings  = RPDB::Settings::Database::Record::VariableLength.new
      variable_length_settings.set_delimeter_byte( '$' )
      variable_length_settings.delimeter_byte.should == '$'
    end

end

