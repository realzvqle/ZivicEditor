#include "../headers/drawText.h"





void drawText(char* text, int x, int y, int size, Font font, Color color) {
	DrawTextEx(font, text, (Vector2) { x, y }, size, 4, color);
}