#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "dbg.h"

// DESC: By default, the console is not attached in gui
void Console_On(void){
	AllocConsole();
	ShowWindow(GetConsoleWindow(), SW_NORMAL);
	freopen("CONOUT$", "w", stdout);
	return; 
}

// DESC: Hide the console created by Cosole_On() function
void Console_Off(void){
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	return;
}