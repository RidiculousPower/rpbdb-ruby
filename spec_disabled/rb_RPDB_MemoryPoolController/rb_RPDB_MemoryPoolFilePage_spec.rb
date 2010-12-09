require_relative '../../../lib/rbdb/rbdb'

describe Rbdb::Environment::MemoryPoolController::MemoryPoolFileController::MemoryPoolFile::MemoryPoolFilePageController::MemoryPoolFilePage do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rbdb_spec_environment_home'

  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_name, $environment_path )
    @environment.open
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  #########################
  #  settings_controller  #
  #########################

  ########################
  #  parent_environment  #
  ########################

end
