#ifndef CATALOGSCREEN_H
#define CATALOGSCREEN_H

#include "DisplayScreen.h"
#include "User.h"
#include "Catalog.h"

class CatalogScreen : public DisplayScreen {
private:
    User& user;
    Catalog catalog;
public:
    explicit CatalogScreen(User& userRef);
    void render() override;
};

#endif