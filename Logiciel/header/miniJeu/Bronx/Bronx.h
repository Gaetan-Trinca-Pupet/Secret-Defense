#ifndef __DISTRIBMINITESTS_H_
#define __DISTRIBMINITESTS_H_

#include "../MiniJeu.h"
#include "../../Chrono.h"
#include "Verre.h"
#include "Refrigerateur.h"
#include "Shaker.h"
#include "Ingredient.h"
#include <vector>

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

    Chrono chrono;
    sf::Sprite backGround;

    std::vector<Verre*> verres;
    std::vector<Ingredient*> ingredients;
    Shaker shaker;
    Refrigerateur refrigerateur;

};
}


#endif
