#include "../../../header/miniJeu/BranchePC/BranchePC.h"

void BranchePC::BranchePC::setup()
{
	const unsigned short nbPrise(9);

	app.window.sf::Window::setMouseCursorVisible(false);
	std::srand(std::time(nullptr));

	

	
	

	
	tabPrise.resize(nbPrise);

	std::vector<unsigned> tabPos1(nbPrise);

	for (unsigned i(0); i < tabPos1.size(); ++i)
		tabPos1[i] = 200 + ((app.window.getSize().x - 200)/nbPrise) * i;

	std::vector<unsigned> tabPos2 = tabPos1;

	for (unsigned i(0); i < tabPrise.size(); ++i)
	{
		unsigned rand = std::rand() % tabPos1.size();
		tabPrise[i] = new Prise(new Prise(nullptr, tabPos1[rand], 50), 0, app.window.getSize().y - 200);
		tabPos1[rand] = tabPos1[tabPos1.size() - 1];
		tabPos1.pop_back();

		rand = std::rand() % tabPos2.size();
		tabPrise[i]->setX(tabPos2[rand]);
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

	main.setX(app.window.getSize().x / 2);
	main.setY(app.window.getSize().y / 2);
}

void BranchePC::BranchePC::draw()
{
	for (unsigned i(0); i < tabPrise.size(); ++i)
		tabPrise[i]->draw(app.window);
	main.draw(app.window);
}

void BranchePC::BranchePC::update()
{
	main.update(app.window);
}

BranchePC::BranchePC::BranchePC(AppData& appData): MiniJeu(appData)
{

}

BranchePC::BranchePC::~BranchePC()
{
	for (unsigned i(0); i < tabPrise.size(); ++i)
		delete tabPrise[i];
}
