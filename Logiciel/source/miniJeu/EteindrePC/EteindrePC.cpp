#include "../../../header/miniJeu/EteindrePC/EteindrePC.h"


EteindrePC::EteindrePC::EteindrePC(AppData& appData) : MiniJeu(appData){
	
}

void EteindrePC::EteindrePC::setup(){
	setBackgroundColor(sf::Color(245,200,120));
}

void EteindrePC::EteindrePC::draw(){
	sf::RectangleShape solHall(sf::Vector2f(150,540));
	solHall.setFillColor(sf::Color(200,200,230));
	app.window.draw(solHall);
	
	sf::RectangleShape mur1(sf::Vector2f(10,100));
	mur1.setFillColor(sf::Color(0,0,0));
	mur1.setPosition(sf::Vector2f(140,0));
	app.window.draw(mur1);
	
	sf::RectangleShape mur2(sf::Vector2f(10,540-100-50-150));
	mur2.setFillColor(sf::Color(0,0,0));
	mur2.setPosition(sf::Vector2f(140,150));
	app.window.draw(mur2);
	
	sf::RectangleShape mur3(sf::Vector2f(10,100));
	mur3.setFillColor(sf::Color(0,0,0));
	mur3.setPosition(sf::Vector2f(140,540-100));
	app.window.draw(mur3);
	
	sf::RectangleShape table1(sf::Vector2f(600,75));
	table1.setFillColor(sf::Color(200,200,200));
	table1.setPosition(sf::Vector2f(360,0));
	app.window.draw(table1);
	
	sf::RectangleShape table2(sf::Vector2f(660,100));
	table2.setFillColor(sf::Color(200,200,200));
	table2.setPosition(sf::Vector2f(300,220));
	app.window.draw(table2);
	
	sf::RectangleShape table3(sf::Vector2f(600,75));
	table3.setFillColor(sf::Color(200,200,200));
	table3.setPosition(sf::Vector2f(360,540-75));
	app.window.draw(table3);
	
	
	laporte.draw(app.window);
	
}

void EteindrePC::EteindrePC::update(){
	laporte.update();
}