#include "../header/miniJeu/Bronx/Bronx.h"

void Bronx::Bronx::setup()
{
    Verre verre=new Verre(truc);
    for(unsigned int i=0; i<verres.size(); ++i)
    {
        verres[i]=verre;
    }

    Ingredient ingredient=new Ingredient(truc);
    for(unsigned int i=0; i<ingredients.size(); ++i)
    {
        ingredients[i]=ingredient;
    }
}

void Bronx::Bronx::draw()
{

}

void Bronx::Bronx::update()
{
    bool verresOk=true;
    for(unsigned int i=0; i<verres.size(); ++i)
    {
        if(!(minX<=verres[i]->getPosition().x<=maxX) && (minY<=verres[i]->getPosition().y<=maxY))
        {
            verresOk=false;
        }
    }


}
