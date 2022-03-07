/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "Engine.h"
#include <Windows.h>

int main()
{
	//Hides Console window
	//ShowWindow(GetConsoleWindow(), SW_HIDE);

	Engine game = Engine();

	game.run();

	return 0;
}