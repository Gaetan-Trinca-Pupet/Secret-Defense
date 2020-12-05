#include "../../../header/miniJeu/CorrigeCopie/BoutonVF.h"

void CorrigeCopie::BoutonVF::actionOnClick()
{
	beenClicked = true;
}

bool CorrigeCopie::BoutonVF::isWhat()
{
	return VF;
}

bool CorrigeCopie::BoutonVF::hasBeenClicked()
{
	return beenClicked;
}

void CorrigeCopie::BoutonVF::update()
{
	backSquare.setPosition(getPosition().x, getPosition().y);

	if (isHovered())
	{
		if (VF)
		{
			backSquare.setFillColor(sf::Color(25, 100, 25));
			backSquare.setOutlineThickness(4);
			backSquare.setOutlineColor(sf::Color(5, 50, 5));
		}
		else
		{
			backSquare.setFillColor(sf::Color(100, 25, 25));
			backSquare.setOutlineThickness(4);
			backSquare.setOutlineColor(sf::Color(50, 5, 5));
		}
	}
	else
	{
		if (VF)
		{
			backSquare.setFillColor(sf::Color(100, 200, 100));
			backSquare.setOutlineThickness(4);
			backSquare.setOutlineColor(sf::Color(20, 150, 20));
		}
		else
		{
			backSquare.setFillColor(sf::Color(200, 100, 100));
			backSquare.setOutlineThickness(4);
			backSquare.setOutlineColor(sf::Color(150, 20, 20));
		}
	}
}

void CorrigeCopie::BoutonVF::draw(sf::RenderWindow& window)const
{
	window.draw(backSquare);
}

CorrigeCopie::BoutonVF::BoutonVF(sf::RenderWindow& window, const bool& vf, const unsigned x, const unsigned y, const unsigned short& s) : VF(vf), Clickable(sf::Vector2f(x,y), sf::Vector2f(s,s), &window)
{
	beenClicked = false;
	backSquare.setSize(sf::Vector2f(s, s));

	if (VF)
	{
		backSquare.setFillColor(sf::Color(100,200,100));
		backSquare.setOutlineThickness(4);
		backSquare.setOutlineColor(sf::Color(20,150,20));
	}
	else
	{
		backSquare.setFillColor(sf::Color(200, 100, 100));
		backSquare.setOutlineThickness(4);
		backSquare.setOutlineColor(sf::Color(150, 20, 20));
	}


}

CorrigeCopie::BoutonVF::~BoutonVF()
{

}