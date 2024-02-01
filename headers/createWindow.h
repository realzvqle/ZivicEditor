#pragma once
#include "button.h"



typedef struct zivWindow {
	int x;
	int y;
	int sizeX;
	int sizeY;
	bool isDragging;
	int dragOffsetX;
	int dragOffsetY;
	double dragStopDelay;
} zivWindow;


void spawnWindow(zivWindow* window, state* state);
void spawnWindowEx(zivWindow* window, state* state, Color titleBarColor, Color titleBarColorHover, Color windowColor, Color windowColorHover, Color textColor, char* titleBarTitle, bool isResizeable);