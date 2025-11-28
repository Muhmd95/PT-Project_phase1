#ifndef DEFS_H
#define DEFS_H

//This file contains some global constants and definitions to be used in the project.

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

// DONE: Add any action type here
enum ActionType // The actions supported
{
	ADD_START, //Add start statement DONE
	ADD_END,   //Add end statement DONE
	ADD_DECLARE_VARIABLE, // Add  declare variable statement DONE
	ADD_VALUE_ASSIGN, //Add value assignment statement done
	ADD_VAR_ASSIGN,	  //Add variable assignment statement DONE
	ADD_OPER_ASSIGN,  //Add operator assignment statement DONE
	ADD_CONDITION,    //Add a conditional statement (for if and while-loop statements) done
	ADD_READ,  //Add read statement done
	ADD_WRITE, //Addd write statemetn done

	ADD_CONNECTOR, //Add a connector between two statements done
	
	SELECT,		//Select a statement, a connector done
	EDIT_STAT,	//Edit a statement done

	DEL,   //Delete a figure done
	COPY,  //Copy a figure done
	CUT,   //Cut a figure done
	PASTE, //Paste a figure done

	SAVE,		//Save the whole graph to a file done
	LOAD,		//Load a graph from a file done

	SWITCH_DSN_MODE,	//Switch to Design mode done 
	SWITCH_SIM_MODE,	//Switch to simulatiom mode DONE

	EXIT,		//Exit the application done


	//DONE: ADD THE ACTIONS OF SIMULATION MODE
	VALIDATE,	    //Validate done
	RUN,	        //Run done
	DEBUG,         //debug done
	GENCODE,      //generate c++ code done
	REVALIDATE,  // revalidate done
	RERUN,      //rerun done
	UNDO,      //undo done
	REDO,     //redo done
	

	DRAWING_AREA,  //A click on the drawing area done
	OUTPUT_AREA,   //A click on the output area done
	SIM_TOOL,		//a click on an empty place in sim tool bar done
	DSN_TOOL,	   //A click on an empty place in the design tool bar done
	STATUS 		   //A click on the status bar done
};

// DONE: you should add more items
enum DesignMenuItem //The items of the design menu --> THE ORDER MATTERS
{
	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too
	// 
	// 
	// Start and End
	ITM_START,
	ITM_END,

	// Declarations
	ITM_DECLARE,

	// Assignment Statements (3 types)
	ITM_VALUE_ASSIGN,	//simple assignment statement
	ITM_VAR_ASSIGN,		//for variable assign
	ITM_OPER_ASSIGN,	//for operator assign

	// Conditional
	ITM_COND,	//conditional statement

	// I/O Statements (Read and Write)
	ITM_READ,
	ITM_WRITE,

	// Connectors
	ITM_CONNECTOR,

	// Selection and Editing
	ITM_SELECT,
	ITM_EDIT,

	// Clipboard and Deletion
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DEL,
	//UNDO,redo
	ITM_UNDO,
	ITM_REDO,

	// File Operations
	ITM_SAVE,
	ITM_LOAD,

	ITM_SWITCH_SIM,	//switch
	ITM_EXIT,		//Exit

	DSN_ITM_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};

// DONE: you should add more items if needed
enum SimMenuItem //The items of the simulation menu
{
	//Note: Items are ordered here as they appear in menu
	ITM_VALIDATE,	//Validate
	ITM_RUN,	    //Run

	//DONE:Add more items names here

	ITM_DEBUG,
	ITM_GENCODE,
	ITM_SWITCH_DSN_MODE,
	ITM_EXITSIM,


	
	SIM_ITM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};




#ifndef NULL
#define NULL 0
#endif

#endif