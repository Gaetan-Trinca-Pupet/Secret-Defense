#include "../header/FramerateManager.h"


FramerateManager::FramerateManager(){
    expectedMode = dyn;
    mode = high;
    //reset();
}

void FramerateManager::reset(){
    updatecount.ecomode = 0b10;
    updatecount.highmode = 0b1;
    updatecount.middlemode = 0b0;
	framecount = 0;
	nbUpdatePerSec=0;
	if(expectedMode != dyn)updateMode();
    else{
        switch(mode){
            case FramerateMode::eco :
                window->setFramerateLimit(30);
                break;
            case FramerateMode::middle :
                window->setFramerateLimit(45);
                break;
            case FramerateMode::high :
                window->setFramerateLimit(60);
                break;
        }
	}
	clock.restart();
}

bool FramerateManager::mustUpdate(){
	bool must_update(true);
    if(mode == high || (mode == middle && updatecount.middlemode == 0)){
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
	if(must_update)++nbUpdatePerSec;
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
        switch((unsigned char)mode){
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
    //std::cout << "framecount : " << framecount << std::endl;
    //std::cout << "nbUpdatePerSec : " << nbUpdatePerSec << std::endl;
	framecount = 0;
	nbUpdatePerSec = 0;
	clock.restart();
}
