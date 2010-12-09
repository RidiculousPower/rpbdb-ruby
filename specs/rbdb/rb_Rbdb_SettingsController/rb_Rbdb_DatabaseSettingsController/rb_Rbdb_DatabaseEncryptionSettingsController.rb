require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Encryption do

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

  # Rbdb::Settings::Database::Encryption.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Encryption.new( @environment ).is_a?( Rbdb::Settings::Database::Encryption ).should == true
  end

  # Rbdb::Settings::Database::Encryption.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Encryption.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Encryption ).should == true
  end

  # Rbdb::Settings::Database::Encryption.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Encryption.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Encryption ).should == true
  end

  # Rbdb::Settings::Database::Encryption.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Encryption.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Encryption ).should == true
  end

  # Rbdb::Settings::Database::Encryption.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Encryption.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Encryption ).should == true
  end

  # Rbdb::Settings::Database::Encryption.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Encryption.new.is_a?( Rbdb::Settings::Database::Encryption ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    Rbdb::Settings::Database::Encryption.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with database
    Rbdb::Settings::Database::Encryption.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    Rbdb::Settings::Database::Encryption.new.parent_database.should == nil
    # with database
    Rbdb::Settings::Database::Encryption.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Encryption.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with database
    Rbdb::Settings::Database::Encryption.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    Rbdb::Settings::Database::Encryption.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with database
    Rbdb::Settings::Database::Encryption.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  #########################
  #  encrypted?           #
	#  turn_encryption_on   #
	#  turn_encryption_off  #
  #########################

  it "can turn encryption on and off and report whether it is encrypted" do
    # with settings controller
    encryption_settings = Rbdb::Settings::Database::Encryption.new
    test_encrypted( encryption_settings )
    # with database
    encryption_settings = Rbdb::Settings::Database::Encryption.new( Rbdb::Database.new( $database_name ) )
    test_encrypted( encryption_settings )
  end
  
  def test_encrypted( encryption_settings )

    encryption_settings.encrypted?.should == false
    encryption_settings.turn_encryption_on( 'password!' )
    encryption_settings.encrypted?.should == true
    encryption_settings.turn_encryption_off( 'not the password!' )
    encryption_settings.encrypted?.should == true
    encryption_settings.turn_encryption_off( 'password!' )
    encryption_settings.encrypted?.should == false
    
  end

end

