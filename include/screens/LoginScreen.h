#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "DisplayScreen.h"
#include <string>

using namespace std;

class LoginScreen : public DisplayScreen {
    private:
        bool adminLogin = false;
    public:
        LoginScreen(bool adminLogin);
        void render() override;
        string handleUsernameInput();
        string handlePasswordInput();
        bool isValidPassword(const string& password);
};

#endif