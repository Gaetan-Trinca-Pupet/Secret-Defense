#include "../../../header/miniJeu/TestProjetPtut/InnerInterface.h"

void TestProjetPtut::InnerInterface::draw(sf::RenderWindow& window){
    sf::Sprite sprite;
    sprite.setTexture(AssetManager::getTexture("../ressource/image/coeur.png"));
    sprite.setTextureRect(sf::IntRect(0,0,(int(11.25*(*pv))),23));
    sprite.setPosition(sf::Vector2f(0,50));
    window.draw(sprite);
}

void TestProjetPtut::InnerInterface::setPv(const short int& hp){
	pv = &hp;
}