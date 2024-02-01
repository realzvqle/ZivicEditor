#pragma once
#include <stdio.h>
#include <raylib.h>
#include <stdint.h>



typedef struct window {
	int sizeX;
	int sizeY;
	char* name;
} window;

typedef struct args {
	int argc;
	char* argv[20];
} args;

typedef struct currentScene {
	uint_fast8_t currentScene;
	bool init;
} scene;


typedef struct state {
	window mainWindow;
	Color backgroundColor;
	args arguments;
	scene scene;
	Font font;
	bool isExit;
	bool isWindowSpawned;
} state;