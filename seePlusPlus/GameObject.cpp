#include "GameObject.h"

GameObject::GameObject(sf::Sprite sprite, sf::Texture texture)
{
    this->object = sprite;
    this->image = texture;
    this->isFocus = false;
}

GameObject::GameObject(sf::Sprite sprite) : GameObject(sprite, *(sprite.getTexture())) {}

GameObject::GameObject(sf::Texture texture) : GameObject(sf::Sprite(texture), texture){}

///how will we document this?
///pass in image filename and x/y position of object
GameObject::GameObject(std::string fileName, float xPos, float yPos)
{
    this->image = sf::Texture();
    if (!this->image.loadFromFile(fileName))
    {
        throw "Error loading image";
    }
    this->object = sf::Sprite(this->image);
    this->object.setPosition(xPos, yPos);
    this->isFocus = false;
}

GameObject::~GameObject()
{
}

void GameObject::setFocus(bool focus){this->isFocus = focus;}

///toggle the focus and return what that focus was toggled to
bool GameObject::toggleFocus() { this->setFocus(!this->isFocus); return this->isFocus; }