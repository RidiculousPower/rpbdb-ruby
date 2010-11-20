require_relative '../../../../../../lib/rpdb.rb'

describe RPDB::Settings::Database::Cursor::Cache::Priority do

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

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( @environment ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( @environment.database_controller ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_cursor_controller )
  it "can be created with a database cursor controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor_controller ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings.new ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings::Database.new ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database cursor settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings::Database::Cursor.new ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  # RPDB::Settings::Database::Cursor::Cache::Priority.new( database_settings_controller )
  it "can be created with a database cursor cache settings controller" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Settings::Database::Cursor::Cache.new ).is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end
  
  # RPDB::Settings::Database::Cursor::Cache::Priority.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database::Cursor::Cache::Priority.new.is_a?( RPDB::Settings::Database::Cursor::Cache::Priority ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_environment.should_not == nil
    # with a database
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).parent_environment.is_a?( RPDB::Environment ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor ).parent_environment.is_a?( RPDB::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_database.should == nil
    # with a database
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).parent_database.is_a?( RPDB::Database ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor ).parent_database.is_a?( RPDB::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_settings_controller.should_not == nil
    # with a database
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPDB::Settings ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor ).parent_settings_controller.is_a?( RPDB::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_database_settings_controller.should_not == nil
    # with a database
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor ).parent_database_settings_controller.is_a?( RPDB::Settings::Database ).should == true
  end

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  it "can return its parent database cursor settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_database_cursor_settings_controller.should_not == nil
    # with a database
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).parent_database_cursor_settings_controller.is_a?( RPDB::Settings::Database::Cursor ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor ).parent_database_cursor_settings_controller.is_a?( RPDB::Settings::Database::Cursor ).should == true
  end

  ######################################################
  #  parent_database_cursor_cache_settings_controller  #
  ######################################################

  it "can return its parent database cursor cache settings controller" do
    # with a settings controller
    RPDB::Settings::Database::Cursor::Cache::Priority.new.parent_database_cursor_cache_settings_controller.should_not == nil
    # with a database
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) ).parent_database_cursor_cache_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
    # with a database cursor
    RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor ).parent_database_cursor_cache_settings_controller.is_a?( RPDB::Settings::Database::Cursor::Cache ).should == true
  end

  ######################
	#  set_to_very_low   #
	#  set_to_low        #
	#  set_to_default    #
	#  set_to_high       #
	#  set_to_very_high  #
  #  very_low?         #
  #  low?              #
  #  default?          #
  #  high?             #
  #  very_high?        #
  #  current_priority  #
  ######################

  it "can set priority and report whether a priority level is currently set as well as report its current priority" do
    # with a settings controller
    priority_settings_controller  = RPDB::Settings::Database::Cursor::Cache::Priority.new
    test_priority_settings( priority_settings_controller )

    # with a database
    priority_settings_controller  = RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) )
    test_priority_settings( priority_settings_controller )

    # with a database cursor
    priority_settings_controller  = RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor )
    test_priority_settings( priority_settings_controller )
  end
  
  def test_priority_settings( priority_settings_controller )

    priority_settings_controller.current_priority.should == 0
    priority_settings_controller.set_to_very_low
    priority_settings_controller.very_low?.should == true
    priority_settings_controller.set_to_low
    priority_settings_controller.low?.should == true
    priority_settings_controller.set_to_default
    priority_settings_controller.default?.should == true
    priority_settings_controller.set_to_high
    priority_settings_controller.high?.should == true
    priority_settings_controller.set_to_very_high
    priority_settings_controller.very_high?.should == true

  end

  #########################
  #  at_least_very_low?   #
  #  at_most_very_low?    #
  #  at_least_low?        #
  #  at_most_low?         #
  #  at_least_default?    #
  #  at_most_default?     #
  #  at_least_high?       #
  #  at_most_high?        #
  #  at_least_very_high?  #
  #  at_most_very_high?   #
  #########################

  it "can report on relative priority levels" do
    # with a settings controller
    priority_settings_controller  = RPDB::Settings::Database::Cursor::Cache::Priority.new
    test_relative_priority_settings( priority_settings_controller )

    # with a database
    priority_settings_controller  = RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ) )
    test_relative_priority_settings( priority_settings_controller )
    
    # with a database cursor
    priority_settings_controller  = RPDB::Settings::Database::Cursor::Cache::Priority.new( RPDB::Database.new( $database_name ).cursor )
    test_relative_priority_settings( priority_settings_controller )    
  end

  def test_relative_priority_settings( priority_settings_controller )
    
    priority_settings_controller.set_to_very_low
    priority_settings_controller.is_at_least_very_low?.should == true
    priority_settings_controller.is_at_most_very_low?.should == true
    priority_settings_controller.is_at_least_low?.should == false
    priority_settings_controller.is_at_most_low?.should == true
    priority_settings_controller.is_at_least_default?.should == false
    priority_settings_controller.is_at_most_default?.should == true
    priority_settings_controller.is_at_least_high?.should == false
    priority_settings_controller.is_at_most_high?.should == true
    priority_settings_controller.is_at_least_very_high?.should == false
    priority_settings_controller.is_at_most_very_high?.should == true

    priority_settings_controller.set_to_low
    priority_settings_controller.is_at_least_very_low?.should == true
    priority_settings_controller.is_at_most_very_low?.should == false
    priority_settings_controller.is_at_least_low?.should == true
    priority_settings_controller.is_at_most_low?.should == true
    priority_settings_controller.is_at_least_default?.should == false
    priority_settings_controller.is_at_most_default?.should == true
    priority_settings_controller.is_at_least_high?.should == false
    priority_settings_controller.is_at_most_high?.should == true
    priority_settings_controller.is_at_least_very_high?.should == false
    priority_settings_controller.is_at_most_very_high?.should == true

    priority_settings_controller.set_to_default
    priority_settings_controller.is_at_least_very_low?.should == true
    priority_settings_controller.is_at_most_very_low?.should == false
    priority_settings_controller.is_at_least_low?.should == true
    priority_settings_controller.is_at_most_low?.should == false
    priority_settings_controller.is_at_least_default?.should == true
    priority_settings_controller.is_at_most_default?.should == true
    priority_settings_controller.is_at_least_high?.should == false
    priority_settings_controller.is_at_most_high?.should == true
    priority_settings_controller.is_at_least_very_high?.should == false
    priority_settings_controller.is_at_most_very_high?.should == true

    priority_settings_controller.set_to_high
    priority_settings_controller.is_at_least_very_low?.should == true
    priority_settings_controller.is_at_most_very_low?.should == false
    priority_settings_controller.is_at_least_low?.should == true
    priority_settings_controller.is_at_most_low?.should == false
    priority_settings_controller.is_at_least_default?.should == true
    priority_settings_controller.is_at_most_default?.should == false
    priority_settings_controller.is_at_least_high?.should == true
    priority_settings_controller.is_at_most_high?.should == true
    priority_settings_controller.is_at_least_very_high?.should == false
    priority_settings_controller.is_at_most_very_high?.should == true

    priority_settings_controller.set_to_very_high
    priority_settings_controller.is_at_least_very_low?.should == true
    priority_settings_controller.is_at_most_very_low?.should == false
    priority_settings_controller.is_at_least_low?.should == true
    priority_settings_controller.is_at_most_low?.should == false
    priority_settings_controller.is_at_least_default?.should == true
    priority_settings_controller.is_at_most_default?.should == false
    priority_settings_controller.is_at_least_high?.should == true
    priority_settings_controller.is_at_most_high?.should == false
    priority_settings_controller.is_at_least_very_high?.should == true
    priority_settings_controller.is_at_most_very_high?.should == true
    
  end

end

