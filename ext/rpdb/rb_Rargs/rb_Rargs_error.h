#ifndef RB_RARGS_ERROR
	#define RB_RARGS_ERROR

	#include <ruby.h>
	
	#include "rb_Rargs_types.h"
	
	void RARG_error_NoMatchForParameters( rarg_parameter_set_t*		parameter_sets );
	
#endif