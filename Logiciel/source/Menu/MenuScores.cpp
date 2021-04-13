#include "../../header/Menu/MenuScores.h"

Menu::MenuScores::MenuScores(std::string* player): playerName(player)
{
	title.setPosition(380, 30);
	title.setString("Meilleur scores");
	title.setFillColor(sf::Color::White);
	title.setOutlineColor(sf::Color::Black);
	title.setOutlineThickness(2);

	cadreBest.setPosition(285, 90);
	cadreBest.setFillColor(sf::Color(211, 211, 211));
	cadreBest.setOutlineColor(sf::Color::White);
	cadreBest.setOutlineThickness(10);
	cadreBest.setSize(sf::Vector2f(390, 260));

	cadre = cadreBest;
	cadre.setPosition(285, 360);
	cadre.setSize(sf::Vector2f(390, 42));

	boutonRetour.setPosition(sf::Vector2f(480, 460));
	boutonRetour.setSize(sf::Vector2f(250, 50));
	boutonRetour.setString("Retour");
	boutonRetour.isReleased();

	bestScores.setPosition(300, 95);
	bestScores.setCharacterSize(18);
	bestScores.setFillColor(sf::Color::Black);

	playerScore.setPosition(300, 370 );
	playerScore.setCharacterSize(18);
	playerScore.setFillColor(sf::Color::Black);


}

void Menu::MenuScores::draw(sf::RenderWindow& window)
{
	window.draw(title);
	window.draw(cadreBest);
	window.draw(cadre);
	window.draw(bestScores);
	window.draw(playerScore);
	boutonRetour.draw(window);
}

void Menu::MenuScores::setup()
{
	std::vector<Score> theScores = ScoreServer::get10BestScores();
	if (ScoreServer::error)
	{
		bestScores.setString("Erreur de connection");
		return;
	}

	std::string str;
	
	for (size_t i = 0; i < theScores.size(); i++)
	{
		str += std::to_string(i+1) + (i >= 9 ? "    " : "      ") + theScores[i].first + "  :  " + std::to_string(theScores[i].second) + '\n';
	}
	bestScores.setString(sf::String::fromUtf8(str.begin(), str.end()));


	int thePersonalScore = ScoreServer::getBestScore(*playerName);
	if (ScoreServer::error)
	{
		bestScores.setString("Erreur de connection");
		return;
	}
	if(thePersonalScore == -1)
	{
		playerScore.setString("Pas de score");
	}
	else
	{
		playerScore.setString("Vous:   " + sf::String::fromUtf8(playerName->begin(), playerName->end())
			+ "  :  "+ std::to_string(thePersonalScore));
	}
	
}

void Menu::MenuScores::update(sf::RenderWindow& window, Menus& menu)
{
	boutonRetour.update(window);
	if (boutonRetour.isReleased())
		menu = principal;
}

void Menu::MenuScores::setFont(sf::Font& font)
{
	bestScores.setFont(font);
	playerScore.setFont(font);
	title.setFont(font);
	boutonRetour.setFont(font);
}
