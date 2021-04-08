#include "../header/transition.h"

transition::transition(AppData & appData, sf::Text txt) : MiniJeu(appData), text(txt), isTextureBgOn(false), isTextureImgOn(false), fontText(app.font), positionText(sf::Vector2f((app.window.getView().getSize().x/2), app.window.getView().getSize().y/3)), positionImg(sf::Vector2f((app.window.getView().getSize().x/2), app.window.getView().getSize().y/3)){
    setTextureBackGround("../ressource/Menu/transBg.png");
}

void transition::setTextureBackGround(const std::string &value)
{
    spriteBg.setTexture(AssetManager::getTexture(value));
    isTextureBgOn=true;
}

void transition::setTextureImage(const std::string &value)
{
    spriteImg.setTexture(AssetManager::getTexture(value));
    spriteImg.setOrigin(sf::Vector2f(spriteImg.getGlobalBounds().width/2,spriteImg.getGlobalBounds().height/2));
    isTextureImgOn=true;
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
    spriteImg.setPosition(positionImg);

    if (isTextureBgOn==false){
        setBackgroundColor(bgColor);
    }

    chrono=Chrono(app.window);
    chrono.setTempsMax(5);
	if (isTextureImgOn){
        spriteChiffre.setPosition(app.window.getView().getSize().x/2-80,positionImg.y+20);
    }
    else{
        spriteChiffre.setPosition(sf::Vector2f(app.window.getView().getSize().x/2-80, app.window.getView().getSize().y-300));
    }
	
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
    else{
        app.window.draw(textBox);
        app.window.draw(text);
    }
    app.window.draw(chrono);
    app.window.draw(spriteChiffre);
}

void transition::update()
{
    if (chrono.getTimePassed()>=chrono.getTempsMax())
    {
        isFinished=true;
    }
    if ((chrono.getTempsMax()-3<chrono.getTimePassed()) && (chrono.getTimePassed()<chrono.getTempsMax()-2))
    {
        spriteChiffre.setTexture(AssetManager::getTexture("../ressource/image/3.png"));
    }
    else if ((chrono.getTempsMax()-2<chrono.getTimePassed()) && (chrono.getTimePassed()<chrono.getTempsMax()-1))
    {
        spriteChiffre.setTexture(AssetManager::getTexture("../ressource/image/2.png"));
    }
    else if ((chrono.getTempsMax()-1<chrono.getTimePassed()) && (chrono.getTimePassed()<chrono.getTempsMax()))
    {
        spriteChiffre.setTexture(AssetManager::getTexture("../ressource/image/1.png"));
    }
    chrono.update();
}
