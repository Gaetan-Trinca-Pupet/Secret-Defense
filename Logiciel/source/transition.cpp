#include "../header/transition.h"
#include <iostream>

transition::transition(AppData & appData, transData & transitionData) : MiniJeu(appData), transi(transitionData){

}

void transition::setup()
{
    transi.text.setFillColor(transi.colorText);
    if (transi.isTextureOn)
    {
        sprite.setTexture(transi.textureBackGround);
        sprite.setPosition(0, 0);
    }
    else
    {
        setBackgroundColor(transi.bgColor);
    }
    time=2;
    chrono=Chrono(time, &clock, app.window);
}

void transition::draw()
{
    if (transi.isTextureOn) app.window.draw(sprite);
    app.window.draw(transi.text);
    app.window.draw(chrono);
}

void transition::update()
{
    if (clock.getElapsedTime().asSeconds()>=time)
    {
        isFinished=true;
    }
    chrono.update();
}
