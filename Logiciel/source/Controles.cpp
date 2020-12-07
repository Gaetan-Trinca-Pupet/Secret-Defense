#include "../header/Controles.h"

Controles::Controles(const std::vector<sf::Keyboard::Key>& up, const std::vector<sf::Keyboard::Key>& down, const std::vector<sf::Keyboard::Key>& left, const std::vector<sf::Keyboard::Key>& right, const std::vector<sf::Keyboard::Key>& action){
	controles['z']=up;
	controles['s']=down;
	controles['q']=left;
	controles['d']=right;
	controles[' ']=action;
	upPress=false;
	downPress=false;
	leftPress=false;
	rightPress=false;
	actionPress=false;
	
	upClick=false;
	downClick=false;
	leftClick=false;
	rightClick=false;
	actionClick=false;
	
	//std::srand(std::time(NULL));
}

Controles::Controles(){
	shuffledControles['z'] = 'z';
	shuffledControles['q'] = 'q';
	shuffledControles['s'] = 's';
	shuffledControles['d'] = 'd';
	shuffledControles[' '] = ' ';
	/*controles['z'].push_back(sf::Keyboard::Z);
	controles['s'].push_back(sf::Keyboard::S);
	controles['q'].push_back(sf::Keyboard::Q);
	controles['d'].push_back(sf::Keyboard::D);
	controles[' '].push_back(sf::Keyboard::Space);*/
	upPress=false;
	downPress=false;
	leftPress=false;
	rightPress=false;
	actionPress=false;
	
	upClick=false;
	downClick=false;
	leftClick=false;
	rightClick=false;
	actionClick=false;
	
	//std::srand(std::time(NULL));
}

void Controles::update(){
	
	if(isKeyPressed('z')){
		upClick=!upPress;
		upPress=true;
	}else{
		upClick=false;
		upPress=false;
	}
	
	if(isKeyPressed('s')){
		downClick=!downPress;
		downPress=true;
	}else{
		downClick=false;
		downPress=false;
	}
	
	if(isKeyPressed('q')){
		leftClick=!leftPress;
		leftPress=true;
	}else{
		leftClick=false;
		leftPress=false;
	}
	
	if(isKeyPressed('d')){
		rightClick=!rightPress;
		rightPress=true;
	}else{
		rightClick=false;
		rightPress=false;
	}
	
	if(isKeyPressed(' ')){
		actionClick=!actionPress;
		actionPress=true;
	}else{
		actionClick=false;
		actionPress=false;
	}
	
}

bool Controles::isUpPressed(){
	return upPress;
}

bool Controles::isDownPressed(){
	return downPress;
}

bool Controles::isLeftPressed(){
	return leftPress;
}

bool Controles::isRightPressed(){
	return rightPress;
}

bool Controles::isActionPressed(){
	return actionPress;
}

bool Controles::isUpClicked(){
	return upClick;
}

bool Controles::isDownClicked(){
	return downClick;
}

bool Controles::isLeftClicked(){
	return leftClick;
}

bool Controles::isRightClicked(){
	return rightClick;
}

bool Controles::isActionClicked(){
	return actionClick;
}

void Controles::setUpKey(sf::Keyboard::Key key){
	controles['z'].push_back(key);
}

void Controles::setDownKey(sf::Keyboard::Key key){
	controles['s'].push_back(key);
}

void Controles::setLeftKey(sf::Keyboard::Key key){
	controles['q'].push_back(key);
}

void Controles::setRightKey(sf::Keyboard::Key key){
	controles['d'].push_back(key);
}

void Controles::setActionKey(sf::Keyboard::Key key){
	controles[' '].push_back(key);
}

bool Controles::isKeyPressed(char idKey){
	for(const sf::Keyboard::Key& key : controles[shuffledControles[idKey]]){
		if(sf::Keyboard::isKeyPressed(key))return true;
	}
	return false;
}

void Controles::shuffle(){
	std::vector<char> keys = {'q','d',' '};
	std::vector<char> ids = {'q','d',' '};
	for(const char& id :ids){
		unsigned int i = ((unsigned int)std::rand())%keys.size();
		shuffledControles[id] = keys[i];
		keys.erase(keys.begin()+i);
	}
}