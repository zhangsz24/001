#include "LevelSelect.h"
#include <iostream>
#include <stdlib.h>
#include "SetCursor.h"

#undef max


//选择关卡步骤的前置函数，后续实现在主程序中
// 这是最后一关的编号
const int LAST_LEVEL = 4;//此次假设为4

void selectLevel(int highestPassedLevel) {
    system("cls");
    SetCursor(51, 7);
    std::cout << "--- 选择关卡 ---\n" << std::endl;
    for (int i = 1; i <= highestPassedLevel; ++i) {
        SetCursor(52, 9);
        std::cout << "关卡 " << i << ": 已通过\n" << std::endl;
    }
    if (highestPassedLevel < LAST_LEVEL) {
        for (int i = highestPassedLevel + 1; i <= highestPassedLevel + 1; ++i) { // 最多显示下一个关卡
            SetCursor(52, 11);
            std::cout << "关卡 " << i << ": 未通过\n" << std::endl;
        }
        SetCursor(48, 15);
        std::cout << "请选择挑战关卡 (1-" << highestPassedLevel + 1 << "): ";
    }
    else {
        // 当最高通过的关卡等于最后一个关卡时
        SetCursor(52, 11);
        std::cout << "所有关卡已通过!\n" << std::endl;
        SetCursor(48, 15);
        std::cout << "请选择挑战关卡 (1-" << LAST_LEVEL << "): ";
    }
}