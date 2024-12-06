#ifndef REMOVEBOOKSCREEN_H
#define REMOVEBOOKSCREEN_H

#include "DisplayScreen.h"
#include "Admin.h"
#include "Catalog.h"
#include <string>

using namespace std;

class RemoveBookScreen : public DisplayScreen {
private:
    Admin& admin;
public:
    RemoveBookScreen(Admin& admin);
    void render() override;
};

#endif