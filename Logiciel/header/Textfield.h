#ifndef __TEXTFIELD_H_
#define __TEXTFIELD_H_

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Textfield{
	private :
		sf::RenderTexture renderTexture;
		sf::Sprite sprite;
		sf::RectangleShape rectangleShape;
		sf::Text text;
		struct {sf::Clock clock;bool visible;}curseur;
		unsigned int max_length;
		bool focus;
		bool validate;
		
	public :
		Textfield();
		std::string getString()const;
		void setPosition(const sf::Vector2f& pos);
        void setSize(const sf::Vector2u& size);
		void draw(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void setFillColor(const sf::Color& color);
		void setOutlineColor(const sf::Color& color);
		void setOutlineThickness(const float thickness);
        void updateText();
		void setFont(const sf::Font& font);
		void setMaxLength(unsigned int length);
		void setTextSize(const unsigned int size);
		void setTextColor(const sf::Color& color);
        void setFocus(const bool& state);
		bool isFocus()const;
		bool isValidate()const;
		void setString(const std::string& str);
};


#endif
