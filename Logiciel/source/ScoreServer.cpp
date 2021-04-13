#include "../header/ScoreServer.h"


bool ScoreServer::error = false;

void ScoreServer::sendScore(std::string name, int score)
{
	sf::Http server;
	server.setHost("http://adrien-sylvain.alwaysdata.net/");

	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Method::Post);
	request.setUri("PTUT/main.php");

	request.setBody("user=" + name + "&action=addScore&score=" + std::to_string(score));

	sf::Http::Response response = server.sendRequest(request);
	if (response.getStatus() != sf::Http::Response::Status::Ok)
	{
		std::cout << "error: " << response.getStatus() << std::endl;
		error = true;
		return;
	}
	error = false;

	return;
}

int ScoreServer::getBestScore(std::string name)
{
	sf::Http server;
	server.setHost("http://adrien-sylvain.alwaysdata.net/");


	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Method::Post);
	request.setUri("PTUT/main.php");

	request.setBody("user=" + name + "&action=getBestScore");

	sf::Http::Response response = server.sendRequest(request);
	if (response.getStatus() != sf::Http::Response::Status::Ok)
	{
		std::cout << "error: " << response.getStatus() << std::endl;
		error = true;
		return -1;
	}
	error = false;

	std::stringstream stream(response.getBody());

	int score;
	stream >> score;
	if (stream.fail())
	{
		return -1;
	}

	return score;
}

std::vector<Score> ScoreServer::get10BestScores()
{
	sf::Http server;
	server.setHost("http://adrien-sylvain.alwaysdata.net/");

	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Method::Post);
	request.setUri("PTUT/main.php");
	request.setBody("action=get10BestScore");
	sf::Http::Response response = server.sendRequest(request);

	std::vector<Score> result = std::vector<Score>();

	if (response.getStatus() != sf::Http::Response::Status::Ok)
	{
		std::cout << "error: " << response.getStatus() << std::endl;
		error = true;
		return result;
	}

	std::stringstream stream(response.getBody());


	stream.peek();
	while (stream.good())
	{
		std::string scorestring;
		int score;
		std::string nom;
		std::getline(stream, nom);
		if (!stream.good()) break;
		std::getline(stream, scorestring);
		score = stoi(scorestring);


		result.push_back(Score(nom, score));
	}

	error = false;
	return result;
}
