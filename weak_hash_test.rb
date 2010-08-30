require_relative 'lib/rpdb/WeakHash.rb'
require 'pp'

$weak_hash = WeakHash.new

class TestClass
  def test
    $weak_hash[ 'test' ] = self
  end
end

@test = TestClass.new
@test.test
pp $weak_hash[ 'test' ]
@test = nil
remove_instance_variable "@test"
pp $weak_hash[ 'test' ]
pp defined? @test