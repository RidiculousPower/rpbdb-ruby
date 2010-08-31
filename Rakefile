###############################################################################
#                                                                             #
#                             Gem Specification                               #
#                                                                             #
###############################################################################

  define_gem                  = 'rpdb'
  has_c_source                = true

  developer_name              = 'Asher'
  email                       = 'asher@ridiculouspower.com'
  rubyforge_name              = 'asher'

  $VERBOSE                    = false

################################################################################

require 'hoe'
require 'rake/extensiontask'

require 'pp'

Hoe.spec define_gem do
  developer( developer_name, email )
  self.rubyforge_name   = rubyforge_name
  self.version          = File.open( 'VERSION.rdoc' ).readline
  self.readme_file			= 'README.rdoc'
  self.history_file     = 'CHANGELOG.rdoc'
  self.extra_rdoc_files	= FileList['*.rdoc']
  if has_c_source
    self.spec_extras			= { :extensions => ["ext/rpdb/extconf.rb"] }
    self.extra_dev_deps << ['rake-compiler', '>= 0']  
  end
  Rake::ExtensionTask.new( define_gem, spec ) do |ext|
    ext.lib_dir = File.join( 'lib', define_gem )
  end
end

task :cultivate do
  system "touch Manifest.txt; rake check_manifest | grep -v \"(in \" | patch"
  system "rake debug_gem | grep -v \"(in \" > " + define_gem + ".gemspec"
end

# clear default task and set default to :compile
if has_c_source
  Rake::Task[ :default ].clear
  task :default => :compile
end

# allow spec task to be turned off from command line
if  has_c_source and 
    not ( ENV[ "no_spec" ]            or 
          ENV[ "no_spec" ] == "true"  or 
          ENV[ "no_spec" ] == "yes"   or 
          ENV[ "no_spec" ] == "on"    or 
          ENV[ "spec" ] == "false"    or
          ENV[ "spec" ] == "no"       or
          ENV[ "spec" ] == "off" )
  Rake::Task[ :spec ].prerequisites << :compile
end
