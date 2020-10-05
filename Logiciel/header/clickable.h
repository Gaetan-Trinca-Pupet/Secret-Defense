#ifndef CLICKABLE_H
#define CLICKABLE_H


class Clickable
{
public:
    Clickable();
    virtual void onClick();
    virtual bool isClicked();
};

#endif // CLICKABLE_H
