#include "../../../header/miniJeu/Bronx/Bronx.h"

Bronx::Bronx::Bronx(AppData& appData)
    : MiniJeu(appData), chrono(app.window), etape(1), shaker(&app.window)
{
}

Bronx::Bronx::~Bronx()
{
    for (Deliverable* i : ingredientsComestibles)
        delete i;
    for (Deliverable* i : ingredientsNonComestibles)
        delete i;
}

void Bronx::Bronx::setup()
{

    chrono.setTempsMax(120);
    hand.setSprite(AssetManager::getTexture("../ressource/hand.png"));

    GravityAffected::setGetGroundLevelFunc(&getGroundLevel);

    srand(std::time(NULL));

    frigoZone.setPosition(725, 310);
    frigoZone.setSize(sf::Vector2f(500, 500));
    frigoZone.setFillColor(sf::Color::Transparent);

    for (unsigned int i = 0; i < 7; ++i)
    {
        Verre tmp = Verre(&AssetManager::getTexture("../ressource/Bronx/martini_vide.png"));
        tmp.setTarget(&frigoZone);
        verres.push_back(tmp);
    }

    ingredientsComestibles.push_back(new Deliverable(&AssetManager::getTexture("../ressource/Bronx/cinzano_doux.png"), true));

    ingredientsComestibles.push_back(new Deliverable(&AssetManager::getTexture("../ressource/Bronx/cinzano_sec.png"), true));

    for (unsigned int i = 0; i < 2; ++i)
        ingredientsComestibles.push_back(new Deliverable(&AssetManager::getTexture("../ressource/Bronx/gin.png"), true));

    for (unsigned int i = 0; i < 4; ++i)
        ingredientsComestibles.push_back(new Deliverable(&AssetManager::getTexture("../ressource/Bronx/jus_orange.png"), true));

    for (unsigned int i = 0; i < 19; ++i)
    {
        std::string sprite;
        switch (rand() % 3)
        {
        case 0:
            sprite = "../ressource/Bronx/poison.png";
            break;
        case 1:
            sprite = "../ressource/Bronx/bleche.png";
            break;
        case 2:
            sprite = "../ressource/Bronx/champignon.png";
            break;
        }
        ingredientsNonComestibles.push_back(new Deliverable(&AssetManager::getTexture(sprite), true));
    }
        

    backGround.setTexture(AssetManager::getTexture("../ressource/Bronx/background.png"));
    
    placeObjects();

    for (Verre& v : verres)
        hand.add(&v);

    for (Deliverable* i : ingredientsComestibles)
        hand.add(i);

    for (Deliverable* i : ingredientsNonComestibles)
        hand.add(i);

    hand.add(&shaker);

}

void Bronx::Bronx::placeObjects()
{

    for (unsigned long long i(0); i < verres.size(); ++i)
        verres[i].setPosition(180 + i * 50, 480);

    for (int i(0); i < 3; ++i)
    {
        placards.push_back(std::vector<Door>());
        for (int j(0); j < 3; ++j)
        {
            placards[i].push_back(Door(0, 0, app, &AssetManager::getTexture("../ressource/Bronx/porte_placard.png"), false));
        }
    }

    frigo=Door(683, 238, app, &AssetManager::getTexture("../ressource/Bronx/porte_frigo.png"));

    std::vector<Deliverable*> ingredientsTmp;
    for(Deliverable* ingredient : ingredientsComestibles)
    {
        ingredientsTmp.push_back(ingredient);
    }
    for(Deliverable* ingredient : ingredientsNonComestibles)
    {
        ingredientsTmp.push_back(ingredient);
    }

    std::random_shuffle(ingredientsTmp.begin(), ingredientsTmp.end());

    for (int i(0); i < 3; ++i)
    {
        for (int j(0); j < 3; ++j)
        {
            placards[i][j].setPosition(36 + 211 * j, 27 + i * 137);
            for (int k(0); k < 3; ++k)
            {
                ingredientsTmp[i * 9 + j * 3 + k]->setPosition(36 + 211 * j + 16 + k * 42, 27 + i * 137 + 102);
                ingredientsTmp[i * 9 + j * 3 + k]->setCanBeGrabbed(false);
            }

        }
    }

    shaker.setPosition(35, 492);
}

float Bronx::Bronx::getGroundLevel(sf::Vector2f pos)
{
    return (pos.x < 695 && pos.y < 501 ? 490 : 999999);
}

