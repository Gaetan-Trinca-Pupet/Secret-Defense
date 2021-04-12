#include "../../../header/miniJeu/EteindrePC/PC_base.h"

bool EteindrePC::PC_base::isOn() const{
	return on;
}

void EteindrePC::PC_base::update(){
	if((!notFirstTime || clock.getElapsedTime().asSeconds() >= 1.2) && this->isPersonnageLookingAt() && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		on = (!on) & 1;
        AssetManager::playSound("../ressource/audio/" + std::string(on ? "bong" : "bing") + ".wav",20);
		clock.restart();
		notFirstTime = true;
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

EteindrePC::PC_base::PC_base(){
	on = false;
}

void EteindrePC::PC_base::setOn(bool b){
	on = b;
	
}

EteindrePC::PC_base::~PC_base(){
	
}
