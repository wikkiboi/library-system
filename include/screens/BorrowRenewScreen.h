#ifndef BORROWRENEWSCREEN_H
#define BORROWRENEWSCREEN_H

#include "DisplayScreen.h"
#include "Client.h"
#include "Catalog.h"
#include <string>

using namespace std;

class BorrowRenewScreen : public DisplayScreen {
private:
    Client& client;
public:
    BorrowRenewScreen(Client& client);
    void render() override;
};

#endif