#ifndef USERSCREEN_H
#define USERSCREEN_H

#include "DisplayScreen.h"
#include "Client.h"

class UserScreen : public DisplayScreen {
private:
    Client& client;
public:
    UserScreen(Client& clientRef);
    void render() override;
    bool handleUserChoice();
};

#endif