#include "GameObject.h"

GameObject::GameObject(sf::Sprite sprite, sf::Texture texture)
{
    this->object = sprite;
    this->image = texture;
    this->isFocus = false;
    this->object.setPosition(0, 0);
}

GameObject::GameObject(sf::Sprite sprite) : GameObject(sprite, *(sprite.getTexture())) {}

GameObject::GameObject(sf::Texture texture) : GameObject(sf::Sprite(texture), texture){}

///<summary>pass in image filename and x/y position of object</summary>
///<param>string: the name of the file containing the image of the object</param>
///<param>float: x position of the object</param>
///<param>float: y position of the object</param>
GameObject::GameObject(std::string fileName, float xPos, float yPos){
    this->image = sf::Texture();
    if (!this->image.loadFromFile(fileName))
    {
        throw "Error loading image file: " + fileName;
    }
    this->object = sf::Sprite(this->image);
    this->object.setPosition(xPos, yPos);
    this->isFocus = false;
}

GameObject::~GameObject()
{
}



///<summary>toggle the focus and return what that focus was toggled to</summary>
bool GameObject::toggleFocus() { this->setFocus(!this->isFocus); return this->isFocus; }

///<summary>return whether this object isFocus</summary>
bool GameObject::getFocus() { return this->isFocus; }

///<summary>set the focus equal to the boolean</summary>
///<param>boolean: as to whether this object is in control by the user</param>
void GameObject::setFocus(bool focus){this->isFocus = focus;}

///<summary>return current Object address</summary>
GameObject* GameObject::getAddress() { return this; }

///<summary>returns string representation of this object</summary>
void GameObject::getStatus()
{ 
    std::cout << "Position: " << this->object.getPosition().x<< "," << this->object.getPosition().y << std::endl; 
    std::cout << "Address : " << this << std::endl;
}