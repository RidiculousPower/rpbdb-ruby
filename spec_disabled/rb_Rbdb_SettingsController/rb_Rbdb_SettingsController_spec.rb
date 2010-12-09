require_relative '../../../../lib/rbdb/rbdb'

describe Rbdb::Environment::SettingsController do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rbdb_spec_environment_home'

  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_name, $environment_path )
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

  # Rbdb::Environment::SettingsController::Database.new( environment )
  # Rbdb::Environment::SettingsController::Database.new( environment_name ) 
  # Rbdb::Environment::SettingsController::Database.new
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
