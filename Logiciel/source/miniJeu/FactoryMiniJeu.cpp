#include "../../header/miniJeu/FactoryMiniJeu.h"

FactoryMiniJeu::FactoryMiniJeu(MiniJeu * (*create_MiniJeu)(AppData& app), const std::string& desc){
    createMiniJeu=create_MiniJeu;
    description=desc;
}

const std::string &FactoryMiniJeu::getDescription() const
{
    return description;
}

MiniJeu *FactoryMiniJeu::createNewMiniJeu(AppData &app)
{
    return (*createMiniJeu)(app);
}
