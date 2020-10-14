#include "../header/button.h"

Button::Button(const std::string &t) : text(t)
{

}

Button::~Button()
{

}

void Button::actionOnClick() {
    std::cout << "It works !" << std::endl;
}
