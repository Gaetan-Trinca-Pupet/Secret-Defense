#ifndef CODELINE_H
#define CODELINE_H

#include "../../button.h"

namespace correctthecode {
class CodeLine : public Button {
private:
    bool wrongness;
    void actionOnClick() override;
    static std::vector<std::vector<std::string>> codeLinesVector;
    static std::vector<unsigned short> wrongLine;
public:
    static void initCodeLine();
    CodeLine(sf::RenderWindow* w = nullptr, const unsigned short & type = 0, const unsigned short & rank = 0);
    virtual ~CodeLine();
    bool isWrong();
};
}

#endif // CODELINE_H
