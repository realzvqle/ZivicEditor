#include "../headers/windowaddition.h"





static void handleResizeButton(zivWindow* window, state* state, Color windowColor, Color windowColorHover) {
    window->resizeButtonHeight = 30;
    window->resizeButtonGap = 0;

    ButtonState underResize = drawButton("", window->x, window->y + window->sizeY + window->resizeButtonGap, window->sizeX, window->resizeButtonHeight, state->font, windowColor, WHITE, windowColorHover, NULL);

    if (underResize == BUTTON_DOWN_LEFT || window->isResizing) {
        if (!window->isResizing) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                window->isResizing = true;
                window->resizeOffsetX = GetMouseX() - window->sizeX;
                window->resizeOffsetY = GetMouseY() - window->sizeY;
            }
        }

        if (window->isResizing && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            window->sizeX = GetMouseX() - window->resizeOffsetX;
            window->sizeY = GetMouseY() - window->resizeOffsetY;
        }

        if (window->prevSizeX > window->sizeX) window->sizeX = window->prevSizeX;
        if (window->prevSizeY > window->sizeY) window->sizeY = window->prevSizeY;
    }
}

static void handleResizeStop(zivWindow* window) {
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || (window->isResizing && window->resizeStopDelay <= 0)) {
        window->isResizing = false;
        window->resizeStopDelay = 0.5;
    }
}

void resize(zivWindow* window, state* state, Color windowColor, Color windowColorHover) {
    printf("window-prevsize: %d, %d -- window-currentsize: %d, %d\n", window->prevSizeX, window->prevSizeY, window->sizeX, window->sizeY);

    if (window->prevSizeX <= window->sizeX && window->prevSizeY <= window->sizeY) {
        handleResizeButton(window, state, windowColor, windowColorHover);
    }

    handleResizeStop(window);
}