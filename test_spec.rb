require_relative 'lib/rpdb.rb'

describe RPDB::Database::Controller do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = RPDB::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller

  end

  after( :each ) do
    @environment.close
  end




  it "can set its cache size according to various measures" do
    database_cache_settings = RPDB::Settings::Database::Cache.new

    database_cache_settings.set_max_size_in_bytes( 12 )
    database_cache_settings.max_size_in_bytes.should == 12

    database_cache_settings.set_max_size_in_kbytes( 42 )
    database_cache_settings.max_size_in_kbytes.should == 42 * 1024

    database_cache_settings.set_max_size_in_mbytes( 37 )
    database_cache_settings.max_size_in_mbytes.should == 37 * ( 1024 * 1024 )

    database_cache_settings.set_max_size_in_gbytes( 420 )
    database_cache_settings.max_size_in_gbytes.should == 420 * ( 1024 * 1024 * 1024 )

    database_cache_settings.set_max_size_in_gbytes_mbytes_kbytes_bytes( 420, 37, 42, 12 )
    database_cache_settings.max_size_in_bytes.should == 420 * ( 1024 * 1024 * 1024 ) + 37 * ( 1024 * 1024 ) + 42 * 1024 + 12

    database_cache_settings.set_max_size_in_mbytes_kbytes_bytes( 37, 42, 12 )
    database_cache_settings.max_size_in_bytes.should == 37 * ( 1024 * 1024 )

    database_cache_settings.set_max_size_in_kbytes_bytes( 42, 12 )
    database_cache_settings.max_size_in_bytes.should == 42 * 1024 + 12
    
  end



end
