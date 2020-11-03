#include "../header/gameOverWindow.h"

gameOverWindow::gameOverWindow(AppData& appData) : MiniJeu(appData)
{
}

void gameOverWindow::setup()
{
    text.setFont(app.font);
    text.setString("Game Over, souhaitez-vous continuer?");
    //text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    sf::FloatRect rect=text.getGlobalBounds();
    text.setPosition(app.window.getSize().x/2-rect.width/2, app.window.getSize().y/6);
    bouton1.setRadius(50);
    bouton1.setPosition(app.window.getSize().x/2 - bouton1.getRadius()-100,app.window.getSize().y/2 - bouton1.getRadius());
    bouton1.setFillColor(sf::Color(sf::Color::Blue));

    bouton2.setRadius(50);
    bouton2.setPosition(app.window.getSize().x/2 - bouton2.getRadius()+100,app.window.getSize().y/2 - bouton2.getRadius());
    bouton2.setFillColor(sf::Color(sf::Color::Red));
}

void gameOverWindow::draw()
{
    app.window.draw(text);
    app.window.draw(bouton1);
    app.window.draw(bouton2);
    //std::cout<<cercle.getPosition().x<<'\n';
    //std::cout<<sf::Mouse::getPosition(app.window).x<<std::endl;
}

void gameOverWindow::update()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if ((bouton1.getPosition().x <= sf::Mouse::getPosition(app.window).x && sf::Mouse::getPosition(app.window).x <= bouton1.getPosition().x+bouton1.getRadius()*2)
                && (bouton1.getPosition().y <= sf::Mouse::getPosition(app.window).y && sf::Mouse::getPosition(app.window).y <= bouton1.getPosition().y+bouton1.getRadius()*2))
        {
            app.lives=3;
            app.difficulty=1;
            isFinished=true;
        }

        if ((bouton2.getPosition().x <= sf::Mouse::getPosition(app.window).x && sf::Mouse::getPosition(app.window).x <= bouton2.getPosition().x+bouton2.getRadius()*2)
                && (bouton2.getPosition().y <= sf::Mouse::getPosition(app.window).y && sf::Mouse::getPosition(app.window).y <= bouton2.getPosition().y+bouton2.getRadius()*2))
        {
            app.window.close(); //enlever ça
            app.selecteur=0; //changer pour le chiffre correspondant à l'écran de score final
            isFinished=true; //laisser ça
        }
    }

}
