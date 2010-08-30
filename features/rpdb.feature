Feature: Environment
	In order to work with databases
	An environment must be opened
	
Scenario: Environment is defined with name and directory
	Given an Environment has been created
		And a request to open Environment with name "environment_name" and home directory "./environment_home" 
	When I open Environment
	Then Environment should report that it is open

Scenario: Environment is defined with directory
	Given Environment home directory "./environment_home" 
	When I open Environment
	Then Environment should report that it is open
	
