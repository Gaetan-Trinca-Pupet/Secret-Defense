#ifndef TEXT_H
#define TEXT_H

#include <string>

#include "header/entity.h"

class Text : Entity
{
private:
    std::string text;
public:
    Text();
    std::string getText() const;
    void setText(const std::string &value);
};

#endif // TEXT_H
