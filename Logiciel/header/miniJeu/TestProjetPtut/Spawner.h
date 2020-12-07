#ifndef __TEST_PROJET_PTUT__SPAWNER_H_
#define __TEST_PROJET_PTUT__SPAWNER_H_

#include <vector>
#include <cstdlib>

#include <SFML/System.hpp>

#include "Invader.h"

namespace TestProjetPtut{
	class Spawner{
		private :
			std::vector<Invader>* invaders;
			sf::Clock cooldown;
			float cooldownDuration;
			float y_spawnpoint;
			unsigned char nbMaxInvaderPerWave;
			unsigned char nbSpawnedInvadersCurrentWave;
			bool waveFinished;
			
		public :
			Spawner();
			void setInvaders(std::vector<Invader>* tabInvaders);
			void setDifficulty(unsigned int difficulty);
			void update();
			bool isWaveFinished();
			
	};
}

#endif