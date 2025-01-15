#ifndef LOGIN_H
#define LOGIN_H

#include <string>

struct LoginResult {
    bool success;
    std::string username;
};

class Login {
public:
    static LoginResult login();  // ��̬��Ա���������ص�¼������û���
private:
    static void createAccount(const std::string& username);
};

#endif // LOGIN_H