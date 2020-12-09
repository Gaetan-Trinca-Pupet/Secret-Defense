#include "../../../header/miniJeu/EteindrePC/EteindrePC.h"


EteindrePC::EteindrePC::EteindrePC(AppData& appData) : MiniJeu(appData), chrono(appData.window), mur1(0,100),mur2(150,240), mur3(440,100), 
		table1(sf::Vector2f(360,0), sf::Vector2f(600,75)),
		table2(sf::Vector2f(300,220), sf::Vector2f(660,100)),
		table3(sf::Vector2f(360,540-75), sf::Vector2f(600,75)){
	app.window.setMouseCursorVisible(false);
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
	chrono.setTempsMax(15);
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
	app.window.draw(chrono);
	
}

void EteindrePC::EteindrePC::update(){
	chrono.update();
	laporte.update();
	for(PC_base* pc : pcs)pc->update();
	if(chrono.getTimePassed() > 15){
		bool win(true);
		if(laporte.getPersoView().first->x > 100){
			win=false;
		}else{
			for(PC_base* pc : pcs){
				if(pc->isOn()){
					win=false;
					break;
				}
			}
		}
		if(!win)--app.lives;
		isFinished=true;
	}
}

EteindrePC::EteindrePC::~EteindrePC(){
	app.window.setMouseCursorVisible(true);
	for(PC_base* pc : pcs)delete pc;
}

void EteindrePC::EteindrePC::createPCs(){
	for(unsigned int i(0);i < 9; ++i){
		{
			if(i < 7){
				PC_base * pc = new PC_haut;
				pc->setPosition(sf::Vector2f(360+64*i,75-32));
				pc->setPersoView(laporte.getPersoView());
				pcs.push_back(pc);
			}
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
	int max_i(int((32.0*app.difficulty/(app.difficulty + 10.0))+1.0));
	if(max_i>33)max_i=33;
	std::vector<PC_base*> pcs_copie = pcs;
	for(int i(max_i);i >= 0;--i){
		int j = std::rand()%pcs_copie.size();
		pcs_copie[j]->setOn(true);
		pcs_copie.erase(pcs_copie.begin()+j);
	}
}