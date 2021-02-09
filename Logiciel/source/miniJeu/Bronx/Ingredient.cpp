#include "../../../header/miniJeu/Bronx/Ingredient.h"

Ingredient::Ingredient(bool _comestible, sf::Texture* texture)
    :Deliverable(texture, true), comestible(_comestible)
{
	stored = false;
}


bool Ingredient::isComestible()
{
	return comestible;
}


