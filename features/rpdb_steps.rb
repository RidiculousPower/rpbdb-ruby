# features/rpdb_steps.rb
require_relative '../lib/rpdb/rpdb'

Given /an Environment has been created/ do
  @environment = RPDB::Environments.new
end
