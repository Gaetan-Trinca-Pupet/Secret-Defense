#include "../../../header/miniJeu/Bronx/Ingredient.h"

Ingredient::Ingredient(bool _comestible)
	:Deliverable(0, 0, 0, 0, true), comestible(_comestible)
{

}


bool Ingredient::isComestible()
{
	return comestible;
}


