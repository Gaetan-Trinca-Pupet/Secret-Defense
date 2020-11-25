#include "../../../header/miniJeu/CorrectTheCode/CodeLine.h"

using namespace correctthecode;

void CodeLine::actionOnClick()
{

}

void CodeLine::initCodeLine()
{
    codeLinesVector.resize(10);
    wrongLine.resize(10);
    for (unsigned short i = 0; i < codeLinesVector.size(); ++i)
        codeLinesVector[i].resize(i / 2 + 2);
    codeLinesVector[0][0] = "unsigned short score;";
    codeLinesVector[0][1] = "score = 10";
    wrongLine[0] = 1;

    codeLinesVector[1][0] = "string text;";
    codeLinesVector[1][1] = "text = 'Hello World !';";
    wrongLine[1] = 1;

    codeLinesVector[2][0] = "string text;";
    codeLinesVector[2][1] = "cout << \"Saisissez une chaine de caracteres\" << endl;";
    codeLinesVector[2][2] = "cout >> text;";
    wrongLine[2] = 1;

    codeLinesVector[3][0] = "unsigned randomNumber (rand%100 - 50);";
    codeLinesVector[3][1] = "if (randomNumber == 12)";
    codeLinesVector[3][2] = "    cout << \"Gagne !\";";
    wrongLine[3] = 0;

    codeLinesVector[4][0] = "string f1 (12,345);";
    codeLinesVector[4][1] = "float f2 (1,2345);";
    codeLinesVector[4][2] = "if (f1 == f2)";
    codeLinesVector[4][3] = "    cout << \"Gagne !\";";
    wrongLine[4] = 2;

    codeLinesVector[5][0] = "int myNumber (1254);";
    codeLinesVector[5][1] = "myNumber += 12;";
    codeLinesVector[5][2] = "mynumber *=2;";
    codeLinesVector[5][3] = "cout << myNumber << endl;";
    wrongLine[5] = 0;

    codeLinesVector[6][0] = "";
    codeLinesVector[6][1] = "";
    codeLinesVector[6][2] = "";
    codeLinesVector[6][3] = "";
    codeLinesVector[6][4] = "";
    wrongLine[6] = 0;

    codeLinesVector[7][0] = "";
    codeLinesVector[7][1] = "";
    codeLinesVector[7][2] = "";
    codeLinesVector[7][3] = "";
    codeLinesVector[7][4] = "";
    wrongLine[7] = 0;

    codeLinesVector[8][0] = "";
    codeLinesVector[8][1] = "";
    codeLinesVector[8][2] = "";
    codeLinesVector[8][3] = "";
    codeLinesVector[8][4] = "";
    codeLinesVector[8][5] = "";
    wrongLine[8] = 0;

    codeLinesVector[9][0] = "";
    codeLinesVector[9][1] = "";
    codeLinesVector[9][2] = "";
    codeLinesVector[9][3] = "";
    codeLinesVector[9][4] = "";
    codeLinesVector[9][5] = "";
    wrongLine[9] = 0;
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
