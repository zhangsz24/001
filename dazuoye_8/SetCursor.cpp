#include "SetCursor.h"
#include <Windows.h>


//用于控制光标位置的函数，用于画面美观
void SetCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}