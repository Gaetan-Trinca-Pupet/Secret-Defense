#ifndef CORRECTTHECODE_H
#define CORRECTTHECODE_H

#include <vector>

#include "../MiniJeu.h"
#include "../../button.h"
#include "CodeLine.h"

namespace correctthecode {
class CorrectTheCode : public MiniJeu {
private :
    std::vector<CodeLine> code;
public :
    CorrectTheCode(AppData & appdata);
    virtual void setup();
    virtual void draw();
    virtual void update();
    ~CorrectTheCode();
};
}

#endif //CORRECTTHECODE_H
