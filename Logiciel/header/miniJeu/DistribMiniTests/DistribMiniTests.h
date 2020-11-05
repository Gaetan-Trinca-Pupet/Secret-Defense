#ifndef __DISTRIBMINITESTS_H_
#define __DISTRIBMINITESTS_H_

#include "../MiniJeu.h"
#include "MiniTest.h"
#include "Etudiant.h"

class DisitribMiniTests : public MiniJeu {
public:

	virtual void draw();
	virtual void update();

	std::vector<MiniTest> MiniTests;
	std::vector<Etudiant> Etudiants;

private:
	DisitribMiniTests(AppData& appData);
	virtual ~DisitribMiniTests();
};

#endif