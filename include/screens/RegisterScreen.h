#ifndef REGISTERSCREEN_H
#define REGISTERSCREEN_H

#include "DisplayScreen.h"
#include <string>

using namespace std;

class RegisterScreen : public DisplayScreen {
    public:
        RegisterScreen() {};
        void render() override;
        string handleUsernameInput();
        string handlePasswordInput();
        bool isValidPassword(const string& password);
};

#endif