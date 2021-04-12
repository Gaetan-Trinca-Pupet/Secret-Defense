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
	 * \param path le chemin vers la texture
	 * \return la texture
	 */
	static sf::Texture& getTexture(std::string path);


	/**
	 * Joue le son
	 *
	 * \param path le chemin vers le son
	 * \return la texture
	 */
    static void playSound(std::string path, float volume=100);
	


private:

	/**
	 * Renvoi une référence du son chargé à partir du fichier path, et la garde en mémoire.
	 * (Si ce même son est demmandé une fois de plus, elle n'aura pas a être chargé)
	 *
	 * \param path le chemin vers le son
	 * \return le son
 */
	static sf::SoundBuffer& getSoundBuffer(std::string path);


	static std::map<std::string, sf::Texture> textures;
	static std::vector<sf::Sound> sounds;
	static std::map<std::string, sf::SoundBuffer> soundBuffers;
	//static sf::Font font;
};

#endif // ASSETMANAGER_Hs
