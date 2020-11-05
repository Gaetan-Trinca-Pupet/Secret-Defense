#ifndef __DISTRIBMINITESTS_H_
#define __DISTRIBMINITESTS_H_

#include "../MiniJeu.h"
#include "MiniTest.h"
#include <vector>

class DisitribMiniTests : public MiniJeu {
public:

	virtual void draw();
	virtual void update();

	std::vector<MiniTest> MiniTests;
	std::vector<

private:
	DisitribMiniTests(AppData& appData);
	virtual ~DisitribMiniTests();
};

#endif