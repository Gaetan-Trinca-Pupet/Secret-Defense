#ifndef __DISTRIBMINITESTS_H_
#define __DISTRIBMINITESTS_H_

#include "../MiniJeu.h"
#include "../../Chrono.h"
#include "Verre.h"
#include "Refrigerateur.h"
#include "Shaker.h"
#include "Ingredient.h"
#include <vector>

class DistribMiniTests : public MiniJeu
{
public:

	virtual void draw();
	virtual void update();
	virtual void setup();

	DistribMiniTests(AppData& appData);
	virtual ~DistribMiniTests();

private:

	Chrono chrono;
	sf::Sprite backGround;

	std::vector<Verre> verres;
	std::vector<Verre> Ingredients;
	Shaker shaker;
	Refrigerateur refrigerateur;

};

#endif