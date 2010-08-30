/*
 *		RPBDB::SettingsController::SettingsStatusController
 *
 *
 */

#include "RPBDB_StatusSettingsController.h"

/*******************************************************************************************************************************************************************************************
********************************************************************************************************************************************************************************************
																		Public Methods
********************************************************************************************************************************************************************************************
*******************************************************************************************************************************************************************************************/

/*************
*	 new	 *
*************/

RPBDB_StatusController* RPBDB_StatusSettingsController_new( VALUE rb_parent_settings_controller )	{

	RPBDB_SettingsController*	c_parent_settings_controller;
	C_RPBDB_DATABASE_SETTINGS_CONTROLLER( rb_parent_settings_controller, c_parent_settings_controller );

	return Data_Wrap_Struct(	rb_RPBDB_StatusSettingsController,
								NULL, 
								RPBDB_StatusSettingsController_free, 
								RPBDB_StatusSettingsController_new( c_parent_settings_controller ) );
}

/***************************************
*	environment	*
***************************************/
VALUE rb_RPBDB_StatusSettingsController_parentEnvironment(	VALUE	rb_status_settings_controller )	{

	RPBDB_StatusSettingsController*	c_status_settings_controller;
	C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

	return Data_Wrap_Struct(	rb_RPBDB_Environment,
								NULL, 
								RPBDB_Environment_free, 
								RPBDB_StatusSettingsController_parentEnvironment( c_status_settings_controller ) );
}

/******************************
*	 displayAllInformation	  *
******************************/

//	DB_STAT_ALL				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_stat.html
VALUE rb_RPBDB_StatusSettingsController_displayAllInformation( VALUE	rb_status_settings_controller )	{

	RPBDB_StatusSettingsController*	c_status_settings_controller;
	C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

	return ( RPBDB_StatusSettingsController_displayAllInformation( c_status_settings_controller )	?	T_TRUE
																									:	T_FALSE );
}

	/*************************************
	*	 turnDisplayAllInformationOn	 *
	*************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDisplayAllInformationOn( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDisplayAllInformationOn( c_status_settings_controller );

		return rb_status_settings_controller;
	}

	/*************************************
	*	 turnDisplayAllInformationOff	 *
	*************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDisplayAllInformationOff( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDisplayAllInformationOff( c_status_settings_controller );

		return rb_status_settings_controller;
	}

/*************************************
*	 resetStatisticsAfterDisplay	 *
*************************************/

//	DB_STAT_CLEAR			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_stat.html
VALUE rb_RPBDB_StatusSettingsController_resetStatisticsAfterDisplay( VALUE	rb_status_settings_controller )	{

	RPBDB_StatusSettingsController*	c_status_settings_controller;
	C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

	return ( RPBDB_StatusSettingsController_resetStatisticsAfterDisplay( c_status_settings_controller )	?	T_TRUE
																										:	T_FALSE );
}

	/*****************************************
	*	 turnResetStatisticsAfterDisplayOn	 *
	*****************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnResetStatisticsAfterDisplayOn( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnResetStatisticsAfterDisplayOn( c_status_settings_controller );

		return rb_status_settings_controller;
	}

	/*****************************************
	*	 turnResetStatisticsAfterDisplayOff	 *
	*****************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnResetStatisticsAfterDisplayOff( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnResetStatisticsAfterDisplayOff( c_status_settings_controller );

		return rb_status_settings_controller;
	}

/*************************************
*	 displayAllSubsystemInformation	 *
*************************************/

//	DB_STAT_SUBSYSTEM		http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/env_stat.html
VALUE rb_RPBDB_StatusSettingsController_displayAllSubsystemInformation( VALUE	rb_status_settings_controller )	{

	RPBDB_StatusSettingsController*	c_status_settings_controller;
	C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

	return ( RPBDB_StatusSettingsController_displayAllSubsystemInformation( c_status_settings_controller )	?	T_TRUE
																											:	T_FALSE );
}

	/*********************************************
	*	 turnDisplayAllSubsystemInformationOn	 *
	*********************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDisplayAllSubsystemInformationOn( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDisplayAllSubsystemInformationOn( c_status_settings_controller );

		return rb_status_settings_controller;
	}

	/*********************************************
	*	 turnDisplayAllSubsystemInformationOff	 *
	*********************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDisplayAllSubsystemInformationOff( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDisplayAllSubsystemInformationOff( c_status_settings_controller );

		return rb_status_settings_controller;
	}

/************************************************
*	 retrieveCachedStatistics	*
************************************************/

