#include "../../../header/miniJeu/AmphiReponse/QuestionReponse.h"

bool AmphiReponse::QuestionReponse::isClose() const
{
	return 
		(((x >= match->getX() - match->getSizeX() / 2) && (x <= match->getX() + match->getSizeX() / 2)) ||
		((match->getX() >= x - size_x / 2) && (match->getX() <= x + size_x / 2))) &&
		(((y >= match->getY() - match->getSizeY() / 2) && (y <= match->getY() + match->getSizeY() / 2)) ||
		((match->getY() >= y - size_y / 2) && (match->getY() <= y + size_y / 2)));
}

AmphiReponse::QuestionReponse::QuestionReponse(QuestionReponse* QR, const std::string& str, const bool& isQuest, const int& myX, const int& myY) : Grabbable(myX, myY)
{
	
	match = QR;
	libele_font.loadFromFile("../ressource/fonts/unispace rg.ttf");
	libele.setFont(libele_font);
	libele.setString(str);
	libele.setCharacterSize(20);

	sound.loadFromFile("../ressource/BranchePC/correct.wav");
	sound_plugged.setBuffer(sound);
	sound_plugged.setVolume(5);
	sound_plugged.setPitch(4);

	setSizeX((str.length()/1.5) * (libele.getCharacterSize() + libele.getLetterSpacing()));
	setSizeY(libele.getCharacterSize() + 10);

	bulle.setSize(sf::Vector2f(size_x +3, size_y +3));
	bord_bulle.setSize(sf::Vector2f(size_x+10, size_y+10));

	if (isQuest)
	{
		libele.setFillColor(sf::Color::White);
		bulle.setFillColor(sf::Color::Black);
		bord_bulle.setFillColor(sf::Color::White);
	}
	else
	{
		libele.setFillColor(sf::Color::Black);
		bulle.setFillColor(sf::Color::White);
		bord_bulle.setFillColor(sf::Color::Black);
	}
}

AmphiReponse::QuestionReponse::~QuestionReponse()
{
	delete match;
}

void AmphiReponse::QuestionReponse::updateOnGrab()
{
	if ( match != nullptr && isClose() && !isItMatched)
	{
		sound_plugged.play();
		isItMatched = true;
	}
}

void AmphiReponse::QuestionReponse::draw(sf::RenderWindow& window)
{
	if (!isItMatched)
	{
		libele.setPosition(x + (std::rand() % 3) - size_x / 2, y + (std::rand() % 3) - size_y / 2);
		bulle.setPosition(x + (std::rand() % 3) - (size_x + 3) / 2, y + (std::rand() % 3) - (size_y + 3) / 2);
		bord_bulle.setPosition(x + (std::rand() % 3) - (size_x+10) / 2, y + (std::rand() % 3) - (size_y+10) / 2);

		window.draw(bord_bulle);
		window.draw(bulle);
		window.draw(libele);
		if (this->match != nullptr) this->match->draw(window);
	}
}

bool AmphiReponse::QuestionReponse::isMatched() const
{
	return isItMatched;
}

AmphiReponse::QuestionReponse* AmphiReponse::QuestionReponse::getMatch() const
{
	return match;
}
