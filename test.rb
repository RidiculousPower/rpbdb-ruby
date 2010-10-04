require_relative 'lib/rpdb.rb'

$environment_path           = '/tmp/rpdb_spec_environment_home/'

$database_name              = :spec_database
$secondary_database_name    = $database_name.to_s + '_secondary'
$database_new_name          = :spec_database_renamed
$database_extension         = '.db'
$duplicates_database_name   = :duplicates_db




@environment = RPDB::Environment.new( $environment_path )
@environment.open






database = @environment.database.new( $database_name ).open
#database.write( "key" => 'some data' )
#database.delete( :value => 'some data' )

#database.retrieve( "data" ).should == nil    
#database.retrieve( "key", "data" ).should == nil    
#database.retrieve( "key" => "data" ).should == nil    
#database.retrieve( "key" => [ "data" ] ).should == nil    






@environment.close
