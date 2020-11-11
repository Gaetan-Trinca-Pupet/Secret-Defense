#include "../header/Controles.h"

Controles::Controles(sf::Keyboard::Key up, sf::Keyboard::Key down,sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key action){
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
}

Controles::Controles(){
	controles['z']=sf::Keyboard::Z;
	controles['s']=sf::Keyboard::S;
	controles['q']=sf::Keyboard::Q;
	controles['d']=sf::Keyboard::D;
	controles[' ']=sf::Keyboard::Space;
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
}

void Controles::update(){
	
	if(sf::Keyboard::isKeyPressed(controles['z'])){
		upClick=!upPress;
		upPress=true;
	}else{
		upClick=false;
		upPress=false;
	}
	
	if(sf::Keyboard::isKeyPressed(controles['s'])){
		downClick=!downPress;
		downPress=true;
	}else{
		downClick=false;
		downPress=false;
	}
	
	if(sf::Keyboard::isKeyPressed(controles['q'])){
		leftClick=!leftPress;
		leftPress=true;
	}else{
		leftClick=false;
		leftPress=false;
	}
	
	if(sf::Keyboard::isKeyPressed(controles['d'])){
		rightClick=!rightPress;
		rightPress=true;
	}else{
		rightClick=false;
		rightPress=false;
	}
	
	if(sf::Keyboard::isKeyPressed(controles[' '])){
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
	controles['z']=key;
}

void Controles::setDownKey(sf::Keyboard::Key key){
	controles['s']=key;
}

void Controles::setLeftKey(sf::Keyboard::Key key){
	controles['q']=key;
}

void Controles::setRightKey(sf::Keyboard::Key key){
	controles['d']=key;
}

void Controles::setActionKey(sf::Keyboard::Key key){
	controles[' ']=key;
}