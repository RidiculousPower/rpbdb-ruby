require_relative '../../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database::SequenceController do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpdb_spec_environment_home'

  before( :each ) do
    @environment = RPDB::Environment.new( $environment_name, $environment_path )
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

  # RPDB::Environment::DatabaseController::Database::SequenceController.new( database )
  # RPDB::Environment::DatabaseController::Database::SequenceController.new( database_name )
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
