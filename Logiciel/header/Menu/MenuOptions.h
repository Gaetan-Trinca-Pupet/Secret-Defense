#ifndef __MENU_MENU_OPTIONS_H_
#define __MENU_MENU_OPTIONS_H_

#include <regex>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../miniJeu/MiniJeu.h"
#include "../miniJeu/MiniJeuManager.h"
#include "MenusEnum.h"
#include "Selecteur.h"
#include "Bouton.h"
#include "../Textfield.h"



namespace Menu{
	
	/**
	*	MenuOptions make a menu where users can enter their pseudo, choose the framerate mode and mute/unmute the sounds and musics.
	*	@author Erwann Lubrano
	*
	*/
	
	class MenuOptions{
		private :
			Textfield pseudoField;
			Selecteur selecteurFramrateMode;
			Selecteur selecteurMusiqueOnOff;
			Bouton bt_valider;
			
			sf::Text text_framerateMode;
			sf::Text text_Music;
			sf::Text text_pseudo;
			
		public :
		
			/**
			*	Default constructor for MenuOptions
			*/
			MenuOptions();
			
			/**
			*	@param window : the window 
			*	@param menu : the actual menu 
			*	@param app : contains framerateMode and pseudo
			*/
			void update(sf::RenderWindow& window, Menus& menu, AppData& app);
			
			/**
			*	draw : display the option's menu
			*	@param window : the window to display the elements
			*/
			void draw(sf::RenderWindow& window);
			
			/**
			*	setFont : set the text's font
			*	@param f : the font to set
			*/
			void setFont(sf::Font& f);
			
			void loadOptions(AppData& app);
			void storeOptions(AppData& app);
			void setup(AppData& app);
			void updateText();
	};
}

#endif