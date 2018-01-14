#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 300), "Yo check this garbo!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	bool first = true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		struct timespec req = { 0 };
		req.tv_nsec = 0;
		req.tv_sec = 2;

		if (first) 
		{
			for (int i = 0; i < 1000; i++)
			{
				window.clear();
				cout << shape.getPosition().x << "," << shape.getPosition().y << endl;
				shape.setPosition(shape.getPosition().x + 1, 0);
				window.draw(shape);
				window.display();
				//Sleep(1000);
			}
			first = false;
		}
		
	}

	return 0;
}