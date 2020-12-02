#ifndef __ETUDIANT_H_
#define __ETUDIANT_H_


#include "SFML/Graphics.hpp"
#include <vector>
#include "../../AssetManager.h"

class Etudiant : public sf::RectangleShape{
public:

	Etudiant();
	Etudiant(sf::Vector2f& pos);
	virtual ~Etudiant();

	bool tryToCatch(const sf::Vector2f pos);
	
	

private:

	bool waitingMiniTest;

};

#endif