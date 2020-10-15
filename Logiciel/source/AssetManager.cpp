#include"../header/AssetManager.h"


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

void AssetManager::unloadTexture(std::string path)
{
    textures.erase(path);
}


