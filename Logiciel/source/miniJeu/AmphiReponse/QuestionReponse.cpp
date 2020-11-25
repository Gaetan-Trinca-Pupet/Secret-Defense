#include "../../../header/miniJeu/AmphiReponse/QuestionReponse.h"

bool AmphiReponse::QuestionReponse::isClose() const
{
	return 
		(((getPosition().x >= match->getPosition().x - match->getSize().x / 2) && (getPosition().x <= match->getPosition().x + match->getSize().x / 2)) ||
		((match->getPosition().x >= getPosition().x - getSize().x / 2) && (match->getPosition().x <= getPosition().x + getSize().x / 2))) &&
		(((getPosition().y >= match->getPosition().y - match->getSize().y / 2) && (getPosition().y <= match->getPosition().y + match->getSize().y / 2)) ||
		((match->getPosition().y >= getPosition().y - getSize().y / 2) && (match->getPosition().y <= getPosition().y + getSize().y / 2)));
}

AmphiReponse::QuestionReponse::QuestionReponse(QuestionReponse* QR, const std::string& str, const bool& isQuest, const int& myX, const int& myY) : Grabbable(myX, myY)
{
	
	match = QR;
	libele_font.loadFromFile("../ressource/fonts/unispace rg.ttf");
	libele.setFont(libele_font);
	libele.setString(str);
	libele.setCharacterSize(20);

	//sound.loadFromFile("../ressource/BranchePC/correct.wav");
	//sound_plugged.setBuffer(sound);
	//sound_plugged.setVolume(5);
	//sound_plugged.setPitch(4);

	setSize(sf::Vector2f((str.length()/1.5) * (libele.getCharacterSize() + libele.getLetterSpacing()),libele.getCharacterSize() + 10));

	bulle.setSize(sf::Vector2f(getSize().x +3, getSize().y +3));
	bord_bulle.setSize(sf::Vector2f(getSize().x+10, getSize().y+10));

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
		//sound_plugged.play();
		isItMatched = true;
	}
}

void AmphiReponse::QuestionReponse::draw(sf::RenderWindow& window)
{
	if (!isItMatched)
	{
		libele.setPosition(getPosition().x + (std::rand() % 3) - getSize().x / 2, getPosition().y + (std::rand() % 3) - getSize().y/ 2);
		bulle.setPosition(getPosition().x + (std::rand() % 3) - (getSize().x + 3) / 2, getPosition().y + (std::rand() % 3) - (getSize().y + 3) / 2);
		bord_bulle.setPosition(getPosition().x + (std::rand() % 3) - (getSize().x+10) / 2, getPosition().y + (std::rand() % 3) - (getSize().y+10) / 2);

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
