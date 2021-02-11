#include "../../../header/miniJeu/CorrectTheCode/CodeLine.h"

using namespace correctthecode;

void CodeLine::actionOnClick()
{

}

void CodeLine::initCodeLine()
{
    codeLinesVector.resize(10);
    wrongLine.resize(10);
    std::fstream file;
    file.open("../ressource/CorrectTheCode/Code.txt",std::ios::in);
    if (file.is_open()) {
        std::string line;
        for (unsigned short i = 0; i < codeLinesVector.size(); ++i) {
            codeLinesVector[i].resize(i / 2 + 2);
            for (unsigned j = 0; j < i/ 2 + 2; ++j) {
                if (!std::getline(file, line)) std::cerr << "Fichier ressource de CorrectTheCode invalide";
                codeLinesVector[i][j] = sf::String::fromUtf8(line.begin(),line.end());
            }
            std::getline(file, line);
            wrongLine[i] = stoi(line);
        }
    }
}

CodeLine::CodeLine(sf::RenderWindow *w, const unsigned short &type, const unsigned short &rank) : Button(w, sf::Vector2f(750,50), sf::Vector2f(100, 100 + 75*rank), "", 20, sf::Color::White)
{
    setText(codeLinesVector[type][rank]);
    if (rank == wrongLine[type])
        wrongness = true;
    else
        wrongness = false;
}

CodeLine::~CodeLine()
{

}

bool CodeLine::isWrong()
{
    return wrongness;
}

std::vector<std::vector<std::string>> correctthecode::CodeLine::codeLinesVector;
std::vector<unsigned short> correctthecode::CodeLine::wrongLine;
