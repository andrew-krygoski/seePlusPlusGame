#pragma once
#ifndef M_I
#define M_I
#include "main.h"
#endif // M_I

//TODO: make objects JSON so we can keep them in external files and pull them in as needed

class GameObject
{
public:
    //https://www.sfml-dev.org/documentation/2.0/classsf_1_1Sprite.php
    //sf::Sprite instance doesn't copy the texture that it uses, it only keeps a reference to it
    sf::Texture image;
    sf::Sprite object; 

    GameObject(sf::Sprite, sf::Texture);
    GameObject(sf::Sprite);
    GameObject(sf::Texture);
    GameObject(std::string);
    GameObject(std::string, float, float);
    GameObject(std::string, float, float, bool);
    GameObject(sf::Sprite, sf::Texture, float, float);
    GameObject(sf::Sprite, sf::Texture, float, float, bool);
    ~GameObject();
    void setFocus(bool);
    bool toggleFocus();
    bool getFocus();
    GameObject* getAddress();
    void getStatus();

protected:
    bool isFocus;
    bool clickable;
    GUID objectId;
    int gameObjectType; 

    //TODO: might not be necessary to record
    GUID triggersAssociated[];
};

static enum GameObjectType { Sentient, Nonsentient, Scene };

/*
//GameObject JSON
{
isFocus: bool,
clickable: bool,
objectId: GUID,
gameObjectType: int,
triggersToLoad: GUID[]
}
*/