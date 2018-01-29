#pragma once
#ifndef G_I
#define G_I
#include "Game.h"
#endif // G_I

static class WindowController {
public:
    static void drawScene(Game theGame) {
        for each(GameObject object in theGame.objectContainer)
        {
            object.object.setTexture(object.image);
            window.draw(object.object); //lmao, how many times can i use the word object?
        }
    }
    
    static sf::RenderWindow window;
};