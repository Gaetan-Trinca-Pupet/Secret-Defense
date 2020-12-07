#include "../header/transition.h"
#include <iostream>

transition::transition(AppData & appData, sf::Text txt) : MiniJeu(appData), text(txt){

}

void transition::setTextureBackGround(const sf::Texture &value)
{
    textureBackGround = value;
}

void transition::setTextureImage(const sf::Texture &value)
{
    textureImage = value;
}

void transition::setColorText(const sf::Color &value)
{
    colorText = value;
}

void transition::setBgColor(const sf::Color &value)
{
    bgColor = value;
}

void transition::setFontText(const sf::Font &value)
{
    fontText = value;
}

void transition::setPositionText(const sf::Vector2f &value)
{
    positionText = value;
}

void transition::setPositionImg(const sf::Vector2f &value)
{
    positionImg = value;
}

void transition::setup()
{
    text.setFont(fontText);
    text.setPosition(sf::Vector2f(positionText.x-text.getGlobalBounds().width/2,positionText.y));
    text.setFillColor(colorText);
    if (textureBackGround.getSize()!=sf::Vector2u(0,0)) isTextureBgOn=true;
    if (textureImage.getSize()!=sf::Vector2u(0,0)) isTextureImgOn=true;
    if (isTextureBgOn)
    {
        spriteBg.setTexture(textureBackGround);
    }
    else
    {
        setBackgroundColor(bgColor);
    }
    if (isTextureImgOn)
    {
        spriteImg.setTexture(textureImage);
        spriteImg.setPosition(positionImg);
    }
    time=2;
    chrono=Chrono(app.window);
}

void transition::draw()
{
    if (isTextureBgOn) app.window.draw(spriteBg);
    if (isTextureImgOn) app.window.draw(spriteImg);
    app.window.draw(text);
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
