#ifndef __QUESTIONREPONSE_H_
#define __QUESTIONREPONSE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "../../Grabber.hpp"

namespace AmphiReponse
{
	class QuestionReponse : public Grabber::Grabbable
	{
	private:
		QuestionReponse* match;
		bool isItMatched = false;

		//sf::SoundBuffer sound;
		//sf::Sound sound_plugged;

		sf::RectangleShape bulle;
		sf::RectangleShape bord_bulle;

		sf::Font libele_font;
		sf::Text libele;

		bool isClose()const;

	public:
		QuestionReponse(QuestionReponse* QR, const std::string& str, const bool& isQuest = false, const int& myX = 0, const int& myY = 0);
		~QuestionReponse();

		virtual void update();

		void draw(sf::RenderWindow& window);

		bool isMatched()const;

		QuestionReponse* getMatch()const;
	};
}

#endif