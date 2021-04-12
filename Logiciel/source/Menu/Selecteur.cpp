#include "../../header/Menu/Selecteur.h"

Menu::Selecteur::Selecteur(){
	folded = true;
	enable = true;
	selectedOption = nullptr;
}

void Menu::Selecteur::update(sf::RenderWindow& window){
	if(!enable)return;
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f mouse = window.mapPixelToCoords(pixelPos);
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(folded){
			sf::Rect<float> body(sf::Vector2f(position.x-size.x/2, position.y-size.y/2), size);
			if(body.contains(mouse)){
				folded = false;
			}
		}else{
			
			for(unsigned int i(0); i < options.size();++i){
				sf::Rect<float> body(sf::Vector2f(position.x-size.x/2, position.y-size.y/2 + size.y*(i+1)), size);
				if(body.contains(mouse)){
					folded = true;
					selectedOption = &options[i];
				}
			}
		}
	}
}

void Menu::Selecteur::draw(sf::RenderWindow& window){
	unsigned int index(0);
	drawCase(window, index);
	++index;
	if(folded)return;
	for(unsigned int i(1);i <= options.size(); ++i)drawCase(window, i);
	
}

void Menu::Selecteur::setPosition(const sf::Vector2f& _position){
	position = _position;
}

void Menu::Selecteur::setSize(const sf::Vector2f& _size){
	size = _size;
}

const sf::Vector2f& Menu::Selecteur::getPosition()const{
	return position;
}

const sf::Vector2f& Menu::Selecteur::getSize()const{
	return size;
}

void Menu::Selecteur::drawCase(sf::RenderWindow& window, unsigned int& index){
	sf::RectangleShape rectangle(size);
	sf::Text text;
	text.setFont(*font);
	text.setFillColor(sf::Color(0,0,0));
	if(selectedOption != nullptr && index == 0){
		text.setString(*selectedOption);
	}else if(index > 0){
		text.setString(options[index-1]);
	}
	rectangle.setPosition(sf::Vector2f(position.x, position.y+size.y*index));
	rectangle.setOrigin(sf::Vector2f(size.x/2, size.y/2));
	text.setOrigin(sf::Vector2f(text.getGlobalBounds().width/2, text.getGlobalBounds().height*2/3));
	text.setPosition(sf::Vector2f(position.x, position.y+size.y*index));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color(0, 0, 0));
	rectangle.setFillColor(sf::Color(255, 255, 255));
	window.draw(rectangle);
	window.draw(text);
	
}

std::string Menu::Selecteur::getSelected()const{
	if(selectedOption == nullptr)return "";
	else return *selectedOption;
}

void Menu::Selecteur::setSelected(const std::string& str){
	for(std::string& option : options){
		if(option == str){
			selectedOption = &option;
		} 
	}
}

void Menu::Selecteur::pushOption(const std::string& str){
	options.push_back(str);
}

void Menu::Selecteur::setFont(sf::Font& f){
	font = &f;
}

bool Menu::Selecteur::isFolded()const{
	return folded;
}

void Menu::Selecteur::setEnable(bool _enable){
	enable = _enable;
}