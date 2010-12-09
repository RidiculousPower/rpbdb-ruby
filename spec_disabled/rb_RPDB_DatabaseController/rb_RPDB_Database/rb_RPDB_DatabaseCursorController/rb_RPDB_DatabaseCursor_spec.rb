require_relative '../../../../../lib/rbdb/rbdb'

describe Rbdb::Environment::DatabaseController::Database::CursorController::Cursor do

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

  # Rbdb::Environment::DatabaseController::Database::CursorController::Cursor.new( environment )
  # Rbdb::Environment::DatabaseController::Database::CursorController::Cursor.new( environment_name ) 
  # Rbdb::Environment::DatabaseController::Database::CursorController::Cursor.new( database_controller ) 
  # Rbdb::Environment::DatabaseController::Database::CursorController::Cursor.new
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
