#ifndef __CONTROLES
#define __CONTROLES

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <map>

class Controles{
	private:
		std::map<char,sf::Keyboard::Key> controles;
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
	
	public:
		Controles(sf::Keyboard::Key up, sf::Keyboard::Key down,sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key action);
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
};

#endif