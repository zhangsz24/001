//此为登录所需两个函数

#include "Login.h"
#include <iostream>
#include <fstream>
#include <string>
#include "SetCursor.h"
#include <stdlib.h>


//登录流程
LoginResult Login::login() {
    system("cls");
    std::string username, password, storedPassword;
    SetCursor(48, 10);
    std::cout << "用户名: ";
    std::cin >> username;
    SetCursor(48, 13);
    std::cout << "密码: ";
    std::cin >> password;

    std::string filename = username + ".txt";
    std::ifstream file(filename);
    if (file.is_open()) {
        std::getline(file, storedPassword);
        file.close();
        if (storedPassword == password) {
            return { true,username };
        }
        else {
            SetCursor(40, 16);
            std::cout << "密码错误！是否重新输入？ (y/n): ";
            char choice;
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                return login();
            }
            return { false, "" };
        }
    }
    else {
        SetCursor(49, 16);
        std::cout << "账号未注册" << std::endl;
        SetCursor(42, 17);
        std::cout << "是否注册新账号？ (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {

            createAccount(username);
            return login();
        }
        return { false, "" };
    }
}


//未注册账号的文件创建
void Login::createAccount(const std::string& username) {
    system("cls");
    SetCursor(48, 10);
    std::string password;
    std::cout << "用户名:" << username << std::endl;
    SetCursor(48, 12);
    std::cout << "新密码: ";
    std::cin >> password;

    std::string filename = username + ".txt";
    std::ofstream file(filename);
    if (file.is_open()) {
        file << password << std::endl; // 确保密码独占第一行
        file.close();
        SetCursor(44, 15);
        std::cout << "账号创建成功！请重新登录" << std::endl;
        Sleep(2000);
    }
    else {
        SetCursor(48, 14);
        std::cout << "账号创建失败！" << std::endl;
        Sleep(2000);

    }
}