#ifndef CORRECTTHECODE_H
#define CORRECTTHECODE_H

#include <vector>

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

public :
    ///
    /// \brief CorrectTheCode initializes the minigame
    /// \param appdata is the struct containing the difficulty and the window the minigame will be displayed on
    ///
    CorrectTheCode(AppData & appdata);
    ///
    /// \brief setup setups the minigame : it creates the codelines and chooses the wrong one
    ///
    virtual void setup();
    ///
    /// \brief draw displays every codeline and the chrono
    ///
    virtual void draw();
    ///
    /// \brief update updates the minigame : it checks if the player clicks on a codeline, and reacts accordingly : ends the game or ends it while reducing the life total by one.
    ///     When the minigame is finished, there is a 1s delay before it completely ends, where the wrong codeline changes color.
    ///
    virtual void update();
    ~CorrectTheCode();
};
}

#endif //CORRECTTHECODE_H
