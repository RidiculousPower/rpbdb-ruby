###############################################################################
#                                                                             #
#                             Gem Specification                               #
#                                                                             #
###############################################################################

  gem_target                  = 'rpdb'
  has_c_source                = true

  developer_name              = 'Asher'
  email                       = 'asher@ridiculouspower.com'
  rubyforge_username          = 'asher'

################################################################################

require 'hoe'
require 'rake/extensiontask'

require 'pp'


Hoe.spec gem_target do
  self.developer( developer_name, email )
  self.rubyforge_name     = rubyforge_username
  self.version            = 0.1
  self.readme_file			  = 'README.txt'
  self.history_file       = 'History.txt'
  self.extra_rdoc_files	  = FileList['*.rdoc']
  if has_c_source
    self.spec_extras			= { :extensions => ["ext/rpdb/extconf.rb"] }
    self.extra_dev_deps << ['rake-compiler', '>= 0']  
    Rake::ExtensionTask.new( gem_target, spec ) do |ext|
      ext.lib_dir = File.join( 'lib', gem_target )
    end
    Rake::Task[ :spec ].prerequisites << :compile
  end
end

task :cultivate do
  system "touch Manifest.txt; rake check_manifest | grep -v \"(in \" | patch"
  system "rake debug_gem | grep -v \"(in \" > " + gem_target + ".gemspec"
end
