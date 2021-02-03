#ifndef FACTORYMINIJEU_H
#define FACTORYMINIJEU_H

#include <string>
#include "MiniJeu.h"

class FactoryMiniJeu{
public:
    FactoryMiniJeu(MiniJeu * (*create_MiniJeu)(AppData& app), const std::string& title, const std::string& desc);

    const std::string &getDescription () const;
    [[nodiscard]] MiniJeu* createNewMiniJeu(AppData& app);
    const std::string& getTitle()const;
private:
    MiniJeu * (*createMiniJeu)(AppData& app);
    std::string description;
    std::string title;
};

#endif // FACTORYMINIJEU_H
