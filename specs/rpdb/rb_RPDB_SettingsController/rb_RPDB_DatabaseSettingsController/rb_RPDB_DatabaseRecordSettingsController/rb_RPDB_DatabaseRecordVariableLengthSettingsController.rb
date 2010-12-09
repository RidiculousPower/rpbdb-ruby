require_relative '../../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Record::VariableLength do

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

  # Rbdb::Settings::Database::Record::VariableLength.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Record::VariableLength.new( @environment ).should_not == nil
  end

  # Rbdb::Settings::Database::Record::VariableLength.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Record::VariableLength.new( @environment.database_controller ).should_not == nil
  end

  # Rbdb::Settings::Database::Record::VariableLength.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Record::VariableLength.new( Rbdb::Database.new( $database_name ) ).should_not == nil
  end

  # Rbdb::Settings::Database::Record::VariableLength.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Record::VariableLength.new( Rbdb::Settings.new ).should_not == nil
  end

  # Rbdb::Settings::Database::Record::VariableLength.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Record::VariableLength.new( Rbdb::Settings::Database.new ).should_not == nil
  end

  # Rbdb::Settings::Database::Record::VariableLength.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Record::VariableLength.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    Rbdb::Settings::Database::Record::VariableLength.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with database
    Rbdb::Settings::Database::Record::VariableLength.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    Rbdb::Settings::Database::Record::VariableLength.new.parent_database.should == nil
    # with database
    Rbdb::Settings::Database::Record::VariableLength.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Record::VariableLength.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with database
    Rbdb::Settings::Database::Record::VariableLength.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Record::VariableLength.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with database
    Rbdb::Settings::Database::Record::VariableLength.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  ################################################
  #  parent_database_record_settings_controller  #
  ################################################

  it "can return its parent database record settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Record::VariableLength.new.parent_database_record_settings_controller.is_a?( Rbdb::Settings::Database::Record ).should == true
    # with database
    Rbdb::Settings::Database::Record::VariableLength.new.parent_database_record_settings_controller.is_a?( Rbdb::Settings::Database::Record ).should == true
  end

  	########################
  	#  set_delimeter_byte  #
  	#  delimeter_byte      #
  	########################

    it "can set and return its record delimiter" do
      # with settings controller
      variable_length_settings  = Rbdb::Settings::Database::Record::VariableLength.new
      test_delimeter_byte( variable_length_settings )
      # with database
      variable_length_settings  = Rbdb::Settings::Database::Record::VariableLength.new( Rbdb::Database.new( $database_name ) )
      test_delimeter_byte( variable_length_settings )
    end
    
    def test_delimeter_byte( variable_length_settings )

      variable_length_settings.set_delimeter_byte( '$' )
      variable_length_settings.delimeter_byte.should == '$'
      
    end

end

