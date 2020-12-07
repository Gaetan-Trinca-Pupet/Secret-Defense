#ifndef __DISTRIBMINITESTS_H_
#define __DISTRIBMINITESTS_H_

#include "../MiniJeu.h"
#include "../../Chrono.h"
#include "MiniTest.h"
#include "Etudiant.h"
#include <vector>

class DisitribMiniTests : public MiniJeu
{
public:

	virtual void draw();
	virtual void update();
	virtual void setup();

	void creerEtudiants();

	void creerMiniTests();

	DisitribMiniTests(AppData& appData);
	virtual ~DisitribMiniTests();

private:

	sf::Sprite backGround;

	std::vector<MiniTest*> miniTests;
	std::vector<Etudiant> etudiants;

	Grabber::Grabber hand;

	Chrono chrono;

	sf::RectangleShape throwZone;

	unsigned short nbADistribuer;

	float tempsMax;

};

#endif