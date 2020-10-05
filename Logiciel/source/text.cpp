#include "header/text.h"

Text::Text()
{

}

std::string Text::getText() const
{
    return text;
}

void Text::setText(const std::string &value)
{
    text = value;
}
