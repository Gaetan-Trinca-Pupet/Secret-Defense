#include"../header/AssetManager.h"


std::map<std::string, sf::Texture> AssetManager::textures;

AssetManager::AssetManager() {
}

sf::Texture& AssetManager::getTexture(std::string path)
{
    typedef std::map<std::string, sf::Texture>::iterator iter;

    iter pairFound = textures.find(path);
    if (pairFound != textures.end()) {

        return pairFound->second;
    }
    else
    {
        sf::Texture& texture = textures[path];
        texture.loadFromFile(path);
        return texture;
    }
}


