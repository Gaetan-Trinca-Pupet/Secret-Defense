#include "../../../header/miniJeu/CorrectTheCode/CorrectTheCode.h"

using namespace correctthecode;
CorrectTheCode::CorrectTheCode(AppData &appdata) : MiniJeu(appdata), maxTime((5+1*std::min(int(app.difficulty+1), 9))* pow(0.95, std::max(int(app.difficulty)-8, 0) )), chrono(app.window), isEnding(false)
{

}

void CorrectTheCode::setup()
{
    CodeLine::initCodeLine();
    unsigned short codenb (rand()%2 + std::min(2*(((unsigned)app.difficulty)/2), unsigned(8)));
    code.resize(std::min(((unsigned)app.difficulty)/2 + 2, unsigned(6)));
    for (unsigned short rank = 0; rank < code.size(); ++rank) {
        code[rank] = CodeLine(&app.window, codenb, rank);
    }
    chrono.setTempsMax(maxTime);
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
                chrono.setTempsMax(1);
                //clock.restart();
                isEnding = true;
            }
        }

        if (chrono.getTimePassed() > maxTime){
            for (CodeLine & codeline : code) {
                if (codeline.isWrong())
                    codeline.setColor(sf::Color::Red);
            }
            --app.lives;
            isEnding = true;
            chrono.setTempsMax(1);
            //clock.restart();
        }
    }
    else {
        if (chrono.getTimePassed() > 1) {
            isFinished = true;
        }
    }
}

CorrectTheCode::~CorrectTheCode()
{

}
