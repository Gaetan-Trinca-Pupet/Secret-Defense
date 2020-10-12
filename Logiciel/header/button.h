#ifndef BUTTON_H
#define BUTTON_H

#include "header/clickable.h"

class Button:Clickable
{
private:
    std::string text;
public:
    Button(const std::string & t = std::string());
    virtual ~Button();
    virtual void actionOnClick();
};

#endif // BUTTON_H
