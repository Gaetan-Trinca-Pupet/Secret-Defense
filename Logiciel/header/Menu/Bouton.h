#ifndef __MENU_BOUTON_H_
#define __MENU_BOUTON_H_

#include <SFML/Graphics.hpp>

#include "MenusEnum.h"

namespace Menu{
	/*
	enum background_type{
		color,
		texture
	};*/
	
	class Bouton{
		private :
			sf::RectangleShape body;
			//Menus value;
			struct{
				bool focus : 1;
				bool clicked : 1;
				bool pressed : 1;
				bool released : 1;
				bool enable : 1;
			}flags;
			sf::Text text;
			
		public :
			Bouton();
			
			void update(sf::RenderWindow& window);
			void draw(sf::RenderWindow& window);
			
			[[deprecated]]sf::RectangleShape& getBody();
			[[deprecated]]sf::Text& getText();
			
			void updateText();
			
			//const Menus& getValue()const;
			//void setValue(Menus menu);
			
			bool isFocus()const;
			bool isClicked()const;
			bool isPressed()const;
			bool isReleased()const;
			bool isEnabled()const;
			
			void enable();
			void disable();
			
			void setBackground(const sf::Color& color);
			void setBackground(sf::Texture& texture);
			
			void setString(const std::string& str);
			void setSize(const sf::Vector2f& size);
			void setPosition(const sf::Vector2f& position);
			//void setOrigin(const sf::Vector2f& origin);
			void setFont(const sf::Font& font);
			
			
	};
}

#endif