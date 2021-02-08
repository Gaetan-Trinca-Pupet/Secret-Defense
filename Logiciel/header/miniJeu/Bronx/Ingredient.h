#ifndef __INGREDIENT_H_
#define __INGREDIENT_H_

#include "Deliverable.h"

class Ingredient: public Deliverable{
public:
	Ingredient(bool _comestible);
	bool isComestible();
private:
	bool comestible;
};

#endif
