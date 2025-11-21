#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1200;
	UI.height = 620;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;   // I edited the width of the items
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");
	
	pWind->SetPen(RED,3);

	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//DONE: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem

	//DONE: Prepare images for each menu item and add it to the list
	string MenuItemImages[DSN_ITM_CNT];

	//START AND END
	MenuItemImages[ITM_START] = "images\\Assign.jpg"; 
	MenuItemImages[ITM_END] = "images\\Assign.jpg";

	//DECLARE
	MenuItemImages[ITM_DECLARE] = "images\\Assign.jpg";

	//ASSIGN
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_VAR_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_OPER_ASSIGN] = "images\\Assign.jpg";

	//COND
	MenuItemImages[ITM_COND] = "images\\Assign.jpg";

	//READ AND WRITE
	MenuItemImages[ITM_READ] = "images\\Assign.jpg";
	MenuItemImages[ITM_WRITE] = "images\\Assign.jpg";

	//CONNECTOR
	MenuItemImages[ITM_CONNECTOR] = "images\\Assign.jpg";

	//SELECTION AND EDITING
	MenuItemImages[ITM_SELECT] = "images\\Assign.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Assign.jpg";

	//CLIPBOARD
	MenuItemImages[ITM_COPY] = "images\\Assign.jpg";
	MenuItemImages[ITM_CUT] = "images\\Assign.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Assign.jpg";
	MenuItemImages[ITM_DEL] = "images\\Assign.jpg";

	//FILES
	MenuItemImages[ITM_SAVE] = "images\\Assign.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Assign.jpg";

	MenuItemImages[ITM_SWITCH_SIM] = "images\\Condition.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Assign.jpg";

	
	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//DONE: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	string MenuItemImages[SIM_ITM_CNT];
	//valdiating
	MenuItemImages[ITM_VALIDATE] = "images\\validate.jpg";
	//run
	MenuItemImages[ITM_RUN] = "images\\run.jpg";
    //Dubug
	MenuItemImages[ITM_DEBUG] = "images\\debug.jpg";
    //GENCODE
	MenuItemImages[ITM_GENCODE] = "images\\Gend-code.jpg";
    //REVALIDATE
	MenuItemImages[ITM_REVALIDATE]= "images\\revalidate.jpg";
    //Rerun
	MenuItemImages[ITM_RERUN]= "images\\rerun.jpg";
    //undo
	MenuItemImages[ITM_UNDO] = "images\\undo.jpg";
    //Redo
	MenuItemImages[ITM_REDO] = "images\\redo.jpg";
    //switch
	MenuItemImages[ITM_SWITCH_DSN_MODE]= "images\\switch.jpg";
	//Draw menu item one image at a time

	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int) (UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions							//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if(Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor,3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor,3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);
		
	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x+width/4, Left.y + height/4, Text);
}

//TODO: Add similar functions for drawing all other statements.
//		e.g. DrawDeclareStat(.....), DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them

void Output::DrawCondionalStat(Point Center, int width, int height, string Text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);
	int cx = Center.x;
	int cy = Center.y;
	int X[4] = { cx, cx + width / 2, cx, cx - width / 2 };
	int Y[4] = { cy - height / 2, cy, cy + height / 2, cy };
	pWind->DrawPolygon(X, Y, 4);
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(cx - width/ 4, cy, Text);
}
void Output::DrawStart(Point Center, int width, int height, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);
	pWind->DrawEllipse(Center.x - width / 2, Center.y - height / 2, Center.x + width / 2, Center.y + height / 2);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - width/4 , Center.y , "START");
}
void Output::DrawEnd(Point Center, int width, int height, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	pWind->DrawEllipse(Center.x - width / 2, Center.y - height / 2, Center.x + width / 2, Center.y + height / 2);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - width/4, Center.y, "END");
}
	
//TODO: Add DrawConnector function

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
