require_relative '/Users/asher/Projects/rp/rbdb/ruby/lib/rbdb/rbdb'

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

  ##################
  #  step          #
  #  step( # )     #
  #  step_by( # )  #
  ##################

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

