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
	static std::string name;
	static void sendScore(int score);
	static int getBestScore();
	static std::vector<Score> get10BestScores();


private:

};


#endif

