require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Verbosity do

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

  # Rbdb::Settings::Database::Verbosity.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Verbosity.new( @environment ).is_a?( Rbdb::Settings::Database::Verbosity ).should == true
  end

  # Rbdb::Settings::Database::Verbosity.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Verbosity.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Verbosity ).should == true
  end

  # Rbdb::Settings::Database::Verbosity.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Verbosity.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Verbosity ).should == true
  end

  # Rbdb::Settings::Database::Verbosity.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Verbosity.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Verbosity ).should == true
  end

  # Rbdb::Settings::Database::Verbosity.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Verbosity.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Verbosity ).should == true
  end

  # Rbdb::Settings::Database::Verbosity.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Verbosity.new.is_a?( Rbdb::Settings::Database::Verbosity ).should == true
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    Rbdb::Settings::Database::Verbosity.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with a database
    Rbdb::Settings::Database::Verbosity.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    Rbdb::Settings::Database::Verbosity.new.parent_database.should == nil
    # with a database
    Rbdb::Settings::Database::Verbosity.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Verbosity.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with a database
    Rbdb::Settings::Database::Verbosity.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Verbosity.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with a database
    Rbdb::Settings::Database::Verbosity.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  ########################################################################
  #  display_additional_information_for_database_register_flag?          #
	#  turn_display_additional_information_for_database_register_flag_on   #
	#  turn_display_additional_information_for_database_register_flag_off  #
  ########################################################################

  it "can be set to display additional information while handling database registration" do
    # with a settings controller
    verbosity_settings  = Rbdb::Settings::Database::Verbosity.new
    # with a database
    verbosity_settings  = Rbdb::Settings::Database::Verbosity.new( Rbdb::Database.new( $database_name ) )
  end
  
  def test_( verbosity_settings )
    
    verbosity_settings.display_additional_information_for_database_register_flag?.should == false
    verbosity_settings.turn_display_additional_information_for_database_register_flag_on
    verbosity_settings.display_additional_information_for_database_register_flag?.should == true
    verbosity_settings.turn_display_additional_information_for_database_register_flag_off
    verbosity_settings.display_additional_information_for_database_register_flag?.should == false

  end

end

