#ifndef __MENU_SELECTEUR_H_
#define __MENU_SELECTEUR_H_

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "../FramerateManager.h"

namespace Menu{
	class Selecteur{
		private :
			sf::Vector2f position;
			sf::Vector2f size;
			std::vector<std::string> options;
			sf::Font * font;
			std::string * selectedOption;
			bool folded;
			
			void drawCase(sf::RenderWindow& window, unsigned int& index);
		public :
			Selecteur();
			void update(sf::RenderWindow& window);
			void draw(sf::RenderWindow& window);
			void setPosition(const sf::Vector2f& _position);
			void setSize(const sf::Vector2f& _size);
			const sf::Vector2f& getPosition()const;
			const sf::Vector2f& getSize()const;
			std::string getSelected()const;
			void setSelected(const std::string& str);
			void pushOption(const std::string& str);
			void setFont(sf::Font& f);
	};
}

#endif