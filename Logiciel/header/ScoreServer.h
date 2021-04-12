#ifndef __TEXTFIELD_H_
#define __TEXTFIELD_H_

#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>
#include <string>

typedef std::pair<std::string, int> Score;

class ScoreServer
{
public:

	static bool error;
	static void sendScore(std::string name, int score);
	static int getBestScore(std::string name);
	static std::vector<Score> get10BestScores();


private:

};


#endif

