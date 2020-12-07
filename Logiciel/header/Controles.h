#ifndef __CONTROLES
#define __CONTROLES

#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Controles{
	private:
		std::map<char,std::vector<sf::Keyboard::Key>> controles;
		std::map<char,char> shuffledControles;
		bool upPress;
		bool downPress;
		bool leftPress;
		bool rightPress;
		bool actionPress;
		
		bool upClick;
		bool downClick;
		bool leftClick;
		bool rightClick;
		bool actionClick;
		
		bool isKeyPressed(char idKey);
	
	public:
		Controles(const std::vector<sf::Keyboard::Key>& up, const std::vector<sf::Keyboard::Key>& down, const std::vector<sf::Keyboard::Key>& left, const std::vector<sf::Keyboard::Key>& right, const std::vector<sf::Keyboard::Key>& action);
		Controles();
		
		void update();
		
		bool isUpPressed();
		bool isDownPressed();
		bool isLeftPressed();
		bool isRightPressed();
		bool isActionPressed();
		
		bool isUpClicked();
		bool isDownClicked();
		bool isLeftClicked();
		bool isRightClicked();
		bool isActionClicked();
		
		void setUpKey(sf::Keyboard::Key key);
		void setDownKey(sf::Keyboard::Key key);
		void setLeftKey(sf::Keyboard::Key key);
		void setRightKey(sf::Keyboard::Key key);
		void setActionKey(sf::Keyboard::Key key);
		
		void shuffle();
};

#endif