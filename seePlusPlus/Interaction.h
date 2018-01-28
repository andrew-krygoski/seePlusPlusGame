#pragma once
#ifndef G_O
#define G_O
#include "GameObject.h"
#endif // G_O
#ifndef WC_I
#define WC_I
#include "WindowControl.h"
#endif // WC_I
#ifndef MI_I
#define MI_I
#include "Misc.h"
#endif // MI_I
const std::vector<int> arrowKeys({ 71,72,73,74 });

class Interaction
{
public:
    static GameObject handleKeyPress(sf::Event event, GameObject object)
    {
        if (!Misc<int>::Contains(arrowKeys, (int)event.key.code)) {
            std::cout << "That is not in my programming, idiot. Key Pressed: " << event.key.code << std::endl;
            return object;
        }

        if      (event.key.code == sf::Keyboard::Up && object.object.getPosition().y != 0) {
            object.object.setPosition(object.object.getPosition().x, object.object.getPosition().y - 1);
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            std::cout << "we aint going further up ";
        }
        else if (event.key.code == sf::Keyboard::Down && object.object.getPosition().y != (WindowController().window.getSize().y - object.object.getLocalBounds().height)) {
            object.object.setPosition(object.object.getPosition().x, object.object.getPosition().y + 1);
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            std::cout << "we aint going further Down ";
        }
        else if (event.key.code == sf::Keyboard::Left && object.object.getPosition().x != 0) {
            object.object.setPosition(object.object.getPosition().x - 1, object.object.getPosition().y);
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            std::cout << "we aint going further left ";
        }
        else if (event.key.code == sf::Keyboard::Right && object.object.getPosition().x != (WindowController().window.getSize().x - object.object.getLocalBounds().height)) {
            object.object.setPosition(object.object.getPosition().x + 1, object.object.getPosition().y);
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            std::cout << "we aint going further Right ";
        }
        else
            std::cout << "shit don't work" << std::endl;

        return object;
    }
};