#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include<SFML/Graphics.hpp>

class AssetManager
{
public:
    AssetManager();
    sf::Texture& getTexture(std::string path);
    void unloadTexture(std::string path);
private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
};

#endif // ASSETMANAGER_Hs
