#include"../header/AssetManager.h"
#include<iostream>


std::map<std::string, sf::Texture> AssetManager::textures;
std::map<std::string, sf::SoundBuffer> AssetManager::soundBuffers;
std::vector<sf::Sound> AssetManager::sounds;


AssetManager::AssetManager()
{
}

sf::Texture& AssetManager::getTexture(std::string path)
{


	std::map<std::string, sf::Texture>::iterator searchIter = textures.find(path);
	if (searchIter != textures.end())
	{

		return searchIter->second;
	}
	else
	{
		sf::Texture texture;
		textures[path] = texture;
		textures[path].loadFromFile(path);
		return textures[path];
	}
	
}

void AssetManager::playSound(std::string path)
{
	for (int i(sounds.size()); i != 0 && sounds.size() != 0;)
	{
		--i;
		if (sounds[i].getStatus() == sf::Sound::Stopped)
		{
			sounds.erase(sounds.begin()+i);
		}
	}

	sounds.push_back(sf::Sound(getSoundBuffer(path)));
	sounds.back().play();
}

sf::SoundBuffer& AssetManager::getSoundBuffer(std::string path)
{


	std::map<std::string, sf::SoundBuffer>::iterator searchIter = soundBuffers.find(path);
	if (searchIter != soundBuffers.end())
	{
		return searchIter->second;
	}
	else
	{
		sf::SoundBuffer soundBuff;
		soundBuffers[path] = soundBuff;
		soundBuffers[path].loadFromFile(path);
		return soundBuffers[path];
	}
}


