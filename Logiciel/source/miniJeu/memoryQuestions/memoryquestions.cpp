#include "../../../header/miniJeu/memoryQuestions/memoryquestions.h"

using namespace memoryQuestions;

MemoryQuestions::MemoryQuestions(AppData &appData) : MiniJeu(appData), questionList(appData.difficulty),
    leftQuestion(&appData.window, sf::Vector2f(600,100), sf::Vector2f(100,100), "", 20, sf::Color::Cyan),
    rightQuestion(&appData.window, sf::Vector2f(600,100), sf::Vector2f(100,300), "", 20, sf::Color::Cyan)
{

}

void memoryQuestions::MemoryQuestions::setup()
{
    leftQuestionRank = questionList.getRandomQuestion();
    leftQuestionButton.setText(questionList.getQuestion(leftQuestionRank));
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
    if (clock.getElapsedTime().asSeconds() > 2) {
        questionList.askQuestion(leftQuestionRank);
        questionList.askQuestion(rightQuestionRank);
        leftQuestionRank = questionList.getRandomQuestion();
        leftQuestionButton.setText(questionList.getQuestion(leftQuestionRank));
        rightQuestionRank = questionList.getRandomQuestion();
        rightQuestionButton.setText(questionList.getQuestion(rightQuestionRank));
        clock.restart();
    }
}

MemoryQuestions::~MemoryQuestions()
{

}
