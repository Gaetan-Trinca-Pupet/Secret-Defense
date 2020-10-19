#ifndef TRANSITION_H
#define TRANSITION_H

#include <SFML/Graphics.hpp>
#include "miniJeu/MiniJeu.h"
#include "Chrono.h"

struct transData
{
    sf::Text text;
    sf::Color colorText=sf::Color(255,255,255,255);
    sf::Texture textureBackGround;
    bool isTextureOn=false;
    sf::Color bgColor=sf::Color();
};

class transition : public MiniJeu
{
private:
    sf::Sprite sprite; //sprite pour le texte, ajouter sprite image tips
    Chrono chrono;
    float time;
    sf::Clock clock;
protected:
    transData& transi;
    virtual void setup();

    virtual void draw();
    virtual void update();

public:
    transition (AppData & appData, transData & transitionData);
};

#endif // TRANSITION_H
