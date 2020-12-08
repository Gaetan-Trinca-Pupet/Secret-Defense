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
    ///
    /// \brief initCodeLine initializes the static members of CodeLine, by creating the matrix of strings and the vector of bool telling which line is false
    ///
    static void initCodeLine();

    ///
    /// \brief CodeLine creates a codeline with the text corresponding to its type and rank
    /// \param w is the window the codeline will be displayed on
    /// \param type is the ID of the code
    /// \param rank is the rank of the line in the code
    ///
    CodeLine(sf::RenderWindow* w = nullptr, const unsigned short & type = 0, const unsigned short & rank = 0);
    virtual ~CodeLine();
    bool isWrong();
};
}

#endif // CODELINE_H
