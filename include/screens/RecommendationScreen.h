#ifndef RECOMMENDATIONSCREEN_H
#define RECOMMENDATIONSCREEN_H

#include "DisplayScreen.h"
#include "Client.h"
#include "Catalog.h"

class RecommendationScreen : public DisplayScreen {
private:
    Client& client;
    Catalog catalog;
public:
    RecommendationScreen(Client& clientRef);
    void render() override;
};

#endif