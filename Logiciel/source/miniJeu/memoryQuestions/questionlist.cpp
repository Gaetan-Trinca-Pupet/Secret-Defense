#include "../../../header/miniJeu/memoryQuestions/questionlist.h"

using namespace memoryQuestions;

QuestionList::QuestionList(unsigned short difficulty)
{
    std::srand(std::time(NULL));
    availableQuestions.resize(10);
    answeredQuestions.resize(10, false);
    unsigned short nbAvailable (0);
    while (nbAvailable < difficulty + 4 && nbAvailable < availableQuestions.size()) {
        unsigned short rank = rand()%10;
        if (!availableQuestions[rank]) {
            availableQuestions[rank] = true;
            ++nbAvailable;
        }
    }
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
    switch (rank) {
    case 0 :
        return "Est ce que je peux faire un cin ?";
        break;
    case 1 :
        return "Est ce que je peux faire un goto ?" ;
        break;
    case 2 :
        return "Vous pouvez répeter la question ?" ;
        break;
    case 3 :
        return "Je ne comprend pas pourquoi mon code ne marche pas ici." ;
        break;
    case 4 :
        return "Pourquoi mon code ne marche pas?" ;
        break;
    case 5 :
        return "Pourquoi vous avez mis cette condition ici ?" ;
        break;
    case 6 :
        return "Est ce qu'on aurait pas pu inverser les conditions ?" ;
        break;
    case 7 :
        return "Quelle est la différence entre & et && ?" ;
        break;
    case 8 :
        return "Quelle est la différence entre | et || ?" ;
        break;
    case 9 :
        return "Est ce que je peux faire un cout ?" ;
        break;
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