void Bronx::Bronx::draw()
{
    app.window.draw(backGround);

    for (Deliverable* ingredient : ingredientsComestibles)
    {
        if (ingredient->isStored())
            app.window.draw(*ingredient);
    }

    for (Deliverable* ingredient : ingredientsNonComestibles)
    {
        if (ingredient->isStored())
            app.window.draw(*ingredient);
    }

    for (Verre& v : verres)
    {
        if (v.isStored())
            app.window.draw(v);
    }

    for (std::vector<Door>& row : placards)
    {
        for (Door& d : row)
        {
            app.window.draw(d);
        }
    }
    app.window.draw(frigo);

    app.window.draw(shaker);

    for (Deliverable* ingredient : ingredientsComestibles)
    {
        if (!ingredient->isStored())
            app.window.draw(*ingredient);
    }
    for (Deliverable* ingredient : ingredientsNonComestibles)
    {
        if (!ingredient->isStored())
            app.window.draw(*ingredient);
    }

    for (Verre& v : verres)
    {
        if (!v.isStored())
            app.window.draw(v);
    }

    

    app.window.draw(chrono);
}

void Bronx::Bronx::update()
{
    for (Deliverable* ingredient : ingredientsComestibles)
        ingredient->update();

    for (Deliverable* ingredient : ingredientsNonComestibles)
        ingredient->update();

    for (Deliverable& verre : verres)
        verre.update();



    hand.update(app.window);
    if(chrono.getTimePassed()>chrono.getTempsMax())
    {
        app.lives-=1;
        isFinished=true;
    }

    chrono.update();


    // PAS FINI

    switch(etape)
    {
    case 1:
    {
        frigo.update();
        bool verresStockes=true;
        for(unsigned int i=0; i<verres.size(); ++i)
        {
            if(!verres[i].isDelivered())
            {
                verresStockes=false;
                break;
            }
        }
        if(verresStockes==true)
        {
            ++etape;
            for (Verre& verre : verres)
            {
                verre.setCanBeGrabbed(false);
            }
            for(Deliverable* ingredient : ingredientsComestibles)
            {
                ingredient->setTarget(&shaker);
                ingredient->setCanBeGrabbed(true);
            }
            for(Deliverable* ingredient : ingredientsNonComestibles)
            {
                ingredient->setTarget(&shaker);
                ingredient->setCanBeGrabbed(true);
            }
            frigo.setOpened(false);
        }
        break;
    }
    case 2:

        for (std::vector<Door>& row : placards)
            for (Door& d : row)
                d.update();

        for (int i(ingredientsComestibles.size()); i != 0 && ingredientsComestibles.size() != 0;)
        {
            --i;
            if(ingredientsComestibles[i]->isDelivered())
            {
                hand.remove(ingredientsComestibles[i]);
                ingredientsComestibles.erase(ingredientsComestibles.begin() + i);
            }
        }
        for (int i(ingredientsNonComestibles.size()); i != 0 && ingredientsNonComestibles.size() != 0;)
        {
            --i;
            if(ingredientsNonComestibles[i]->isDelivered())
            {
                --app.lives;
                isFinished=true;
                break;
            }
        }

        if(ingredientsComestibles.size()==0)
        {
            ++etape;
            shaker.startShaking();

            for (std::vector<Door>& row : placards)
                for (Door& d : row)
                    d.setOpened(false);

            for (Deliverable* ingredient : ingredientsNonComestibles)
            {
                ingredient->setTarget(nullptr);

                if (ingredient->isStored())
                    ingredient->setCanBeGrabbed(false);
            }
        }
        break;
    case 3:

        if(shaker.isShakingFinished())
        {
            ++etape;
            for (Verre& verre : verres)
            {
                verre.setCanBeGrabbed(true);
            }
        }
        break;

    case 4:
    {
        frigo.update();
        bool verresSortis = true;
        for (unsigned int i = 0; i < verres.size(); ++i)
        {
            if (verres[i].isStored())
            {
                verresSortis = false;
                break;
            }
        }
        if (verresSortis == true)
        {
            ++etape;
            shaker.startFilling();
            frigo.setOpened(false);
        }
    }
    case 5:


        for(Verre& v: verres)
        {
            v.update();
        }

        bool verresPleins = true;
        for (unsigned int i = 0; i < verres.size(); ++i)
        {
            if (!verres[i].isFull())
            {
                verresPleins = false;
                break;
            }
        }
        if (verresPleins == true)
            ++etape;
        break;
    }

}


