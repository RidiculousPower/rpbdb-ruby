require_relative '../../../lib/rpbdb/rpbdb'

describe RPbdb::Environment::Record::Key::SecondaryKeys do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpbdb_spec_environment_home'

  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_name, $environment_path )
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
