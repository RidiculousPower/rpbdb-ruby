require_relative '../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpdb_spec_environment_home'

  before( :each ) do
    @environment = RPDB::Environment.new( $environment_name, $environment_path )
    @environment.open
    @database_controller  = @environment.database_controller
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Environment::DatabaseController::DatabaseVerificationController.new( environment )
  # RPDB::Environment::DatabaseController::DatabaseVerificationController.new( environment_name ) 
  # RPDB::Environment::DatabaseController::DatabaseVerificationController.new( database_controller ) 
  # RPDB::Environment::DatabaseController::DatabaseVerificationController.new
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
