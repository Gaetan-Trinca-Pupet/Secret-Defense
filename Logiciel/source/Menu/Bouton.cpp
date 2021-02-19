#include "../../header/Menu/Bouton.h"

Menu::Bouton::Bouton(){
	body.setOutlineThickness(1);
	body.setOutlineColor(sf::Color(0,0,0));
	text.setFillColor(sf::Color(0,0,0));
	value = quitter;
	flags.enable = true;
	flags.clicked = false;
	flags.pressed = false;
	flags.released = false;
	flags.focus = false;
}

void Menu::Bouton::update(sf::RenderWindow& window){
	if(flags.enable){
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		
		if(worldPos.x >= body.getGlobalBounds().left && worldPos.x <= body.getGlobalBounds().left + body.getGlobalBounds().width
		&& worldPos.y >= body.getGlobalBounds().top && worldPos.y <= body.getGlobalBounds().top + body.getGlobalBounds().height){
			flags.focus = true;
		}else{
			flags.focus = false;
		}
		
		if(flags.released)flags.released = false;
		if(flags.focus){
			if(flags.pressed){
				flags.clicked = false;
				if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					flags.released = true;
					flags.pressed = false;
				}
			}else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				flags.clicked = true;
				flags.pressed = true;
			}
		}else{
			flags.clicked = false;
			flags.pressed = false;
			flags.released = false;
		}
	}else{
		flags.clicked = false;
		flags.pressed = false;
		flags.released = false;
		flags.focus = false;
	}
	
	if(!flags.enable){
		body.setOutlineThickness(0.1);
	}else if(flags.clicked){
		body.setOutlineThickness(2);
	}else if(flags.released){
		body.setOutlineThickness(5);
	}else if(flags.pressed){
		body.setOutlineThickness(3);
	}else if(flags.focus){
		body.setOutlineThickness(4);
	}else{
		body.setOutlineThickness(1);
	}
}

void Menu::Bouton::draw(sf::RenderWindow& window){
	window.draw(body);
	window.draw(text);
}

sf::RectangleShape& Menu::Bouton::getBody(){
	return body;
}

const Menu::Menus& Menu::Bouton::getValue()const{
	return value;
}

void Menu::Bouton::setValue(Menus menu){
	value = menu;
}

bool Menu::Bouton::isFocus()const{
	return flags.focus;
}

bool Menu::Bouton::isClicked()const{
	return flags.clicked;
}
bool Menu::Bouton::isPressed()const{
	return flags.pressed;
}

bool Menu::Bouton::isReleased()const{
	return flags.released;
}

bool Menu::Bouton::isEnabled()const{
	return flags.enable;
}

void Menu::Bouton::enable(){
	flags.enable = true;
}

void Menu::Bouton::disable(){
	flags.enable = false;
}

sf::Text& Menu::Bouton::getText(){
	return text;
}

void Menu::Bouton::updateText(){
	text.setOrigin(sf::Vector2f(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2));
	text.setPosition(sf::Vector2f(body.getGlobalBounds().left + body.getGlobalBounds().width/2, body.getGlobalBounds().top + body.getGlobalBounds().height/2));
}

void Menu::Bouton::setBackground(const sf::Color& color){
	body.setFillColor(color);
}

void Menu::Bouton::setBackground(sf::Texture& texture){
	body.setTexture(&texture,true);
}