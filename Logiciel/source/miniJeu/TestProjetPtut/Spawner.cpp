#include "../../../header/miniJeu/TestProjetPtut/Spawner.h"


TestProjetPtut::Spawner::Spawner(){
	y_spawnpoint =  -std::rand()%1000/float(10);
	waveFinished = false;
}

void TestProjetPtut::Spawner::update(){
	constexpr unsigned int windowWidth = 960;
	if(nbSpawnedInvadersCurrentWave < nbMaxInvaderPerWave && cooldown.getElapsedTime().asSeconds() > cooldownDuration){
		invaders->push_back(Invader(sf::Vector2f(windowWidth/2,y_spawnpoint)));
		++nbSpawnedInvadersCurrentWave;
		cooldown.restart();
	}else if(nbSpawnedInvadersCurrentWave >= nbMaxInvaderPerWave && invaders->size() == 0){
		nbSpawnedInvadersCurrentWave = 0;
		y_spawnpoint =  -std::rand()%1000/float(10);
		waveFinished = true;
	}
}

void TestProjetPtut::Spawner::setInvaders(std::vector<Invader>* tabInvaders){
	invaders = tabInvaders;
}

void TestProjetPtut::Spawner::setDifficulty(unsigned int difficulty){
	constexpr unsigned char limitNbMaxInvaderPerWave = 15;
	constexpr float limitMinCooldownDuration = 0.3;
	constexpr float limitMaxCooldownDuration = 0.9;
	nbMaxInvaderPerWave = difficulty + 2;
	if(nbMaxInvaderPerWave > limitNbMaxInvaderPerWave)nbMaxInvaderPerWave = limitNbMaxInvaderPerWave;
	if(difficulty > 10)cooldownDuration = limitMaxCooldownDuration-(difficulty-limitNbMaxInvaderPerWave)/float(10);
	else cooldownDuration = limitMaxCooldownDuration;
	if(cooldownDuration < limitMinCooldownDuration)cooldownDuration = limitMinCooldownDuration;
	waveFinished = false;
	cooldown.restart();
}

bool TestProjetPtut::Spawner::isWaveFinished(){
	bool finished(waveFinished);
	waveFinished = false;
	return finished;
}