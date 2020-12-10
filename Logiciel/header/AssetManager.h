#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class AssetManager
{
public:

	/**
	 * Constructeur de Assetmanager. Jamais utilisé.
	 * 
	 */
	AssetManager();

	/**
	 * Renvoi une référence de la texture chargé à partir du fichier path, et la garde en mémoire.
	 * (Si cette même texture est demmandé une fois de plus, elle n'aura pas a être chargé)
	 * 
	 * \param path
	 * \return la texture
	 */
	static sf::Texture& getTexture(std::string path);
	//static sf::Sound& getSound(std::string path);
	//static sf::Font& getFont();
private:
	static std::map<std::string, sf::Texture> textures;
	//static std::map<std::string, sf::Sound> sounds;
	//static sf::Font font;
};

#endif // ASSETMANAGER_Hs