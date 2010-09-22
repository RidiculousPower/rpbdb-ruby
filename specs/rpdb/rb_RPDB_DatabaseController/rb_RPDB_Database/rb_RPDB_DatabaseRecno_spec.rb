require_relative '../../../../lib/rpdb/rpdb'

describe RPDB::Environment::DatabaseController::Database::Recno do

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

  ###########
  #  shift  #
  ###########
  
  # shift
  it "can shift the first record" do
    Fail
  end
  
  #############
  #  unshift  #
  #############

  # unshift
  it "can unshift to become the first record" do
    Fail
  end

  #########
  #  pop  #
  #########

  # pop
  it "can pop the last record" do
    Fail
  end

  ##########
  #  push  #
  ##########

  # push
  it "can push to become the last record" do
    Fail
  end
  
end
