#ifndef EDITBOOKSCREEN_H
#define EDITBOOKSCREEN_H

#include "DisplayScreen.h"
#include "Admin.h"
#include "Catalog.h"
#include <string>

using namespace std;

class EditBookScreen : public DisplayScreen {
private:
    Admin& admin;
public:
    EditBookScreen(Admin& admin);
    void render() override;
};

#endif