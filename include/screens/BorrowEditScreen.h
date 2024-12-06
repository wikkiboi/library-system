#ifndef BORROWSCREEN_H
#define BORROWSCREEN_H

#include "DisplayScreen.h"
#include "Client.h"
#include "Catalog.h"
#include <string>

using namespace std;

class BorrowEditScreen : public DisplayScreen {
private:
    Client& client;
    Borrow& borrow;
public:
    BorrowEditScreen(Client& client, Borrow& borrow);
    void render() override;
};

#endif