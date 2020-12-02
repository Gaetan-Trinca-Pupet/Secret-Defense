#include "../../../header/miniJeu/DistribMiniTests/Etudiant.h"



Etudiant::Etudiant() {

}

Etudiant::Etudiant(sf::Vector2f& pos)
{
	setPosition(pos);
	setSize(sf::Vector2f(120,175));
	setOutlineThickness(3);
	setOutlineColor(sf::Color::Green);

}


Etudiant::~Etudiant() {

}

bool Etudiant::tryToCatch(const sf::Vector2f pos)
{

	sf::FloatRect tmpLocalBound = getLocalBounds();
	tmpLocalBound.height /= 2;

	if (tmpLocalBound.contains(pos)) {
		setOutlineColor(sf::Color::Red);
		return true;
	}

	return false;
}

