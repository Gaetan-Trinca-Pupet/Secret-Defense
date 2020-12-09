#include "../../../header/miniJeu/BranchePC/BranchePC.h"

void BranchePC::BranchePC::setup()
{
	
	nbPrise = (1 + std::rand()%6);

	chrono.setTempsMax(15);


	
	tabPrise.resize(nbPrise);

	std::vector<unsigned> tabPos1(nbPrise);

	const unsigned short decalage = 200;

	for (unsigned i(0); i < tabPos1.size(); ++i)
		tabPos1[i] = decalage + ((app.window.getView().getSize().x - decalage)/nbPrise) * i;

	std::vector<unsigned> tabPos2 = tabPos1;

	for (unsigned i(0); i < tabPrise.size(); ++i)
	{
		unsigned rand = std::rand() % tabPos1.size();
		tabPrise[i] = new Prise(new Prise(nullptr, tabPos1[rand], 50), 0, app.window.getView().getSize().y - 200);
		tabPos1[rand] = tabPos1[tabPos1.size() - 1];
		tabPos1.pop_back();

		rand = std::rand() % tabPos2.size();
		tabPrise[i]->setPosition(tabPos2[rand] + ((app.window.getView().getSize().x - decalage) / nbPrise) / 2, tabPrise[i]->getPosition().y);
		tabPos2[rand] = tabPos2[tabPos2.size() - 1];
		tabPos2.pop_back();
	}

	
		
	for (unsigned i = 0; i < tabPrise.size(); i++)
	{
		sf::Texture texture;
		std::string src = "../ressource/BranchePC/prise_" + std::to_string(i) + ".png";
		texture.loadFromFile(src);
		tabPrise[i]->setSprite(texture);
	}
	
	for (unsigned i = 0; i < tabPrise.size(); ++i)
		main.add(tabPrise[i]);
	main.setX(app.window.getView().getSize().x / 2);
	main.setY(app.window.getView().getSize().y / 2);
	sf::Texture texture;
	texture.loadFromFile("../ressource/BranchePC/hand.png");
	main.setSprite(texture);
}

void BranchePC::BranchePC::draw()
{
	app.window.draw(background);
	for (unsigned i(0); i < tabPrise.size(); ++i)
		tabPrise[i]->draw(app.window);
	main.draw(app.window);
	app.window.draw(chrono);
}

void BranchePC::BranchePC::update()
{
	main.update(app.window);
	for (Prise* prise : tabPrise)
		if (prise->isMatched() && main.find(prise))
		{
			main.remove(prise);
			--nbPrise;
		}
	if (nbPrise <= 0)
	{
		isFinished = true;
	}
	
	chrono.update();
	
	if (chrono.getTimePassed() > chrono.getTempsMax() && ! isFinished)
	{
		app.lives -= 1;
		isFinished = true;
	}
}

BranchePC::BranchePC::BranchePC(AppData& appData): MiniJeu(appData), chrono(app.window)
{
	app.window.sf::Window::setMouseCursorVisible(false);
	std::srand(std::time(nullptr));

	main = Grabber::Grabber();

	backImage.loadFromFile("../ressource/BranchePC/background.png");
	background.setTexture(backImage);
}

BranchePC::BranchePC::~BranchePC()
{
	for (unsigned i(0); i < tabPrise.size(); ++i)
		delete tabPrise[i];

	app.window.setMouseCursorVisible(true);
}
