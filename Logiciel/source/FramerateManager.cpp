#include "../header/FramerateManager.h"

FramerateManager::FramerateManager(){
	expectedMode = dyn;
	mode = high;
	reset();
}

void FramerateManager::reset(){
	updatecount.ecomode = 2;
	updatecount.highmode = 1;
	updatecount.middlemode = 0;
	framecount = 0;
	if(expectedMode != dyn)updateMode();
	else{
		switch(mode){
			case eco :
				window->setFramerateLimit(30);
				break;
			case middle :
				window->setFramerateLimit(45);
				break;
			case high :
				window->setFramerateLimit(60);
				break;
		}
	}
	clock.restart();
}

bool FramerateManager::mustUpdate(){
	bool must_update(true);
	if(mode == high || mode == middle && updatecount.middlemode == 0){
		if(updatecount.highmode == 0){
			must_update = false;
			updatecount.middlemode = 1;
			++framecount;
		}
		--updatecount.highmode;
	}else{
		if(updatecount.ecomode == 0){
			must_update = false;
			updatecount.middlemode = 0;
			++framecount;
			updatecount.ecomode = 3;
		}
		--updatecount.ecomode;
	}
	if(clock.getElapsedTime().asSeconds() > 1.0)updateMode();
	return must_update;
}

void FramerateManager::setMode(FramerateMode framerateMode){
	expectedMode = framerateMode;
}

void FramerateManager::setWindow(sf::RenderWindow& renderWindow){
	window = &renderWindow;
}

void FramerateManager::updateMode(){
	if(framecount == 0){
		mode = expectedMode;
		switch(mode){
			case eco :
				window->setFramerateLimit(30);
				break;
			case middle :
				window->setFramerateLimit(45);
				break;
			case high :
				window->setFramerateLimit(60);
				break;
		}
	}else{
		if(framecount < 40 && mode == middle){
			mode = eco;
			window->setFramerateLimit(30);
		}else if(framecount < 50 && mode == high){
			mode = middle;
			window->setFramerateLimit(45);
		}else if(expectedMode == dyn){
			if(mode == eco && framecount > 30){
				mode = middle;
				window->setFramerateLimit(45);
			}else if(mode == middle && framecount > 45){
				mode = high;
				window->setFramerateLimit(60);
			}
		}
	}
	framecount = 0;
	clock.restart();
}