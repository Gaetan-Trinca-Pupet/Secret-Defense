#ifndef __TEXTFIELD_H_
#define __TEXTFIELD_H_

#include <SFML/Network.hpp>


class ScoreServer
{
public:

	static std::string name;
	static bool sendScore(int score);
	static bool getBestScore();
	static std::vector<std::pair<std::string, int>> get10BestScores();

private:
	static sf::TcpSocket serverSocket;
	static bool connect();
};


#endif

