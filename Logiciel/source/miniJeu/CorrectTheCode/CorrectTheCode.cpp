#include "../../../header/miniJeu/CorrectTheCode/CorrectTheCode.h"

using namespace correctthecode;
CorrectTheCode::CorrectTheCode(AppData &appdata) : MiniJeu(appdata), maxTime((5+1*std::min(int(app.difficulty+1), 9))* pow(0.95, std::max(int(app.difficulty)-8, 0) )), chrono(app.window)
{

}

void CorrectTheCode::setup()
{
    CodeLine::initCodeLine();
    unsigned short codenb (std::min((unsigned)app.difficulty*2-1, unsigned(9)) - rand()%2);
    code.resize((unsigned)codenb/2+2);
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

    chrono.update();
    for (CodeLine & codeline : code) {
        if (codeline.isClicked()) {
            if (codeline.isWrong()){
                codeline.setColor(sf::Color::Green);
                end(true);
            }
            else {
                end(false);
                codeline.setColor(sf::Color::Red);
            }
        }
    }

    if (chrono.getTimePassed() > maxTime){
        for (CodeLine & codeline : code) {
            if (codeline.isWrong())
                codeline.setColor(sf::Color::Red);
        }
        end(false);
    }
}

CorrectTheCode::~CorrectTheCode()
{

}
