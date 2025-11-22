
#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point &P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///DONE: add code to read a double value from the user and assign it to D

	double D = 0;
	string label;
	//This function should make any needed validations on the entered text 
	// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 �etc.).
	while(1) {
		pO->PrintMessage("Please enter a value");
		label = GetString(pO);
		if (IsValue(label)) {
			D =stod(label);
			break;
		}
	}
	//Read a double value from the user
	return D;
}


//DONE: Add the function Input::GetVariable 
// to read a �variable name� from the user (from the keyboard). 
// It does not return before taking a valid variable name.
string Input::GetVariable(Output *pO) const {
        string label;
	while(1) {
		pO->PrintMessage("Please enter a Variable");
		label = GetString(pO);
		if (IsVariable(label)) {
           return label;
		}
	}

}

//DONE: Add the function Input::GetArithOperator 
// to read an arithmetic operator (+, -, * or /) from the user. 
// It does not return before taking a valid arithmetic operator.
 char Input::GetArithOperator(Output* pO) const {
	string label;
	while(1) {
		pO->PrintMessage("Please enter a Operator");
		label = GetString(pO);
		if (label == "+" || label == "-" || label == "*" || label == "/" ) {
			return label[0];
		}
	}
}
//DONE: Add the function Input::GetCompOperator
// similar to the previous function but for comparison operators (==, !=, <, <=, > or >=).

string Input::GetCompOperator(Output* pO) const
{
	string label;
	while (true) {
		pO->PrintMessage("Please enter a Comparison Operator");
		label = GetString(pO);
		if (label == "==" || label == ">=" || label == "<=" || label == "!=" || label == ">" || label == "<") {
			break;
		}
	}

	return label;
}


//DONE: Complete the implementation of the following function
ActionType Input::GetUserAction() const
{	
	//This function reads the position where the user clicks to determine the desired action

	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_START:		return ADD_START;
			case ITM_END:		return ADD_END;
			case ITM_DECLARE:		return ADD_DECLARE_VARIABLE;
			case ITM_VALUE_ASSIGN:		return ADD_VALUE_ASSIGN;
			case ITM_VAR_ASSIGN:		return ADD_VAR_ASSIGN;
			case ITM_OPER_ASSIGN:		return ADD_OPER_ASSIGN;
			case ITM_COND:		return ADD_CONDITION;
			case ITM_READ:		return ADD_READ;
			case ITM_WRITE:		return ADD_WRITE;
			case ITM_CONNECTOR:		return ADD_CONNECTOR;
			case ITM_SELECT:		return SELECT;
			case ITM_EDIT:		return EDIT_STAT;
			case ITM_DEL:		return DEL;
			case ITM_COPY:		return COPY;
			case ITM_CUT:		return CUT;
			case ITM_PASTE:		return PASTE;
			case ITM_SAVE:		return SAVE;
			case ITM_LOAD:		return LOAD;
			case ITM_SWITCH_SIM:		return SWITCH_SIM_MODE;
			case ITM_EXIT:		return EXIT;


			default: return DSN_TOOL;
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;	
			else
				return OUTPUT_AREA;
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{

		// DONE: This should be changed after creating the compelete simulation bar 
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check which Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_VALIDATE: return VALIDATE ;
			case ITM_RUN: return RUN;
			case ITM_DEBUG: return DEBUG;
			case ITM_GENCODE: return GENCODE;
			case ITM_REVALIDATE: return REVALIDATE;
			case ITM_RERUN: return RERUN;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_SWITCH_DSN_MODE: return SWITCH_DSN_MODE;

			default: return SIM_TOOL;
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}

}


Input::~Input()
{
}
