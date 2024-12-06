#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "DisplayScreen.h"
#include <string>

using namespace std;

class MainMenuScreen : public DisplayScreen {
    public:
        MainMenuScreen() {};
        void render() override;
        void handleMainMenuChoice(int choice);
};

#endif