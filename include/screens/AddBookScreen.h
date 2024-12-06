#ifndef ADDBOOKSCREEN_H
#define ADDBOOKSCREEN_H

#include "DisplayScreen.h"
#include "Admin.h"
#include "Catalog.h"
#include <string>

using namespace std;

class AddBookScreen : public DisplayScreen {
private:
    Admin& admin;
public:
    AddBookScreen(Admin& admin);
    void render() override;
};

#endif