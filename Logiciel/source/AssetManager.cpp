#include"../header/AssetManager.h"


std::map<std::string, sf::Texture> AssetManager::textures;

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
		sf::Texture& texture = textures[path];
		texture.loadFromFile(path);
		return texture;
	}
}


