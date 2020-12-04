#include "../../header/miniJeu/MiniJeu.h"

MiniJeu::MiniJeu(AppData& appData) : app(appData), isFinished(false), backgroundColor(sf::Color(0, 0, 0, 255))
{

}

void MiniJeu::play()
{
	this->setup();
	while (app.window.isOpen() && !isFinished)
	{

		deltaTime = deltaTimeClock.restart().asSeconds();

		sf::Event event;
		while (app.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				app.window.close();
				return;
			}
		}
		app.window.clear(backgroundColor);
		this->update();
		this->draw();
		drawInterface();
		app.window.display();
	}
}

void MiniJeu::setup()
{

}

MiniJeu::~MiniJeu()
{

}

sf::Color MiniJeu::getBackgroundColor()const
{
	return backgroundColor;
}

void MiniJeu::setBackgroundColor(const sf::Color& color)
{
	backgroundColor = color;
}

void MiniJeu::drawInterface()
{
	if (!coeur.loadFromFile("../ressource/image/coeur.png"))
	{
		std::cout << "erreur loadFromFile" << std::endl;
	}
	sf::Text texteScore;
	texteScore.setFont(app.font);
	texteScore.setString("Score: " + std::to_string(app.score));
	texteScore.setPosition(app.window.getSize().x - 150, app.window.getSize().y - 30);
	sf::Sprite sprite1, sprite2, sprite3;
	sprite1.setTexture(coeur);
	sprite1.setScale(0.1f, 0.1f);
	sprite1.setPosition(sf::Vector2f(0, 0));
	sprite2.setTexture(coeur);
	sprite2.setScale(0.1f, 0.1f);
	sprite2.setPosition(sf::Vector2f(40, 0));
	sprite3.setTexture(coeur);
	sprite3.setScale(0.1f, 0.1f);
	sprite3.setPosition(sf::Vector2f(80, 0));
	if (app.lives >= 1) app.window.draw(sprite1);
	if (app.lives >= 2) app.window.draw(sprite2);
	if (app.lives >= 3) app.window.draw(sprite3);
	app.window.draw(texteScore);
}
