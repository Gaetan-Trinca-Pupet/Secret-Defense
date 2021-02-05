#include "../header/miniJeu/Bronx/Bronx.h"

void Bronx::Bronx::setup()
{
    for(unsigned int i=0; i<verres.size(); ++i)
    {
        verres[i]=new Verre(quelquechose);
    }

    for(unsigned int i=0; i<ingredients.size(); ++i)
    {
        ingredients[i]=new Ingredient(quelquechose);
    }
}

void Bronx::Bronx::draw()
{

}

void Bronx::Bronx::update()
{

}
