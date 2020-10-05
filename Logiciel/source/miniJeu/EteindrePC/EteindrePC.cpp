#include "../../../header/miniJeu/EteindrePC/EteindrePC.h"

EteindrePC::EteindrePC::EteindrePC(AppData& appData) : MiniJeu(appData){
	
}

void EteindrePC::EteindrePC::setup(){
	
}

void EteindrePC::EteindrePC::draw(){
	laporte.draw(app.window);
}

void EteindrePC::EteindrePC::update(){
	laporte.update();
}