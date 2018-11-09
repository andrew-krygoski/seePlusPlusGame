#pragma once
#ifndef G_I
#define G_I
#include "Game.h"
#endif // G_I


///<summary>static Window that will contain everything the User sees</summary>
static class WindowController {
public:
    
    ///<summary>loops through Game().objectContainer, sets the textures, and draws on the static window</summary>
    static void drawScene() {
        for each(GameObject toBeDrawn in theGame.constantObjects)
        {
            toBeDrawn.object.setTexture(toBeDrawn.image);
            window.draw(toBeDrawn.object);
        }
    }

    ///<summary>static window that contains all the User can see</summary>
    static sf::RenderWindow window;
} theWindow;