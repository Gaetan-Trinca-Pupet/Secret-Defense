#include "../../../header/miniJeu/Bronx/Bronx.h"

void Bronx::Bronx::setup()
{

    for (unsigned int i = 0; i < 8; ++i)
    {
        //TODO: remplacer 666 par des vraies valeur de position
        verres.push_back(new Deliverable(666 + i * 666, 666, 42, 72));
        verres[i]->setTexture(&AssetManager::getTexture("cheminVersLeSpriteDeVerVide"));
    }

    for (unsigned int i = 0; i < 2; ++i)
    {
        
        //TODO: remplacer 666 par des vraies valeur de position et taille
        Ingredient* tmpIngredient= new Ingredient(true);
        ingredients.push_back(tmpIngredient);
        tmpIngredient->setTexture(&AssetManager::getTexture("cheminVersLeSpriteDeVerDeGin"));
        tmpIngredient->setSize(sf::Vector2f(666,666));
    }

    for (unsigned int i = 0; i < 4; ++i)
    {
        //TODO: remplacer 666 par des vraies valeur de position
        Ingredient* tmpIngredient = new Ingredient(true);
        ingredients.push_back(tmpIngredient);
        tmpIngredient->setTexture(&AssetManager::getTexture("cheminVersLeSpriteDeVerDeJusDOrange"));
        tmpIngredient->setSize(sf::Vector2f(666, 666));
    }

    for (unsigned int i = 0; i < 19; ++i)
    {
        //TODO: remplacer 666 par des vraies valeur de position
        Ingredient* tmpIngredient = new Ingredient(true);
        ingredients.push_back(tmpIngredient);

        switch (rand() % 777)
        {
            case 0:
                tmpIngredient->setTexture(&AssetManager::getTexture("cheminVersLeSpriteDeTrucPasComestible0"));
                tmpIngredient->setSize(sf::Vector2f(666, 666));
                break;
            case 1:
                tmpIngredient->setTexture(&AssetManager::getTexture("cheminVersLeSpriteDeTrucPasComestible1"));
                tmpIngredient->setSize(sf::Vector2f(666, 666));
                break;
            case 2:
                tmpIngredient->setTexture(&AssetManager::getTexture("cheminVersLeSpriteDeTrucPasComestible2"));
                tmpIngredient->setSize(sf::Vector2f(666, 666));
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
        if(!verres[i]->isStored())
        {
            verresOk=false;
            break;
        }
    }


}
