#ifndef USERSCREEN_H
#define USERSCREEN_H

#include "DisplayScreen.h"
#include "Client.h"

class UserScreen : public DisplayScreen {
private:
    Client& client;
public:
    explicit UserScreen(Client& clientRef);
    void render() override;
    void handleUserChoice(int choice);
};

#endif