= RP-DB

http://www.ridiculouspower.com/db

== DESCRIPTION:

RPbdb is an object-oriented database environment built on top of Oracle's Berkeley Database. 
It provides both persistent database-transparent object storage, and also a fully-functional 
database wrapper. The design is intended above all to simplify interfacing with the database 
environment while also permitting any underlying settings to be adjusted as necessary. 

== SUMMARY:
	
	RPbdb functions inside a database environment. The environment provides isolation for a 
	set of databases.
	
	Databases are key/value stores in one of four types: Btree (default), Hash, Record Number, 
	or Queue. They are organized in a one => many, primary => secondary relation. Primary
	databases hold primary key => data value, while secondary databases hold secondary key =>
	primary key. Retrieving from a secondary database automatically performs a join, returning
	both the primary key and the data associated with it. 

== REQUIREMENTS:

	* Berkeley DB >= 5.0

== INSTALL:

	* sudo gem install

== INITIALIZING DATABASE ENVIRONMENT:

	Any use of RPbdb requires opening an environment. Multiple environments are supported, but
	most use cases will only require one.

	1. Declare an environment:
	
		environment = RPbdb::Environment.new(	'name_to_identify_environment', 
												'path/to/db/storage/directory' )
	
	1.1 (Optional), Assert environment's identity
		
		environment.identify_as( 'identifier' )
		
	1.2 (Optional), Open a transaction:
		
		environment.transaction.open

	2. Open environment (implied by environment-related activity).

	Once the environment is open, databases may be declared and used. 

== DECLARING A CLASS AS DATABASE OBJECT:

	The best way to use RPbdb with Ruby is with Database-Enabled Objects, which we will refer to
	as "Database Objects".
	
	Database Objects permit essentially transparent storage of objects. The object's class becomes 
	a controller that manages object instance retrieval using Class.retrieve, and the object instance 
	becomes capable of storing itself, using object.write. 
	
	1. Include module in class:
	
		class AnyClass
			include RPbdb
		end
		
	2. Configure Class for Database Object
	
		class AnyClass
			include RPbdb
			
			#	Database Object configuration here:
			def self.configure_rpbd

				#	Primary Key Method must be specified
				self.set_primary_key_method( method_in_self )

				#	Secondary Key Methods (optional)

				#	A non-unique secondary key
				self.add_secondary_key_method( method_in_self )

				#	A unique secondary key
				self.add_unique_secondary_key_method( method_in_self )

			end
			
			#	Database Object identification here (optional):
			def self.identify_for_rpbd_as
			
				#	return array of identifiers (Class constants or class constant names as strings or symbols)
				#	if true is returned as one of the element, object will identify with first environment opened,
				#	or if multiple environments are open, object will identify with the first identifier available, 
				#	or with the first environment that was opened.
				return [ 'identifier', true ]
			
			end
			
			#	Database Object initialization here (optional):
			def self.init_rpbd
				
				#	Anything that needs to happen when Database Object's database is configured/openable
				
			end
			
		end

	3. Write instances of Class
	
		instance_of_any_class = AnyClass.new

		#	example of setting primary key value - can be an accessor to a var, or a method
		instance_of_any_class.primary_key_value = 'value'

		#	assumes that instance.primary_key_method returns a value
		instance_of_any_class.write
	
	4. Retrieve instances of Class

		#	by primary key
		#	returns object
		AnyClass.retrieve( primary_key_value )

		#	by specified index
		#	if index is unique, returns object
		#	if index allows duplicates, returns cursor
		AnyClass.retrieve( index => primary_or_secondary_key_value )

		#	by join
		#	returns cursor to list of objects that match join
		AnyClass.retrieve(	:index			=> value,
							:second_index	=> value,
							... )

== ARBITRARY NON-CLASS ORIENTED DATA STORAGE:

	An alternative to Database Objects is to use the underlying database system directly. This
	is included here primarily for reference, as Database Objects are almost always the most
	appropriate solution. 
	
	When using a database directly, programmer is responsible for translating any objects to strings
	before writing to or retrieving from database.

	1. Get database for name (creates database if necessary):
	
		database = environment.databases[ 'name_to_identify_database' ]
		
	1.1	(Optional) Set database to allow duplicates
		
		database.set_to.readwrite.duplicates
	
	1.2 (Optional) Set database to sort duplicates

		database.set_to.readwrite.sorted_duplicates
		
	2. Open database (implied by database-related activity)
		
		database.open
		
	3. Write to database
		
		#	writing through the database directly requires a string; when using Database Objects this is managed
		#	automatically by way of serialization (currently via Marshal).
		database.write( key_string, object_as_string )
	
	3.1 (Optional) Create a secondary index
	
		secondary_database = database.create_secondary_index( callback_object, :callback_method )
	
	4. Retrieve from database
		
		#	by primary key
		#	returns object
		primary_database.retrieve( primary_key_string )
		
		#	by specified index
		#	if index is unique, returns object
		#	if index allows duplicates, returns cursor
		primary_database.retrieve( :index => primary_or_secondary_key_string )
		
		#	by join (on databases that hold duplicate values)
		#	returns cursor to list of objects that match join
		primary_database.retrieve(	:index			=> value,
									:second_index	=> value,
									... )

		#	also, secondary indices can be used for direct retrieval
		#	if index is unique, returns object
		#	if index allows duplicates, returns cursor
		secondary_database.retrieve( secondary_key_string )

== LICENSE:

	No license is implied. This software is currently private and not for distribution. 
	All rights reserved. 
	