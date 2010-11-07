require_relative '../../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Cursor::ReadWrite do

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

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_cursor_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ).cursor_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_cursor )
  it "can be created with a database cursor" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( @environment.database_controller.new( $database_name ).cursor ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Cursor::ReadWrite.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Cursor::ReadWrite.new.should_not == nil
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

  #####################
  #  parent_database  #
  #####################

  it "" do
    Fail
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "" do
    Fail
  end

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  it "" do
    Fail
  end

  ################################################
  #  parent_database_cursor_settings_controller  #
  ################################################

  it "" do
    Fail
  end

  ##################
  #  permit_write  #
  ##################

  it "" do
    Fail
  end

  	#####################
  	#  permit_write_on  #
  	#####################

    it "" do
      Fail
    end

  	######################
  	#  permit_write_off  #
  	######################

    it "" do
      Fail
    end

  ##################
  #  ignore_lease  #
  ##################

  it "" do
    Fail
  end

  	#####################
  	#  ignore_lease_on  #
  	#####################

    it "" do
      Fail
    end

  	######################
  	#  ignore_lease_off  #
  	######################

    it "" do
      Fail
    end

  #######################################
  #  write_locks_instead_of_read_locks  #
  #######################################

  it "" do
    Fail
  end

  	###############################################
  	#  turn_write_locks_instead_of_read_locks_on  #
  	###############################################

    it "" do
      Fail
    end

  	################################################
  	#  turn_write_locks_instead_of_read_locks_off  #
  	################################################

    it "" do
      Fail
    end

  ################################
  #  return_multiple_data_items  #
  ################################

  it "" do
    Fail
  end

  	########################################
  	#  turn_return_multiple_data_items_on  #
  	########################################

    it "" do
      Fail
    end

  	#########################################
  	#  turn_return_multiple_data_items_off  #
  	#########################################

    it "" do
      Fail
    end

  ####################################
  #  return_multiple_key_data_pairs  #
  ####################################

  it "" do
    Fail
  end

  	############################################
  	#  turn_return_multiple_key_data_pairs_on  #
  	############################################

    it "" do
      Fail
    end

  	#############################################
  	#  turn_return_multiple_key_data_pairs_off  #
  	#############################################

    it "" do
      Fail
    end

end

