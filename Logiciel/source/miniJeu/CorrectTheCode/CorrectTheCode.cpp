#include "../../../header/miniJeu/CorrectTheCode/CorrectTheCode.h"

using namespace correctthecode;
CorrectTheCode::CorrectTheCode(AppData &appdata) : MiniJeu(appdata), maxTime((3+0.66*std::min(int(app.difficulty), 9))* pow(0.95, std::max(int(app.difficulty)-9, 0) )), chrono(maxTime, &clock, app.window)
{

}

void CorrectTheCode::setup()
{
    CodeLine::initCodeLine();
    unsigned short codenb (rand()%2 + std::min(2*((app.difficulty-1)/2), unsigned(8)));
    code.resize(std::min((app.difficulty-1)/2 + 2, unsigned(6)));
    for (unsigned short rank = 0; rank < code.size(); ++rank) {
        code[rank] = CodeLine(&app.window, codenb, rank);
    }
    clock.restart();
}

void CorrectTheCode::draw()
{
    for (CodeLine & codeline : code)
        app.window.draw(codeline);
    app.window.draw(chrono);
}

void CorrectTheCode::update()
{
    if (!isEnding) {
        chrono.update();
        for (CodeLine & codeline : code) {
            if (codeline.isClicked()) {
                if (codeline.isWrong()){
                    codeline.setColor(sf::Color::Green);
                }
                else {
                    --app.lives;
                    codeline.setColor(sf::Color::Red);
                }
                clock.restart();
                isEnding = true;
            }
        }

        if (clock.getElapsedTime().asSeconds() > maxTime){
            for (CodeLine & codeline : code) {
                if (codeline.isWrong())
                    codeline.setColor(sf::Color::Red);
            }
            --app.lives;
            isEnding = true;
            clock.restart();
        }
    }
    else {
        if (clock.getElapsedTime().asSeconds() > 1) {
            isFinished = true;
        }
    }
}

CorrectTheCode::~CorrectTheCode()
{

}
