require_relative '../../../../lib/rpdb.rb'

describe RPDB::Environment::Settings::Database::Verification do

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

  # RPDB::Environment::Settings::Database::Verification.new( environment )
  it "can be created with an environment" do
    RPDB::Environment::Settings::Database::Verification.new( @environment ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Verification.new( database_controller )
  it "can be created with a database controller" do
    RPDB::Environment::Settings::Database::Verification.new( @environment.database_controller ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Verification.new( database )
  it "can be created with a database" do
    RPDB::Environment::Settings::Database::Verification.new( @environment.database_controller.new( $database_name ) ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Verification.new( settings_controller )
  it "can be created with a settings controller" do
    RPDB::Environment::Settings::Database::Verification.new( RPDB::Environment::Settings.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Verification.new( database_settings_controller )
  it "can be created with a database settings controller" do
    RPDB::Environment::Settings::Database::Verification.new( RPDB::Environment::Settings::Database.new ).should_not == nil
  end

  # RPDB::Environment::Settings::Database::Verification.new
  it "can be created with no argument specified" do
    RPDB::Environment::Settings::Database::Verification.new.should_not == nil
  end

  ##############
  #  self.new  #
  ##############

  ################
  #  initialize  #
  ################

  ########################
  #  parent_environment  #
  ########################

  #####################
  #  parent_database  #
  #####################

  ################################
  #  parent_settings_controller  #
  ################################

  #########################################
  #  parent_database_settings_controller  #
  #########################################

  ##########
  #  file  #
  ##########

  ##############
  #  set_file  #
  ##############

  ####################################
  #  aggressive_key_data_pair_dump?  #
  ####################################

  	###########################################
  	#  turn_aggressive_key_data_pair_dump_on  #
  	###########################################

  	############################################
  	#  turn_aggressive_key_data_pair_dump_off  #
  	############################################

  ###########################
  #  printable_characters?  #
  ###########################

  	##################################
  	#  turn_printable_characters_on  #
  	##################################

  	###################################
  	#  turn_printable_characters_off  #
  	###################################

  #######################
  #  skip_order_check?  #
  #######################

  	##############################
  	#  turn_skip_order_check_on  #
  	##############################

  	###############################
  	#  turn_skip_order_check_off  #
  	###############################

  #######################
  #  only_order_check?  #
  #######################

  	##############################
  	#  turn_only_order_check_on  #
  	##############################

  	###############################
  	#  turn_only_order_check_off  #
  	###############################

  ########################
  #  force_order_check?  #
  ########################

  	###############################
  	#  turn_force_order_check_on  #
  	###############################

  	################################
  	#  turn_force_order_check_off  #
  	################################

end

