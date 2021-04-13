#include "../../header/miniJeu/MiniJeuManager.h"

MiniJeuManager::MiniJeuManager(AppData &app_):app(app_)
{
    phaseMusique='1';

    addMiniJeu([](AppData& app) -> MiniJeu * { return new AmphiReponse::AmphiReponse(app); }, "AmphiReponse", "Déplacez les réponses sur les bonne questions.\n(Souris)");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new correctthecode::CorrectTheCode(app); }, "CorrectTheCode", "descriptionCorrectTheCode");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new BranchePC::BranchePC(app); }, "BranchePC", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new CorrigeCopie::CorrigeCopie(app); }, "CorrigeCopie", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new DistribMiniTests(app); }, "DistribMiniTests", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu * { return new EteindrePC::EteindrePC(app); }, "EteindrePC", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu* { return new memoryQuestions::MemoryQuestions(app); }, "MemoryQuestions", "descriptionAmphiReponse");
    addMiniJeu([](AppData& app) -> MiniJeu* { return new TrouveSansMasque::TrouveSansMasque(app); }, "TrouveSansMasque", app.pseudo != "Laporte" ? "descriptionTrouveSansMasque" : "Giflez les passants sans masque\n(Souris)");
    addBoss([](AppData& app) -> MiniJeu* { return new TestProjetPtut::TestProjetPtut(app); }, "TestProjetPtut", "descriptionAmphiReponse");
    addBoss([](AppData& app) -> MiniJeu* { return new Bronx::Bronx(app); }, "Bronx", "descriptionBronx");
}

void MiniJeuManager::play(unsigned int nbMiniJeu, unsigned int nbBoss)
{
	reset();
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
            std::string transitionMessage = lastMsg + '\n' + wave[wave.size()-1]->getDescription();
            txt.setString(sf::String::fromUtf8(transitionMessage.cbegin(),transitionMessage.cend()));
            app.mainMusique.stop();
            if(!app.mainMusique.openFromFile("../ressource/audio/transition.wav"))
                std::cerr<<"erreur openFromFile musique de transition"<<std::endl;

            app.mainMusique.setLoop(false);
            app.mainMusique.setVolume(30);
            app.mainMusique.play();
            transition transtest (app, txt);
            transtest.play();
        }

        MiniJeu* miniJeu=wave[wave.size()-1]->createNewMiniJeu(app);
        wave.pop_back();
        unsigned short int lives(app.lives);

        if(!app.mainMusique.openFromFile(std::string("../ressource/audio/etapes/minijeu")+phaseMusique+".wav"))
            std::cerr<<"erreur openFromFile audio"<<std::endl;
        app.mainMusique.play();
        app.mainMusique.setLoop(true);

        if(++phaseMusique>'5')
            phaseMusique='1';

        lastMsg = miniJeu->play();
        delete miniJeu;


        if(lives==app.lives)
        {
            ++app.score;
        }

    }
    ScoreServer::sendScore(app.pseudo, app.score);
}

void MiniJeuManager::play(const std::string &title)
{
	reset();
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
            std::string transitionMessage = lastMsg + '\n' + factoryMiniJeu->getDescription();
            txt.setString(sf::String::fromUtf8(transitionMessage.cbegin(), transitionMessage.cend()));
            transition transtest (app, txt);
            transtest.play();
        }
        MiniJeu* miniJeu=factoryMiniJeu->createNewMiniJeu(app);
        unsigned short int lives(app.lives);
        lastMsg = miniJeu->play();
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
        wave.push_back(&listBoss[tabChoix[r]]);
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
        wave.push_back(&listMiniJeu[tabChoix[r]]);
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

void MiniJeuManager::reset(){
	app.difficulty=0;
    app.score=0;
    app.lives=3;
}
