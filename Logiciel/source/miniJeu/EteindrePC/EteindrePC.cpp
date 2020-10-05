#include "../../../header/miniJeu/EteindrePC/EteindrePC.h"


EteindrePC::EteindrePC::EteindrePC(AppData& appData) : MiniJeu(appData){
	
}

void EteindrePC::EteindrePC::setup(){
	setBackgroundColor(sf::Color(245,200,120));
}

void EteindrePC::EteindrePC::draw(){
	laporte.draw(app.window);
}

void EteindrePC::EteindrePC::update(){
	laporte.update();
}