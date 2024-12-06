#ifndef BORROWRETURNSCREEN_H
#define BORROWRETURNSCREEN_H

#include "DisplayScreen.h"
#include "Client.h"
#include "Catalog.h"
#include <string>

using namespace std;

class BorrowReturnScreen : public DisplayScreen {
private:
    Client& client;
public:
    BorrowReturnScreen(Client& client);
    void render() override;
};

#endif