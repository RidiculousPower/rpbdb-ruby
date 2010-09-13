require_relative 'lib/rpdb.rb'

$environment_path           = '/tmp/rpdb_spec_environment_home/'

$database_name              = :spec_database
$secondary_database_name    = $database_name.to_s + '_secondary'
$database_new_name          = :spec_database_renamed
$database_extension         = '.db'
$duplicates_database_name   = :duplicates_db




@environment = RPDB::Environment.new( $environment_path )
@environment.open
@database_controller = @environment.database_controller






database = @environment.database.new( $database_name ).open
database.create_secondary_index( :value ) do |key, value|
  return value
end







@environment = RPDB::Environment.new( $environment_path )
@environment.open
@database_controller = @environment.database_controller
