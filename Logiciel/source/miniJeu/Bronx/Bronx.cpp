#include "../../../header/miniJeu/Bronx/Bronx.h"

void Bronx::Bronx::setup()
{

    for (unsigned int i = 0; i < 8; ++i)
        verres.push_back(Deliverable(&AssetManager::getTexture("../ressource/Bronx/martini_vide.png")));


    ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/cinzano_doux.png")));

    ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/cinzano_sec.png")));

    for (unsigned int i = 0; i < 2; ++i)
    {
        ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/gin.png")));
    }



    for (unsigned int i = 0; i < 4; ++i)
    {
        ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/jus_orange.png")));
    }

    for (unsigned int i = 0; i < 19; ++i)
    {

        switch (rand() % 3)
        {
            case 0:
                ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/poison.png")));
                break;
            case 1:
                ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/bleach.png")));
                break;
            case 2:
                ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/champignon.png")));
                break;
        }
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
        if(!verres[i].isStored())
        {
            verresOk=false;
            break;
        }
    }

}

Bronx::Bronx::~Bronx()
{

}
