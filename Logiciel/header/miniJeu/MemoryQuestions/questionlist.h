#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include <vector>
#include <random>
#include <ctime>
#include <iostream>

namespace memoryQuestions {

class QuestionList
{
private:
    std::vector<bool> availableQuestions;
    std::vector<bool> answeredQuestions;
public:
    QuestionList(unsigned short difficulty = 0);
    bool askQuestion (const unsigned short & rank);
    std::string getQuestion (const unsigned short & rank);
    unsigned short getRandomQuestion();
};

}

#endif // QUESTIONLIST_H
