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
    switch (rank) {
    case 0 :
        return "Est ce que je peux faire un cin ?";
        break;
    case 1 :
        return "Est ce que je peux faire un goto ?" ;
        break;
    case 2 :
        return "Vous pouvez repeter la question ?" ;
        break;
    case 3 :
        return "Je ne comprend pas pourquoi mon code ne marche pas ici." ;
        break;
    case 4 :
        return "Pourquoi mon code ne marche pas ?" ;
        break;
    case 5 :
        return "Pourquoi vous avez mis cette condition ici ?" ;
        break;
    case 6 :
        return "Est ce qu'on aurait pas pu inverser les conditions ?" ;
        break;
    case 7 :
        return "Quelle est la difference entre & et && ?" ;
        break;
    case 8 :
        return "Quelle est la difference entre | et || ?" ;
        break;
    case 9 :
        return "Est ce que je peux faire un cout ?" ;
        break;
    case 10 :
        return "Je peux utiliser i++ ici ?";
        break;
    case 11 :
        return "Je peux utiliser ++i ici ?";
        break;
    case 12 :
        return "Quelle est la difference entre ++i et i++";
        break;
    case 13 :
        return "Quelle est la difference entre un pointeur et une reference ?";
        break;
    case 14 :
        return "Quelle est la difference entre * et &";
        break;
    case 15 :
        return "Pourquoi on utilise const & ?";
        break;
    case 16 :
        return "Est ce qu'on utilise la recursivite ?";
        break;
    case 17 :
        return "Comment marche la recursivite ?";
        break;
    case 18 :
        return "On peut utiliser nos PC pour programmer ?";
        break;
    case 19 :
        return "Sur quoi sera le prochain controle ?";
        break;
    }
	return ""; 
}

unsigned short QuestionList::getRandomQuestion()
{
    std::vector<unsigned short> availableRanks;
    for (unsigned short i (0); i < availableQuestions.size(); ++i)
        if (availableQuestions[i])
            availableRanks.push_back(i);
    return availableRanks[rand()%availableRanks.size()];
}


