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
	createPCs();
	initPCs();
	temps = 30 - app.difficulty;
	if(temps < 15)temps = 15;
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
	
	for(PC_base* pc : pcs)pc->draw(app.window);
	
	laporte.draw(app.window);
	app.window.draw(rond);
	
}

void EteindrePC::EteindrePC::update(){
	laporte.update();
	for(PC_base* pc : pcs)pc->update();
	rond.setDeg(3.14159265359*2*(temps-clock.getElapsedTime().asSeconds())/temps);
	if(laporte.getPersoView().first->x >= 150) tempsCouloir = clock.getElapsedTime();
	if(clock.getElapsedTime().asSeconds() > temps || clock.getElapsedTime() - tempsCouloir > sf::seconds(5)){
		if(laporte.getPersoView().first->x > 150)app.life -= 1;
		for(PC_base* pc : pcs){
			if(pc->isOn()){
				app.life -= 1;
				break;
			}
		}
		isFinished=true;
	}
}

EteindrePC::EteindrePC::~EteindrePC(){
	for(PC_base* pc : pcs)delete pc;
}

void EteindrePC::EteindrePC::createPCs(){
	for(unsigned int i(0);i < 9; ++i){
		{
			PC_base * pc = new PC_haut;
			pc->setPosition(sf::Vector2f(360+64*i,75-32));
			pc->setPersoView(laporte.getPersoView());
			pcs.push_back(pc);
		}
		{
			PC_base * pc = new PC_haut;
			pc->setPosition(sf::Vector2f(360+64*i,320-32));
			pc->setPersoView(laporte.getPersoView());
			pcs.push_back(pc);
		}
		{
			PC_base * pc = new PC_bas;
			pc->setPosition(sf::Vector2f(360+64*i,220));
			pc->setPersoView(laporte.getPersoView());
			pcs.push_back(pc);
		}
		{
			PC_base * pc = new PC_bas;
			pc->setPosition(sf::Vector2f(360+64*i,540-75));
			pc->setPersoView(laporte.getPersoView());
			pcs.push_back(pc);
		}
	}
}

void EteindrePC::EteindrePC::initPCs(){
	std::srand(std::time(nullptr));
	int dif = app.difficulty*5 + std::rand()%9+5;
	if(dif > 120)dif= 120;
	while(dif>0){
		unsigned int id_pc = std::rand()%pcs.size();
		while(pcs[id_pc]->isOn())id_pc = std::rand()%pcs.size();
		pcs[id_pc]->setOn(true);
		dif-=(((id_pc/3)*3)%9)+1;
	}
}