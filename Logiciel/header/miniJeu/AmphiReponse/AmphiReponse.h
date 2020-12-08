#ifndef __AMPHIREPONSE_H_
#define __AMPHIREPONSE_H_

#include "QuestionReponse.h"
#include "../MiniJeu.h"
#include "../../Grabber.hpp"
#include "../../Chrono.h"
#include <vector>

namespace AmphiReponse
{
	class AmphiReponse : public MiniJeu
	{
	private:
		Chrono chrono;
		unsigned short nbQuestion;

		Grabber::Grabber main;
		std::vector<QuestionReponse*> tabQuest;

		sf::Sprite background;
		sf::Texture backImage;

		sf::Sprite laporteSprite;
		sf::Texture laporteTexture;
		unsigned laporteX;
		unsigned laporteY;

	protected:
		virtual void setup();
		virtual void draw();
		virtual void update();
	public:
		AmphiReponse(AppData& appData);
		~AmphiReponse();
		

	};

}

#endif