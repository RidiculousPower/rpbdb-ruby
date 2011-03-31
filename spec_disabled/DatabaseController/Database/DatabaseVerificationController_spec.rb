require_relative '../../../../lib/rpbdb/rpbdb'

describe RPbdb::Environment::DatabaseController::Database do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpbdb_spec_environment_home'

  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_name, $environment_path )
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

  # RPbdb::Environment::DatabaseController::DatabaseVerificationController.new( environment )
  # RPbdb::Environment::DatabaseController::DatabaseVerificationController.new( environment_name ) 
  # RPbdb::Environment::DatabaseController::DatabaseVerificationController.new( database_controller ) 
  # RPbdb::Environment::DatabaseController::DatabaseVerificationController.new
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
