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
			Menus value;
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
			
			sf::RectangleShape& getBody();
			sf::Text& getText();
			
			void updateText();
			
			const Menus& getValue()const;
			void setValue(Menus menu);
			
			bool isFocus()const;
			bool isClicked()const;
			bool isPressed()const;
			bool isReleased()const;
			bool isEnabled()const;
			
			void enable();
			void disable();
			
			void setBackground(const sf::Color& color);
			void setBackground(sf::Texture& texture);
	};
}

#endif