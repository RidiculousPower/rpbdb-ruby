require_relative '../../../../../lib/rbdb/rbdb'

describe Rbdb::Database::Sequence do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $sequence_name              = :spec_sequence
  $other_sequence_name        = :other_spec_sequence_name
  
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

  # Rbdb::Database::Sequence.new( database_sequence_controller )
  it "can be created with a name, a parent database sequence controller" do
    Rbdb::Database::Sequence.new( $sequence_name, @database.sequence_controller ).should_not == nil
  end

  # Rbdb::Database::Sequence.new( database )
  it "can be created with a name and a parent database" do
    Rbdb::Database::Sequence.new( $sequence_name, @database ).should_not == nil
  end

  # Rbdb::Database::Sequence.new( database )
  it "can be created with a name and a database name" do
    Rbdb::Database::Sequence.new( $sequence_name, @database.name ).should_not == nil
  end

  # Rbdb::Database::Sequence.new( environment, database_name ) 
  it "can be created with a name, a database controller and a database name" do
    Rbdb::Database::Sequence.new( $sequence_name, @database_controller, @database.name ).should_not == nil  
  end

  # Rbdb::Database::Sequence.new( environment, database_name ) 
  it "can be created with a name, a parent environment and a database name" do
    Rbdb::Database::Sequence.new( $sequence_name, @environment, @database.name ).should_not == nil  
  end

  # Rbdb::Database::Sequence.new( environment_directory, database_name ) 
  it "can be created with a name, a parent environment home directory and a database name" do
    Rbdb::Database::Sequence.new( $sequence_name, $environment_path, @database.name ).should_not == nil  
  end

  ##############
  #  open      #
  #  close     #
  #  is_open?  #
  ##############

  it "can be opened and close as well as report on its status" do
    sequence = @database.sequence( $sequence_name )
    sequence.is_open?.should == false
    sequence.open.is_open?.should == true
    sequence.close.is_open?.should == false
  end

  ##################
  #  step          #
  #  step( # )     #
  #  step_by( # )  #
  ##################

  it "can step by one or by any number" do
    sequence = @database.sequence( $sequence_name )
    sequence.delete!
    sequence.step.should == 0
    # we step by 2 which gives back 1[, 2]
    sequence.step_by( 2 ).should == 1
    # so our next is 3[, 4]
    sequence.step_by( 2 ).should == 3
    # and then 6
    sequence.step.should == 5
    sequence.delete!
  end

  ############
  #  delete  #
  ############

  it "can delete itself" do
    sequence = @database.sequence( $sequence_name )
    sequence.delete!
    sequence.step.should == 0
    sequence.step.should == 1
    sequence.delete!
    sequence.step.should == 0
    sequence.delete!
  end

  ############
  #  rename  #
  ############

  it "can rename itself" do
    sequence = @database.sequence( $sequence_name )
    sequence.step_by( 10 ).should == 0
    renamed_sequence = sequence.rename!( $other_sequence_name )
    sequence_new = @database.sequence( $sequence_name )
    sequence_new.step.should == 0
    renamed_sequence.step.should == 9
    sequence_new.delete!
    renamed_sequence.delete!
  end

end

