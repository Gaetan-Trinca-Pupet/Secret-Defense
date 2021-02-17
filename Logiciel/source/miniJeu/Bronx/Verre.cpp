#include "..\..\..\header\miniJeu\Bronx\Verre.h"

Verre::Verre(sf::Texture *texture, bool _full):Deliverable(texture, false), full(_full)
{

}

bool Verre::isFull()
{
    return full;
}
