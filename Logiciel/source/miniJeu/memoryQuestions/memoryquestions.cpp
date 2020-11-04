#include "../../../header/miniJeu/memoryQuestions/memoryquestions.h"

using namespace memoryQuestions;

MemoryQuestions::MemoryQuestions(AppData &appData) : MiniJeu(appData), result  (unfinished), questionList(appData.difficulty),
    leftQuestionButton(&appData.window, sf::Vector2f(600,100), sf::Vector2f(100,100), "", 20, sf::Color::Cyan),
    rightQuestionButton(&appData.window, sf::Vector2f(600,100), sf::Vector2f(100,300), "", 20, sf::Color::Cyan)
{

}

void memoryQuestions::MemoryQuestions::setup()
{
    leftQuestionRank = questionList.getRandomQuestion();
    leftQuestionButton.setText(questionList.getQuestion(leftQuestionRank));
    rightQuestionRank = questionList.getRandomQuestion();
    while (rightQuestionRank == leftQuestionRank)
        rightQuestionRank = questionList.getRandomQuestion();
    rightQuestionButton.setText(questionList.getQuestion(rightQuestionRank));
    clock.restart();
}

void memoryQuestions::MemoryQuestions::draw()
{
    app.window.draw(leftQuestionButton);
    app.window.draw(rightQuestionButton);
}

void memoryQuestions::MemoryQuestions::update()
{
    if (result == unfinished) {
        if (leftQuestionButton.getColor() == sf::Color::Blue) {
            leftQuestionButton.setColor(sf::Color::Cyan);
            rightQuestionButton.setColor(sf::Color::Cyan);
        }
        if (leftQuestionButton.isClicked()) {
            if (questionList.askQuestion(leftQuestionRank)) {
                result = wonLeft;
                leftQuestionButton.setColor(sf::Color::Green);
            }
            else {
                result = lostRight;
                leftQuestionButton.setColor(sf::Color::Red);
            }
        }
        if (rightQuestionButton.isClicked()) {
            if (questionList.askQuestion(rightQuestionRank)) {
                result = wonRight;
                rightQuestionButton.setColor(sf::Color::Green);
            }
            else {
                result = lostRight;
                rightQuestionButton.setColor(sf::Color::Red);
            }
        }
        if (clock.getElapsedTime().asSeconds() > 2) {
            if (questionList.askQuestion(leftQuestionRank)) {
                result = lostLeft;
                leftQuestionButton.setColor(sf::Color::Red);
            }
            if (questionList.askQuestion(rightQuestionRank)) {
                if (result == lostLeft) result = lostBoth;
                else result = lostRight;
                rightQuestionButton.setColor(sf::Color::Red);
            }
            if (result == unfinished) {
                leftQuestionButton.setColor(sf::Color::Blue);
                rightQuestionButton.setColor(sf::Color::Blue);

                unsigned short oldRank = leftQuestionRank;
                leftQuestionRank = questionList.getRandomQuestion();
                while (leftQuestionRank == oldRank) leftQuestionRank = questionList.getRandomQuestion();
                leftQuestionButton.setText(questionList.getQuestion(leftQuestionRank));

                oldRank = rightQuestionRank;
                rightQuestionRank = questionList.getRandomQuestion();
                while (rightQuestionRank == leftQuestionRank || rightQuestionRank == oldRank)
                    rightQuestionRank = questionList.getRandomQuestion();
                rightQuestionButton.setText(questionList.getQuestion(rightQuestionRank));
            }
            clock.restart();
        }
    }
    else {
        if (clock.getElapsedTime().asSeconds() > 2) {
            if (result == lostBoth || result == lostLeft || result == lostRight) {
                app.lives -= 1;
            }
            isFinished = true;
        }
    }
}

MemoryQuestions::~MemoryQuestions()
{

}
