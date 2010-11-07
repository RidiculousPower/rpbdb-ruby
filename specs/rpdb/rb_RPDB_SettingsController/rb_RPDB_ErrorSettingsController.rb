require_relative '../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Error do

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

  # RPDB::Environment::Settings::Error.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Error.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Error.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Error.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Error.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Error.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  it "" do
    Fail
  end

  ################
  #  initialize  #
  ################

  it "" do
    Fail
  end

  ########################
  #  parent_environment  #
  ########################

  it "" do
    Fail
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "" do
    Fail
  end

  ##########
  #  file  #
  ##########

  it "" do
    Fail
  end

  	##############
  	#  set_file  #
  	##############

    it "" do
      Fail
    end

  ############
  #  prefix  #
  ############

  it "" do
    Fail
  end

  	################
  	#  set_prefix  #
  	################

    it "" do
      Fail
    end

  ###############################
  #  set_error_callback_method  #
  ###############################

  it "" do
    Fail
  end

  ###########################
  #  error_callback_method  #
  ###########################

  it "" do
    Fail
  end

end

