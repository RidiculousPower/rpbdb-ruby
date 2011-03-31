require_relative '../../../../../lib/rpbdb/rpbdb'

describe RPbdb::Environment::DatabaseController::Database::SequenceController do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpbdb_spec_environment_home'

  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_name, $environment_path )
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

  # RPbdb::Environment::DatabaseController::Database::SequenceController.new( database )
  # RPbdb::Environment::DatabaseController::Database::SequenceController.new( database_name )
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
