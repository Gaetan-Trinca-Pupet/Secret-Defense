#include "../../../header/miniJeu/memoryQuestions/questionlist.h"

using namespace memoryQuestions;

QuestionList::QuestionList(unsigned short difficulty)
{
    std::srand(std::time(NULL));
    if (difficulty + 4 > 20) availableQuestions.resize(20,true);
    else {
        availableQuestions.resize(20);
        unsigned short nbAvailable (0);
        while (nbAvailable < difficulty + 4 && nbAvailable < availableQuestions.size()) {
            unsigned short rank = rand()%availableQuestions.size();
            if (!availableQuestions[rank]) {
                availableQuestions[rank] = true;
                ++nbAvailable;
            }
        }
    }
    answeredQuestions.resize(availableQuestions.size(), false);

}

bool QuestionList::askQuestion(const unsigned short & rank)
{
    if (rank >= answeredQuestions.size() || !availableQuestions[rank]) {
        std::cerr << "Question invalide";
        return true;
    }
    if (answeredQuestions[rank]) return true;
    else {
        answeredQuestions[rank] = true;
        return false;
    }
}

std::string QuestionList::getQuestion(const unsigned short & rank)
{
    if (!availableQuestions[rank]) {
        std::cerr << "Question non disponible";
        return "";
    }
    std::fstream questionFile;
    questionFile.open("../ressource/MemoryQuestions/QuestionList.txt",std::ios::in);
    if (questionFile.is_open()) {
        std::string question;
        for (unsigned i = 0; i < rank; ++i)
            std::getline(questionFile, question);
        return question;
    }
    else {
        return "";
    }
}

unsigned short QuestionList::getRandomQuestion()
{
    std::vector<unsigned short> availableRanks;
    for (unsigned short i (0); i < availableQuestions.size(); ++i)
        if (availableQuestions[i])
            availableRanks.push_back(i);
    return availableRanks[rand()%availableRanks.size()];
}


