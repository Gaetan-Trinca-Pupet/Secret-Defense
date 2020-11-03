#ifndef TRANSITION_H
#define TRANSITION_H

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
#include "Chrono.h"

/*struct transData
{
    sf::Text text;
    sf::Color colorText=sf::Color(255,255,255,255);
    sf::Texture textureBackGround;
    sf::Texture textureImage;
    bool isTextureBgOn=false;
    bool isTextureImgOn=false;
    sf::Color bgColor=sf::Color();
};*/

class transition : public MiniJeu
{
private:
    sf::Text text;
    sf::Color colorText=sf::Color(255,255,255,255);
    sf::Texture textureBackGround;
    sf::Texture textureImage;
    bool isTextureBgOn=false;
    bool isTextureImgOn=false;
    sf::Color bgColor=sf::Color();
    sf::Font fontText=app.font;
    sf::Vector2f positionText=sf::Vector2f((app.window.getSize().x/2)-text.getGlobalBounds().width/2, app.window.getSize().y/6);
    sf::Vector2f positionImg;

    sf::Sprite spriteBg; //sprite pour le background
    sf::Sprite spriteImg; //sprite pour l'image des controles/astuces
    Chrono chrono;
    float time;
    sf::Clock clock;
protected:
    //transData& transi;
    virtual void setup();

    virtual void draw();
    virtual void update();

public:
    transition (AppData & appData/*, transData & transitionData*/, sf::Text txt);

    void setTextureBackGround(const sf::Texture &value);
    void setTextureImage(const sf::Texture &value);
    void setColorText(const sf::Color &value);
    void setBgColor(const sf::Color &value);
    void setFontText(const sf::Font &value);
    void setPositionText(const sf::Vector2f &value);
    void setPositionImg(const sf::Vector2f &value);
};

#endif // TRANSITION_H