//	DB_FAST_STAT				http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_stat.html
VALUE rb_RPBDB_StatusSettingsController_retrieveCachedStatistics( VALUE	rb_status_settings_controller )	{

	RPBDB_StatusSettingsController*	c_status_settings_controller;
	C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

	return ( RPBDB_StatusSettingsController_retrieveCachedStatistics( c_status_settings_controller )	?	T_TRUE
																										:	T_FALSE );
}

	/*********************************************************
	*	 turnRetrieveCachedStatisticsOn	 *
	*********************************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnRetrieveCachedStatisticsOn( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnRetrieveCachedStatisticsOn( c_status_settings_controller );

		return rb_status_settings_controller;
	}

	/*********************************************************
	*	 turnRetrieveCachedStatisticsOff	 *
	*********************************************************/

	VALUE rb_RPBDB_StatusSettingsController_turnRetrieveCachedStatisticsOff( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnRetrieveCachedStatisticsOff( c_status_settings_controller );

		return rb_status_settings_controller;
	}

/****************************
*	 degreeTwoIsolation		*
****************************/

//	DB_READ_COMMITTED			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_stat.html
//	http://www.oracle.com/technology/documentation/berkeley-db/db/ref/transapp/read.html
VALUE rb_RPBDB_StatusSettingsController_degreeTwoIsolation( VALUE	rb_status_settings_controller )	{

	RPBDB_StatusSettingsController*	c_status_settings_controller;
	C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

	return ( RPBDB_StatusSettingsController_degreeTwoIsolation( c_status_settings_controller )	?	T_TRUE
																								:	T_FALSE );
}

	/*********************************
	*	 turnDegreeTwoIsolationOn	 *
	**********************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDegreeTwoIsolationOn( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDegreeTwoIsolationOn( c_status_settings_controller );

		return rb_status_settings_controller;
	}

	/*********************************
	*	 turnDegreeTwoIsolationOff	 *
	*********************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDegreeTwoIsolationOff( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDegreeTwoIsolationOff( c_status_settings_controller );

		return rb_status_settings_controller;
	}

/********************************
*	 degreeOneIsolation		*
********************************/

//	DB_READ_UNCOMMITTED			http://www.oracle.com/technology/documentation/berkeley-db/db/api_c/db_stat.html
//	http://www.oracle.com/technology/documentation/berkeley-db/db/ref/transapp/read.html
VALUE rb_RPBDB_StatusSettingsController_degreeOneIsolation( VALUE	rb_status_settings_controller )	{

	RPBDB_StatusSettingsController*	c_status_settings_controller;
	C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

	return ( RPBDB_StatusSettingsController_degreeOneIsolation( c_status_settings_controller )	?	T_TRUE
																								:	T_FALSE );
}

	/*********************************
	*	 turnDegreeOneIsolationOn	 *
	*********************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDegreeOneIsolationOn( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDegreeOneIsolationOn( c_status_settings_controller );

		return rb_status_settings_controller;
	}

	/*********************************
	*	 turnDegreeOneIsolationOff	 *
	*********************************/

	VALUE rb_RPBDB_StatusSettingsController_turnDegreeOneIsolationOff( VALUE	rb_status_settings_controller )	{

		RPBDB_StatusSettingsController*	c_status_settings_controller;
		C_RPBDB_STATUSSETTINGS_CONTROLLER( rb_status_settings_controller, c_status_settings_controller );

		RPBDB_StatusSettingsController_turnDegreeOneIsolationOff( c_status_settings_controller );

		return rb_status_settings_controller;
	}
