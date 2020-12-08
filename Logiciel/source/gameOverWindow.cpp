#include "../header/gameOverWindow.h"

gameOverWindow::gameOverWindow(AppData& appData) : MiniJeu(appData)
{
    app.window.display();
    capturedImg.create(app.window.getView().getSize().x, app.window.getView().getSize().y);
    capturedImg.update(app.window);
}

void gameOverWindow::setup()
{
    text.setFont(app.font);
    text.setString("Game Over, souhaitez-vous continuer?");
    //text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    sf::FloatRect rect=text.getGlobalBounds();
    text.setPosition(app.window.getView().getSize().x/2-rect.width/2, /*app.window.getView().getSize().y/6*/20);
//    bouton1.setRadius(50);
//    bouton1.setPosition(app.window.getView().getSize().x/2 - bouton1.getRadius()-100,app.window.getView().getSize().y-200 - bouton1.getRadius());
//    bouton1.setFillColor(sf::Color(sf::Color::Blue));

//    bouton2.setRadius(50);
//    bouton2.setPosition(app.window.getView().getSize().x/2 - bouton2.getRadius()+100,app.window.getView().getSize().y-200 - bouton2.getRadius());
//    bouton2.setFillColor(sf::Color(sf::Color::Red));

    spriteRetry.setTexture(assetmanager.getTexture("../ressource/image/r.png"));
    spriteRetry.setPosition(app.window.getView().getSize().x/2 - (spriteRetry.getGlobalBounds().width/2)-100,app.window.getView().getSize().y-200 - spriteRetry.getGlobalBounds().height/2);
    spriteQuit.setTexture(assetmanager.getTexture("../ressource/image/q.png"));
    spriteQuit.setPosition(app.window.getView().getSize().x/2 - (spriteQuit.getGlobalBounds().width/2)+100,app.window.getView().getSize().y-200 - spriteQuit.getGlobalBounds().height/2);

    captureSprite.setTexture(capturedImg);

    prompt.setFont(app.font);
    prompt.setString("Entrez votre nom pour enregistrer le score :");
    prompt.setFillColor(sf::Color::White);
    prompt.setPosition(app.window.getView().getSize().x/2-prompt.getGlobalBounds().width/2, app.window.getView().getSize().y/4);

    txtField.setFont(app.font);
    txtField.setPosition(sf::Vector2f(app.window.getView().getSize().x/2-300, app.window.getView().getSize().y/2-50));
    txtField.setTextColor(sf::Color::Black);
    txtField.setFillColor(sf::Color::White);
    txtField.setSize(sf::Vector2u(600,50));
    txtField.setFocus(true);

    box.setPosition(0,0);
    box.setSize(sf::Vector2f(app.window.getView().getSize().x,app.window.getView().getSize().y));
    box.setFillColor(sf::Color(0,0,0,150));
}

void gameOverWindow::draw()
{
    app.window.draw(captureSprite);
    app.window.draw(box);
    app.window.draw(text);
//    app.window.draw(bouton1);
//    app.window.draw(bouton2);
    app.window.draw(spriteRetry);
    app.window.draw(spriteQuit);
    app.window.draw(prompt);
    txtField.draw(app.window);
}

void gameOverWindow::update()
{

    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());


    txtField.update(app.window);
    txtField.setFocus(true);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
//        if ((bouton1.getPosition().x <= sf::Mouse::getPosition(app.window).x && sf::Mouse::getPosition(app.window).x <= bouton1.getPosition().x+bouton1.getRadius()*2)
//                && (bouton1.getPosition().y <= sf::Mouse::getPosition(app.window).y && sf::Mouse::getPosition(app.window).y <= bouton1.getPosition().y+bouton1.getRadius()*2))
        if((spriteRetry.getPosition().x <= sf::Mouse::getPosition(app.window).x && sf::Mouse::getPosition(app.window).x <= spriteRetry.getPosition().x+spriteRetry.getGlobalBounds().width)
                && (spriteRetry.getPosition().y <= sf::Mouse::getPosition(app.window).y && sf::Mouse::getPosition(app.window).y <= spriteRetry.getPosition().y+spriteRetry.getGlobalBounds().height))
        {
            if (txtField.isValidate())
            {
                std::ofstream myfile;
                myfile.open("../ressource/scores/"+txtField.getString()+".txt", std::ios::app);
                myfile<< time(&currentTime) << " - Score : "+std::to_string(app.score)+"\n\n";
                myfile.close();
                app.score=0;
                app.lives=3;
                app.difficulty=0;
                isFinished=true;
            }

        }

//        if ((bouton2.getPosition().x <= sf::Mouse::getPosition(app.window).x && sf::Mouse::getPosition(app.window).x <= bouton2.getPosition().x+bouton2.getRadius()*2)
//                && (bouton2.getPosition().y <= sf::Mouse::getPosition(app.window).y && sf::Mouse::getPosition(app.window).y <= bouton2.getPosition().y+bouton2.getRadius()*2))
        if((spriteQuit.getPosition().x <= sf::Mouse::getPosition(app.window).x && sf::Mouse::getPosition(app.window).x <= spriteQuit.getPosition().x+spriteQuit.getGlobalBounds().width)
                && (spriteQuit.getPosition().y <= sf::Mouse::getPosition(app.window).y && sf::Mouse::getPosition(app.window).y <= spriteQuit.getPosition().y+spriteQuit.getGlobalBounds().height))
        {
            if (txtField.isValidate())
            {
                std::ofstream myfile;
                myfile.open("../ressource/scores/"+txtField.getString()+".txt", std::ios::app);
                myfile<< time(&currentTime) +" - Score : "+std::to_string(app.score)+"\n\n";
                myfile.close();
                app.window.close(); //enlever ça
                //app.selecteur=0; //changer pour le chiffre correspondant à l'écran de score final
                isFinished=true; //laisser ça
            }

        }
    }
}
