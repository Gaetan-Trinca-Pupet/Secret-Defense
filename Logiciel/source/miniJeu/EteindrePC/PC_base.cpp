#include "../../../header/miniJeu/EteindrePC/PC_base.h"

bool EteindrePC::PC_base::isOn() const{
	return on;
}

void EteindrePC::PC_base::update(){
	if(this->isPersonnageLookingAt() && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !alreadyChanged){
		on = !on;
		alreadyChanged = true;
	}
}

void EteindrePC::PC_base::draw(sf::RenderWindow& window){
	if(isOn())this->drawWhenIsOn(window);
	else this->drawWhenIsOff(window);
}

void EteindrePC::PC_base::setPersoView(const std::pair<sf::Vector2f*,EteindrePC::Direction*>& pView){
	persoView = pView;
}

void EteindrePC::PC_base::setPosition(const sf::Vector2f& pos){
	position = pos;
}