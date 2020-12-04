#include "../../../header/miniJeu/DistribMiniTests/Etudiant.h"

sf::Vector2f Etudiant::etuPos[6] = { sf::Vector2f(34,208), sf::Vector2f(151,86), sf::Vector2f(526,80),
									 sf::Vector2f(551,193), sf::Vector2f(714,151), sf::Vector2f(225,214) };

Etudiant::Etudiant()
{

}

Etudiant::Etudiant(sf::Vector2f& pos)
{
	setPosition(pos);
	setSize(sf::Vector2f(120, 175));
	setOutlineThickness(3);
	setOutlineColor(sf::Color::Green);

	working = false;

}

Etudiant::Etudiant(unsigned numEtu)
{
	setPosition(etuPos[numEtu]);

	//setFillColor(sf::Color::Transparent);
	setTexture(&AssetManager::getTexture("../ressource/DistribMiniTests/etu_" + std::to_string(numEtu) + ".png"));

	sf::IntRect newTextureRect = getTextureRect();
	newTextureRect.width /= 2;

	setTextureRect(newTextureRect);
	setSize(sf::Vector2f(newTextureRect.width, newTextureRect.height));




	working = false;
}


Etudiant::~Etudiant()
{

}

bool Etudiant::tryToCatch(const sf::Vector2f& pos)
{
	if (working) return false;

	sf::FloatRect tmpGlobalBound = getGlobalBounds();
	tmpGlobalBound.top = tmpGlobalBound.top + tmpGlobalBound.height * 0.25;
	tmpGlobalBound.height *= 0.5;
	tmpGlobalBound.left = tmpGlobalBound.left + tmpGlobalBound.width * 0.15;
	tmpGlobalBound.width *= 0.7;


	if (tmpGlobalBound.contains(pos))
	{

		setTextureRect(sf::IntRect(getTextureRect().width, 0, getTextureRect().width, getTextureRect().height));
		working = true;
		return true;
	}

	return false;
}

bool Etudiant::operator<(Etudiant& e)const
{
	return getPosition().y < e.getPosition().y;
}

