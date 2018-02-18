#ifndef M_I
#define M_I
#include "main.h"
#endif // M_I
#ifndef G_I
#define G_I
#include "Game.h"
#endif // G_I.
#ifndef I_I
#define I_I
#include "Interaction.h"
#endif // I_I

static void handleEvent(sf::Event event);

int main()
{
    //Initialize Event, which is what we use to handle User Input
    sf::Event event;

    //draw and display the initial screen (going to be title screen at first I guess)
    theWindow.drawScene();
    theWindow.window.display();

    std::cout << "Drew initial scene" << std::endl;

    try {
        //we only want to continue playing if the window's open
        while (theWindow.window.isOpen())
        {
            //fill the event object with any event, then handle it inside
            while (theWindow.window.pollEvent(event))
            {
                handleEvent(event);
            }
        }
    }
    catch (std::exception& ie)
    {
        std::cout << ie.what() << std::endl;
        theWindow.window.close();

        //i don't know how to System("Pause"); anymore...
        int tmp;
        std::cin >> tmp;
    }
}

static void handleEvent(sf::Event event)
{
    //if we need garbage collection, we'll dump it here
    if (event.type == sf::Event::Closed) {
        theWindow.window.close();
        return;
    }

    //on resize, we need to reset the view
    if (event.type == sf::Event::Resized) {
        theWindow.window.clear();

        //circles becomes ovals if there's no resetting of view
        //https://stackoverflow.com/questions/27785940/shapes-proportionally-resize-with-window-in-sfml-2-x
        theWindow.window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
    }

    //irl, this will be way more convoluted past the 
    if (event.type == sf::Event::KeyPressed) {
       Interaction().handleKeyPress(event);
    }

    theWindow.window.clear();
    theWindow.drawScene();
    theWindow.window.display();
}
