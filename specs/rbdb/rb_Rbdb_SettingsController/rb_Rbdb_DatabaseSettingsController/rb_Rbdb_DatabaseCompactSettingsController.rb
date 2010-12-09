require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Settings::Database::Compact do

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

  # Rbdb::Settings::Database::Compact.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Database::Compact.new( @environment ).is_a?( Rbdb::Settings::Database::Compact ).should == true
  end

  # Rbdb::Settings::Database::Compact.new( database_controller )
  it "can be created with a database controller" do
    Rbdb::Settings::Database::Compact.new( @environment.database_controller ).is_a?( Rbdb::Settings::Database::Compact ).should == true
  end

  # Rbdb::Settings::Database::Compact.new( database )
  it "can be created with a database" do
    Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) ).is_a?( Rbdb::Settings::Database::Compact ).should == true
  end

  # Rbdb::Settings::Database::Compact.new( settings_controller )
  it "can be created with a settings controller" do
    Rbdb::Settings::Database::Compact.new( Rbdb::Settings.new ).is_a?( Rbdb::Settings::Database::Compact ).should == true
  end

  # Rbdb::Settings::Database::Compact.new( database_settings_controller )
  it "can be created with a database settings controller" do
    Rbdb::Settings::Database::Compact.new( Rbdb::Settings::Database.new ).is_a?( Rbdb::Settings::Database::Compact ).should == true
  end

  # Rbdb::Settings::Database::Compact.new
  it "can be created with no argument specified" do
    Rbdb::Settings::Database::Compact.new.is_a?( Rbdb::Settings::Database::Compact ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    Rbdb::Settings::Database::Compact.new.parent_environment.is_a?( Rbdb::Environment ).should == true
    # with a database
    Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) ).parent_environment.is_a?( Rbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    Rbdb::Settings::Database::Compact.new.parent_database.should == nil
    # with a database
    Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) ).parent_database.is_a?( Rbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Compact.new.parent_settings_controller.is_a?( Rbdb::Settings ).should == true
    # with a database
    Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( Rbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    Rbdb::Settings::Database::Compact.new.parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
    # with a database
    Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( Rbdb::Settings::Database ).should == true
  end

  ######################
  #  set_fill_percent  #
  #  fill_percent      #
  ######################

  it "can set and report the level at which compaction should occur" do
    # with a settings controller
    compact_settings  = Rbdb::Settings::Database::Compact.new
    test_fill_percent( compact_settings )
    # with a database
    compact_settings  = Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) )
    test_fill_percent( compact_settings )
  end

  def test_fill_percent( compact_settings )
    
    compact_settings.set_fill_percent( 42 )
    compact_settings.fill_percent.should == 42

  end

  ##############################
  #  set_max_pages_to_compact  #
  #  max_pages_to_compact      #
  ##############################

  it "can set and report the maximum amount of pages to be compacted at any time" do
    # with a settings controller
    compact_settings  = Rbdb::Settings::Database::Compact.new
    test_max_pages_to_compact( compact_settings )
    # with a database
    compact_settings  = Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) )
    test_max_pages_to_compact( compact_settings )
  end

  def test_max_pages_to_compact( compact_settings )
    
    compact_settings.set_max_pages_to_compact( 42 )
    compact_settings.max_pages_to_compact.should == 42

  end

  #################
  #  set_timeout  #
  #  timeout      #
  #################

  it "can set and report compaction timeout" do
    # with a settings controller
    compact_settings  = Rbdb::Settings::Database::Compact.new
    test_timeout( compact_settings )
    # with a database
    compact_settings  = Rbdb::Settings::Database::Compact.new( Rbdb::Database.new( $database_name ) )
    test_timeout( compact_settings )
  end

  def test_timeout( compact_settings )
    
    compact_settings.set_timeout( 42 )
    compact_settings.timeout.should == 42

  end

end

