#include "../../../header/miniJeu/memoryQuestions/memoryquestions.h"

using namespace memoryQuestions;

MemoryQuestions::MemoryQuestions(AppData &appData) : MiniJeu(appData), result  (unfinished), questionList(appData.difficulty+1),
    leftQuestionButton(&appData.window, sf::Vector2f(600,50), sf::Vector2f(50,30), "", 20, sf::Color::Cyan),
    rightQuestionButton(&appData.window, sf::Vector2f(600,50), sf::Vector2f(100,165), "", 20, sf::Color::Cyan), timeBetweenQuestions(3 * pow(0.95, std::max(int(app.difficulty)-15, 0))),
    laporte(sf::Vector2f(163,228)), background(sf::Vector2f(960, 540))
{
    laporte.setTexture(&assetManager.getTexture("../ressource/image/laporte.png"));
    laporte.setPosition(sf::Vector2f(366, 300));
    background.setTexture(&assetManager.getTexture(("../ressource/image/background.png")));
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
    if (result == lostBoth || result == lostLeft || result == lostRight)
        laporte.setPosition(sf::Vector2f(laporte.getPosition().x + (std::rand() % 3-1), laporte.getPosition().y + (std::rand() % 3-1)));
    app.window.draw(background);
    app.window.draw(laporte);
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
                laporte.setTexture(&assetManager.getTexture("../ressource/image/laporteColere.png"));
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
                laporte.setTexture(&assetManager.getTexture("../ressource/image/laporteColere.png"));
            }
        }
        if (clock.getElapsedTime().asSeconds() > timeBetweenQuestions) {
            if (questionList.askQuestion(leftQuestionRank)) {
                result = lostLeft;
                leftQuestionButton.setColor(sf::Color::Red);
                laporte.setTexture(&assetManager.getTexture("../ressource/image/laporteColere.png"));
            }
            if (questionList.askQuestion(rightQuestionRank)) {
                if (result == lostLeft) result = lostBoth;
                else result = lostRight;
                rightQuestionButton.setColor(sf::Color::Red);
                laporte.setTexture(&assetManager.getTexture("../ressource/image/laporteColere.png"));
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
