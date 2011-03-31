require 'date'

Gem::Specification.new do |spec|

  spec.name                      =  'rbdb'
  spec.rubyforge_project         =  'rbdb'
  spec.version                   =  '0.1'

  spec.summary                   =  "Object oriented wrapper for BDB."
  spec.description               =  "Object oriented wrapper for BDB."
  
  spec.authors                   =  [ 'Asher' ]
  spec.email                     =  'asher@ridiculouspower.com'
  spec.homepage                  =  'http://www.ridiculouspower.com/rbdb'
  
  spec.date                      =  Date.today.to_s

  spec.extensions                << 'ext/rbdb/extconf.rb'

  # ensure the gem is built out of versioned files
  spec.files                     = Dir[ '{lib,spec,ext}/**/*',
                                        'README*', 
                                        'LICENSE*' ] & `git ls-files -z`.split("\0")

end
