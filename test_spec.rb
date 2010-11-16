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


  it "can perform order checking alone" do
    verification_settings  = RPDB::Settings::Database::Verification.new( RPDB::Database.new( $database_name ) )
    verification_settings.only_order_check?.should == false
    verification_settings.turn_skip_order_check_on
    verification_settings.parent_database.verify
    verification_settings.turn_only_order_check_on
    verification_settings.only_order_check?.should == true
    verification_settings.turn_only_order_check_off
    verification_settings.only_order_check?.should == false
  end

 

end
