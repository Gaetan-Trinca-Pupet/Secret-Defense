#include "../../../header/miniJeu/AmphiReponse/QuestionReponse.h"

bool AmphiReponse::QuestionReponse::isClose() const
{
	return this->getGlobalBounds().intersects(this->match->getGlobalBounds());
}

AmphiReponse::QuestionReponse::QuestionReponse(QuestionReponse* QR, const std::string& str, const bool& isQuest, const int& myX, const int& myY) : Grabbable(myX, myY)
{
	
	match = QR;
	libele_font.loadFromFile("../ressource/fonts/unispace rg.ttf");
	libele.setFont(libele_font);
	libele.setString(sf::String::fromUtf8(str.begin(),str.end()));
	libele.setCharacterSize(20);

	//sound.loadFromFile("../ressource/BranchePC/correct.wav");
	//sound_plugged.setBuffer(sound);
	//sound_plugged.setVolume(5);
	//sound_plugged.setPitch(4);

	setSize(sf::Vector2f((str.length()/1.5) * (libele.getCharacterSize() + libele.getLetterSpacing()) + 10,libele.getCharacterSize() + 20));

	bulle.setSize(sf::Vector2f(getSize().x -7, getSize().y -7));
	bord_bulle.setSize(sf::Vector2f(getSize().x, getSize().y));

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
	if ( match != nullptr && !isItMatched && isClose())
	{
		//sound_plugged.play();
		isItMatched = true;
	}
}

void AmphiReponse::QuestionReponse::draw(sf::RenderWindow& window)
{
	if (!isItMatched)
	{
		libele.setPosition(getPosition().x + (std::rand() % 3) + 10, getPosition().y + (std::rand() % 3) + 10);
		bulle.setPosition(getPosition().x + (std::rand() % 3) + 3, getPosition().y + (std::rand() % 3) + 3);
		bord_bulle.setPosition(getPosition().x + (std::rand() % 3), getPosition().y + (std::rand() % 3));

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
