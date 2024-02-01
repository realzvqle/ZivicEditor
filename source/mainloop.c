#include "../headers/mainloop.h"




static scene startEditor() {
	scene scene;
	scene.currentScene = 0;
	scene.init = true;
}


bool mainLoop(state* state) {
	if (!state->scene.init) {
		state->scene = startEditor();
	}
	
	switch (state->scene.currentScene) {
		case 0:
			scene0(state);
			break;
		case 1:
			state->backgroundColor = (Color){ 0,0,50,255 };
			break;
		default:
			state->scene.currentScene = 0;

	}
}