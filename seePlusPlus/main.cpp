#include "main.h"
#include "Interaction.h"
#include "Misc.h"
#include "Game.h"

int main()
{
    WindowController theWindow;
    sf::Event event;
    Game theGame;

    //need to draw the shape before displaying
    theWindow.drawScene(theGame);
    theWindow.window.display();

    while (theWindow.window.isOpen())
    {
        while (theWindow.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                theWindow.window.close();
            }

            if (event.type == sf::Event::Resized) {
                theWindow.window.clear();

                //we need to reset the view if the window is resized, otherwise circles becomes an oval
                //https://stackoverflow.com/questions/27785940/shapes-proportionally-resize-with-window-in-sfml-2-x
                theWindow.window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

                theWindow.drawScene(theGame);
                theWindow.window.display();
            }

            //irl, this will be way more convoluted past the 
            if (event.type == sf::Event::KeyPressed) {
                theGame.objectContainer[0] = Interaction().handleKeyPress(event, theGame.objectContainer[0]);
                theWindow.window.clear();
                theWindow.drawScene(theGame);
                theWindow.window.display();
            }
        }
    }
    
    
}

