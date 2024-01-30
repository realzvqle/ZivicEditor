#include "../headers/window.h"


static window setupWindow() {
	window window;
	window.sizeX = 1600;
	window.sizeY = 900;
	window.name = "Zivic Editor";

	return window;
}



int createWindow(state* state) {
	state->mainWindow = setupWindow();
	state->backgroundColor = BLACK;
	SetTraceLogLevel(LOG_ERROR);

	InitWindow(state->mainWindow.sizeX, state->mainWindow.sizeY, state->mainWindow.name);
	SetWindowState(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawFPS(10, 10);
		ClearBackground(state->backgroundColor);
		EndDrawing();
	}
	return 0;
}