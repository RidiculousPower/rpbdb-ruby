require_relative '../../../../../lib/rbdb/rbdb'

describe Rbdb::Database::Sequence::Controller do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $sequence_name              = :spec_sequence
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller
    @database = @database_controller.database( $database_name ).open
  end

  after( :each ) do
    @database.close
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # Rbdb::Database::Sequence::Controller.new( database )
  it "can be created with a parent database" do
    Rbdb::Database::Sequence::Controller.new( @database ).should_not == nil
  end

  # Rbdb::Database::Sequence::Controller.new( database )
  it "can be created with a database name" do
    Rbdb::Database::Sequence::Controller.new( @database.name ).should_not == nil
  end

  # Rbdb::Database::Sequence::Controller.new( environment, database_name ) 
  it "can be created with a parent database controller and a database name" do
    Rbdb::Database::Sequence::Controller.new( @environment, @database.name ).should_not == nil  
  end

  # Rbdb::Database::Sequence::Controller.new( environment, database_name ) 
  it "can be created with a parent environment and a database name" do
    Rbdb::Database::Sequence::Controller.new( @environment, @database.name ).should_not == nil  
  end

  # Rbdb::Database::Sequence::Controller.new( environment_directory, database_name ) 
  it "can be created with a parent environment home directory and a database name" do
    Rbdb::Database::Sequence::Controller.new( $environment_path, @database.name ).should_not == nil  
  end

  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    @database.sequences.settings_controller.should_not == nil
    @database.sequences.settings_controller.should_not == @environment.settings.database.sequence
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    @database.sequences.parent_environment.should == @environment
  end
  
  #####################
  #  parent_database  #
  #####################

  it "can refer to its parent database" do
    @database.sequences.parent_database.should == @database
  end
  
  ##############
  #  sequence  #
  ##############

  it "can return a sequence" do
    @database.sequence( $sequence_name ).is_a?( Rbdb::Database::Sequence ).should == true
  end
  
end
