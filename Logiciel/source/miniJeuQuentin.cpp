#include "../header/miniJeuQuentin.h"
#include <iostream>

miniJeuQ::miniJeuQ(AppData& appData) : MiniJeu(appData)
{
}

void miniJeuQ::setup()
{
    cercle.setRadius(50);
    cercle.setPosition(app.window.getSize().x/2 - cercle.getRadius(),app.window.getSize().y/2 - cercle.getRadius());
    cercle.setFillColor(sf::Color(sf::Color::Red));
    std::cout<<app.lives<<std::endl;
    time=8;
    chrono=Chrono(time, &clock, app.window);
}

void miniJeuQ::draw()
{
    app.window.draw(cercle);
    app.window.draw(chrono);
}

void miniJeuQ::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        cercle.move(0,-4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        cercle.move(-4,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cercle.move(0,4);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        cercle.move(4,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) || clock.getElapsedTime().asSeconds()>=time)
    {
        app.lives-=1;
        isFinished=true;
    }


    if (cercle.getPosition().y<0 || cercle.getPosition().y>app.window.getSize().y-cercle.getRadius()*2)
    {
        app.score+=1;
        isFinished=true;
    }
    if (cercle.getPosition().x<0 || cercle.getPosition().x>app.window.getSize().x-cercle.getRadius()*2)
    {
        isFinished=true;
    }

    if ((cercle.getPosition().x <= sf::Mouse::getPosition(app.window).x && sf::Mouse::getPosition(app.window).x <= cercle.getPosition().x+cercle.getRadius()*2)
            && (cercle.getPosition().y <= sf::Mouse::getPosition(app.window).y && sf::Mouse::getPosition(app.window).y <= cercle.getPosition().y+cercle.getRadius()*2))
    {
        cercle.setFillColor(sf::Color::Blue);
    }
    else
    {
        cercle.setFillColor(sf::Color::Red);
    }

    chrono.update();
}
