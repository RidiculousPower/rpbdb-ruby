require_relative '../../../../../lib/rbdb/rbdb'

describe Rbdb::Environment::DatabaseController::Database::SequenceController::Sequence do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rbdb_spec_environment_home'

  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_name, $environment_path )
    @environment.open
    @database_controller  = @environment.database_controller
    @database             = @database_controller.database
    @sequence_controller  = @database.sequence_controller
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # Rbdb::Environment::DatabaseController::Database::SequenceController::Sequence.new( database )
  # Rbdb::Environment::DatabaseController::Database::SequenceController::Sequence.new( database_name ) 
  # Rbdb::Environment::DatabaseController::Database::SequenceController::Sequence.new( sequence_controller ) 
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
