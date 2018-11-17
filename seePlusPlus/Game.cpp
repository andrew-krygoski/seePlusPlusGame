#include "Game.h"

bool Game::init = false;

std::vector<GameObject> Game::constantObjects{ 
    GameObject("wordStart.PNG", 268, 680),  
    GameObject("titleScreen.PNG", 100, 100),
    GameObject("wordNah.PNG", 811, 680)
};

/*
Game::Game()
{
    //create init objects (will be the title screen here, I guess?)
    this->constantObjects.push_back(GameObject("wut.PNG",0,0));
    this->constantObjects[0].setFocus(true);
}


Game::~Game()
{
}

*/