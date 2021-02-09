#ifndef DOOR_H
#define DOOR_H

#include "../MiniJeu.h"
#include "../../clickable.h"

class Door: public Clickable
{
public:
    Door(const int& x, const int& y, AppData& app, sf::Texture* texture, bool _opened = false);


    void setOpened(bool val);

    bool isOpened();
private:
    bool opened;
};

#endif // DOOR_H
