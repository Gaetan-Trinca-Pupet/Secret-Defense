#include "../header/Textfield.h"

void incrementAnything(void* i){
	++*(char*)i;
	/* ne marche que sur windows
	asm("movb (%rcx), %al");
	asm("inc %al");
	asm("movb %al, (%rcx)");*/
}

Textfield::Textfield(){
	setSize(sf::Vector2u(100,20));
	setPosition(sf::Vector2f(0,0));
	setFillColor(sf::Color(0,0,0,0));
	validate = false;
	focus = false;
}

std::string Textfield::getString(){
	return text.getString().toAnsiString();
}

void Textfield::setPosition(const sf::Vector2f& pos){
	sprite.setPosition(pos);
	rectangleShape.setPosition(pos);
}

void Textfield::setSize(const sf::Vector2u& size){
	renderTexture.create(size.x,size.y);
	sprite.setTexture(renderTexture.getTexture());
	sprite.setTextureRect(sf::Rect<int>(0,0,size.x,size.y));
    rectangleShape.setSize(sf::Vector2f(size.x,size.y));
}

void Textfield::draw(sf::RenderWindow& window){
	renderTexture.draw(text);
	if(curseur.visible && focus){
		sf::RectangleShape line(sf::Vector2f(0,text.getCharacterSize()));
		line.setOutlineColor(text.getFillColor());
		line.setOutlineThickness(1);
		line.setPosition(sf::Vector2f(text.getGlobalBounds().left+text.getGlobalBounds().width+2,text.getGlobalBounds().top));
		renderTexture.draw(line);
	}
	renderTexture.display();
	window.draw(rectangleShape);
	window.draw(sprite);
	renderTexture.clear(sf::Color(0,0,0,0));
}

void Textfield::update(sf::RenderWindow& window){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		if(		worldPos.x < sprite.getPosition().x || worldPos.x > sprite.getPosition().x + sprite.getGlobalBounds().width
			||	worldPos.y < sprite.getPosition().y || worldPos.y > sprite.getPosition().y + sprite.getGlobalBounds().height){
				focus = false;
			}else{
				focus = true;
				validate = false;
			}
	}
	if(focus && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
		focus = false;
		validate = true;
	}
    
	if(curseur.clock.getElapsedTime().asSeconds() > 0.5){
		curseur.visible = !(curseur.visible) &1;
		curseur.clock.restart();
	}
}

void Textfield::setFillColor(const sf::Color& color){
	rectangleShape.setFillColor(color);
}

void Textfield::setOutlineColor(const sf::Color& color){
	rectangleShape.setOutlineColor(color);
}

void Textfield::setOutlineThickness(const float thickness){
	rectangleShape.setOutlineThickness(thickness);
}
	
void Textfield::updateText(){
	if(!focus)return;
	char offsetChar = (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)||sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))?65:97;
	if(max_length == 0 || max_length > text.getString().getSize()){
		for(sf::Keyboard::Key i(sf::Keyboard::A); i < 36;incrementAnything(&i)){
			if(i == sf::Keyboard::Num0)offsetChar=22;
			if(sf::Keyboard::isKeyPressed(i)){
				text.setString(text.getString()+sf::String(std::string(1,((char)i)+offsetChar)));
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			text.setString(text.getString()+sf::String(std::string(1,' ')));
		}
	}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
        if(text.getString().getSize()>0)text.setString(text.getString().substring(0,text.getString().getSize()-1));
    }
}

void Textfield::setFont(const sf::Font& font){
	text.setFont(font);
}

void Textfield::setMaxLength(unsigned int length){
	max_length = length;
}

void Textfield::setTextSize(const unsigned int size){
	text.setCharacterSize(size);
}

void Textfield::setTextColor(const sf::Color& color){
	text.setFillColor(color);
    text.setOutlineColor(color);
}

void Textfield::setFocus(const bool &state){
    focus=state;
}

bool Textfield::isFocus()const{
	return focus;
}

bool Textfield::isValidate()const{
	return validate;
}

void Textfield::setString(const std::string& str){
	text.setString(str);
}