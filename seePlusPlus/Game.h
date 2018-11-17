#pragma once
#ifndef G_O
#define G_O
#include "GameObject.h"
#endif // G_O

static class Game
{
public:
    static GameObject* getFocused()
    {
        for (int i = 0; i < constantObjects.size(); i++)
        {
            if (constantObjects[i].getFocus())
                return &constantObjects[i];
        }
        if (!init) {
            init = true;
            constantObjects[0].toggleFocus();
            return getFocused();
        }
        throw ExceptionNoFocus();
    }

    static void printObjectPositions()
    {
        for (int i = 0; i < constantObjects.size(); i++)
        {
            std::cout << "\nObject #" << i << ": ";
            constantObjects[i].getStatus();
        }
    }

    static std::vector<GameObject> constantObjects;
    
    //I want to put a list of triggers so that the Interaction class can cycle through the triggers and apply the effects


    static bool init;
} theGame;

