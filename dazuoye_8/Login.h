#ifndef LOGIN_H
#define LOGIN_H

#include <string>

struct LoginResult {
    bool success;
    std::string username;
};

class Login {
public:
    static LoginResult login();  // 静态成员函数，返回登录结果和用户名
private:
    static void createAccount(const std::string& username);
};

#endif // LOGIN_H