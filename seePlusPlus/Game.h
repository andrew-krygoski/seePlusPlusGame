#pragma once
#ifndef G_O
#define G_O
#include "GameObject.h"
#endif // G_O

class Game
{
public:
    Game();
    ~Game();

    std::vector<GameObject> objectContainer;
};

