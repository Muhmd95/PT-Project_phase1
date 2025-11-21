
#include "HelperFn.h"
#include <string.h>

bool IsValue (string input)
{
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function   Mohamed Ahmed
	if (input.empty())
	{
		return false;
	}
	bool point = false;
	bool found_numric = false;
	for (int i = 0; i < input.length(); i++)
	{
		//validating the negative char
		if (input[i] == '-' && i == 0)
		{
			continue;
		}
		//valdiating if chars are numbers or a point of frequence=1
		if ((input[i] >= 48 && input[i] <= 57) || (input[i] == '.' && point == false))
		{
			if (input[i] == '.') point = true;
			if (input[i] >= 48 && input[i] <= 57) found_numric = true;
		}
		else return false;
	}
	//checking if no numeric values
	if (found_numric == false)
	{
		return false;
	}
	return true;
}

bool IsVariable(string input)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function
	if (input[0] != '_' && ((input[0] > 'z' || input[0] < 'a') && (input[0] < 'A' || input[0] > 'Z'))) {
		return false;
	}
	int len = input.size();
	for (int i = 1; i < len; i++)
	{
		if (input[i] != '_' && (input[i] > 'z' || input[i] < 'a') && (input[i] < 'A' || input[i] > 'Z') && (input[i] < '0' || input[i]>'9')) {
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
	if (IsVariable(input))
	{
		return VARIABLE_OP;
	}
	else if (IsValue(input)) {
		return VALUE_OP;
	}

	return INVALID_OP;
}
