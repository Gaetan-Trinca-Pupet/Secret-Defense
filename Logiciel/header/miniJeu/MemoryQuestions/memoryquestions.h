#ifndef MEMORYQUESTIONS_H
#define MEMORYQUESTIONS_H

#include <vector>
#include <string>

#include "../MiniJeu.h"
#include "../../button.h"
#include "questionlist.h"

namespace memoryQuestions {

enum resultId {
    unfinished,
    wonLeft,
    wonRight,
    lostLeft,
    lostRight,
    lostBoth
};

class MemoryQuestions : public MiniJeu
{
private:
    resultId result;
    QuestionList questionList;
    Button leftQuestionButton;
    Button rightQuestionButton;
    unsigned short leftQuestionRank;
    unsigned short rightQuestionRank;
    sf::Clock clock;
public:
    MemoryQuestions(AppData & appData);
    virtual void setup();
    virtual void draw();
    virtual void update();
    virtual ~MemoryQuestions();
};
}
#endif // MEMORYQUESTIONS_H
