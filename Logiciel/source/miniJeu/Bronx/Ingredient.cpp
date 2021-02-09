#include "../../../header/miniJeu/Bronx/Ingredient.h"

Ingredient::Ingredient(bool _comestible, sf::Texture* texture)
	:Deliverable(0, 0, texture, true), comestible(_comestible)
{

}


bool Ingredient::isComestible()
{
	return comestible;
}


