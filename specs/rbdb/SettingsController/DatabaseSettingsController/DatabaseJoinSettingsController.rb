require_relative '../../../../lib/rpbdb.rb'

describe RPbdb::Settings::Database::Join do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
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

  # RPbdb::Settings::Database::Join.new( environment )
  it "can be created with an environment" do
    RPbdb::Settings::Database::Join.new( @environment ).is_a?( RPbdb::Settings::Database::Join ).should == true
  end

  # RPbdb::Settings::Database::Join.new( database_controller )
  it "can be created with a database controller" do
    RPbdb::Settings::Database::Join.new( @environment.database_controller ).is_a?( RPbdb::Settings::Database::Join ).should == true
  end

  # RPbdb::Settings::Database::Join.new( database )
  it "can be created with a database" do
    RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) ).is_a?( RPbdb::Settings::Database::Join ).should == true
  end

  # RPbdb::Settings::Database::Join.new( settings_controller )
  it "can be created with a settings controller" do
    RPbdb::Settings::Database::Join.new( RPbdb::Settings.new ).is_a?( RPbdb::Settings::Database::Join ).should == true
  end

  # RPbdb::Settings::Database::Join.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPbdb::Settings::Database::Join.new( RPbdb::Settings::Database.new ).is_a?( RPbdb::Settings::Database::Join ).should == true
  end

  # RPbdb::Settings::Database::Join.new
  it "can be created with no argument specified" do
    RPbdb::Settings::Database::Join.new.is_a?( RPbdb::Settings::Database::Join ).should == true
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    # with settings controller
    RPbdb::Settings::Database::Join.new.parent_environment.is_a?( RPbdb::Environment ).should == true
    # with database
    RPbdb::Settings::Database::Join.new.parent_environment.is_a?( RPbdb::Environment ).should == true
    # with join cursor
    RPbdb::Settings::Database::Join.new.parent_environment.is_a?( RPbdb::Environment ).should == true
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    # with settings controller
    RPbdb::Settings::Database::Join.new.parent_database.should == nil
    # with database
    RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) ).parent_database.is_a?( RPbdb::Database ).should == true
    # with join cursor
    raise "Join cursor"
    RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) ).parent_database.is_a?( RPbdb::Database ).should == true
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Join.new.parent_settings_controller.is_a?( RPbdb::Settings ).should == true
    # with database
    RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) ).parent_settings_controller.is_a?( RPbdb::Settings ).should == true
    # with join cursor
    raise "Join cursor"
    RPbdb::Settings::Database::Join.new.parent_settings_controller.is_a?( RPbdb::Settings ).should == true
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "can return its parent database settings controller" do
    # with settings controller
    RPbdb::Settings::Database::Join.new.parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
    # with database
    RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) ).parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
    # with join cursor
    raise "Join cursor"
    RPbdb::Settings::Database::Join.new.parent_database_settings_controller.is_a?( RPbdb::Settings::Database ).should == true
  end

  ###################################
  #  degree_one_isolation?          #
	#  turn_degree_one_isolation_on   #
	#  turn_degree_one_isolation_off  #
  ###################################

  it "can return records using degree one isolation, which reads data that has been modified but not yet committed in addition to committed data." do
    # with settings controller
    join_settings = RPbdb::Settings::Database::Join.new
    test_degree_one_isolation( join_settings )
    # with database
    join_settings = RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) )
    test_degree_one_isolation( join_settings )
    # with join cursor
    raise "Join cursor"
    join_settings = RPbdb::Settings::Database::Join.new
    test_degree_one_isolation( join_settings )
  end
  
  def test_degree_one_isolation( join_settings )
    
    join_settings.degree_one_isolation?.should == false
    join_settings.turn_degree_one_isolation_on
    join_settings.degree_one_isolation?.should == true
    join_settings.turn_degree_one_isolation_off
    join_settings.degree_one_isolation?.should == false

  end

  ################################################
  #  write_locks_instead_of_read_locks?          #
	#  turn_write_locks_instead_of_read_locks_on   #
	#  turn_write_locks_instead_of_read_locks_off  #
  ################################################

  it "can use write locks instead of read locks" do
    # with settings controller
    join_settings = RPbdb::Settings::Database::Join.new
    test_write_locks_instead_of_read_locks( join_settings )
    # with database
    join_settings = RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) )
    test_write_locks_instead_of_read_locks( join_settings )
    # with join cursor
    raise "Join cursor"
    join_settings = RPbdb::Settings::Database::Join.new
    test_write_locks_instead_of_read_locks( join_settings )
  end

  def test_write_locks_instead_of_read_locks( join_settings )

    join_settings.write_locks_instead_of_read_locks?.should == false
    join_settings.turn_write_locks_instead_of_read_locks_on
    join_settings.write_locks_instead_of_read_locks?.should == true
    join_settings.turn_write_locks_instead_of_read_locks_off
    join_settings.write_locks_instead_of_read_locks?.should == false
    
  end

  ##################################
  #  no_sort_before_join?          #
	#  turn_no_sort_before_join_on   #
	#  turn_no_sort_before_join_off  #
  ##################################

  it "can skip sorting before joining" do
    # with settings controller
    join_settings = RPbdb::Settings::Database::Join.new
    test_no_sort_before_join( join_settings )
    # with database
    join_settings = RPbdb::Settings::Database::Join.new( RPbdb::Database.new( $database_name ) )
    test_no_sort_before_join( join_settings )
    # with join cursor
    raise "Join cursor"
    join_settings = RPbdb::Settings::Database::Join.new
    test_no_sort_before_join( join_settings )
  end

  def test_no_sort_before_join( join_settings )
    
    join_settings.no_sort_before_join?.should == false
    join_settings.turn_no_sort_before_join_on
    join_settings.no_sort_before_join?.should == true
    join_settings.turn_no_sort_before_join_off
    join_settings.no_sort_before_join?.should == false

  end

end

