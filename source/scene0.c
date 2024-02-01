#include "../headers/scene0.h"




void scene0(state* state) {
    static char* Buffer = "HIII";
    static zivWindow window = { 10, 10, 200, 400 ,false, 0, 0, 0.0 };
    static zivWindow window1 = { 20, 20, 200, 400 ,false, 0, 0, 0.0 };
    static zivWindow window2 = { 30, 30, 200, 400 ,false, 0, 0, 0.0 };
    static zivWindow window3 = { 40, 40, 200, 400 ,false, 0, 0, 0.0 };

    
    spawnWindowEx(&window, state, BLUE, SKYBLUE, RED, LIGHTGRAY, GREEN, "Hello", false);
    spawnWindowEx(&window1, state, BLUE, SKYBLUE, RED, LIGHTGRAY, GREEN, "Hello", false);
    spawnWindowEx(&window2, state, BLUE, SKYBLUE, RED, LIGHTGRAY, GREEN, "Hello", false);
    spawnWindowEx(&window3, state, BLUE, SKYBLUE, RED, LIGHTGRAY, GREEN, "Hello", false);


    drawText(Buffer, window.x, window.y, 50, state->font, BLACK);
    ButtonState button = drawButton("Click Me", window.x + 40, window.y + 90, 110, 70, state->font, GRAY, WHITE, DARKGRAY, 30);
    if (button == BUTTON_CLICK_LEFT) {
        if(Buffer == "HIII") Buffer = "BYEEE";
        else Buffer = "HIII";
        
    }
}