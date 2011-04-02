require 'date'
require 'fileutils'

target		=	'rpbdb'

sourcedir				=	'src'
sourcetargetdir	=	File.join( sourcedir, target )

# get files
headers	= Dir.glob( sourcedir + '/rpbdb/**/*.h' )
sources = Dir.glob( sourcedir + '/rpbdb/**/*.c' )
files = headers.concat( sources )

# copy source to temp 'ext' we will include in gem
extdir	=	File.join( 'ext', target )
Dir.mkdir( 'ext' )
Dir.mkdir( extdir )
FileUtils.copy( files, extdir )
FileUtils.copy( sourcetargetdir + '/extconf.rb', extdir )

Gem::Specification.new do |spec|

  spec.name                      =  target
  spec.rubyforge_project         =  target
  spec.version                   =  '0.1'

  spec.summary                   =  "Object oriented wrapper for BDB."
  spec.description               =  "Implements RPbdb, which is written on top of BDB C Lib."
  
  spec.authors                   =  [ 'Asher' ]
  spec.email                     =  'asher@ridiculouspower.com'
  spec.homepage                  =  'http://www.ridiculouspower.com/rpbdb'
  
  spec.date                      =  Date.today.to_s

  spec.extensions                << 'ext/rpbdb/extconf.rb'

  spec.files                     = Dir[ '{lib,spec,ext}/**/*',
																        'README*', 
																        'LICENSE*' ]

end

