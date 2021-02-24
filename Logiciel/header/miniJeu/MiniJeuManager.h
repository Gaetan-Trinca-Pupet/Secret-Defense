#ifndef MINIJEUMANAGER_H
#define MINIJEUMANAGER_H

#include <vector>
#include <cstdlib>
#include "MiniJeu.h"
#include "FactoryMiniJeu.h"
#include "../transition.h"
#include "../gameOverWindow.h"
#include "DistribMiniTests/DistribMiniTests.h"
#include "Gifle/Gifle.h"
#include "MemoryQuestions/memoryquestions.h"
#include "TestProjetPtut/TestProjetPtut.h"
#include "EteindrePC/EteindrePC.h"
#include "AmphiReponse/AmphiReponse.h"
#include "BranchePC/BranchePC.h"
#include "CorrectTheCode/CorrectTheCode.h"
#include "CorrigeCopie/CorrigeCopie.h"
#include "Gifle/Gifle.h"
#include "Bronx/Bronx.h"

class MiniJeuManager{
    AppData& app;
    std::vector<FactoryMiniJeu> listMiniJeu;
    std::vector<FactoryMiniJeu> listBoss;
    std::vector<FactoryMiniJeu*> wave;
public:
    MiniJeuManager(AppData& app);
    void play(unsigned int nbMiniJeu=4, unsigned int nbBoss=1);
    void play(const std::string& title);
    void buildWave(unsigned int nbMiniJeu=4, unsigned int nbBoss=1);
    void addMiniJeu(MiniJeu * (*create_MiniJeu)(AppData& app), const std::string& title, const std::string& desc);
    void addBoss(MiniJeu * (*create_MiniJeu)(AppData& app), const std::string& title, const std::string& desc);
};

#endif // MINIJEUMANAGER_H
