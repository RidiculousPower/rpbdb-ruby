#include "rb_Rargs_error.h"
#include "rb_Rargs_describe.h"

/************************************
*  RARG_error_NoMatchForParameters  *
************************************/

void RARG_error_NoMatchForParameters( rarg_parameter_set_t*		parameter_sets )	{

	VALUE	rb_arg_formats_array			=	RARG_collectDescriptionsForParameterSets( parameter_sets );
	VALUE	rb_arg_formats_string			=	rb_funcall(	rb_arg_formats_array,
																								rb_intern( "join" ),
																								1,
																								rb_str_new( "\n * ",
																														4 ) );
	char*	c_arg_formats_string	=	StringValuePtr( rb_arg_formats_string );
	char*	c_format_string				=	"Failed to match any acceptable parameter formats. Acceptable formats:\n * %s\n\n";
	int		c_error_string_length	=	strlen( c_arg_formats_string ) + strlen( c_format_string );
	char*	c_error_string				=	calloc( c_error_string_length + 1, sizeof( char ) );		
	sprintf(	c_error_string, 
						c_format_string, 
						c_arg_formats_string );			
	VALUE	rb_exception	=	rb_exc_new2( rb_eArgError, c_error_string );
	free( c_error_string );
	rb_exc_raise( rb_exception );

}