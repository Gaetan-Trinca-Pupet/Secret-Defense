#include "../../../header/miniJeu/BranchePC/BranchePC.h"

void BranchePC::BranchePC::setup()
{
	const unsigned short nbPrise(5);
	tabPrise.resize(nbPrise);

	for (unsigned i(0) ; i < tabPrise.size() ; ++i)
		tabPrise[i] = new BranchePC::Prise(new BranchePC::Prise(nullptr, 10 * i, 200), 10 * i, 100);

	for (unsigned i(0); i < tabPrise.size(); ++i)
	{
		tabPrise[i].setSprite(sf::RectangleShape(5,5));
		tabPrise[i].getMatch().setSprite(sf::RectangleShape(5,5));

		tabPrise[i].setFillColor(Color(20+i*50,i*50,i*50));
		tabPrise[i].getMatch().setFillColor(Color(20 + i * 50, i * 50, i * 50));
	}

}

void BranchePC::BranchePC::draw()
{
	for (unsigned i(0); i < tabPrise.size(); ++i)
		tabPrise[i].draw(app.window);
}

void BranchePC::BranchePC::update()
{

}

BranchePC::BranchePC::BranchePC(AppData& appData): MiniJeu(AppData)
{

}

BranchePC::BranchePC::~BranchePC()
{
	for (unsigned i(0); i < tabPrise.size(); ++i)
		delete tabPrise[i];
}
