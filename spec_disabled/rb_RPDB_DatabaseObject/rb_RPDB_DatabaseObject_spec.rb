require_relative '../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpdb_spec_environment_home'

  before( :each ) do
    @environment = RPDB::Environment.new( $environment_name, $environment_path )
    @environment.open
  end

  after( :each ) do
    @environment.close
  end

  #############
  #  include  #
  #############

  # include RPDB
  
  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
