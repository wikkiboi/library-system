#ifndef BORROWSCREEN_H
#define BORROWSCREEN_H

#include "DisplayScreen.h"
#include "Client.h"
#include "Catalog.h"
#include <string>

using namespace std;

class BorrowScreen : public DisplayScreen {
private:
    Client& client;
    Catalog catalog;
public:
    BorrowScreen(Client& client);
    void render() override;
};

#endif