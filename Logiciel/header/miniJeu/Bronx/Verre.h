#ifndef __VERRE_H_
#define __VERRE_H_

#include "Deliverable.h"

class Verre: public Deliverable
{
public:
    Verre(sf::Texture* texture, bool _full=false);
    void update();
    bool isFull();
    void setFull(bool val);
private:
    bool full;
};

#endif
