#ifndef BUTTON_H
#define BUTTON_H

#include "../header/clickable.h"

<<<<<<< HEAD
=======
///
/// \brief The Button class is supposed to be a clickable that displays a string easily modifiable (but it is not implemented)
///

>>>>>>> master
class Button:Clickable
{
private:
    std::string text;
public:
    Button(const std::string & t = std::string());
    virtual ~Button();
<<<<<<< HEAD
=======
    virtual void actionOnClick();
>>>>>>> master
};

#endif // BUTTON_H
