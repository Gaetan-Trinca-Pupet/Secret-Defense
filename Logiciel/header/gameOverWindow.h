#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <chrono>
#include <time.h>
#include <sstream>
#include "miniJeu/MiniJeu.h"
#include "Textfield.h"
#include "AssetManager.h"

class gameOverWindow : public MiniJeu
{
private:
    sf::Text text;
    bool isContinuer;
//    sf::CircleShape bouton1;
//    sf::CircleShape bouton2;
    sf::Texture capturedImg;
    sf::Sprite captureSprite;
    sf::Text prompt;
    Textfield txtField;

    AssetManager assetmanager;
    //sf::Clock clock;


    sf::Sprite spriteRetry;
    sf::Sprite spriteQuit;
    sf::RectangleShape box;
protected:
    virtual void setup();

    virtual void draw();
    virtual void update();

public:
    gameOverWindow(AppData& appData);
};

#endif // GAMEOVERWINDOW_H
