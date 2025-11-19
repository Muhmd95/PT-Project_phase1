
#include "HelperFn.h"
#include <string.h>

bool IsValue (string input)
{
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function

	return false;
}

bool IsVariable (string input)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function
	if (input.empty()) {
		return false;
	}
	if (input[0] != '_' || ( (input[0] > 'z' || input[0] < 'a') && (input[0] < 'A' || input[0] > 'Z') ) )  {
		return false;
	}
	int len = input.size();
	for (int i = 1; i < len; i++)
	{
		if (input[i] != '_' || ( (input[i] > 'z' || input[i] < 'a') && (input[i] < 'A' || input[i] > 'Z') ) || (input[i]<'0' || input[i]>'9') ) {
			return false;
		}
	}

	return true;
}

OpType ValueOrVariable (string input)
{
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function

	return INVALID_OP;
}
