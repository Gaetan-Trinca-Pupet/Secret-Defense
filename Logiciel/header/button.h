#ifndef BUTTON_H
#define BUTTON_H

#include "../header/clickable.h"

///
/// \brief The Button class is supposed to be a clickable that displays a string easily modifiable (but it is not implemented)
///

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
