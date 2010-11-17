require_relative 'lib/rpdb.rb'

describe RPDB::Database::Controller do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path ).open

  end

  after( :each ) do
    @environment.close
  end




  it "can turn system buffering on and off" do
    log_settings  = RPDB::Settings::Log.new( @environment )
    log_settings.disable_system_buffering?.should == false
    log_settings.turn_disable_system_buffering_on
    log_settings.disable_system_buffering?.should == true
    log_settings.turn_disable_system_buffering_off
    log_settings.disable_system_buffering?.should == false
  end
 

end
