#ifndef CATALOGSCREEN_H
#define CATALOGSCREEN_H

#include "DisplayScreen.h"
#include "User.h"
#include "Catalog.h"

class CatalogScreen : public DisplayScreen {
private:
    Catalog catalog;
public:
    CatalogScreen() {};
    void render() override;
};

#endif