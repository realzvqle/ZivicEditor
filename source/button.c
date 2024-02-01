#include "../headers/button.h"





ButtonState drawButton(char* text, int x, int y, int sizeX, int sizeY, Font font, Color baseColor, Color textColor, Color hoverColor, int textSize) {
    if (!textSize) {
        textSize = sizeY / 2;
    }
    bool isMouseOver = CheckCollisionPointRec(GetMousePosition(), (Rectangle) { x, y, sizeX, sizeY });
    Color buttonColor = isMouseOver ? hoverColor : baseColor;

    DrawRectangle(x, y, sizeX, sizeY, buttonColor);

    int textWidth = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        textWidth += MeasureText(&text[i], textSize);
    }

    int textX = x + (sizeX - MeasureTextEx(font, text, textSize, 4).x) / 2;
    int textY = y + (sizeY - textSize) / 2;

    drawText(text, textX, textY, textSize, font, textColor);

    if (isMouseOver && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_CLICK_LEFT;
    }

    if (isMouseOver && IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_CLICK_RIGHT;
    }
    
    if (isMouseOver) {
        DrawRectangleLinesEx((Rectangle) { x, y, sizeX, sizeY }, 2, textColor);
        return BUTTON_HOVER;
    }

    return BUTTON_NOT_INTERACTED;
}



void exitButton(int x, int y, int size, Font font, state* state) {
    int sizeX;
    int sizeY;
    if (!size) {
        sizeX = 30;
        sizeY = 30;
    }
    else {
        sizeX = size;
        sizeY = size;
    }
    ButtonState button = drawButton("X", x, y, sizeX, sizeY, font, GRAY, RED, DARKGRAY, NULL);
    if (button == BUTTON_CLICK_LEFT) state->isExit = true;
}

