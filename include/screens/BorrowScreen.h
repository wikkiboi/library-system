#ifndef BORROWSCREEN_H
#define BORROWSCREEN_H

#include "DisplayScreen.h"
#include <string>

using namespace std;

class BorrowScreen : public DisplayScreen {
private:
    string username;
public:
    BorrowScreen(const string& user);
    void render() override;
    void handleBorrowChoice(int choice);
};

#endif