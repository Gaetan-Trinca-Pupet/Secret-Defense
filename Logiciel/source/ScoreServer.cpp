#include "../header/ScoreServer.h"

std::string ScoreServer::name;

bool ScoreServer::error = false;

void ScoreServer::sendScore(int score)
{
	sf::Http server;
	server.setHost("a.com");

	sf::Http::Request request("/handleRequest.php");
	request.setField("action", "addScore");
	request.setField("score", std::to_string(score));
	request.setField("name", name);

	sf::Http::Response response = server.sendRequest(request);
	if (std::to_string(response.getStatus())[2] != 2)
	{
		std::cout << "error: " << response.getStatus() << std::endl;
		error = true;
		return;
	}
	error = false;

	return;
}

int ScoreServer::getBestScore()
{
	sf::Http server;
	server.setHost("a.com");

	sf::Http::Request request("/handleRequest.php");
	request.setField("action", "getBestScore");
	request.setField("name", name);

	sf::Http::Response response = server.sendRequest(request);
	if (std::to_string(response.getStatus())[2] != 2)
	{
		std::cout << "error: " << response.getStatus() << std::endl;
		error = true;
		return -1;
	}
	error = false;

	return std::stoi(response.getBody());
}

std::vector<Score> ScoreServer::get10BestScores()
{
	sf::Http server;
	server.setHost("https://adrien-sylvain.alwaysdata.net/PTUT/main.php");

	sf::Http::Request request("main.php");
	request.setField("action", "get10BestScores");
	sf::Http::Response response = server.sendRequest(request);

	std::vector<Score> result = std::vector<Score>();
	if (std::to_string(response.getStatus())[2] != 2)
	{
		std::cout << "error: " << response.getStatus() << std::endl;
		error = true;
		return result;
	}

	std::stringstream stream(response.getBody());
	while (true)
	{

		int score;
		std::string nom;
		std::getline(std::cin, nom);
		stream >> score;
		if (!stream.good())
			break;

		result.push_back(Score(nom, score));
	}

	error = false;
	return result;
}
