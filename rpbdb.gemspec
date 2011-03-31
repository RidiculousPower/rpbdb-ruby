require 'date'

Gem::Specification.new do |spec|

  spec.name                      =  'rpbdb'
  spec.rubyforge_project         =  'rpbdb'
  spec.version                   =  '0.1'

  spec.summary                   =  "Object oriented wrapper for BDB."
  spec.description               =  "Object oriented wrapper for BDB."
  
  spec.authors                   =  [ 'Asher' ]
  spec.email                     =  'asher@ridiculouspower.com'
  spec.homepage                  =  'http://www.ridiculouspower.com/rpbdb'
  
  spec.date                      =  Date.today.to_s

  spec.extensions                << 'ext/rpbdb/extconf.rb'

  # ensure the gem is built out of versioned files
  spec.files                     = Dir[ '{lib,spec,ext}/**/*',
                                        'README*', 
                                        'LICENSE*' ] & `git ls-files -z`.split("\0")

end
