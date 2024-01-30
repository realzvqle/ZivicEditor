#pragma once
#include <stdio.h>
#include <raylib.h>




typedef struct window {
	int sizeX;
	int sizeY;
	char* name;
} window;

typedef struct args {
	int argc;
	char* argv[20];
} args;

typedef struct state {
	window mainWindow;
	Color backgroundColor;
	args arguments;
} state;