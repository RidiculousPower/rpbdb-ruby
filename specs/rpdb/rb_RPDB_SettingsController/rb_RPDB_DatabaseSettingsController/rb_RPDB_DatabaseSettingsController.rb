require_relative '../../../../lib/rpdb.rb'

describe RPDB::Settings::Database do

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

  # RPDB::Settings::Database.new( environment )
  it "can be created with an environment" do
    RPDB::Settings::Database.new( @environment ).should_not == nil
  end

  # RPDB::Settings::Database.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Settings::Database.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Settings::Database.new( database )
  it "can be created with a database" do
    RPDB::Settings::Database.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Settings::Database.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Settings::Database.new( RPDB::Settings.new ).should_not == nil
  end

  # RPDB::Settings::Database.new
  it "can be created with no argument specified" do
    RPDB::Settings::Database.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    RPDB::Settings::Database.new.parent_environment.should_not == nil
  end

  #####################
  #  parent_database  #
  #####################

  it "can return its parent database" do
    RPDB::Settings::Database.new( RPDB::Database.new( $database_name ) ).parent_environment.should_not == nil
  end

  ##############
  #  checksum  #
  ##############

  it "" do
    Fail
  end

  	######################
  	#  turn_checksum_on  #
  	######################

    it "" do
      Fail
    end

  	#######################
  	#  turn_checksum_off  #
  	#######################

    it "" do
      Fail
    end

  ##########
  #  logs  #
  ##########

  it "" do
    Fail
  end

  	##################
  	#  turn_logs_on  #
  	##################

    it "" do
      Fail
    end

  	###################
  	#  turn_logs_off  #
  	###################

    it "" do
      Fail
    end

  ##############
  #  pagesize  #
  ##############

  it "" do
    Fail
  end

  ##################
  #  set_pagesize  #
  ##################

  it "" do
    Fail
  end

  ####################
  #  is_big_endian?  #
  ####################

  it "" do
    Fail
  end

  ##################################
  #  set_byte_order_to_big_endian  #
  ##################################

  it "" do
    Fail
  end

  #######################
  #  is_little_endian?  #
  #######################

  it "" do
    Fail
  end

  #####################################
  #  set_byte_order_to_little_endian  #
  #####################################

  it "" do
    Fail
  end

  #####################
  #  is_byteswapped?  #
  #####################

  it "" do
    Fail
  end
  
  ###############################
  #  error_settings_controller  #
  ###############################

  it "" do
    Fail
  end

  #####################################
  #  association_settings_controller  #
  #####################################

  it "" do
    Fail
  end
 
  #####################
  #  join_controller  #
  #####################

  it "" do
    Fail
  end

  ######################
  #  cache_controller  #
  ######################

  it "" do
    Fail
  end

  #######################
  #  cursor_controller  #
  #######################

  it "" do
    Fail
  end

  ##################################
  #  sequence_settings_controller  #
  ##################################

  it "" do
    Fail
  end

  ##############################
  #  type_settings_controller  #
  ##############################

  it "" do
    Fail
  end

  ####################################
  #  read_write_settings_controller  #
  ####################################

  it "" do
    Fail
  end

  ################################
  #  record_settings_controller  #
  ################################

  it "" do
    Fail
  end

end

