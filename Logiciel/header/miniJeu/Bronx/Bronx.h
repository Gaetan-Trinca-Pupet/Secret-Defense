#ifndef __BRONX_H_
#define __BRONX_H_

#include <vector>
#include "../MiniJeu.h"
#include "../../Chrono.h"
#include "../../AssetManager.h"
#include "Deliverable.h"
#include "Verre.h"
#include "Shaker.h"
#include "Door.h"
#include "../../Grabber.hpp"

namespace Bronx {
class Bronx : public MiniJeu
{
public:

    virtual void draw();
    virtual void update();
    virtual void setup();

    Bronx(AppData& appData);
    virtual ~Bronx();

private:

    void placeObjects();

    Chrono chrono;
    sf::Sprite backGround;
    int etape;

    Grabber::Grabber hand;

    sf::RectangleShape frigoZone;

    std::vector<Verre> verres;
    std::vector<Deliverable> ingredientsComestibles;
    std::vector<Deliverable> ingredientsNonComestibles;
    Shaker shaker;
    std::vector<std::vector<Door>> placards;
    Door frigo;
};
}


#endif
