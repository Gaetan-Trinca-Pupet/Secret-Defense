#ifndef __ETUDIANT_H_
#define __ETUDIANT_H_


#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
#include "../../AssetManager.h"

class Etudiant : public sf::RectangleShape
{
public:

	Etudiant();
	Etudiant(sf::Vector2f& pos);
	Etudiant(unsigned numEtu);
	virtual ~Etudiant();

	bool tryToCatch(const sf::Vector2f& pos);

	bool operator< (Etudiant& e)const;

private:

	static sf::Vector2f etuPos[6];

	bool working;

};

#endif