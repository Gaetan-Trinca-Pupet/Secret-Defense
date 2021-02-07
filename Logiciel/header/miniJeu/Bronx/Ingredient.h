
#include "Deliverable.h"

class Ingredient: public Deliverable{
public:
	Ingredient(bool _comestible);
	bool isComestible();
private:
	bool comestible;
};
