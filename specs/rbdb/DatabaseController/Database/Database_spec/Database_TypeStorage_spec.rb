require_relative '../../../../../lib/rpbdb/rpbdb'

describe RPbdb::Database do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $unsorted_duplicates_database_name   = :unsorted_duplicates_db
  $sorted_duplicates_database_name   = :sorted_duplicates_db
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
    @environment.open
    @database_controller = @environment.database_controller
  end

  after( :each ) do
    @environment.close
  end

  ################################
  #  type storage and retrieval  #
  ################################

  it "can store typed key/data values and restore those typed objects from storage" do

    database = @database_controller.new( $database_name )
    database.settings.read_write.turn_record_typing_on
    
    # string
    string = "string"
    database.write( :string => string )
    database.retrieve( :string ).should == string
    database.write( string => :string )
    database.retrieve( string ).should == :string
    
    # symbol
    symbol = :symbol
    database.write( :symbol => symbol )
    database.retrieve( :symbol ).should == symbol
    database.write( symbol => :symbol )
    database.retrieve( symbol ).should == :symbol
    
    # regexp
    regexp = Regexp.new( /[A-Za-z]+/ )
    database.write( :regexp => regexp )
    database.retrieve( :regexp ).should == regexp
    database.write( regexp => :regexp )
    database.retrieve( regexp ).should == :regexp
    
    # class (name)
    klass = RPbdb::Database
    database.write( :class => klass )
    database.retrieve( :class ).should == klass
    database.write( klass => :class )
    database.retrieve( klass ).should == :class
    
    # integer
    integer = 42
    database.write( :integer => integer )
    database.retrieve( :integer ).should == integer
    database.write( integer => :integer )
    database.retrieve( integer ).should == :integer
    
    # float
    float = 42.0
    database.write( :float => float )
    database.retrieve( :float ).should == float
    database.write( float => :float )
    database.retrieve( float ).should == :float
    
    # complex
    complex = Complex( 42, 37 )
    database.write( :complex => complex )
    database.retrieve( :complex ).should == complex
    database.write( complex => :complex )
    database.retrieve( complex ).should == :complex
    
    # rational
    rational = Rational( 42, 37 )
    database.write( :rational => rational )
    database.retrieve( :rational ).should == rational
    database.write( rational => :rational )
    database.retrieve( rational ).should == :rational
    
    # true/false
    true_false = true
    database.write( :true_false => true_false )
    database.retrieve( :true_false ).should == true_false
    database.write( true_false => :true_false )
    database.retrieve( true_false ).should == :true_false
    
    # file as path
    file_as_path = __FILE__
    database.write( :file_as_path => file_as_path )
    database.retrieve( :file_as_path ).should == file_as_path
    database.write( file_as_path => :file_as_path )
    database.retrieve( file_as_path ).should == :file_as_path
    
    # file as contents
    database.settings.read_write.turn_store_file_not_path_on
    database.write( :file_as_contents => File.open( __FILE__ ) )
    database.retrieve( :file_as_contents ).should == File.open( __FILE__ ).readlines.join( "\n" )
    database.write( File.open( __FILE__ ) => :file_as_contents )
    database.retrieve( File.open( __FILE__ ) ).should == :file_as_contents

  end

end

