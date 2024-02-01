#include "../headers/createWindow.h"


void spawnWindow(zivWindow* window, state* state) {
    

    printf("Before Dragging - X: %d, Y: %d\n", window->x, window->y);
    drawButton("", window->x, window->y, window->sizeX, window->sizeY, state->font, (Color) { 0, 0, 100, 255 }, WHITE, (Color) { 0, 0, 200, 255 }, NULL);
    ButtonState bar = drawButton("", window->x, window->y - 10, window->sizeX, 10, state->font, (Color) { 0, 100, 0, 255 }, WHITE, (Color) { 0, 200, 0, 255 }, NULL);

    if (bar == BUTTON_CLICK_LEFT || window->isDragging) {
        if (!window->isDragging) {
            window->isDragging = true;
            window->dragOffsetX = GetMouseX() - window->x;
            window->dragOffsetY = GetMouseY() - window->y;
        }

        if (window->isDragging && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            window->x = GetMouseX() - window->dragOffsetX;
            window->y = GetMouseY() - window->dragOffsetY;
            printf("After Dragging - X: %d, Y: %d\n", window->x, window->y);
            window->dragStopDelay -= GetFrameTime();
        }
    }

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || (window->isDragging && window->dragStopDelay <= 0)) {
        window->isDragging = false;
        window->dragStopDelay = 0.5;
    }
}



