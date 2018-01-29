#include "Game.h"



Game::Game()
{
    //create init objects
    this->objectContainer.push_back(GameObject("wut.PNG",0,0));
    this->objectContainer[0].setFocus(true);
}


Game::~Game()
{
}

