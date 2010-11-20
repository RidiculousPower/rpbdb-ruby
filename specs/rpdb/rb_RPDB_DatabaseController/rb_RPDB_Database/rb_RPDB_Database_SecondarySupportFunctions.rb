##########################################
#  Secondary Database Support Functions  #
##########################################

def key_from_data__lambda
  return lambda do |data|
    data.should_not == nil
    return data
  end
end

def key_from_key__lambda
  return lambda do |key, data|
    key.should_not == nil
    data.should_not == nil
    return key
  end
end

def key_from_database__lambda
  return lambda do |database, key, data|
    database.should_not == nil
    key.should_not == nil
    data.should_not == nil
    return database.name
  end
end

def secondary_key_test_elements
  return [  :key_from_data,
            key_from_data__lambda,
            :key_from_key,
            key_from_key__lambda,
            :key_from_database,
            key_from_database__lambda ]
end

def verify_callback( secondary_database, object, method )
  secondary_database.secondary_key_creation_callback_method[ :object ].should == ( method.is_a?( Proc ) ? method : object.method( method ) )
  secondary_database.secondary_key_creation_callback_method[ :method ].should == ( method.is_a?( Proc ) ? nil : method )

  secondary_database.erase! if File.exists?( secondary_database.filename )
  secondary_database.primary.erase! if File.exists?( secondary_database.primary.filename )
end

def verify_secondary( primary_database, secondary_database, object, method, primary_key, data, secondary_key )

  secondary_database.is_secondary?.should == true
  secondary_database.primary_database.should == primary_database

  secondary_database.primary.write( primary_key, data )
  secondary_database.retrieve( secondary_key ).should == data
  secondary_database.primary.retrieve( :index, secondary_key ).should == data    

  verify_callback( secondary_database, object, method )

  primary_database.empty!
end
