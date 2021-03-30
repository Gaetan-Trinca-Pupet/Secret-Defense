#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>

namespace memoryQuestions {

class QuestionList
{
private:
    std::vector<bool> availableQuestions;
    std::vector<bool> answeredQuestions;
public:
    ///
    /// \brief QuestionList is the constructor for QuestionList. It selects randomly the questions which will be available.
    /// \param difficulty the difficulty, which is used to choose how many questions will be available
    ///
    QuestionList(unsigned short difficulty = 0);
    ///
    /// \brief askQuestion asks the question, and return true if it have already been asked, else it sets the correponding rank in answeredQuestions to true
    /// \param rank is the rank of the question to ask
    /// \return true if the question have already been asked, else, returns false
    ///
    bool askQuestion (const unsigned short & rank);
    ///
    /// \brief getQuestion gets the string corresponding to the question linked to a rank
    /// \param rank is the rank of the question
    /// \return the string corresponding to the rank
    ///
    std::string getQuestion (const unsigned short & rank);
    ///
    /// \brief getRandomQuestion gets a rank choosen randomly among the ones available
    /// \return the rank choosen randomly among the ones available
    ///
    unsigned short getRandomQuestion();
};

}

#endif // QUESTIONLIST_H
