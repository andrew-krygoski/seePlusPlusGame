#include "Game.h"



Game::Game()
{
    //create init objects
    sf::Texture tmp;
    tmp.loadFromFile("wut.PNG");
    this->objectContainer.push_back(GameObject(tmp));
    this->objectContainer[0].setFocus(true);
}


Game::~Game()
{
}

