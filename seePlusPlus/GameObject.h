#pragma once
#ifndef M_I
#define M_I
#include "main.h"
#endif // M_I

class GameObject
{
public:
    sf::Sprite object;
    sf::Texture image;
    GameObject(sf::Sprite, sf::Texture);
    GameObject(sf::Sprite);
    GameObject(sf::Texture);
    GameObject(std::string, float, float);
    ~GameObject();
    void setFocus(bool);
    bool toggleFocus();
    
protected:
    //https://www.sfml-dev.org/documentation/2.0/classsf_1_1Sprite.php
    //sf::Sprite instance doesn't copy the texture that it uses, it only keeps a reference to it
    
    
    bool isFocus;
};

