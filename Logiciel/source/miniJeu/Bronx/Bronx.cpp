#include "../../../header/miniJeu/Bronx/Bronx.h"

void Bronx::Bronx::setup()
{
    chrono.setTempsMax(20);
    hand.setSprite(AssetManager::getTexture("../ressource/hand.png"));

    srand(std::time(NULL));

    frigoZone.setPosition(725, 310);
    frigoZone.setSize(sf::Vector2f(500, 500));
    frigoZone.setFillColor(sf::Color::Transparent);

    for (unsigned int i = 0; i < 8; ++i)
    {
        Verre tmp = Verre(&AssetManager::getTexture("../ressource/Bronx/martini_vide.png"));
        tmp.setTarget(&frigoZone);
        verres.push_back(tmp);
    }

    ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/cinzano_doux.png")));

    ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/cinzano_sec.png")));

    for (unsigned int i = 0; i < 2; ++i)
        ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/gin.png")));

    for (unsigned int i = 0; i < 4; ++i)
        ingredients.push_back(Ingredient(true, &AssetManager::getTexture("../ressource/Bronx/jus_orange.png")));

    for (unsigned int i = 0; i < 19; ++i)
        switch (rand() % 3)
        {
            case 0:
                ingredients.push_back(Ingredient(false, &AssetManager::getTexture("../ressource/Bronx/poison.png")));
                break;
            case 1:
                ingredients.push_back(Ingredient(false, &AssetManager::getTexture("../ressource/Bronx/bleche.png")));
                break;
            case 2:
                ingredients.push_back(Ingredient(false, &AssetManager::getTexture("../ressource/Bronx/champignon.png")));
                break;
        }

    backGround.setTexture(AssetManager::getTexture("../ressource/Bronx/background.png"));
    
    placeObjects();

    for (Verre& v : verres)
        hand.add(&v);

    for (Ingredient& i : ingredients)
        hand.add(&i);

    hand.add(&shaker);

}

void Bronx::Bronx::placeObjects()
{

    for (int i(0); i < verres.size(); ++i)
        verres[i].setPosition(180 + i * 50, 480);

    for (int i(0); i < 3; ++i)
    {
        placards.push_back(std::vector<Door>());
        for (int j(0); j < 3; ++j)
        {
            placards[i].push_back(Door(0, 0, app, &AssetManager::getTexture("../ressource/Bronx/porte_placard.png")));
        }
    }

    frigo=Door(683, 238, app, &AssetManager::getTexture("../ressource/Bronx/porte_frigo.png"));

    std::random_shuffle(ingredients.begin(), ingredients.end());

    for (int i(0); i < 3; ++i)
    {
        for (int j(0); j < 3; ++j)
        {
            placards[i][j].setPosition(36 + 211 * j, 27 + i * 137);
            for (int k(0); k < 3; ++k)
            {
                ingredients[i * 9 + j * 3 + k].setPosition(36 + 211 * j + 16 + k * 42, 27 + i * 137 + 102);
                //ingredients[i * 9 + j * 3 + k].setCanBeGrabbed(false);
            }

        }
    }

    shaker.setPosition(35, 492);

    
}

void Bronx::Bronx::draw()
{
    app.window.draw(backGround);

    for (Ingredient& i : ingredients)
    {
        if (i.isStored())
            app.window.draw(i);
    }

    for (std::vector<Door>& row : placards)
    {
        for (Door& d : row)
        {
            app.window.draw(d);
        }
    }

    for (Ingredient& i : ingredients)
    {
        if (!i.isStored())
            app.window.draw(i);
    }

    for (Verre& v : verres)
    {
        app.window.draw(v);
    }


    app.window.draw(shaker);
    app.window.draw(frigo);
    app.window.draw(chrono);
}

void Bronx::Bronx::update()
{
    hand.update(app.window);
    if(chrono.getTimePassed()>chrono.getTempsMax())
    {
        app.lives-=1;
        isFinished=true;
    }

    chrono.update();

    for (std::vector<Door>& row : placards)
        for (Door& d : row)
            d.update();

    frigo.update();







    switch(etape)
    {
    case 1:
    {
        bool verresStockes=true;
        for(unsigned int i=0; i<verres.size(); ++i)
        {
            if(!verres[i].isStored())
            {
                verresStockes=false;
                break;
            }
        }
        if(verresStockes==true)
            ++etape;
        break;
    }
    case 2:

        break;
    case 3:
        if(shaker.isShakingFinished())
        {
            ++etape;
        }
        break;
    case 4:
    {
        bool verresPleins=true;
        for(unsigned int i=0; i<verres.size();++i)
        {
            if(!verres[i].isFull())
            {
                verresPleins=false;
                break;
            }
        }
        if(verresPleins==true)
            ++etape;
        break;
    }
    case 5:
        break;
    case 6:
        break;
    }

}

Bronx::Bronx::Bronx(AppData& appData): MiniJeu(appData), chrono(app.window), etape(1)
{
}

Bronx::Bronx::~Bronx()
{

}
