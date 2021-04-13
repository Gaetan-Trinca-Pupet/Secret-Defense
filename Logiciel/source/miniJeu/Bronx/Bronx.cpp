#include "../../../header/miniJeu/Bronx/Bronx.h"

Bronx::Bronx::Bronx(AppData& appData)
    : MiniJeu(appData), chrono(app.window), etape(1), shaker(&app.window, app.difficulty)
{
    chrono.setTempsMax((1 - (app.difficulty / (app.difficulty + 0.5))) * 45 + 34);
}

Bronx::Bronx::~Bronx()
{
    app.window.setMouseCursorVisible(true);

    for (Deliverable* i : ingredientsComestibles)
        delete i;
    for (Deliverable* i : ingredientsNonComestibles)
        delete i;
}

void Bronx::Bronx::setup()
{
    app.mainMusique.stop();
    if(!app.mainMusique.openFromFile("../ressource/audio/bronx.wav"))
        std::cerr<<"erreur openFromFile musique de bronx"<<std::endl;

    app.mainMusique.setVolume(30);
    app.mainMusique.setLoop(true);
    app.mainMusique.play();

    app.window.setMouseCursorVisible(false);

    hint.setString("  Mettez les verres\n         au frigo");
    hint.setFillColor(sf::Color::Black);
    hint.setStyle(sf::Text::Bold);
    hint.setCharacterSize(17);
    hint.setLineSpacing(0.8);
    hint.setFont(app.font);

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

    ingredients = ingredientsComestibles;
    for(int i=0; i<ingredientsNonComestibles.size(); ++i)
    {
        ingredients.push_back(ingredientsNonComestibles[i]);
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
        verres[i].setPosition(180 + i * 50, 490);

    for (int i(0); i < 3; ++i)
    {
        placards.push_back(std::vector<Door>());
        for (int j(0); j < 3; ++j)
        {
            placards[i].push_back(Door(0, 0, app, &AssetManager::getTexture("../ressource/Bronx/porte_placard.png"), false));
        }
    }

    frigo = Door(683, 238, app, &AssetManager::getTexture("../ressource/Bronx/porte_frigo.png"));

    std::vector<Deliverable*> ingredientsTmp;
    for (Deliverable* ingredient : ingredientsComestibles)
    {
        ingredientsTmp.push_back(ingredient);
    }
    for (Deliverable* ingredient : ingredientsNonComestibles)
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

    shaker.setPosition(35, 490);

    hint.setPosition(750, 130);
}

float Bronx::Bronx::getGroundLevel(sf::Vector2f pos)
{
    return (pos.x < 695 && pos.y < 501 ? 490 : 999999);
}

void Bronx::Bronx::draw()
{
    app.window.draw(backGround);
    app.window.draw(hint);

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

    hand.draw(app.window);
}

void Bronx::Bronx::update()
{
    for (Deliverable* ingredient : ingredientsComestibles)
    {
        ingredient->update();
        if(((ingredient->getGlobalBounds().top > app.window.getSize().y)
            || (ingredient->getGlobalBounds().left > app.window.getSize().x)
            || ((ingredient->getGlobalBounds().left+ingredient->getGlobalBounds().width) < 0))
            && (!ingredient->getIsGrabbed()))
        {
            end(false, "Vous avez fait tomber un ingrédient...");
        }
    }

    if(((shaker.getGlobalBounds().top > app.window.getSize().y)
        || (shaker.getGlobalBounds().left > app.window.getSize().x)
        || ((shaker.getGlobalBounds().left+shaker.getGlobalBounds().width) < 0))
        && (!shaker.getIsGrabbed()))
    {
        end(false, "Vous avez fait tomber le shaker...");
    }

    for (Deliverable* ingredient : ingredientsNonComestibles)
        ingredient->update();

    int i=0;
    for (Deliverable& verre : verres)
    {
        verre.update();
        if(((verre.getGlobalBounds().top > app.window.getSize().y)
            || (verre.getGlobalBounds().left > app.window.getSize().x)
            || ((verre.getGlobalBounds().left+verre.getGlobalBounds().width) < 0))
            && (!verre.getIsGrabbed()))
        {
            end(false, "Vous avez fait tomber un ingrédient...");
        }
        if(!verre.getIsGrabbed())
        {
            for(int y=i+1; y<verres.size();++y)
            {
                if(verres[y].getIsGrabbed() || verres[y].isStored()) continue;
                if(y!=i)
                {
                    if(verre.getGlobalBounds().intersects(verres[y].getGlobalBounds()))
                    {
                        verre.setStored(false);
                        verres[y].setStored(false);
                        if(verre.getPosition().x<verres[y].getPosition().x)
                        {
                            verre.move(-5,0);
                            verres[y].move(5,0);
                        }
                        else {
                            verre.move(5,0);
                            verres[y].move(-5,0);
                        }

                    }
                }
            }
        }
        i+=1;
    }


    int x=0;
    for (Deliverable* &ingredient : ingredients)
    {
        if(!ingredient->getIsGrabbed() && !ingredient->isStored())
        {
            for(int y=x+1; y<ingredients.size();++y)
            {
                if(ingredients[y]->getIsGrabbed() || ingredients[y]->isStored()) continue;
                if(y!=x)
                {
                    if(ingredient->getGlobalBounds().intersects(ingredients[y]->getGlobalBounds()))
                    {
                        ingredient->setStored(false);
                        ingredients[y]->setStored(false);
                        if(ingredient->getPosition().x<ingredients[y]->getPosition().x)
                        {
                            ingredient->move(-5,0);
                            ingredients[y]->move(5,0);
                        }
                        else {
                            ingredient->move(5,0);
                            ingredients[y]->move(-5,0);
                        }

                    }
                }
            }
        }
        x+=1;
    }


    shaker.applyVelocity();

    hand.update(app.window);
    if (chrono.getTimePassed() > chrono.getTempsMax())
    {
        end(false, "Vous avez fait tomber un verre...");
    }

    chrono.update();


    switch (etape)
    {
    case 1:
    {
        frigo.update();
        bool verresStockes = true;
        for (unsigned int i = 0; i < verres.size(); ++i)
        {
            if (!verres[i].isDelivered())
            {
                verresStockes = false;
                break;
            }
        }
        if (verresStockes == true)
        {
            ++etape;
            for (Verre& verre : verres)
            {
                verre.setCanBeGrabbed(false);
            }
            for (Deliverable* ingredient : ingredientsComestibles)
            {
                ingredient->setTarget(&shaker);
                ingredient->setCanBeGrabbed(true);
            }
            for (Deliverable* ingredient : ingredientsNonComestibles)
            {
                ingredient->setTarget(&shaker);
                ingredient->setCanBeGrabbed(true);
            }
            frigo.setOpened(false);
            std::string str("          Mettez les\n   ingrédients dans\n           le shaker");
            hint.setString(sf::String::fromUtf8(str.begin(), str.end()));
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
            if (ingredientsComestibles[i]->isDelivered())
            {
                hand.remove(ingredientsComestibles[i]);
                ingredientsComestibles.erase(ingredientsComestibles.begin() + i);
                AssetManager::playSound("../ressource/audio/bing.wav",20);
            }
        }
        for (int i(ingredientsNonComestibles.size()); i != 0 && ingredientsNonComestibles.size() != 0;)
        {
            --i;
            if (ingredientsNonComestibles[i]->isDelivered())
            {

                end(false, "Vous avez mis un mauvais ingrédient...");
                break;
            }
        }

        if (ingredientsComestibles.size() == 0)
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
            std::string str("\n     Agitez le shaker");
            hint.setString(sf::String::fromUtf8(str.begin(), str.end()));
        }
        break;
    case 3:

        if (shaker.isShakingFinished())
        {
            ++etape;
            std::string str("          Sortez les\n     verres du frigo");
            hint.setString(sf::String::fromUtf8(str.begin(), str.end()));
            for (Verre& verre : verres)
            {
                verre.setCanBeGrabbed(true);
            }
            AssetManager::playSound("../ressource/audio/bing.wav",20);
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
            std::string str("\n           Servez");
            hint.setString(sf::String::fromUtf8(str.begin(), str.end()));
            AssetManager::playSound("../ressource/audio/bing.wav",20);
        }
        break;
    }
    case 5:
        shaker.fillUp(verres);
        for (Verre& v : verres)
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
        {
            end(true, "Victoire, la difficulté augmente !");
        }
        break;
    }

}


