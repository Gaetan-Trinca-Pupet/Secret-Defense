#include "../../../header/miniJeu/EteindrePC/EteindrePC.h"


EteindrePC::EteindrePC::EteindrePC(AppData& appData) : MiniJeu(appData), mur1(0,100),mur2(150,240), mur3(440,100), 
		table1(sf::Vector2f(360,0), sf::Vector2f(600,75)),
		table2(sf::Vector2f(300,220), sf::Vector2f(660,100)),
		table3(sf::Vector2f(360,540-75), sf::Vector2f(600,75)){
	
}

void EteindrePC::EteindrePC::setup(){
	setBackgroundColor(sf::Color(245,200,120));
	laporte.addCollisionBox(mur1.getCollisionBox());
	laporte.addCollisionBox(mur2.getCollisionBox());
	laporte.addCollisionBox(mur3.getCollisionBox());
	laporte.addCollisionBox(table1.getCollisionBox());
	laporte.addCollisionBox(table2.getCollisionBox());
	laporte.addCollisionBox(table3.getCollisionBox());
	rond.setRadius(50);
	rond.setColor(sf::Color(255,0,0));
	rond.setPosition(sf::Vector2f(0.9,0.9));
	pc.setPosition(sf::Vector2f(300,220));
	pc.setPersoView(laporte.getPersoView());
	clock.restart();
}

void EteindrePC::EteindrePC::draw(){
	sf::RectangleShape solHall(sf::Vector2f(150,540));
	solHall.setFillColor(sf::Color(200,200,230));
	app.window.draw(solHall);
	
	mur1.draw(app.window);
	mur2.draw(app.window);
	mur3.draw(app.window);
	
	table1.draw(app.window);
	table2.draw(app.window);
	table3.draw(app.window);
	
	laporte.draw(app.window);
	app.window.draw(rond);
	pc.draw(app.window);
}

void EteindrePC::EteindrePC::update(){
	laporte.update();
	pc.update();
	rond.setDeg(3.14159265359*2*(30-clock.getElapsedTime().asSeconds())/30);
}