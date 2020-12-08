#ifndef MEMORYQUESTIONS_H
#define MEMORYQUESTIONS_H

#include <vector>
#include <string>

#include "../MiniJeu.h"
#include "../../button.h"
#include "questionlist.h"
#include "../../AssetManager.h"

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
    float timeBetweenQuestions;
    sf::RectangleShape laporte;
    sf::RectangleShape background;
    AssetManager assetManager;
public:
    ///
    /// \brief MemoryQuestions is the constructor of MemoryQuestions, initializing the two buttons, Laporte's sprite, and the background, and creating a QuestionList
    /// \param appData is the struct containing the difficulty and the window
    ///
    MemoryQuestions(AppData & appData);
    ///
    /// \brief setup chooses two questions and changes the buttons' text accordingly
    ///
    virtual void setup();
    ///
    /// \brief draw displays the background, the buttons, and Laporte
    ///
    virtual void draw();
    ///
    /// \brief update updates the game : if a button is clicked, it "asks" the corresponding question, and ends the game, reducing the life count by one if the question had not been asked earlier
    ///     And if 2 seconds elapsed since the beginning / the last time the question changed, the questions change, and if one of them had already been asked, the player loses one life and the game ends
    ///
    virtual void update();
    virtual ~MemoryQuestions();
};
}
#endif // MEMORYQUESTIONS_H
