#ifndef FACTORYMINIJEU_H
#define FACTORYMINIJEU_H

#include <string>
#include "MiniJeu.h"

class FactoryMiniJeu{
public:
    FactoryMiniJeu(MiniJeu * (*create_MiniJeu)(AppData& app), const std::string& desc);

    const std::string &getDescription () const;
    [[nodiscard]] MiniJeu* createNewMiniJeu(AppData& app);
private:
    MiniJeu * (*createMiniJeu)(AppData& app);
    std::string description;


};

#endif // FACTORYMINIJEU_H
