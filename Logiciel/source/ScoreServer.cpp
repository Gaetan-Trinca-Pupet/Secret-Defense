#include "../header/ScoreServer.h"

sf::Http ScoreServer::server = sf::Http("bite.com");

bool ScoreServer::error = false;

void ScoreServer::sendScore(int score)
{
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
	sf::Http::Request request("/handleRequest.php");
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
	std::string name;
	while (true)
	{
		std::string name;
		int score;
		stream >> name;
		stream >> score;
		if (!stream.good())
			break;

		result.push_back(Score(name, score));
	}

	error = false;
	return result;
}
