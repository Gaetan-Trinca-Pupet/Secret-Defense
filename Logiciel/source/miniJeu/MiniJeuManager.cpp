#include "../../header/miniJeu/MiniJeuManager.h"

MiniJeuManager::MiniJeuManager(AppData &app_):app(app_)
{
    addMiniJeu([](AppData& app) -> MiniJeu * { return new AmphiReponse::AmphiReponse(app); }, "AmphiReponse", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new correctthecode::CorrectTheCode(app); }, "CorrectTheCode", "descriptionCorrectTheCode");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new BranchePC::BranchePC(app); }, "BranchePC", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new CorrigeCopie::CorrigeCopie(app); }, "CorrigeCopie", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new DistribMiniTests(app); }, "DistribMiniTests", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new EteindrePC::EteindrePC(app); }, "EteindrePC", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu* { return new memoryQuestions::MemoryQuestions(app); }, "MemoryQuestions", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu* { return new Gifle::Gifle(app); }, "Gifle", /*app.option.secretMode ? */"descriptionGifle"/* : "descriptionOuEstSansMasque*/);
    addBoss([](AppData& app) -> MiniJeu* { return new TestProjetPtut::TestProjetPtut(app); }, "TestProjetPtut", "descriptionAmphiReponse");
    addBoss([](AppData& app) -> MiniJeu* { return new Bronx::Bronx(app); }, "Bronx", "descriptionBronx");
}

void MiniJeuManager::play(unsigned int nbMiniJeu, unsigned int nbBoss)
{
    buildWave(nbMiniJeu, nbBoss);
    while(app.lives>0 && app.window.isOpen())
    {
        if(wave.size()==0)
        {
			++app.difficulty;
            buildWave(nbMiniJeu, nbBoss);
        }

        {
            sf::Text txt;
            txt.setCharacterSize(17);
            txt.setString(sf::String::fromUtf8(wave[wave.size()-1]->getDescription().cbegin(),wave[wave.size()-1]->getDescription().cend()));
            transition transtest (app, txt);
            transtest.play();
        }
        MiniJeu* miniJeu=wave[wave.size()-1]->createNewMiniJeu(app);
        unsigned short int lives(app.lives);
        miniJeu->play();
        delete miniJeu;
        if(lives==app.lives)
        {
            ++app.score;
        }
        wave.pop_back();
    }
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
    std::vector<unsigned int> tabChoix;

    unsigned int minVal;
    tabChoix.resize(listBoss.size());
    for(unsigned int i=0; i<tabChoix.size();++i)
    {
        tabChoix[i]=i;
    }
    if(nbBoss<listBoss.size()){
        minVal=nbBoss;
    }
    else{
        minVal=listBoss.size();
    }
    for(unsigned int i=0;i<minVal;++i){
        unsigned int r=rand()%tabChoix.size();
        wave.push_back(&listBoss[r]);
        tabChoix.erase(tabChoix.begin()+r);
    }

    tabChoix.resize(listMiniJeu.size());
    for(unsigned int i=0; i<tabChoix.size();++i)
    {
        tabChoix[i]=i;
    }


    if(nbMiniJeu<listMiniJeu.size()){
        minVal=nbMiniJeu;
    }
    else{
        minVal=listMiniJeu.size();
    }
    for(unsigned int i=0;i<minVal;++i){
        unsigned int r=rand()%tabChoix.size();
        wave.push_back(&listMiniJeu[r]);
        tabChoix.erase(tabChoix.begin()+r);
    }


}

void MiniJeuManager::addMiniJeu(MiniJeu *(*create_MiniJeu)(AppData &), const std::string &title, const std::string &desc)
{
    listMiniJeu.push_back(FactoryMiniJeu((*create_MiniJeu),title,desc));
}

void MiniJeuManager::addBoss(MiniJeu *(*create_MiniJeu)(AppData &), const std::string &title, const std::string &desc)
{
    listBoss.push_back(FactoryMiniJeu((*create_MiniJeu),title,desc));
}
