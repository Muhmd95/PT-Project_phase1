#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1400;
	UI.height = 700;
	UI.wx = 15;
	UI.wy =15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 63;   // I edited the width of the items
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
	ClearToolBar(); // created to clear the tool bar
	UI.AppMode = DESIGN;	//Design Mode
	
	//fill the tool bar 
		
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem

	//DONE: Prepare images for each menu item and add it to the list
	string MenuItemImagesdsn[DSN_ITM_CNT];

	//START AND END
	MenuItemImagesdsn[ITM_START] = "images\\Start.jpg"; 
	MenuItemImagesdsn[ITM_END] = "images\\End.jpg";

	//DECLARE
	MenuItemImagesdsn[ITM_DECLARE] = "images\\Declare.jpg";

	//ASSIGN
	MenuItemImagesdsn[ITM_VALUE_ASSIGN] = "images\\VALAssign.jpg";
	MenuItemImagesdsn[ITM_VAR_ASSIGN] = "images\\VARAssign.jpg";
	MenuItemImagesdsn[ITM_OPER_ASSIGN] = "images\\OPAssign.jpg";

	//COND
	MenuItemImagesdsn[ITM_COND] = "images\\Condition.jpg";

	//READ AND WRITE
	MenuItemImagesdsn[ITM_READ] = "images\\Read.jpg";
	MenuItemImagesdsn[ITM_WRITE] = "images\\Write.jpg";

	//CONNECTOR
	MenuItemImagesdsn[ITM_CONNECTOR] = "images\\Connector.jpg";

	//SELECTION AND EDITING
	MenuItemImagesdsn[ITM_SELECT] = "images\\Select.jpg";
	MenuItemImagesdsn[ITM_EDIT] = "images\\Edit.jpg";

	//CLIPBOARD
	MenuItemImagesdsn[ITM_COPY] = "images\\Copy.jpg";
	MenuItemImagesdsn[ITM_CUT] = "images\\Cut.jpg";
	MenuItemImagesdsn[ITM_PASTE] = "images\\Paste.jpg";
	MenuItemImagesdsn[ITM_DEL] = "images\\Delete.jpg";
	//UNDO, REDO
	MenuItemImagesdsn[ITM_UNDO] = "images\\Undo.jpg";
	MenuItemImagesdsn[ITM_REDO] = "images\\Redo.jpg";

	//FILES
	MenuItemImagesdsn[ITM_SAVE] = "images\\Save.jpg";
	MenuItemImagesdsn[ITM_LOAD] = "images\\Load.jpg";

	MenuItemImagesdsn[ITM_SWITCH_SIM] = "images\\SwitchMode.jpg";
	MenuItemImagesdsn[ITM_EXIT] = "images\\Exit.jpg";

	
	//Draw menu item one image at a time
	for(int i=0; i<DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImagesdsn[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(YELLOW, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//DONE: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{

	ClearToolBar();  // created to clear the toolbar
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	string MenuItemImagessim[SIM_ITM_CNT];
	//valdiating
	MenuItemImagessim[ITM_VALIDATE] = "images\\Validate.jpg";
	//run
	MenuItemImagessim[ITM_RUN] = "images\\Run.jpg";
    //Dubug
	MenuItemImagessim[ITM_DEBUG] = "images\\Debug.jpg";
    //GENCODE
	MenuItemImagessim[ITM_GENCODE] = "images\\GenerateCode.jpg";
    //switch
	MenuItemImagessim[ITM_SWITCH_DSN_MODE]= "images\\SwitchMode.jpg";
	//Exit
	MenuItemImagessim[ITM_EXITSIM] = "images\\Exit.jpg";
	//Draw menu item one image at a time

	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImagessim[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(BLUE, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(BLUE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(BLUE, 2);
	pWind->SetBrush(LIGHTGRAY);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	pWind->SetPen(WHITE, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(BLUE, 2);
	pWind->SetBrush(LEMONCHIFFON);
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
	pWind->DrawString(Left.x+width/8, Left.y + height/3, Text);
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
	pWind->DrawString(cx - 6, cy-10, Text);
}

void Output::DrawParallelogram(Point Center, int width, int height, string Text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);
	int X[4] = { Center.x + width / 4, Center.x + width + width / 4, Center.x + width, Center.x };
	int Y[4] = { Center.y, Center.y, Center.y + height, Center.y + height };
	pWind->DrawPolygon(X, Y, 4);
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x + width / 3, Center.y + height / 3, Text);
}
void Output::DrawRead(Point Center, int width, int height, bool Selected)
{
	DrawParallelogram(Center, width, height, "Read", Selected);
}
void Output::DrawWrite(Point Center, int width, int height, bool Selected)
{
	DrawParallelogram(Center, width, height, "Write", Selected);
}


void Output::DrawStart(Point Center, int width, int height,string text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);
	pWind->DrawEllipse(Center.x - width / 2, Center.y - height / 2, Center.x + width / 2, Center.y + height / 2);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - width/8 , Center.y-height/4 , text);
}
void Output::DrawEnd(Point Center, int width, int height, string text, bool Selected)
{
	if (Selected)
		pWind->SetPen(UI.HighlightColor, 3);
	else
		pWind->SetPen(UI.DrawColor, 3);

	pWind->DrawEllipse(Center.x - width / 2, Center.y - height / 2, Center.x + width / 2, Center.y + height / 2);

	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Center.x - width/8, Center.y-height/4, text);
}
	
//DONE: Add DrawConnector function
void Output :: DrawConnector(Point start,Point end,bool Selected)
{
	if (Selected)
	{
		pWind->SetPen(UI.HighlightColor, 3); //highlited
	}
	else
	{
		pWind->SetPen(UI.DrawColor, 3);//normal
	}
	//case 1 default vertical connector
	if ((start.x == end.x) && end.y > start.y)
	{
		pWind->DrawLine(start.x,start.y ,end.x,end.y);
		pWind->DrawTriangle(end.x - 5, end.y, end.x + 5, end.y, end.x, end.y + 10);

	}
	// case 2 horizontal connector points to left then down
	else if (start.x > end.x && end.y > start.y)
	{
		pWind->DrawLine(start.x, start.y, end.x, start.y);
		pWind->DrawLine(end.x, start.y, end.x, end.y);
		pWind->DrawTriangle(end.x - 5, end.y, end.x + 5, end.y, end.x, end.y + 10);
		

	}
	// case 2.1 points right then down
	else if (start.x < end.x && end.y > start.y)
	{
		pWind->DrawLine(start.x, start.y, end.x, start.y);
		pWind->DrawLine(end.x, start.y, end.x, end.y);
		pWind->DrawTriangle(end.x - 5, end.y, end.x + 5, end.y, end.x, end.y + 10);
		

	}
	//case 3 loop case 
	else if (end.y < start.y)
	{
		if (end.x < start.x)// left > up >right
		{
			pWind->DrawLine(start.x, start.y, start.x-50, start.y);
			pWind->DrawLine(start.x -50, start.y, start.x -50, end.y);
			pWind->DrawLine(start.x - 50, end.y, end.x, end.y);
			pWind->DrawTriangle(end.x, end.y - 5, end.x, end.y + 5, end.x + 10, end.y);


		}
		else if (start.x < end.x) //right > up > left
		{
			pWind->DrawLine(start.x, start.y, start.x + 50, start.y);
			pWind->DrawLine(start.x + 50, start.y, start.x + 50, end.y);
			pWind->DrawLine(start.x + 50, end.y, end.x, end.y);
			pWind->DrawTriangle(end.x, end.y + 5, end.x, end.y - 5, end.x - 10, end.y);
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::Drawdouble(Point Center, double d) /// added this to draw double
{
	pWind->DrawDouble(Center.x, Center.y, d);
}


Output::~Output()
{
	delete pWind;
}