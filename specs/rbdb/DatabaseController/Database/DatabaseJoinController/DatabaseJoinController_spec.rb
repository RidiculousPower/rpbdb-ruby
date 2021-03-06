require_relative '../../../../../lib/rpbdb/rpbdb'

describe RPbdb::Database::JoinController do

  $environment_path           = '/tmp/rpbdb_spec_environment_home/'

  $database_name              = :spec_database
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  
  before( :each ) do
    @environment = RPbdb::Environment.new( $environment_path )
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

  # RPbdb::Database::JoinController.new( database )
  it "can be created with a parent database" do
    RPbdb::Database::JoinController.new( @database ).should_not == nil
  end

  # RPbdb::Database::JoinController.new( environment, database_name ) 
  it "can be created with a parent environment and a database name" do
    RPbdb::Database::JoinController.new( @environment, @database.name ).should_not == nil  
  end

  # RPbdb::Database::JoinController.new( environment_directory, database_name ) 
  it "can be created with a parent environment home directory and a database name" do
    RPbdb::Database::JoinController.new( $environment_path, @database.name ).should_not == nil  
  end

  #########################
  #  settings_controller  #
  #########################

  it "has a local settings controller" do
    @database.join.settings_controller.should_not == nil
    @database.join.settings_controller.should_not == @environment.settings.database.join
  end
  
  ########################
  #  parent_environment  #
  ########################

  it "can refer to its parent environment" do
    @database.join.parent_environment.should == @environment
  end

  #####################
  #  parent_database  #
  #####################

  it "can refer to its parent database" do
    @database.join.parent_database.should == @database
  end

  ##########
  #  join  #
  ##########
  
  it "can perform a join and return a join cursor" do
    letters_database = @database.create_secondary_index( :letters ) do |key, data|
      return key.chars.to_a
    end
    vowels_database = @database.create_secondary_index( :vowels ) do |key, data|
      return key.chars.select { |char| 'aeiou'.chars.include?( char ) }
    end
    @database.write( "n vwls" => "one value" )
    @database.write( "some vowels" => "another value" )
    @database.write( "and every vowel but i and y" => "yet another value" )
    require 'pp'
    pp @database.retrieve( "n vwls" )
    cursor = vowels_database.cursor
pp     cursor.first
#    cursor.each do |key, value, index|
#      puts 'record #' + index.to_s + ' had key "' + key + '" and value "' + value + '".'
#    end
#    vowels_database.retrieve( 'e' ).should_not == nil
#    join_cursor = @database.join.cursor(  :vowels   => 'e',
#                                          :letters  => 'm' )
#    join_cursor.should_not == nil
  end

  ##########################
  #  join_list_of_cursors  #
  ##########################
  
  it "can perform a join and return a join cursor" do
    raise "Failed."
  end

  #######################
  #  close_all_cursors  #
  #  close_all          #
  #######################

  it "can close all join" do
    raise "Failed."
  end
  
end
