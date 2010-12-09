# features/rbdb_steps.rb
require_relative '../lib/rbdb/rbdb'

Given /an Environment has been created/ do
  @environment = Rbdb::Environments.new
end
