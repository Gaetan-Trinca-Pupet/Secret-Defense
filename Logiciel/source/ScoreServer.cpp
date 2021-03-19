#include "../header/ScoreServer.h"

bool ScoreServer::sendScore(int score)
{
	return false;
}

bool ScoreServer::getBestScore()
{
	return false;
}

std::vector<std::pair<std::string, int>> ScoreServer::get10BestScores()
{
	return std::vector<std::pair<std::string, int>>();
}

bool ScoreServer::connect()
{
	return serverSocket.connect("127.0.0.1", 80/*, sf::seconds(10)*/) == sf::Socket::Done;
}
