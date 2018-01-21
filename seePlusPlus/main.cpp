#include "main.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Yo check this garbo!");
    sf::CircleShape shape(100.f);
    sf::Event event;

    //need to draw the shape before displaying
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);
    window.display();

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                window.clear();

                //we need to reset the view if the window is resized, otherwise the circle becomes an oval
                //https://stackoverflow.com/questions/27785940/shapes-proportionally-resize-with-window-in-sfml-2-x
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));

                window.draw(shape);
                window.display();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (!Misc<int>::Contains(arrowKeys, (int)event.key.code)) {
                    std::cout << "That is not in my programming, idiot. Key Pressed: " << event.key.code << std::endl;
                    continue;
                }

                window.clear();

                if (event.key.code == sf::Keyboard::Up && shape.getPosition().y != 0) {
                    shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    std::cout << "we aint going further up ";
                }
                else if (event.key.code == sf::Keyboard::Down && shape.getPosition().y != (window.getSize().y - shape.getRadius())) {
                    shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    std::cout << "we aint going further Down ";
                }
                else if (event.key.code == sf::Keyboard::Left && shape.getPosition().x != 0) {
                    shape.setPosition(shape.getPosition().x - 1, shape.getPosition().y);
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    std::cout << "we aint going further left ";
                }
                else if (event.key.code == sf::Keyboard::Right && shape.getPosition().x != (window.getSize().x - shape.getRadius())) {
                    shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    std::cout << "we aint going further Right ";
                }
                else
                    std::cout << "shit don't work" << std::endl;

                
                window.draw(shape);
                window.display();
                std::cout << shape.getPosition().x << "," << shape.getPosition().y << std::endl;
            }
        }
    }
    
    
}

