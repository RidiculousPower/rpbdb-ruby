require_relative '../../../lib/rpdb.rb'

describe RPDB::Settings do

  $environment_path           = '/tmp/rpdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  ################
  #  self.new    #
  #  initialize  #
  ################

  # RPDB::Settings.new( environment )
  it "can be created with an environment" do
    environment = RPDB::Environment.new( $environment_path ).open
    RPDB::Settings.new( environment ).should_not == nil
    environment.close
  end

  # RPDB::Settings.new
  it "can be created with no argument specified" do
    environment = RPDB::Environment.new( $environment_path ).open
    RPDB::Settings.new.should_not == nil
    environment.close
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    environment = RPDB::Environment.new( $environment_path ).open
    RPDB::Settings.new.parent_environment.should_not == nil
    environment.close
  end

  #################
  #  set_shm_key  #
  #  shm_key      #
  #################

  it "can set and return its shm base ID for shared memory spaces" do
    environment = RPDB::Environment.new( $environment_path )
    shm_key = 1
    environment.settings.shm_key         = shm_key
    environment.settings.shm_key.should == shm_key
  end

  ##############################
  #  file_settings_controller  #
  ##############################

  it "can return its file settings controller" do
    RPDB::Environment.new( $environment_path ).settings.file_settings_controller.should_not == nil
  end

  ###############################
  #  error_settings_controller  #
  ###############################

  it "can return its error settings controller" do
    RPDB::Environment.new( $environment_path ).settings.error_settings_controller.should_not == nil
  end

  #############################
  #  log_settings_controller  #
  #############################

  it "can return its log settings controller" do
    RPDB::Environment.new( $environment_path ).settings.log_settings_controller.should_not == nil
  end

  ##############################
  #  lock_settings_controller  #
  ##############################

  it "can return its lock settings controller" do
    RPDB::Environment.new( $environment_path ).settings.lock_settings_controller.should_not == nil
  end

  #####################################
  #  replication_settings_controller  #
  #####################################

  it "can return its replication settings controller" do
    RPDB::Environment.new( $environment_path ).settings.replication_settings_controller.should_not == nil
  end

  #####################################
  #  memory_pool_settings_controller  #
  #####################################

  it "can return its memory pool settings controller" do
    RPDB::Environment.new( $environment_path ).settings.memory_pool_settings_controller.should_not == nil
  end

  ##################################
  #  database_settings_controller  #
  ##################################

  it "can return its database settings controller" do
    RPDB::Environment.new( $environment_path ).settings.database_settings_controller.should_not == nil
  end

  ###################################
  #  directory_settings_controller  #
  ###################################

  it "can return its directory settings controller" do
    RPDB::Environment.new( $environment_path ).settings.directory_settings_controller.should_not == nil
  end

end

