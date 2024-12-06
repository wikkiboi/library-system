#include "screens/MainMenuScreen.h"


int main() {
    MainMenuScreen menu;
    menu.render();
    menu.handleMainMenuChoice();

    return 0;    
}
