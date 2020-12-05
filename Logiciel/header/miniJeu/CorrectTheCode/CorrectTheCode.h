#ifndef CORRECTTHECODE_H
#define CORRECTTHECODE_H

#include <vector>
#include <cmath>

#include "../MiniJeu.h"
#include "../../button.h"
#include "CodeLine.h"
#include "../../Chrono.h"

namespace correctthecode {
class CorrectTheCode : public MiniJeu {
private :
    std::vector<CodeLine> code;
    float maxTime;
    Chrono chrono;
    sf::Clock clock;
    bool isEnding;
public :
    CorrectTheCode(AppData & appdata);
    virtual void setup();
    virtual void draw();
    virtual void update();
    ~CorrectTheCode();
};
}

#endif //CORRECTTHECODE_H
