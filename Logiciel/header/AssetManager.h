#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class AssetManager
{
public:
    AssetManager();
    static sf::Texture& getTexture(std::string path);
    //sf::Sound& getSound(std::string path);
    //sf::Font& getFont();
private:
    static std::map<std::string, sf::Texture> textures;
    //std::map<std::string, sf::Sound> sounds;
    //sf::Font font;
};

#endif // ASSETMANAGER_Hs
