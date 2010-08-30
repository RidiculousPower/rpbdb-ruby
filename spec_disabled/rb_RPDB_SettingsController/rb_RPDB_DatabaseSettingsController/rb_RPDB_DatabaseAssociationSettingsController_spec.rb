require_relative '../../../../lib/rpdb/rpdb'

describe RPDB::Environment::SettingsController::DatabaseSettingsController::DatabaseAssociationSettingsController do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpdb_spec_environment_home'

  before( :each ) do
    @environment = RPDB::Environment.new( $environment_name, $environment_path )
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

  # RPDB::Environment::SettingsController::Database.new( environment )
  # RPDB::Environment::SettingsController::Database.new( environment_name ) 
  # RPDB::Environment::SettingsController::Database.new
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
