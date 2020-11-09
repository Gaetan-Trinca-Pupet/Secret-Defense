#ifndef __PRISE_H_
#define __PRISE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "../../Grabber.hpp"

namespace BranchePC
{
	class Prise : public Grabber::Grabbable
	{
	private:
		Prise* match;
		bool isItMatched = false;

		sf::Sprite sprite;
		sf::Texture texture;

		sf::SoundBuffer sound;
		sf::Sound sound_plugged;

		bool isClose()const;

	public:
		Prise(Prise* prise = nullptr, const int& myX = 0, const int& myY = 0);
		~Prise();

		void setSprite(const sf::Texture& textur);
		void setSpriteRect(const unsigned short& x1 = 0, const unsigned short& y1 = 0, const unsigned short& x2 = 0, const unsigned short& y2 = 0);

		virtual void updateOnGrab();

		void draw(sf::RenderWindow& window);

		bool isMatched()const;

		Prise* getMatch()const;
	};

}

#endif