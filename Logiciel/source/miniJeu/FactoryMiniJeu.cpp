#include "../../header/miniJeu/FactoryMiniJeu.h"

FactoryMiniJeu::FactoryMiniJeu(MiniJeu * (*create_MiniJeu)(AppData& app), const std::string& title_, const std::string& desc){
    createMiniJeu=create_MiniJeu;
    title=title_;
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

const std::string &FactoryMiniJeu::getTitle() const
{
    return title;
}
