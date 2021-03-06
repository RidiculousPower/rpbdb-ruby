require_relative '../../lib/rpbdb.rb'

describe RPbdb do

  $environment_name           = :spec_environment
  $environment_path             = '/tmp/rpbdb_spec_environment_home/'

  #############
  #  version  #
  #############

  # example: Berkeley DB 5.0.26: (June 25, 2010)
  it "should provide version" do
    RPbdb.version.should_not == nil
  end
  
  ###################
  #  version_major  #
  #  version_minor  #
  #  version_patch  #
  #  version_parts  #
  ###################
  
  it "should provide version parts" do

    version_parts_hash = RPbdb.version_parts
      
    assembled_version_parts_hash  =   { :major  =>  RPbdb.version_major,
                                        :minor  =>  RPbdb.version_minor,
                                        :patch  =>  RPbdb.version_patch }

    assembled_version_parts_hash.should == version_parts_hash

    # we want the first 13 letters "Berkeley DB " plus the 2 periods and the digits in major, minor, patch (probably 1, 1, 1-2)
    version_string_front_end = RPbdb.version.slice( 0, 13 + 2 +  version_parts_hash[ :major ].to_s.length + 
                                                                version_parts_hash[ :minor ].to_s.length + 
                                                                version_parts_hash[ :patch ].to_s.length - 1 )
    
    # we want to compare the start of the string
    version_part_string = "Berkeley DB " + version_parts_hash[ :major ].to_s + '.' + version_parts_hash[ :minor ].to_s + '.' + version_parts_hash[ :patch ].to_s
    
    version_part_string.should == version_string_front_end
    
  end
  
end
