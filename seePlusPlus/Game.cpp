#include "Game.h"

bool Game::init = false;

std::vector<GameObject> Game::constantObjects(1, GameObject("wut.PNG", 0, 0));

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