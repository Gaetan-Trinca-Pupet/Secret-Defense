#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
#include "Chrono.h"
#include "AssetManager.h"

class transition : public MiniJeu
{
private:
    sf::Text text;
    sf::Color colorText;
    bool isTextureBgOn;
    bool isTextureImgOn;
    sf::Color bgColor;
    sf::Font fontText;
    sf::Vector2f positionText;
    sf::Vector2f positionImg;

    sf::Sprite spriteBg; //sprite pour le background
    sf::Sprite spriteImg; //sprite pour l'image des controles/astuces
    Chrono chrono;

    sf::Sprite spriteChiffre;

    sf::RectangleShape textBox;
protected:
    virtual void setup();

    virtual void draw();
    virtual void update();

public:
    transition (AppData & appData, sf::Text txt);

    void setTextureBackGround(const std::string &value);
    void setTextureImage(const std::string &value);
    void setColorText(const sf::Color &value);
    void setBgColor(const sf::Color &value);
    void setFontText(const sf::Font &value);
    void setPositionText(const sf::Vector2f &value);
    void setPositionImg(const sf::Vector2f &value);
};

#endif // TRANSITION_H
