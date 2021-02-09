#ifndef DOOR_H
#define DOOR_H

#include "../../clickable.h"

class Door: public clickable
{
public:
    Door(const int& x, const int& y);


    void setOpened(bool val);

    bool isOpened();
private:
    bool opened;
};

#endif // DOOR_H
