#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include "DisplayScreen.h"
#include "Admin.h"

class AdminScreen : public DisplayScreen {
private:
    Admin& admin;
public:
    explicit AdminScreen(Admin& adminRef);
    void render() override;
    void handleAdminChoice(int choice);
};

#endif // ADMINSCREEN_H