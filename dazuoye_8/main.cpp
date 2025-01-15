#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Login.h"
#include "LevelSelect.h"
#include "SetCursor.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
#include "game.h"
#include <limits>


#undef max //避免后续使用 max() 找最值时出现冲突





// 假设的关卡逻辑
bool playLevel(int levelNumber) {
    switch (levelNumber) {
    case 1: {
        int a=stage1();
        if(a){return true;}
        else{return false;}
    }
    case 2: {
       int a=stage2();
        if(a){return true;}
        else{return false;}
    }
    case 3: {
        int a=stage3();
        if(a){return true;}
        else{return false;}
    }
    case 4: {
        int a=stage4();
        if(a){return true;}
        else{return false;}
    }
    default: {
        std::cout << "Invalid level number." << std::endl;
        return false;
    }
    }
}
//上面为假设,之后需要删除以上假设关卡代码



//用于获得已通过最高关卡的函数
int getHighestPassedLevel(const std::string& username) {
    std::string filename = username + ".txt";
    std::ifstream file(filename);
    int highestLevel = 0;
    if (file.is_open()) {
        std::string line;
        // 跳过密码行
        std::getline(file, line);
        while (std::getline(file, line)) {
            if (line.find("Level") != std::string::npos && line.find("Passed") != std::string::npos) {
                int level = std::stoi(line.substr(5, line.find("Passed") - 5));
                highestLevel = std::max(highestLevel, level);
            }
        }
        file.close();
    }
    return highestLevel;
}

void saveLevelProgress(const std::string& filename, int level) {
    std::ofstream outfile;

    outfile.open(filename, std::ios::app); // 以追加模式打开文件
    if (outfile.is_open()) {
        outfile << "Level" << level << "Passed" << std::endl; // 写入内容
        outfile.close(); // 关闭文件
    }
    else {
        std::cerr << "存储通关信息失败！" << filename << std::endl;
    }
}


// 这是最后一关的编号
const int LAST_LEVEL = 4;//假设为4

int getHighestPassedLevel(const std::string& username);
void saveLevelProgress(const std::string& username, int level);


int main() {
    std::string username;
    LoginResult result = Login::login();
    if (result.success) {
        system("cls");
        SetCursor(51, 13);
        std::cout << "登录成功!" << std::endl;
        Sleep(2000);
    
    }
    else {
        system("cls");
        SetCursor(49, 13);
        std::cout << "登录失败，程序退出!" << std::endl;
        Sleep(2000);
        return 1;
    }

    lableone:system("cls");// lableone 标记处
    username=result.username;//获得username


    bool isPlaying = true;
    while (isPlaying) {
        int highestPassedLevel = getHighestPassedLevel(username);
        selectLevel(highestPassedLevel);
        int selectedLevel;
        std::cin >> selectedLevel;

        if (std::cin.fail() || selectedLevel < 1 || selectedLevel > highestPassedLevel + 1|| selectedLevel > LAST_LEVEL) {
            std::cin.clear(); // 清除错误状态
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入直到下一个换行符
            SetCursor(44, 17);
            if (highestPassedLevel < LAST_LEVEL) {
                std::cout << "无效输入！ 可挑战关卡为 1 到 " << highestPassedLevel + 1 << std::endl;
                SetCursor(49, 18);
                system("pause");
                continue;
            }
            else {
                std::cout << "无效输入！ 可挑战关卡为 1 到 " << LAST_LEVEL << std::endl;
                SetCursor(49, 18);
                system("pause");
                continue;
            }
        }
       
        
    labletwo: system("cls");// labletwo 标记处

        //执行关卡逻辑
        bool success = playLevel(selectedLevel);//执行完成后获得bool值

        if (success) {//判断是否成功，继续用户交互界面
            system("cls");
            SetCursor(43, 12);
            std::cout << "Congratulations! 成功通过关卡 " << selectedLevel << "  ！" << std::endl;
            

            username = username+ ".txt";
            saveLevelProgress(username, selectedLevel);
            if (selectedLevel == LAST_LEVEL) {
                SetCursor(50, 14);
                std::cout << "恭喜你完成所有关卡！" << std::endl;
            }
            
                SetCursor(47, 16);
                std::cout << "是否继续选择关卡? (y/n): ";
                char choice;
                std::cin >> choice;
                 if(choice == 'y' || choice == 'Y')
                goto lableone; //使程序跳回前面 lableone 标记处
                else{break;}
            
        }
        else {
            system("cls");
            SetCursor(43, 14);
            std::cout << "挑战失败！是否再试一次? (y/n): ";
            char choice;
            std::cin >> choice;
            if (choice == 'y' ||choice== 'Y') {
                goto labletwo;//使程序跳回前面 labletwo 标记处
            }
            else {
                system("cls");
                SetCursor(43, 14);
                std::cout<<"是否游玩其他关卡?(y/n):";
                char CHOICE;
                std::cin>>CHOICE;
                if (CHOICE=='y'||CHOICE=='Y'){
                    goto lableone;


                }
                else{
                isPlaying = false;
                }
            }
        }
    }

    return 0;
}