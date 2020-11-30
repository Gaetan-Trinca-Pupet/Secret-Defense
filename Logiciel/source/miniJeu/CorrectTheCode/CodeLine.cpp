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
    wrongLine[2] = 2;

    codeLinesVector[3][0] = "unsigned randomNumber (rand%100 - 50);";
    codeLinesVector[3][1] = "if (randomNumber == 12)";
    codeLinesVector[3][2] = "    cout << \"Gagne !\";";
    wrongLine[3] = 0;

    codeLinesVector[4][0] = "float f1 (12345/100);";
    codeLinesVector[4][1] = "float f2 (0.12345*1000);";
    codeLinesVector[4][2] = "if (f1 == f2)";
    codeLinesVector[4][3] = "    cout << \"Gagne !\";";
    wrongLine[4] = 2;

    codeLinesVector[5][0] = "int myNumber (1254);";
    codeLinesVector[5][1] = "myNumber += 12;";
    codeLinesVector[5][2] = "mynumber *=2;";
    codeLinesVector[5][3] = "cout << myNumber << endl;";
    wrongLine[5] = 2;

    codeLinesVector[6][0] = "vector<unsigned> vect (8,0);";
    codeLinesVector[6][1] = "for (unsigned i = 0; i <= vect.size(); ++i) {";
    codeLinesVector[6][2] = "cout << i << endl;";
    codeLinesVector[6][3] = "vect[i] = i;";
    codeLinesVector[6][4] = "}";
    wrongLine[6] = 1;

    codeLinesVector[7][0] = "int multiply (const int & a, const int & b) {";
    codeLinesVector[7][1] = "   a *= b;";
    codeLinesVector[7][2] = "   cout << a << endl;";
    codeLinesVector[7][3] = "   return a;";
    codeLinesVector[7][4] = "}";
    wrongLine[7] = 1;

    codeLinesVector[8][0] = "int power(const int & x, unsigned n) {";
    codeLinesVector[8][1] = "    if (n == 1)";
    codeLinesVector[8][2] = "        return power (x, 1);";
    codeLinesVector[8][3] = "    else";
    codeLinesVector[8][4] = "        return power(x, n-1) * x;";
    codeLinesVector[8][5] = "}";
    wrongLine[8] = 2;

    codeLinesVector[9][0] = "unsigned add (const int & a, const int & b) {";
    codeLinesVector[9][1] = "   if (a + b >= 0)";
    codeLinesVector[9][2] = "       return a + b;";
    codeLinesVector[9][3] = "   else";
    codeLinesVector[9][4] = "       return \"An error has occured : the result is negative\";";
    codeLinesVector[9][5] = "}";
    wrongLine[9] = 4;
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
