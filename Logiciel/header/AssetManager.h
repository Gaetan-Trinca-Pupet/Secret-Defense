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
	 * Constructeur de Assetmanager. Jamais utilis�.
	 * 
	 */
	AssetManager();

	/**
	 * Renvoi une r�f�rence de la texture charg� � partir du fichier path, et la garde en m�moire.
	 * (Si cette m�me texture est demmand� une fois de plus, elle n'aura pas a �tre charg�)
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