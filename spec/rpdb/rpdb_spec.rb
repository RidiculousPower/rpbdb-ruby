require_relative '../../lib/rpdb.rb'

describe RPDB do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpdb_spec_environment_home'

  #############
  #  version  #
  #############

  # example: Berkeley DB 5.0.26: (June 25, 2010)
  it "should provide version" do
    RPDB.version.should_not == nil
  end
  
  ###################
  #  version_major  #
  #  version_minor  #
  #  version_patch  #
  #  version_parts  #
  ###################
  
  it "should provide version parts" do

    version_parts_hash = RPDB.version_parts
      
    assembled_version_parts_hash  =   { :major  =>  RPDB.version_major,
                                        :minor  =>  RPDB.version_minor,
                                        :patch  =>  RPDB.version_patch }

    assembled_version_parts_hash.should == version_parts_hash

    # we want the first 13 letters "Berkeley DB " plus the 2 periods and the digits in major, minor, patch (probably 1, 1, 1-2)
    version_string_front_end = RPDB.version.slice( 0, 13 + 2 +  version_parts_hash[ :major ].to_s.length + 
                                                                version_parts_hash[ :minor ].to_s.length + 
                                                                version_parts_hash[ :patch ].to_s.length - 1 )
    
    # we want to compare the start of the string
    version_part_string = "Berkeley DB " + version_parts_hash[ :major ].to_s + '.' + version_parts_hash[ :minor ].to_s + '.' + version_parts_hash[ :patch ].to_s
    
    version_part_string.should == version_string_front_end
    
  end
  
  ##################
  #  environments  #
  ##################
  
  it "can provide references to existing environments" do
    environments_hash = RPDB.environments
    environments_hash.should_not == nil
    environments_hash.is_a?( Hash ).should == true
  end

  it "can provide access to an existing environment by name" do
    environment = RPDB::Environment.new( $environment_name, $environment_path )
    same_environment = RPDB.environment( $environment_name )
    same_environment.should == environment
    # make sure we don't get an environment that doesn't exist - as much as possible
    non_existant = RPDB.environment( :non_existant_name )
    non_existant.should == nil
  end
  
end
