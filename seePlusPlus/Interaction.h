#pragma once
#ifndef G_O
#define G_O
#include "GameObject.h"
#endif // G_O
#ifndef WC_I
#define WC_I
#include "WindowControl.h"
#endif // WC_I
const std::vector<int> arrowKeys({ 71,72,73,74 });

class Interaction
{
public:
    static void handleKeyPress(sf::Event event)
    {
        if (!Misc<int>::Contains(arrowKeys, (int)event.key.code)) {
            std::cout << "Key Not coded: " << event.key.code << std::endl;
            return;
        }
        
        //create a reference to the object that is our focus (aka the one we want to control)
        GameObject &focused = *(theGame.getFocused());

        if (willLeadOutOfBounds(focused, event.key.code))
            return;

        //quickly hit up our directionals, move if able
        if (event.key.code == sf::Keyboard::Up) { focused.object.setPosition(focused.object.getPosition().x, focused.object.getPosition().y - movespeed); }
        else if (event.key.code == sf::Keyboard::Down) { focused.object.setPosition(focused.object.getPosition().x, focused.object.getPosition().y + movespeed); }
        else if (event.key.code == sf::Keyboard::Left) { focused.object.setPosition(focused.object.getPosition().x - movespeed, focused.object.getPosition().y); }
        else if (event.key.code == sf::Keyboard::Right) { focused.object.setPosition(focused.object.getPosition().x + movespeed, focused.object.getPosition().y); }
        else
            std::cout << "shit don't work" << std::endl;

    }

    static void handleMousePress(sf::Event event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            std::cout << "Mouse clicked at:" << event.mouseButton.x << "," << event.mouseButton.y << std::endl;
        }
        else
            std::cout << "Stop right clicking";
    }

private:
    //if we make every screen a grid, this would be 10000x easier
    static bool willLeadOutOfBounds(GameObject focused, sf::Keyboard::Key key)
    {
        if (key == sf::Keyboard::Up && focused.object.getPosition().y < movespeed)
        {
            std::cout << "we aint going further Up " << std::endl;
            return true;
        }
        else if (key == sf::Keyboard::Down &&  movespeed > theWindow.window.getSize().y - (focused.object.getPosition().y + focused.object.getLocalBounds().height))
        {
            std::cout << "we aint going further Down " << std::endl;
            return true;
        }
        else if (key == sf::Keyboard::Left && focused.object.getPosition().x < movespeed)
        {
            std::cout << "we aint going further Left " << std::endl;
            return true;
        }
        else if (key == sf::Keyboard::Right && movespeed > theWindow.window.getSize().x - (focused.object.getPosition().x + focused.object.getLocalBounds().width))
        {
            std::cout << "we aint going further Right " << std::endl;
            return true;
        }
        else
            return false;
    }
    static const int movespeed = 10;
};