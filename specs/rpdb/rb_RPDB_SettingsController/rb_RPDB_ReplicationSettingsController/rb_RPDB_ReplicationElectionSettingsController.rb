require_relative '../../../../lib/rbdb.rb'

describe Rbdb::Settings::Replication::Election do

  $environment_path           = '/tmp/rbdb_spec_environment_home/'

  $database_name              = :spec_database
  $secondary_database_name    = $database_name.to_s + '_secondary'
  $database_new_name          = :spec_database_renamed
  $database_extension         = '.db'
  $duplicates_database_name   = :duplicates_db
  
  before( :each ) do
    @environment = Rbdb::Environment.new( $environment_path )
  end

  after( :each ) do
    @environment.close
  end

  ################
  #  self.new    #
  #  initialize  #
  ################

  # Rbdb::Settings::Replication::Election.new( environment )
  it "can be created with an environment" do
    Rbdb::Settings::Replication::Election.new( @environment ).should_not == nil
  end

  # Rbdb::Settings::Replication::Election.new( settings_controller )
  it "can be created with a settings controller" do
    @environment.open
    Rbdb::Settings::Replication::Election.new( Rbdb::Settings.new ).should_not == nil
  end

  # Rbdb::Settings::Replication::Election.new( election_settings_controller )
  it "can be created with a replication settings controller" do
    @environment.open
    Rbdb::Settings::Replication::Election.new( Rbdb::Settings::Replication.new ).should_not == nil
  end

  # Rbdb::Settings::Replication::Election.new
  it "can be created with no argument specified" do
    @environment.open
    Rbdb::Settings::Replication::Election.new.should_not == nil
  end

  ########################
  #  parent_environment  #
  ########################

  it "can return its parent environment" do
    @environment.open
    Rbdb::Settings::Replication::Election.new.parent_environment.should_not == nil
  end

  ################################
  #  parent_settings_controller  #
  ################################

  it "can return its parent settings controller" do
    @environment.open
    Rbdb::Settings::Replication::Election.new.parent_settings_controller.should_not == nil
  end

  ############################################
  #  parent_replication_settings_controller  #
  ############################################

  it "can return its parent replication settings controller" do
    @environment.open
    Rbdb::Settings::Replication::Election.new.parent_replication_settings_controller.should_not == nil
  end

  ###################################
  #  wait_for_all_clients           #
	#  turn_wait_for_all_clients_on   #
	#  turn_wait_for_all_clients_off  #
  ###################################

  it "can be set to wait for all clients to respond to election" do
    election_settings  = Rbdb::Settings::Replication::Election.new( @environment )
    election_settings.parent_replication_settings_controller.turn_on
    election_settings.wait_for_all_clients?.should == false
    election_settings.turn_wait_for_all_clients_on
    election_settings.wait_for_all_clients?.should == true
    election_settings.turn_wait_for_all_clients_off
    election_settings.wait_for_all_clients?.should == false
  end

  ###########################################
  #  wait_for_all_electable_peers?          #
	#  turn_wait_for_all_electable_peers_on   #
	#  turn_wait_for_all_electable_peers_off  #
  ###########################################

  it "can be set to wait for all electable peers" do
    election_settings  = Rbdb::Settings::Replication::Election.new( @environment )
    election_settings.wait_for_all_electable_peers?.should == false
    election_settings.turn_wait_for_all_electable_peers_on
    election_settings.wait_for_all_electable_peers?.should == true
    election_settings.turn_wait_for_all_electable_peers_off
    election_settings.wait_for_all_electable_peers?.should == false
  end

  ############################
  #  wait_for_none?          #
	#  turn_wait_for_none_on   #
	#  turn_wait_for_none_off  #
  ############################

  it "can be set not to wait" do
    election_settings  = Rbdb::Settings::Replication::Election.new( @environment )
    election_settings.wait_for_none?.should == false
    election_settings.turn_wait_for_none_on
    election_settings.wait_for_none?.should == true
    election_settings.turn_wait_for_none_off
    election_settings.wait_for_none?.should == false
  end

  ###########################################
  #  wait_for_at_least_one_client?          #
	#  turn_wait_for_at_least_one_client_on   #
	#  turn_wait_for_at_least_one_client_off  #
  ###########################################

  it "can be set to wait for at least one client" do
    election_settings  = Rbdb::Settings::Replication::Election.new( @environment )
    election_settings.wait_for_at_least_one_client?.should == false
    election_settings.turn_wait_for_at_least_one_client_on
    election_settings.wait_for_at_least_one_client?.should == true
    election_settings.turn_wait_for_at_least_one_client_off
    election_settings.wait_for_at_least_one_client?.should == false
  end

  ###################################################
  #  wait_for_at_least_one_electable_peer?          #
	#  turn_wait_for_at_least_one_electable_peer_on   #
	#  turn_wait_for_at_least_one_electable_peer_off  #
  ###################################################

  it "can be set to wait for at least one electable peer" do
    election_settings  = Rbdb::Settings::Replication::Election.new( @environment )
    election_settings.wait_for_at_least_one_electable_peer?.should == false
    election_settings.turn_wait_for_at_least_one_electable_peer_on
    election_settings.wait_for_at_least_one_electable_peer?.should == true
    election_settings.turn_wait_for_at_least_one_electable_peer_off
    election_settings.wait_for_at_least_one_electable_peer?.should == false
  end

  ####################################################################
  #  wait_for_minimum_electable_peers_for_durable_election?          #
	#  turn_wait_for_minimum_electable_peers_for_durable_election_on   #
	#  turn_wait_for_minimum_electable_peers_for_durable_election_off  #
  ####################################################################

  it "can be set to wait for a minimum number of electable peers for durable election" do
    election_settings  = Rbdb::Settings::Replication::Election.new( @environment )
    election_settings.wait_for_minimum_electable_peers_for_durable_election?.should == false
    election_settings.turn_wait_for_minimum_electable_peers_for_durable_election_on
    election_settings.wait_for_minimum_electable_peers_for_durable_election?.should == true
    election_settings.turn_wait_for_minimum_electable_peers_for_durable_election_off
    election_settings.wait_for_minimum_electable_peers_for_durable_election?.should == false
  end

  ###############################################
	#  set_number_of_sites_required_for_election  #
  #  number_of_sites_required_for_election      #
  ###############################################

  it "can set and return the number of sites required for election" do
    @environment.open
    election_settings  = Rbdb::Settings::Replication::Election.new
    election_settings.set_number_of_sites_required_for_election( 42 )
    election_settings.number_of_sites_required_for_election.should == 42
  end

  ###############################################
	#  set_number_of_votes_required_for_election  #
  #  number_of_votes_required_for_election      #
  ###############################################

  it "can set and return the number of votes required for election" do
    @environment.open
    election_settings  = Rbdb::Settings::Replication::Election.new
    election_settings.set_number_of_votes_required_for_election( 42 )
    election_settings.number_of_votes_required_for_election.should == 42
  end

  ########################################################
  #  set_site_is_now_replication_client_callback_method  #
  #  site_is_now_replication_client_callback_method      #
  ########################################################

  it "can set and return its callback method called when site becomes replication client" do
    @environment.open
    raise "Callback."
  end

  #######################################################
  #  set_site_won_replication_election_callback_method  #
  #  site_won_replication_election_callback_method      #
  #######################################################

  it "can set and return its callback method called when site won replication election" do
    @environment.open
    raise "Callback."
  end

  #################################################################
  #  set_site_is_now_master_of_replication_group_callback_method  #
  #  site_is_now_master_of_replication_group_callback_method      #
  #################################################################

  it "can set and return its callback method called when site becomes master of its replication group" do
    @environment.open
    raise "Callback."
  end

  ##########################################################
  #  set_replication_group_has_new_master_callback_method  #
  #  replication_group_has_new_master_callback_method      #
  ##########################################################

  it "can set and return its callback method called when its replication group has a new master" do
    @environment.open
    raise "Callback."
  end

  ############################################################
  #  set_replication_acknowledgement_failed_callback_method  #
  #  replication_acknowledgement_failed_callback_method      #
  ############################################################

  it "can set and return its callback method called when its replication acknowledement fails" do
    @environment.open
    raise "Callback."
  end

  #######################################################
  #  set_replication_startup_completed_callback_method  #
  #  replication_startup_completed_callback_method      #
  #######################################################

  it "can set and return its callback method called when its replication startup completed" do
    @environment.open
    raise "Callback."
  end

end

