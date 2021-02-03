#include "../../header/miniJeu/MiniJeuManager.h"

MiniJeuManager::MiniJeuManager(AppData &app_):app(app_)
{
    addMiniJeu([](AppData& app) -> MiniJeu * { return new AmphiReponse::AmphiReponse(app); }, "AmphiReponse", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new correctthecode::CorrectTheCode(app); }, "CorrectTheCode", "descriptionCorrectTheCode");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new BranchePC::BranchePC(app); }, "BranchePC", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new CorrigeCopie::CorrigeCopie(app); }, "CorrigeCopie", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new DistribMiniTests(app); }, "DistribMiniTests", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new EteindrePC::EteindrePC(app); }, "EteindrePC", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new memoryQuestions::MemoryQuestions(app); }, "MemoryQuestions", "descriptionAmphiReponse");
    addBoss([](AppData& app) -> MiniJeu * { return new TestProjetPtut::TestProjetPtut(app); }, "TestProjetPtut", "descriptionAmphiReponse");
}

void MiniJeuManager::play()
{

}

void MiniJeuManager::play(const std::string &title)
{
    FactoryMiniJeu* factoryMiniJeu(nullptr);
    for(FactoryMiniJeu& f: listMiniJeu)
    {
        if(f.getTitle()==title)
        {
            factoryMiniJeu=&f;
            break;
        }
    }
    if(factoryMiniJeu==nullptr)
    {
        for(FactoryMiniJeu& f: listBoss)
        {
            if(f.getTitle()==title)
            {
                factoryMiniJeu=&f;
                break;
            }
        }
    }
    while(factoryMiniJeu!=nullptr && app.lives>0 && app.window.isOpen())
    {
        {
            sf::Text txt;
            txt.setCharacterSize(17);
            txt.setString(factoryMiniJeu->getDescription());
            transition transtest (app, txt);
            transtest.play();
        }
        MiniJeu* miniJeu=factoryMiniJeu->createNewMiniJeu(app);
        unsigned short int lives(app.lives);
        miniJeu->play();
        delete miniJeu;
        if(lives==app.lives)
        {
            ++app.score;
        }
        ++app.difficulty;
    }
}

void MiniJeuManager::buildWave(unsigned int nbMiniJeu, unsigned int nbBoss)
{

}

void MiniJeuManager::addMiniJeu(MiniJeu *(*create_MiniJeu)(AppData &), const std::string &title, const std::string &desc)
{
    listMiniJeu.push_back(FactoryMiniJeu((*create_MiniJeu),title,desc));
}

void MiniJeuManager::addBoss(MiniJeu *(*create_MiniJeu)(AppData &), const std::string &title, const std::string &desc)
{
    listBoss.push_back(FactoryMiniJeu((*create_MiniJeu),title,desc));
}
