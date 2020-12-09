#include "../header/transition.h"

transition::transition(AppData & appData, sf::Text txt) : MiniJeu(appData), text(txt), colorText(sf::Color(0,0,0,255)), isTextureBgOn(false), isTextureImgOn(false), fontText(app.font), positionText(sf::Vector2f((app.window.getView().getSize().x/2), app.window.getView().getSize().y/3)){

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
    text.setOrigin(sf::Vector2f(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2));
    text.setPosition(positionText);
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
    time=5;
    chrono=Chrono(app.window);
    chrono.setTempsMax(time);
    spriteChiffre.setPosition(sf::Vector2f(app.window.getView().getSize().x/2-80, app.window.getView().getSize().y-300));

    textBox.setSize(sf::Vector2f(400,100));
    textBox.setOrigin(sf::Vector2f(textBox.getSize().x/2,textBox.getSize().y/2));
    textBox.setPosition(text.getPosition().x,text.getPosition().y);
    textBox.setFillColor(sf::Color(211,211,211));
    textBox.setOutlineColor(sf::Color(255,255,255));
    textBox.setOutlineThickness(10);
}

void transition::draw()
{
    if (isTextureBgOn) app.window.draw(spriteBg);
    if (isTextureImgOn) app.window.draw(spriteImg);
    app.window.draw(textBox);
    app.window.draw(text);
    app.window.draw(chrono);
    app.window.draw(spriteChiffre);
}

void transition::update()
{
    if (chrono.getTimePassed()>=time)
    {
        isFinished=true;
    }
    if ((time-3<chrono.getTimePassed()) && (chrono.getTimePassed()<time-2))
    {
        spriteChiffre.setTexture(assetmanager.getTexture("../ressource/image/3.png"));
    }
    else if ((time-2<chrono.getTimePassed()) && (chrono.getTimePassed()<time-1))
    {
        spriteChiffre.setTexture(assetmanager.getTexture("../ressource/image/2.png"));
    }
    else if ((time-1<chrono.getTimePassed()) && (chrono.getTimePassed()<time))
    {
        spriteChiffre.setTexture(assetmanager.getTexture("../ressource/image/1.png"));
    }
    chrono.update();
}
