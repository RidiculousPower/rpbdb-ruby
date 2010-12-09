require_relative '../../../lib/rbdb/rbdb'

describe Rbdb::Environment::DatabaseController::ObjectDatabase do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rbdb_spec_environment_home'

  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_name, $environment_path )
    @environment.open
    @database_controller  = @environment.database_controller
    @database             = @database_controller.database
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # Rbdb::Environment::DatabaseController::ObjectDatabase.new( environment )
  # Rbdb::Environment::DatabaseController::ObjectDatabase.new( environment_name ) 
  # Rbdb::Environment::DatabaseController::ObjectDatabase.new( database_controller ) 
  # Rbdb::Environment::DatabaseController::ObjectDatabase.new
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
