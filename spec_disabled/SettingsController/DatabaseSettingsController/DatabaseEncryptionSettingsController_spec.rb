require_relative '../../../../lib/rpbdb/rpbdb'

describe RPbdb::Environment::SettingsController::DatabaseSettingsController::DatabaseEncryptionSettingsController do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpbdb_spec_environment_home'

  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_name, $environment_path )
    @environment.open
    @settings_controller  = @environment.settings_controller
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPbdb::Environment::SettingsController::Database.new( environment )
  # RPbdb::Environment::SettingsController::Database.new( environment_name ) 
  # RPbdb::Environment::SettingsController::Database.new
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
