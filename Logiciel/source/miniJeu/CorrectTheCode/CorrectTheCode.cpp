#include "../../../header/miniJeu/CorrectTheCode/CorrectTheCode.h"

using namespace correctthecode;
CorrectTheCode::CorrectTheCode(AppData &appdata) : MiniJeu(appdata)
{

}

void CorrectTheCode::setup()
{
    CodeLine::initCodeLine();
    unsigned short codenb (rand()%2 + std::min(2*app.difficulty-2, unsigned(8)));
    for (unsigned short rank = 0; rank < app.difficulty/2 + 2; ++rank) {
        code.push_back(CodeLine(&app.window, codenb, rank));
    }
}

void CorrectTheCode::draw()
{
    for (CodeLine & codeline : code)
        app.window.draw(codeline);
}

void CorrectTheCode::update()
{

}

CorrectTheCode::~CorrectTheCode()
{

}
